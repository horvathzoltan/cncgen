#include "holetogcode.h"

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
#include <generategcode/tooltogcode.h>

bool HoleToGCode::ParseHole(const QString& str, QString *gcode, QString *err, ToGCodeModel *tmm,TotalStats *tss)
{
    Hole m;
    auto s = Hole::Parse(str, tmm->_XYMode, tmm->_MMode, &m, tmm->_offset_xyz);
    if(s.state()==ParseState::NoData) return false;
    zInfo(GCodeCommon::T1+str);
    if(s.state() == ParseState::Parsed ) // ha Box típusú sor
    {
        if(tmm->_isPlot){
            ToolToGCode::SetToolToPen({&m.p, &m.rp}, &m.gap, &m.cut, &m.feed, tmm);
        } else{
            if(tmm->_safez>0){
                m.p.z+=tmm->_safez;
                //  m.rp.z+=_safez;

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
                if(tmm->_selected_feed3.Check(tmm->_fmin, tmm->_fmax, err)){
                    m.feed = tmm->_selected_feed3;
                }
            }

        }

        if(gcode)*gcode=HoleToGCode::CreateHole(m,err,tmm, tss);
    }
    QString msg;
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg);
    return true;
}


QString HoleToGCode::CreateHole(const Hole &m, QString*err,ToGCodeModel* tmm,TotalStats *tss)
{
    //_lasterr.clear();
    auto msg = GCodeCommon::G1+m.ToString();
    StringHelper::Tabulate(&msg, GCodeCommon::G2);
    zInfo(msg);

    /*DIAMETER*/
    if(tmm->_last_hole_diameter==-1 && m.diameter==-1){if(err){*err=L("no diameter");} return {};}
    if(m.diameter!=-1) tmm->_last_hole_diameter = m.diameter;
    if(tmm->_last_hole_diameter<=0) {
        if(err){*err=L("wrong diameter: ")+GCode::r(tmm->_last_hole_diameter);}
        return {};
    }
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
    qreal holeDiameter = tmm->_last_hole_diameter+m.jointGap;
    if(holeDiameter<t.d) {
        if(err){*err=L("wrong diameter: ")+GCode::r(holeDiameter)+
                   " tool: "+t.ToString();
        }
        return {};
    }


    double path_r = (holeDiameter-t.d)/2; // a furat belső szélét érintő pályapont
    Gap mgap = m.gap.isValid()?m.gap:Gap{2, .5, 0.5};
    if(tmm->_isPlot){
        mgap.height = 0.01;
    }

    // ha csak fúrás, az egy predrill premill nélkül
    bool pre_drill, pre_mill,hasGaps, drillOnly=holeDiameter==t.d;
    if(m.ng)
    {
        hasGaps = false;
        pre_drill = true;
        pre_mill = true;
    }
    else{
        if(m._no_predrill){
            pre_drill = false;
            pre_mill =false;

            if(m.gap.n>0){
                hasGaps = true; //
                int gapn = (2*path_r*M_PI)/(2*t.d+mgap.length); // hány gap fér ki
                if(gapn<1) {if(err)*err=L("cannot create gaps"); return{};}
                if(mgap.n>gapn){mgap.n=gapn;}// ha többet kért, mint ami kifér
            } else{
                hasGaps=false;
            }

        }else{
            if(drillOnly){
                pre_drill=true;
                pre_mill=false;
                hasGaps = false;
            } else{
                hasGaps = holeDiameter>5*t.d; //
                if(hasGaps){
                    pre_drill=false;
                    pre_mill=false;

                    int gapn = (2*path_r*M_PI)/(2*t.d+mgap.length); // hány gap fér ki
                    if(gapn<1) {if(err)*err=L("cannot create gaps"); return{};}
                    if(mgap.n>gapn){mgap.n=gapn;}// ha többet kért, mint ami kifér

                } else {
                    //pre_drill = holeDiameter>=2*t.d; //d=0
                    pre_drill = holeDiameter>=t.d; //d=2*t.d
                    pre_mill = holeDiameter>t.d;
                }
            }
        }
    }
    if(m.p.isValid()){
        tmm->_lastGeom._lastHoleP=m.p;
    }
    if(m.rp.isValid()){
        tmm->_lastGeom._lastHoleP.x+=m.rp.x;
        tmm->_lastGeom._lastHoleP.y+=m.rp.y;
        tmm->_lastGeom._lastHoleP.z+=m.rp.z;
    }

    QString nameComment = m.GetComment();
    GCodeManager g(nameComment);
    g.append(QStringLiteral("(helical interpolation)"));
    g.append(tss->TotalTimeToGCode());

    Point p = tmm->_lastGeom._lastHoleP; // _lastHoleP középpont , p a szerszámpálya kezdőpontja lesz

    msg=GCodeCommon::G2+ p.ToString();
    msg+=' '+m.cut.ToString();
    msg+=' '+m.feed.ToString();
    msg+=" d"+GCode::r(holeDiameter);
    if(pre_drill) msg+=L(" predrill");
    if(pre_mill) msg+=L(" premill");
    if(hasGaps) msg+=L(" gap");
    int steps = qCeil(m.cut.z/m.cut.z0)+1;
    msg+= " steps:"+QString::number(steps);
    zInfo(msg);

    qreal safez = tmm->_safez+1;//(_safez!=0)?_safez:1;

    if(pre_drill || drillOnly){

        qreal d_l = (t.d*M_PI)/2; // a belső átmérőn is vág, kevesebbet
        Compensation::CompensateModel d_c = Compensation::Compensate2(d_l,  m.cut, m.feed, tmm);
        Feed d_feed = m.feed;
        Cut d_cut = m.cut;
        if(d_c.isCompensated){
            d_feed.setFeed(d_c.c_f);
            d_cut.z0=d_c.c_z;

            d_c.ToGCode(&g, m.cut, m.feed);
        }

        qreal zz = tmm->_lastGeom._lastHoleP.z-m.cut.z; // zz: mélység
        //qreal r = p.z+safez; // r: visszahúzás z-je
        qreal q = d_cut.z0/tmm->_peckz_divider;  // q: mélység inkrement per peck

        g.append(L("(predrill)"));
        GoTo::GoToCutposition(&g, p, d_feed, tmm,tss);

        qreal r = p.z + tmm->_safez;//+safez; // r: visszahúzás z-je
        g.append(L("G98 G83")+" z"+GCode::r(zz)+" r"+GCode::r(r)+" q"+GCode::r(q));

        auto menet = zz/q;

        if(m.feed.feed()>0){
            qreal l0 = m.cut.z0*menet;
            qreal l1 = (p.z+safez+zz*menet*2)-l0;

            qreal t0_mins = l0/m.feed.feed();
            qreal t1_mins = l1/1500;
            tss->_total_minutes+=t0_mins+t1_mins;
            tss->_total_cut += zz;
            tss->_total_length += l0+l1;
        }

        tmm->_lastGeom._last_position.setZ(p.z);
    }

    bool helicalMode = m.mode==1;

    if(!drillOnly){
        if(pre_mill){
            g.append(L("(premill)"));
            //int s0_max = _pre_mill_steps;
            qreal tdr = t.d/6;
            qreal td0 = 0;
            qreal tds = t.d/tmm->_preMillSteps; // a maró átmérőjének ennyied része oldalra a fogás
            int steps = (path_r)/tds;
            for(int step=0;step<steps;step++){
                td0+=tds;

                // előmarás a kért átmérőig
                if(path_r-td0>tdr){
                    //SetSelectedFeed(m.feed);
                    QStringList g1 = HelicalCut::CreateCut(td0, m.feed, m.cut, helicalMode, true, false, tmm, tss); // m.cut.z
                    g.append(g1);
                }
            }
        }

        //      SetSelectedFeed(m.feed);
        p.x -= path_r; //szerszámpálya kezdő pontja - furat belső szélének érintése
        // ha van gap, csak a gapig megyünk egyébként teljesen
        /*CUT*/
        qreal z2 = hasGaps?m.cut.z-mgap.height:m.cut.z;
        // z0 az a fogás
        if(m.cut.z0>z2) z2 = m.cut.z;

        // marás a kért átmérőre        
        if(z2>0){
            //SetSelectedFeed(m.feed);
            Cut cut2 = m.cut;
            cut2.z = z2;
            auto g1=HelicalCut::CreateCut(path_r, m.feed, cut2, helicalMode, m._no_simi, false, tmm,tss);
            g.append(g1);
        }

        if(hasGaps){
            Point p = GeoMath::Translation(tmm->_lastGeom._lastHoleP, -100, 0, -z2);//_lastHoleP
            //p.x=0;
            //p.z= _lastHoleP.z-z2;
            qreal b = (mgap.length+t.d)/(path_r);//ennyi szögig tart a gap
            qreal ab = (2*M_PI)/mgap.n;//ennyi szögenként van a gap

            Point p0,p1;
            qreal aa=0;

            for(int i=0;i<mgap.n;i++){
                Point k01{0,0,p.z},k11{0,0,p.z};
                GeoMath::Polar(tmm->_lastGeom._lastHoleP, p, aa+b, path_r, &k01);
                GeoMath::Polar(tmm->_lastGeom._lastHoleP, p, aa+ab, path_r, &k11);
                //QString err2;

                tmm->_lastGeom._lastArc.Store();
                tmm->_lastGeom._lastArc.set(k01,k11,tmm->_lastGeom._lastHoleP);

                Cut cut_gap = m.cut;
                cut_gap.z = mgap.height;
                auto g0 = CircularArcCut::CreateCut(m.feed, cut_gap, true, tmm, tss);
                g.append(g0);

                tmm->_lastGeom._lastArc.Retrieve();
                aa+=ab;
            }
        }
    }

    g.append(tss->TotalTimeToGCode());
    return g.toString();
}
