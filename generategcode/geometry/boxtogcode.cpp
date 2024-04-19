#include "arctogcode.h"
#include "boxtogcode.h"
#include "holetogcode.h"
#include "linetogcode.h"

#include "helpers/logger.h"
#include <QtMath>

#include <helpers/stringhelper.h>

#include <gcode/gcode.h>

#include <generategcode/cuts/circulararccut.h>
#include <generategcode/cuts/helicalcut.h>
#include <generategcode/cuts/linearcut.h>

#include <generategcode/compensation.h>
#include <generategcode/gcodecommon.h>
#include <generategcode/gcodemanager.h>
#include <generategcode/goto.h>
#include <generategcode/lift.h>
#include <generategcode/tooltogcode.h>

bool BoxToGCode::ParseBox(const QString& str, QString *gcode, QString *err, ToGCodeModel *tmm,TotalStats *tss)
{
    Box m;
    auto s = Box::Parse(str, tmm->_XYMode, tmm->_MMode, &m, tmm->_offset_xyz);
    if(s.state()==ParseState::NoData) return false;
    zInfo(GCodeCommon::T1+str);
    if(s.state() == ParseState::Parsed ) // ha Box típusú sor
    {
        if(tmm->_isPlot){
            ToolToGCode::SetToolToPen({&m.p0, &m.p1, &m.rp}, &m.gap, &m.cut, &m.feed, tmm);
        } else{
            if(tmm->_safez>0){
                m.p0.z+=tmm->_safez;
                m.p1.z+=tmm->_safez;
                //    m.rp.z+=_safez;

                m.cut.z+=tmm->_safez;
            }
            if(tmm->_safeb>0){
                m.cut.z+=tmm->_safeb;
                if(m.gap.isValid()){
                    m.gap.height+=tmm->_safeb;
                }
            }
            if(tmm->_overcut>0){
                m.cut.z+=tmm->_overcut;
                if(m.gap.isValid()){
                    m.gap.height+=tmm->_overcut;
                }
            }
            if(!m.feed.Check(tmm->_fmin, tmm->_fmax)){
                if(tmm->_selected_feed3.Check(tmm->_fmin, tmm->_fmax,err)){
                    m.feed = tmm->_selected_feed3;
                }
            }
        }

        if(gcode)*gcode=BoxToGCode::CreateBox(m,err,tmm, tss);
    }
    QString msg;
    msg+=s.ToString();
    if(!msg.isEmpty())zInfo(msg);
    return true;
}

QString BoxToGCode::CreateBox(const Box &m,QString*err, ToGCodeModel* tmm, TotalStats *tss)
{
    //_lasterr.clear();
    auto msg = GCodeCommon::G1+m.ToString();
    StringHelper::Tabulate(&msg, GCodeCommon::G2);
    zInfo(msg);
    msg = "(time[min]: "+QString::number(tss->_total_minutes)+")";
    zInfo(msg);

    /*BOXTYPE*/
    if(tmm->_lastGeom._lastBox.type()==BoxType::Undefined && m.type==BoxType::Undefined){
        if(err)*err=L("no box type");
        return {};
    }
    if(m.type!=BoxType::Undefined) tmm->_lastGeom._lastBox.setType(m.type);
    if(tmm->_lastGeom._lastBox.type()==BoxType::Undefined) {
        if(err)*err=L("undefined box type");
        return {};
    }
    /*CORNER_DIAMETER*/
    if(tmm->_lastGeom._lastBox.type()==BoxType::Corners){
        if(tmm->_last_hole_diameter==-1 && m.corner_diameter==-1){
            if(err){*err=L("no diameter");}
            return {};
        } else{
            if(m.corner_diameter!=-1) tmm->_last_hole_diameter=m.corner_diameter;
        }
    }
    /*CUT*/
    /*CUT*/
    auto cutCheckResult = m.cut.Check(err);
    if(cutCheckResult == Cut::CheckR::invalid){
        return{};
    }
    /*FEED*/
    if(!m.feed.Check(tmm->_fmin, tmm->_fmax, err)){
        return{};
    }
    //SetSelectedFeed(m.feed);
    /*TOOL*/
    if(!tmm->ValidateTool()) {if(err)*err=L("no tool"); return {};}
    Tool t = tmm->selectedTool();

    if(m.p0.isValid()){
        tmm->_lastGeom._lastBox.setP0(m.p0);
    }
    if(m.rp.isValid()){
        if(tmm->_lastGeom._lastBox.p0().isValid()){
            tmm->_lastGeom._lastBox.p0().Translate(m.rp);
        } else{
            if(err)*err=L("p0 not valid");
            return {};
        }
    }
    if(m.p1.isValid()){
        tmm->_lastGeom._lastBox.setP1(m.p1);
    } else{
        if(m.size.isValid()){ // ha van méret megadva az az elsődleges
            auto tp = GeoMath::Translation(tmm->_lastGeom._lastBox.p0(),m.size.width(), m.size.height());
            tmm->_lastGeom._lastBox.setP1(tp);
        } else if(m.rp.isValid() && tmm->_lastGeom._lastBox.p1().isValid()){
            auto tp = GeoMath::Translation(tmm->_lastGeom._lastBox.p1(),m.rp);
            tmm->_lastGeom._lastBox.setP1(tp);
        }
    }


    qreal distance = tmm->_lastGeom._lastBox.Distance();
    if(distance<(t.d/1.4)) {
        if(err){
            *err=L("box diagonal too short: ")+QString::number(distance)+"mm";
        }
        return {};
    }



    /*rectangle normalizálás*/
    auto zz = (tmm->_lastGeom._lastBox.p0().z+tmm->_lastGeom._lastBox.p1().z)/2;
    Point ba,jf,ja,bf;
    if(tmm->_lastGeom._lastBox.p0().x<tmm->_lastGeom._lastBox.p1().x){
        //p0b, p1j
        if(tmm->_lastGeom._lastBox.p0().y<tmm->_lastGeom._lastBox.p1().y){
            //p0ba, p1jf
            ba=tmm->_lastGeom._lastBox.p0();
            jf=tmm->_lastGeom._lastBox.p1();
            //1
            bf={ba.x,jf.y,zz};
            ja={jf.x,ba.y,zz};
        } else{
            //p0bf, p1ja
            bf=tmm->_lastGeom._lastBox.p0();
            ja=tmm->_lastGeom._lastBox.p1();
            //2
            ba={bf.x,ja.y,zz};
            jf={ja.x,bf.y,zz};
        }
    } else{
        //p0j, p1b
        if(tmm->_lastGeom._lastBox.p0().y<tmm->_lastGeom._lastBox.p1().y){
            //p0ja, p1bf
            ja=tmm->_lastGeom._lastBox.p0();
            bf=tmm->_lastGeom._lastBox.p1();
            //3
            ba={bf.x,ja.y,zz};
            jf={ja.x,bf.y,zz};
        } else{
            //p0jf, p1ba
            jf=tmm->_lastGeom._lastBox.p0();
            ba=tmm->_lastGeom._lastBox.p1();
            //4
            bf={ba.x,jf.y,zz};
            ja={jf.x,ba.y,zz};
        }
    }

    QString nameComment = m.GetComment();
    GCodeManager g(nameComment);

    g.append(tss->TotalTimeToGCode());

    if(m.joinGap!=0){
        switch(tmm->_lastGeom._lastBox.type()){
        case BoxType::Outline:
            ba.x+=m.joinGap;
            ba.y+=m.joinGap;
            jf.x-=m.joinGap;
            jf.y-=m.joinGap;
            break;
        case BoxType::Inline:
            ba.y-=m.joinGap;
            ba.x-=m.joinGap;
            jf.y+=m.joinGap;
            jf.x+=m.joinGap;
            break;
        default: break;
        }
    }

    if(jf.x-ba.x<t.d)
    {
        if(err)*err=L("box w is too small");
        return {};
    }

    if(jf.y-ba.y<t.d)
    {
        if(err)*err=L("box h is too small");
        return {};
    }

    /*szerszámpálya*/
    qreal tool_r = t.d/2;

    Point bao=ba, jfo=jf;
    switch(tmm->_lastGeom._lastBox.type()){
    case BoxType::Outline:
        ba.x-=tool_r;
        ba.y-=tool_r;
        jf.x+=tool_r;
        jf.y+=tool_r;


        //
        ja.x=jf.x;
        ja.y=ba.y;
        bf.x=ba.x;
        bf.y=jf.y;
        break;
    case BoxType::Inline:
        ba.y+=tool_r;
        ba.x+=tool_r;
        jf.y-=tool_r;
        jf.x-=tool_r;

        //
        ja.x=jf.x;
        ja.y=ba.y;
        bf.x=ba.x;
        bf.y=jf.y;
        break;
    default: break;
    }

    Point ba1 = ba;
    Point ja1 = ja;
    Point ja2 = ja;
    Point jf2 = jf;
    Point jf3 = jf;
    Point bf3 = bf;
    Point bf4 = bf;
    Point ba4 = ba;

    switch(tmm->_lastGeom._lastBox.type()){
    case BoxType::Outline:
        ba1.x=bf3.x=bao.x;
        ja1.x=jf3.x=jfo.x;
        ja2.y=ba4.y=bao.y;
        jf2.y=bf4.y=jfo.y;
        break;
    case BoxType::Inline:
        ba1.x=bf3.x=ba.x;
        ja1.x=jf3.x=jf.x;
        ja2.y=ba4.y=ba.y;
        jf2.y=bf4.y=jf.y;
        break;
    default: break;
    }

    bool bevOrRound = tmm->_lastGeom._lastBox.type()!=BoxType::Corners && m.rounding>0;

    bool isRounding = false;//_lastBox.type!=BoxType::Corners && m.rounding>0;
    bool isBevelling = false;//_lastBox.type!=BoxType::Corners && m.bevelling>0;
    if(bevOrRound){
        if(m.bevelling>0){
            isBevelling = true;
            isRounding = false;
        } else{
            isBevelling = false;
            isRounding = true;
        }
    }

    bool isR0 = m.nl[0]!=0&&m.nl[1]!=0;//0
    bool isR1 = m.nl[1]!=0&&m.nl[2]!=0;//1
    bool isR2 = m.nl[2]!=0&&m.nl[3]!=0;//2
    bool isR3 = m.nl[3]!=0&&m.nl[0]!=0;//3

    bool isR0m = false;
    bool isR1m = false;
    bool isR2m = false;
    bool isR3m = false;

    //    for(int k=0;k<4;k++){
    //        if(m.nr[k]==false){
    //            zInfo("hutty");
    //        }
    //    }
    if(isRounding || isBevelling){
        qreal rounding_r = m.rounding-tool_r;
        //0
        if(isR0){
            ja1.x-=rounding_r;
            ja2.y+=rounding_r;
        } else{
            if(m.nr[0]){
                if(m.rjoin==1 ){
                    if(m.nl[0]==1||m.nl[1]==1){
                        ja1.x-=rounding_r;
                        ja2.y+=rounding_r;
                        isR0=true;
                    }
                } else if(m.rjoin==2){
                    if(m.type==BoxType::Inline){
                        if(m.nl[0]==0 && m.nl[1]==1){
                            ja1.x+=rounding_r;
                            ja1.y-=t.d;
                            ja2.y+=rounding_r-t.d;
                            isR0m=true;
                        } else if(m.nl[0]==1 && m.nl[1]==0){
                            ja1.x-=rounding_r-t.d;
                            ja2.x+=t.d;
                            ja2.y-=rounding_r;
                            isR0m=true;
                        }
                        isR0=true;
                    } else {
                        if(m.nl[0]==0 && m.nl[1]==1){
                            ja1.x+=rounding_r+t.d;
                            ja2.y+=rounding_r;
                            isR0m=true;
                        } else if(m.nl[0]==1 && m.nl[1]==0){
                            ja1.x-=rounding_r;
                            ja2.y-=rounding_r+t.d;
                            isR0m=true;
                        }
                        isR0=true;
                    }
                }
            }
        }
        //1
        if(isR1){
            jf2.y-=rounding_r;
            jf3.x-=rounding_r;
        }else{
            if(m.nr[1]){
                if(m.rjoin==1 /*|| !m.nr[1]*/){
                    if(m.nl[1]==1||m.nl[2]==1){
                        jf2.y-=rounding_r;
                        jf3.x-=rounding_r;
                        isR1=true;
                    }
                } else if(m.rjoin==2){
                    if(m.type==BoxType::Inline){
                        if(m.nl[1]==0&&m.nl[2]==1){
                            jf2.y+=rounding_r;
                            jf2.x+=t.d;
                            jf3.x-=rounding_r-t.d;
                            isR1m=true;
                        }
                        else if (m.nl[1]==1 &&m.nl[2]==0){
                            jf2.y-=rounding_r-t.d;
                            jf3.y+=t.d;
                            jf3.x+=rounding_r;
                            isR1m=true;
                        }
                        isR1=true;
                    } else{
                        if(m.nl[1]==0 && m.nl[2]==1){ //ez
                            jf3.x-=rounding_r;
                            jf2.y+=rounding_r+t.d;
                            isR1m=true;
                        } else if(m.nl[1]==1 && m.nl[2]==0){
                            jf2.y-=rounding_r;
                            jf3.x+=rounding_r+t.d;
                            isR1m=true;
                        }
                        isR1=true;
                    }
                }
            }
        }
        //2
        if(isR2){
            bf3.x+=rounding_r;
            bf4.y-=rounding_r;
        }else{
            if(m.nr[2]){
                if(m.rjoin==1){
                    if(m.nl[2]==1||m.nl[3]==1){
                        bf3.x+=rounding_r;
                        bf4.y-=rounding_r;
                        isR2=true;
                    }
                } else if(m.rjoin==2){
                    if(m.type==BoxType::Inline){
                        if(m.nl[2]==0&&m.nl[3]==1){
                            bf3.x-=rounding_r;
                            bf3.y+=t.d;
                            bf4.y-=rounding_r-t.d;//+
                            isR2m=true;
                        }
                        else if(m.nl[2]==1&&m.nl[3]==0){
                            bf3.x+=rounding_r-t.d;
                            bf4.x-=t.d;
                            bf4.y+=rounding_r;
                            isR2m=true;
                        }
                        isR2=true;
                    } else{
                        if(m.nl[2]==0 && m.nl[3]==1){
                            bf3.x-=rounding_r+t.d;
                            bf4.y-=rounding_r;
                            isR2m=true;
                        } else if(m.nl[2]==1 && m.nl[3]==0){
                            bf3.x+=rounding_r;
                            bf4.y+=rounding_r+t.d;
                            isR2m=true;
                        }
                        isR2=true;
                    }
                }
            }
        }
        //3
        if(isR3){
            ba1.x+=rounding_r;
            ba4.y+=rounding_r;
        }else{
            if(m.nr[3]){
                if(m.rjoin==1){
                    if(m.nl[3]==1||m.nl[0]==1)
                    {
                        ba1.x+=rounding_r;
                        ba4.y+=rounding_r;
                        isR3=true;
                    }
                } else if(m.rjoin==2){
                    if(m.type==BoxType::Inline){
                        if(m.nl[3]==0&&m.nl[0]==1){
                            ba1.x+=rounding_r-t.d;
                            ba4.x-=t.d;
                            ba4.y-=rounding_r;
                            isR3m=true;
                        }
                        else if(m.nl[3]==1&&m.nl[0]==0){
                            ba1.x-=rounding_r;
                            ba1.y-=t.d;
                            ba4.y+=rounding_r-t.d;
                            isR3m=true;
                        }

                        isR3=true;
                    } else{
                        if(m.nl[3]==0 && m.nl[0]==1){
                            ba1.x+=rounding_r;
                            ba4.y-=rounding_r+t.d;
                            isR3m=true;
                        } else if(m.nl[3]==1 && m.nl[0]==0){//ez
                            ba4.y+=rounding_r;
                            ba1.x-=rounding_r+t.d;
                            isR3m=true;
                        }
                        isR3=true;
                    }
                }
            }
        }
    }

    msg=GCodeCommon::G2+ ba.ToString()+' '+jf.ToString();
    msg+=' '+BoxType::ToString(tmm->_lastGeom._lastBox.type());
    msg+=' '+m.cut.ToString();
    msg+=' '+m.feed.ToString();
    msg+=" d"+GCode::r(tmm->_last_hole_diameter);
    msg+=' '+m.gap.ToString();

    zInfo(msg);

    if(tmm->_lastGeom._lastBox.type() == BoxType::Corners){

        QVarLengthArray<Hole> holes = {
            {ba, tmm->_last_hole_diameter, m.cut, m.feed, {}, m.joinGap, {}, m._no_predrill,false, m.name+":1_ba", true, m.no_simi},
            {ja, tmm->_last_hole_diameter, m.cut, m.feed, {}, m.joinGap, {}, m._no_predrill,false, m.name+":2_ja", true, m.no_simi},
            {jf, tmm->_last_hole_diameter, m.cut, m.feed, {}, m.joinGap, {}, m._no_predrill,false, m.name+":3_jf", true, m.no_simi},
            {bf, tmm->_last_hole_diameter, m.cut, m.feed, {}, m.joinGap, {}, m._no_predrill,false, m.name+":4_bf", true, m.no_simi}
        };

        if(tmm->_verbose){
            for(int i=0;i<holes.length();i++){
                auto&l=holes[i];
                //g.append('('+l.ToString()+')');
                zInfo('h'+QString::number(i)+':'+l.ToString());
            }
        }
        for(auto&h:holes){
            auto gl = HoleToGCode::CreateHole(h,err,tmm, tss);
            if(!gl.isEmpty()){
                g.append(gl);
            } else{
                zInfo("err: "+(err?*err:QString()));
            }
        }
    } else {
        // lemegy egyben a gapig
        //        bool hasGaps = m.gap.isValid() && m.gap.n>0;
        //        qreal z2 = hasGaps?m.cut.z-m.gap.height:m.cut.z;
        //        Cut cut_border{z2, m.cut.z0};
        bool hasGaps = m.gap.isValid() && m.gap.n>0;
        qreal z2 = hasGaps?m.cut.z-m.gap.height:m.cut.z;
        QVarLengthArray<Line> lines_border;
        QVarLengthArray<Line> lines_bevelling;
        QVarLengthArray<Arc> arcs;
        Cut cut_border;//{z2, _last_cut.z0};
        if(z2>0){
            cut_border = {z2, m.cut.z0};

            if(m.vcorner_x>0){
                //1
                ba1.x+=m.vcorner_x;
                ja1.x-=m.vcorner_x;

                //4
                bf3.x+=m.vcorner_x;
                jf3.x-=m.vcorner_x;
            }
            if(m.vcorner_y>0){
                //2
                ja2.y+=m.vcorner_y;
                jf2.y-=m.vcorner_y;

                //3
                ba4.y+=m.vcorner_y;
                bf4.y-=m.vcorner_y;
            }

            lines_border= {
                            {ba1,ja1, cut_border, m.feed,{}, {}, m.name+" border 1 ba1,ja1", false, m.no_compensate, m.menet, m.no_simi},
                            {ja2,jf2, cut_border, m.feed,{}, {}, m.name+" border 2 ja2,jf2", false, m.no_compensate, m.menet, m.no_simi},
                            {jf3,bf3, cut_border, m.feed,{}, {}, m.name+" border 3 jf3,bf3", false, m.no_compensate, m.menet, m.no_simi},
                            {bf4,ba4, cut_border, m.feed,{}, {}, m.name+" border 4 bf4,ba4", false, m.no_compensate, m.menet, m.no_simi}};
        }

        if(isRounding){
            Cut cut = {m.cut.z,m.cut.z0};
            if(isR0){
                if(isR0m)
                    arcs.append({ja1, ja2, {ja1.x, ja2.y,ja2.z}, cut, m.feed, {0,0,0}, m.name+" rounding 1 ja1,ja2"});
                else
                    arcs.append({ja2, ja1, {ja1.x, ja2.y,ja2.z}, cut, m.feed, {0,0,0}, m.name+" rounding 1 ja2,ja1"});
            }
            if(isR1){
                if(isR1m)
                    arcs.append({jf2, jf3, {jf3.x, jf2.y,jf2.z}, cut, m.feed, {0,0,0},  m.name+" rounding 2 jf2,jf3"});
                else
                    arcs.append({jf3, jf2, {jf3.x, jf2.y,jf2.z}, cut, m.feed, {0,0,0},  m.name+" rounding 2 jf3,jf2"});
            }
            if(isR2){
                if(isR2m)
                    arcs.append({bf3, bf4, {bf3.x, bf4.y,bf4.z}, cut, m.feed, {0,0,0}, m.name+" rounding 3 bf3,bf4"});
                else
                    arcs.append({bf4, bf3, {bf3.x, bf4.y,bf4.z}, cut, m.feed, {0,0,0}, m.name+" rounding 3 bf4,bf3"});
            }
            if(isR3){
                if(isR3m)
                    arcs.append({ba4, ba1, {ba1.x, ba4.y,ba4.z}, cut, m.feed, {0,0,0}, m.name+" rounding 4 ba4,ba1"});
                else
                    arcs.append({ba1, ba4, {ba1.x, ba4.y,ba4.z}, cut, m.feed, {0,0,0}, m.name+" rounding 4 ba1,ba4"});
            }
        } else if(isBevelling){
            Cut cut = {m.cut.z,m.cut.z0};
            if(isR0)
                lines_bevelling.append({ja1, ja2, cut, m.feed,{}, {}, m.name+" bevelling 1 ba1,ja2", false, m.no_compensate, m.menet, m.no_simi});
            if(isR1)
                lines_bevelling.append({jf2, jf3, cut, m.feed,{}, {}, m.name+" bevelling 2 jf2,jf3", false, m.no_compensate, m.menet, m.no_simi});
            if(isR2)
                lines_bevelling.append({bf3, bf4, cut, m.feed,{}, {}, m.name+" bevelling 2 bf3,bf4", false, m.no_compensate, m.menet, m.no_simi});
            if(isR3)
                lines_bevelling.append({ba4, ba1, cut, m.feed,{}, {}, m.name+" bevelling 2 ba4,ba1", false, m.no_compensate, m.menet, m.no_simi});
        }

        QVarLengthArray<Line> lines_gap;
        if(hasGaps){
            //gap layer
            ba.z-=z2;
            bf.z-=z2;
            ja.z-=z2;
            jf.z-=z2;

            ba1.z-=z2;
            ja1.z-=z2;
            ja2.z-=z2;
            jf2.z-=z2;
            jf3.z-=z2;
            bf3.z-=z2;
            bf4.z-=z2;
            ba4.z-=z2;

            auto cz0 = m.gap.height<m.cut.z0?m.gap.height:m.cut.z0;
            Cut cut_gap{m.gap.height,  cz0};

            lines_gap = {
                {ba1,ja1, cut_gap, m.feed,{},{}, m.name+" gap 1 ba1,ja1", false, m.no_compensate, m.menet, m.no_simi},
                {ja2,jf2, cut_gap, m.feed,{},{}, m.name+" gap 2 ja2,jf2", false, m.no_compensate, m.menet, m.no_simi},
                {jf3,bf3, cut_gap, m.feed,{},{}, m.name+" gap 3 jf3,bf3", false, m.no_compensate, m.menet, m.no_simi},
                {bf4,ba4, cut_gap, m.feed,{},{}, m.name+" gap 4 bf4,ba4", false, m.no_compensate, m.menet, m.no_simi}
            };
        }
        zInfo(L("(segments)"));
        QList<Line> segments;

        qreal l0 = 0;
        qreal l1 = 0;
        if(lines_border.length()>=4){
            l0 = lines_border[0].Length();
            l1 = lines_border[1].Length();


            //qreal l_min = l0<l1?l0:l1;
            qreal l_max = l0>l1?l0:l1;
            //qreal m_min = (l0<l1?l0:l1)/m.gap.n+1;
            qreal gap_max_l = l_max/m.gap.n+1;

            for(int i=0;i<4;i++){
                if(m.nl[i]==0) continue;
                auto&l_border=lines_border[i];

                QList<Line> gapSegments;
                bool hasGapSegments = false;
                Line line_gap;
                if(hasGaps){
                    qreal l = l_border.Length();
                    Gap gap2 = m.gap;
                    if(l<gap_max_l){
                        gap2.n = 1;
                    } else{
                        gap2.n = m.gap.n;
                    }

                    line_gap = lines_gap[i];
                    gapSegments = line_gap.Divide(gap2, t.d);
                    hasGapSegments = !gapSegments.isEmpty();

                    if(!hasGapSegments){
                        zInfo(QStringLiteral("cannot divide line"));
                    } else{
                        qreal distance = GeoMath::Distance(gapSegments[0].p0, gapSegments[0].p1);
                        if(distance<t.d) {
                            if(err){*err=L("line too short: ")+QString::number(distance)+"mm";}

                            // return {};
                        }
                    }

                }

                // if(lines_border.length()>i){

                //     //l_border.length();
                //     //if(cut_border.z>0){ segments.append(l_border);}

                //     segments.append(l_border);
                // }

                if(lines_border.length()>i){
                    if(hasGapSegments){
                        //l_border.aljasimi = false;
                        //l_border.no_overcut = true;
                        segments.append(l_border);

                        segments.append(gapSegments);
                    }else{
                        //l_border.aljasimi = true;
                        //segments.append(lines_gap[i]);
                        l_border.name+="nogaps_border";
                        segments.append(l_border);

                        if(hasGaps){
                            l_border.name+="nogaps_gap";
                            segments.append(line_gap);
                        }
                    }
                }
            }
        }

        //        if(_verbose){
        //            for(int i=0;i<segments.length();i++){
        //                auto&l=segments[i];
        //                g.append('('+l.ToString()+')');
        //                zInfo('l'+QString::number(i)+':'+l.ToString());
        //            }
        //        }

        if(m.menet==1){
            if(segments.length()>0){
                Point p0=segments[0].p0;
                GoTo::GoToCutposition(&g, p0, m.feed, tmm,tss);
                qreal zz = p0.z-m.cut.z;

                g.Append( "(box_z down)");
                auto g0 = GoTo::GoToZ(GMode::Linear, {0, 0, zz}, m.feed.feed(), tmm,tss);
                g.Append(g0);

                g.Append( "(box_segments)");
                for (Line &s : segments) {
                    //qreal d = GeoMath::Distance(s.p0,s.p1);
                    //dt+=d;
                    g0 = GoTo::GoToXY(GMode::Linear, s.p0, m.feed.feed(),tmm,tss, {});
                    g.Append( g0);
                    g0 = GoTo::GoToXY(GMode::Linear, s.p1, m.feed.feed(),tmm,tss, {});
                    g.Append( g0);
                }
                // utolsót összekötni elsővel
                auto s0 = segments.first();
                g0 = GoTo::GoToXY(GMode::Linear, s0.p0, m.feed.feed(),tmm,tss, {});
                g.Append( g0);


                g0 = Lift::Up(m.feed.feed(), p0.z,tmm,tss);
                g.Append( g0);
            }
        }
        else{
            QList<Line> gaps;
            for(auto&segment:segments){


                if(segment.name.startsWith(" border"))
                {
                    QString e0;
                    auto px0 = tmm->_lastGeom._lastLine.p0();
                    auto px1 = tmm->_lastGeom._lastLine.p1();
                    QString g0;

                    g0 = LineToGCode::CreateLine(segment, &e0, tmm, tss);

                    bool hasGcode = !g0.isEmpty();
                    if(hasGcode){
                        g.append(g0);
                    } else{
                        if(err){
                            if(!err->isEmpty()) *err+=",";
                            *err+=segment.name+": "+e0;
                        }
                        // ki van számolva a gap, de túl kicsi, hiányozni fog
                        zInfo("border segment gcode error");
                    }
                    tmm->_lastGeom._lastLine.setP0(px0); // azonnal vissza is állítjuk
                    tmm->_lastGeom._lastLine.setP1(px1);
                } else if( segment.name.startsWith(" gap")){
                    gaps.append(segment);
                }
            }

            if(!gaps.isEmpty()){
                QString e0;
                auto g0 = LineToGCode::CreateLines(gaps, &e0,tmm,tss);
                bool hasGcode = !g0.isEmpty();
                if(hasGcode){
                    g.append(g0);
                } else{
                    if(err){
                        if(!err->isEmpty()) *err+=",";
                        QString n;
                        for(auto&g:gaps){
                            if(!n.isEmpty()) n+=",";
                            n+=g.name;
                        }
                        *err+=n+": "+e0;
                    }
                    // ki van számolva a gap, de túl kicsi, hiányozni fog
                    zInfo("gap segment gcode error");
                }
                gaps.clear();

            }
        }

        if(isRounding){
            for(auto&arc_rounding:arcs){
                QString e0;
                tmm->_lastGeom._lastArc.Store();
                //auto px0 = _lastGeom._lastArc.p0;
                //auto px1 = _lastGeom._lastArc.p1;
                //auto pxo = _lastGeom._lastArc.o;
                auto g0 = ArcToGCode::CreateArc(arc_rounding, &e0, tmm,tss);
                if(!g0.isEmpty()){
                    g.append(g0);
                } else{
                    if(err){
                        if(!err->isEmpty()) *err+=",";
                        *err+=arc_rounding.name+": "+e0;
                    }
                    zInfo("arc_rounding gcode error");
                }
                tmm->_lastGeom._lastArc.Retrieve();
                //_lastGeom._lastArc.p0 = px0; // azonnal vissza is állítjuk
                //_lastGeom._lastArc.p1 = px1;
                //_lastGeom._lastArc.o = pxo;
            }
        }
        else if(isBevelling){
            for(auto&line_bevelling:lines_bevelling){
                QString e0;
                auto px0 = tmm->_lastGeom._lastLine.p0();
                auto px1 = tmm->_lastGeom._lastLine.p1();

                auto g0 = LineToGCode::CreateLine(line_bevelling,&e0,tmm,tss);
                if(!g0.isEmpty()){
                    g.append(g0);
                } else{
                    if(err){
                        if(!err->isEmpty()) *err+=",";
                        *err+=line_bevelling.name+": "+e0;
                    }
                    zInfo("line_bevelling gcode error");
                }
                tmm->_lastGeom._lastLine.setP0(px0); // azonnal vissza is állítjuk
                tmm->_lastGeom._lastLine.setP1(px1);
            }
        }
    }
    g.append(tss->TotalTimeToGCode());
    return g.toString();
}
