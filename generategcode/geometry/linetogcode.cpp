#include "linetogcode.h"
#include "helpers/logger.h"

#include <QtMath>

#include <helpers/stringhelper.h>

#include <gcode/gcode.h>

#include <generategcode/cuts/circulararccut.h>
#include <generategcode/cuts/helicalcut.h>
#include <generategcode/cuts/linearcut.h>

#include <generategcode/compensation.h>
#include <generategcode/feedtogcode.h>
#include <generategcode/gcodecommon.h>
#include <generategcode/gcodemanager.h>
#include <generategcode/goto.h>
#include <generategcode/tooltogcode.h>

bool  LineToGCode::ParseLine(const QString& str, QString *gcode, QString *err,ToGCodeModel *tmm,TotalStats *tss)
{
    Line m;
    auto s = Line::Parse(str, tmm->_XYMode, tmm->_MMode, &m, tmm->_offset_xyz);
    if(s.state()==ParseState::NoData) return false;
    zInfo(GCodeCommon::T1+str);
    if(s.state() == ParseState::Parsed ) // ha Arc típusú sor
    {
        if(tmm->_isPlot){
            ToolToGCode::SetToolToPen({&m.p0, &m.p1, &m.rp}, &m.gap, &m.cut, &m.feed, tmm);
        } else{
            if(tmm->_safez>0){
                m.p0.z+=tmm->_safez;
                m.p1.z+=tmm->_safez;
                //  m.rp.z+=_safez;
                m.cut.z += tmm->_safez;
            }
            if(tmm->_safeb>0 && !m.no_overcut){
                m.cut.z+=tmm->_safeb;
                if(m.gap.isValid()){
                    m.gap.height+=tmm->_safeb;
                }
            }
            if(tmm->_overcut>0 && !m.no_overcut){
                m.cut.z+=tmm->_overcut;
                if(m.gap.isValid()){
                    m.gap.height+=tmm->_overcut;
                }
            }
            if(!m.feed.Check(tmm->_fmin, tmm->_fmax)){
                if(tmm->_selected_feed3.Check(tmm->_fmin, tmm->_fmax, err)){
                    m.feed = tmm->_selected_feed3;
                }
            }
        }

        // if(m.name=="brekk"){
        //     zInfo("brekk")
        // }
        if(gcode)*gcode=LineToGCode::CreateLine(m,err, tmm, tss);
    }
    QString msg;
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg);
    return true;
}

QString LineToGCode::CreateLine(const Line& m, QString *err, ToGCodeModel *tmm, TotalStats *tss)
{
    //_lasterr.clear();/*LINE*/
    QString msg = GCodeCommon::G1+m.ToString();
    StringHelper::Tabulate(&msg, GCodeCommon::G2);
    zInfo(msg);

    /*CUT*/
    auto cutCheckResult = m.cut.Check(err);
    if(cutCheckResult == Cut::CheckR::invalid){
        return{};
    }

    /*FEED*/
    if(!m.feed.Check(tmm->_fmin, tmm->_fmax, err)){
        return{};
    }
    /*TOOL*/
    if(!tmm->ValidateTool()) {if(err)*err=L("no tool"); return {};}
    Tool t = tmm->selectedTool();

    /**/
    if(m.p0.isValid()){
        tmm->_lastGeom._lastLine.setP0(m.p0);
    }
    if(m.rp.isValid()){
        if(tmm->_lastGeom._lastLine.p0().isValid()){
            tmm->_lastGeom._lastLine.p0().Translate(m.rp);
        } else{
            if(err){*err=L("p0 not valid");}
            return {};
        }
    }
    if(m.p1.isValid()){
        tmm->_lastGeom._lastLine.setP1(m.p1);
    }
    if(m.rp.isValid()){
        if(tmm->_lastGeom._lastLine.p1().isValid()){
            tmm->_lastGeom._lastLine.p1().Translate(m.rp);
        } else {
            if(err){*err=L("p1 not valid");}
            return {};
        }
    }

    if(tmm->_lastGeom._lastLine.p0() == tmm->_lastGeom._lastLine.p1()){
        if(err){*err=L("start and end points are equal");}
        return{};
    }

    qreal distance = tmm->_lastGeom._lastLine.Distance();
    // if(distance<t.d) {
    //     if(err){*err=L("line too short: ")+QString::number(distance)+"mm";}
    //     return {};
    // }

    Gap mgap; // megvalósítandó gap
    if(m.gap.isValid()){//gapeket akarGMode::Rapid
        //if(mgap.height<_last_cut.z0){if(err)*err=L("gap he"); return{};}
        int gapn = qFloor(distance/(t.d+m.gap.length)); // hány gap fér ki
        if(gapn<1) {if(err)*err=L("cannot any create gaps"); return{};}
        if(m.gap.n>gapn) { gapn=m.gap.n;} // ha több is kifér, annyit kap amennyit kér

        // ha többet kért, mint ami kifér
        mgap = {(m.gap.n>gapn)?gapn:m.gap.n, m.gap.length,m.gap.height};
    }

    QString nameComment = m.GetComment();
    QStringList g(nameComment);

    g.append(tss->TotalTimeToGCode());
    msg=GCodeCommon::G2+ tmm->_lastGeom._lastLine.toString();
    msg+=' '+m.cut.ToString();
    msg+=' '+m.feed.ToString();
    if(mgap.isValid()) msg+= " gaps:"+QString::number(mgap.n);
    zInfo(msg);
    /*CUT*/
    qreal z2 = mgap.isValid()?m.cut.z-mgap.height:m.cut.z;
    // z0 az a fogás
    if(m.cut.z0>z2){
     //   z2 = m.cut.z;
    }
    // a gapig egyet vágunk

    if(z2>0){
        Cut cut2 = m.cut;
        cut2.z=z2;

        //bool nogap = !mgap.isValid();
        //bool aljasimi = (!m.no_simi) && nogap;

        auto g0 = LinearCut::CreateCut(m.feed, cut2, m.no_compensate, m.menet, m.no_simi, tmm, tss);
        g.append(g0);
    }


    //utána megvágjuk a gap szakaszopkat
    if(mgap.isValid()){
        Point ba1=GeoMath::Translation(tmm->_lastGeom._lastLine.p0(), 0, 0, -z2);
        Point ja1=GeoMath::Translation(tmm->_lastGeom._lastLine.p1(), 0, 0, -z2);
        Cut cut_gap{mgap.height, m.cut.z0};

        //auto gap_length = GeoMath::Distance(ba1, ja1);
        QString gap_name = m.name+" gap";//: "+QString::number(gap_length);

        Line l_gap={ba1,ja1, cut_gap, m.feed,{}, {}, gap_name, false, m.no_compensate, m.menet, m.no_simi};
        QList<Line> gap_segments = l_gap.Divide(mgap, t.d);

        QList<Cut> gap_cuts;

        for(auto&gap_segment:gap_segments)
        {
            //auto px0 = _lastGeom._lastLine.p0;
            //auto px1 = _lastGeom._lastLine.p1;
            tmm->_lastGeom._lastLine.Store();
            tmm->_lastGeom._lastLine.set(gap_segment.p0, gap_segment.p1);
            //_lastGeom._lastLine.p0 = gap_segment.p0;
            //_lastGeom._lastLine.p1 = gap_segment.p1;
            Cut gap_cut = m.cut;
            gap_cut.z = gap_segment.cut.z;
            gap_cuts.append(gap_cut);
            auto g01 = LinearCut::CreateCut(m.feed, gap_cut, m.no_compensate, m.menet,  m.no_simi, tmm,tss);
            g.append(g01);
            tmm->_lastGeom._lastLine.Retrieve();
            //_lastGeom._lastLine.p0 = px0; // azonnal vissza is állítjuk
            //_lastGeom._lastLine.p1 = px1;
        }
    }


    g.append(tss->TotalTimeToGCode());
    return g.join('\n');
}

QString LineToGCode::CreateLines(const QList<Line>& m2, QString *err, ToGCodeModel* tmm, TotalStats *tss){
    //_lasterr.clear();/*LINE*/

    Line m = m2[0];

    QString msg = GCodeCommon::G1+m.ToString();
    StringHelper::Tabulate(&msg, GCodeCommon::G2);
    zInfo(msg);

    /*CUT*/
    auto cutCheckResult = m.cut.Check(err);
    if(cutCheckResult == Cut::CheckR::invalid){
        return{};
    }

    /*FEED*/
    if(!m.feed.Check(tmm->_fmin, tmm->_fmax, err)){
        return{};
    }
    /*TOOL*/
    if(!tmm->ValidateTool()) {if(err)*err=L("no tool"); return {};}
    //Tool t = _tools[_selected_tool_ix];


    /**/
    if(m.p0.isValid()){
        tmm->_lastGeom._lastLine.setP0(m.p0);
    }
    if(m.rp.isValid()){
        if(tmm->_lastGeom._lastLine.p0().isValid()){
            tmm->_lastGeom._lastLine.p0().Translate(m.rp);
        } else{
            if(err){*err=L("p0 not valid");}
            return {};
        }
    }
    if(m.p1.isValid()){
        tmm->_lastGeom._lastLine.setP1(m.p1);
    }
    if(m.rp.isValid()){
        if(tmm->_lastGeom._lastLine.p1().isValid()){
            tmm->_lastGeom._lastLine.p1().Translate(m.rp);
        } else {
            if(err){*err=L("p1 not valid");}
            return {};
        }
    }

    if(tmm->_lastGeom._lastLine.p0() == tmm->_lastGeom._lastLine.p1()){
        if(err){*err=L("start and end points are equal");}
        return{};
    }


    // if(distance<t.d) {
    //     if(err){*err=L("line too short: ")+QString::number(distance)+"mm";}
    //     return {};
    // }



    QString nameComment = m.GetComment();
    GCodeManager g(nameComment);

    g.append(tss->TotalTimeToGCode());
    msg=GCodeCommon::G2+ tmm->_lastGeom._lastLine.toString();
    msg+=' '+m.cut.ToString();
    msg+=' '+m.feed.ToString();
    // if(mgap.isValid()) msg+= " gaps:"+QString::number(mgap.n);
    zInfo(msg);
    /*CUT*/
    qreal z2 = m.cut.z;

    // a gapig egyet vágunk
    if(z2>0){
        //Cut cut2 = m.cut;
        //cut2.z=z2;

        //    qreal zo = p.z;


        //  int steps_0 = 0;

        //steps_0 = m.cut.steps();

        /*bool aljasimi = !m.no_simi;

        if(aljasimi){
            steps_0 += SIMI;
        } else{
            zInfo("no_simi");
        }*/
        //steps_0 += SIMI;



        // if(!m.no_compensate){
        //     CompensateModel c = Compensate2(l,  m2[0].cut, m2[0].feed);
        //     if(c.isCompensated){
        //         feed.setFeed(c.c_f);
        //         cut.z0=c.c_z;

        //         c.ToGCode(&g, m2[0].cut, m2[0].feed);
        //     }
        // } else{
        //     zInfo("no_compensate")
        // }

        Feed feed = m2[0].feed;
        Cut cut = m2[0].cut;

        GoTo::GoToCutposition(&g, m.p0, feed, tmm,tss);

        // qreal last_z = m.p0.z;
        //qreal mov_z = m.p0.z+_safeb;

        int m2count = m2.count();

        qreal lastz[m2count];
        for(int j=0;j<m2.count();j++){ lastz[j] = m.p0.z;}

        int steps_m[m2count];
        qreal f_m[m2count];
        qreal c_m[m2count];

        int steps_x =0;
        for(int j=0;j<m2count;j++){
            Line mm = m2[j];

            Cut cuta=mm.cut;
            f_m[j] = mm.feed.feed();
            c_m[j] = mm.cut.z0;
            if (!m.no_compensate) {
                qreal l = GeoMath::Distance(mm.p0, mm.p1);
                Compensation::CompensateModel c = Compensation::Compensate2(l, mm.cut, mm.feed, tmm);
                if (c.isCompensated) {
                    f_m[j] = c.c_f;
                    c_m[j] = c.c_z;
                    cuta.z0=c.c_z;

                    c.ToGCode(&g, mm.cut, mm.feed);
                }
            } else{
                zInfo("no_compensate")
            }

            int steps_a = cuta.steps();
            if(!m.no_simi){
                steps_a += GCodeCommon::SIMI;
            }

            steps_m[j]=steps_a;

            if(steps_a>steps_x)steps_x=steps_a;
        }

        for(int i=0;i<steps_x;i++){

            for(int j=0;j<m2count;j++){
                if(i>steps_m[j]) continue;
                Line mm = m2[j];

                feed = mm.feed;
                cut = mm.cut;

                feed.setFeed(f_m[j]);
                cut.z0=c_m[j];

                /*
                if (!m.no_compensate) {
                    qreal l = GeoMath::Distance(mm.p0, mm.p1);
                    CompensateModel c = Compensate2(l, mm.cut, mm.feed);
                    if (c.isCompensated) {
                        feed.setFeed(c.c_f);
                        cut.z0 = c.c_z;

                        c.ToGCode(&g, mm.cut, mm.feed);
                    }
                } else{
                    zInfo("no_compensate")
                }
*/

                qreal z = m2[0].p0.z-(i+1)*cut.z0;
                qreal zz = m2[0].p0.z-cut.z;
                qreal zzz = (z<zz)?zz:z;


                if((!m.no_simi) && lastz[j] == zzz){
                    //isPeck3 = false;
                    g.Append("(simitás)");
                    feed.setFeed(tmm->_fmin);
                    QString g1;
                    bool ok = FeedToGCode::SetToGCode(feed.feed(), &g1, nullptr, tmm);
                    if(ok && !g1.isEmpty()){
                        g1+= L(" (set feed)");
                        g.Append(g1);
                    }
                }

                QString g0;
                bool ok = FeedToGCode::SetToGCode(feed.feed(), &g0, nullptr, tmm);
                if(ok && !g0.isEmpty()){
                    g0+= L(" (set feed)");
                    g.Append(g0);
                }

                g0 = GoTo::GoToXY(GMode::Rapid, mm.p0, feed.feed(), tmm,tss, {});
                g.Append( g0);

                g0 = GoTo::GoToZ(GMode::Rapid, {mm.p0.x, mm.p0.y, lastz[j] }, feed.feed(),tmm,tss);
                g.Append( g0);

                g0 = GoTo::GoToXYZ(GMode::Linear, {mm.p1.x, mm.p1.y, zzz }, feed.feed(),tmm,tss, {});
                g.Append(g0);

                g0 = GoTo::GoToZ(GMode::Rapid,{0,0,tmm->_peckZ}, feed.feed(),tmm,tss);
                g.Append( g0);

                lastz[j] = zzz;
            }

        }
    }

    return g.toString();
}

