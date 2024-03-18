#include "helpers/logger.h"

#include "circulararccut.h"

#include <generategcode/compensation.h>
#include <generategcode/feedtogcode.h>
#include <generategcode/gcodecommon.h>
#include <generategcode/gcodemanager.h>
#include <generategcode/goto.h>
#include <generategcode/lift.h>

#include <gcode/gcode.h>

#include <helpers/stringhelper.h>

QStringList CircularArcCut::CreateCut(const Feed& o_feed,const Cut& o_cut, bool no_simi, ToGCodeModel* tmm,TotalStats *tss)
{
    GCodeManager g(QStringLiteral("(circular_arc cut)"));
    QString msg;

    qreal l= tmm->_lastGeom._lastArc.ArcLength();
    Compensation::CompensateModel c = Compensation::Compensate2(l,  o_cut, o_feed, tmm);
    Feed feed = o_feed;
    Cut cut = o_cut;
    if(c.isCompensated){
        feed.setFeed(c.c_f);
        cut.z0=c.c_z;
        c.ToGCode(&g, o_cut, o_feed);
    }
    GoTo::GoToCutposition(&g, tmm->_lastGeom._lastArc.p0(), feed, tmm,tss);

    GMode::Mode mode;

    //QString ij;
    qreal i,j;

    qreal i1=tmm->_lastGeom._lastArc.i1();
    qreal j1=tmm->_lastGeom._lastArc.j1();
    qreal i0=tmm->_lastGeom._lastArc.i0();
    qreal j0=tmm->_lastGeom._lastArc.j0();

    int steps = cut.steps();

    if(!no_simi){
        steps += GCodeCommon::SIMI;
    }

    msg+= "cut:"+tmm->_lastGeom._lastArc.toString();
    msg+= " total_depth:"+QString::number(cut.z);
    msg+= " steps:"+QString::number(steps);

    Tool t = tmm->selectedTool();
    //qreal peck_z = _lastGeom._lastArc.maxZ();

    bool isPeck = false;
    bool isPeck2 = false;
    bool isPeck3 = true;//false;
    bool isPeck4 = false;

    auto lpeck = t.d*tmm->dPeck/10;
    //auto lpeck2 = t.d*dPeck2/10;

    if(l>t.d*2){
        /*  if(l<=lpeck){
            isPeck = true;
            if(l<=lpeck2){
                isPeck2 = true;
            }
        }*/
        if(l<=lpeck){
            isPeck4 = true;
        }
    } else{
        isPeck3 = true;
        isPeck4 = true;
    }


    if(isPeck){
        g.append("(peck)");
    }

    if(isPeck2){
        g.append("(peck2)");
    }

    //qreal safez = _safez+1;

    Point p = tmm->_lastGeom._lastArc.p0();
    //qreal dt=0;
    if(!isPeck)
    {
        qreal last_z = p.z;
        for(int step=0;step<steps;step++){
            //Point pp = p;
            if(!(step%2))
            {
                p=tmm->_lastGeom._lastArc.p1();
                mode = GMode::Circular;
                i=i1;
                j=j1;
            }
            else
            {
                p=tmm->_lastGeom._lastArc.p0();
                mode = GMode::Circular_ccw;
                i=i0;
                j=j0;
            }

            QString ij2 = "i"+GCode::r(i)+" j"+GCode::r(j);
            qreal z = p.z-(step+1)*cut.z0;
            qreal zz = p.z-cut.z;
            if(z<zz){
                p.z = zz;
            } else {
                p.z = z;
            }


            if((!no_simi) && last_z==p.z){
                isPeck3 = false;
                feed.setFeed(tmm->_fmin);
                QString g1;
                bool ok = FeedToGCode::SetToGCode(feed.feed(), &g1,nullptr, tmm);
                if(ok && !g1.isEmpty()){
                    g1+= QStringLiteral(" (set feed)");
                    g.Append( g1);
                }
            }

            //qreal d=GeoMath::ArcLength(pp,p, _lastArc.o);

            //dt+=d;
            auto g0 = GoTo::GoToXYZ(mode, p, feed.feed(), tmm,tss, {i, j});
            g.append(g0+' '+ij2);

            bool do_peck = false;
            if(isPeck3){
                //bool isPeck0 = !(step % (isPeck4?PECKSTEPS_2:PECKSTEPS));
                bool isPeck0 = (step % (isPeck4?GCodeCommon::PECKSTEPS_2:GCodeCommon::PECKSTEPS))
                               == (isPeck4?GCodeCommon::PECKSTEPS_2:GCodeCommon::PECKSTEPS)-1;
                if(step>0 && isPeck0){
                    do_peck = true;
                }
            }

            if(do_peck){
                auto g0 = GoTo::GoToZ(GMode::Rapid, {0,0,tmm->_movZ}, feed.feed(), tmm,tss);
                g.Append( g0);

                g0 = "G4 P"+QString::number(GCodeCommon::PECKSTEP_MILLISEC);
                g.Append( g0);
                tss->_total_minutes+=TotalStats::MilliSecToMin(GCodeCommon::PECKSTEP_MILLISEC);

                g0 = GoTo::GoToZ(GMode::Rapid, p, feed.feed(), tmm,tss);
                g.Append(g0);
            }

            last_z = p.z;
            // qreal peck_l = qAbs(peck_z-p.z);
            //qreal t0_ms = MinToMilliSec(peck_l/1500);
            // qreal t1_ms = MinToMilliSec(peck_l/feed.feed());
        }
    } else{
        //qreal last_z = p.z;
        for(int step=0;step<steps;step++){
            //  Point pp = p;
            // if(!(step%2))
            // {
            p=tmm->_lastGeom._lastArc.p1();
            mode = GMode::Circular;
            i=i1;
            j=j1;
            // }
            // else
            // {
            //     p=_lastArc.p0;
            //     mode = GMode::Circular_ccw;
            //    i=i0;
            //    j=j0;
            // }
            QString ij2 = "i"+GCode::r(i)+" j"+GCode::r(j);
            qreal z = p.z-(step+1)*cut.z0;
            qreal zz = p.z-cut.z;
            if(z<zz){
                p.z = zz;
            } else {
                p.z = z;
            }

            //qreal d=GeoMath::ArcLength(pp,p, _lastArc.o);
            //dt+=d;
            auto g0 = GoTo::GoToXYZ(mode, p, feed.feed(), tmm,tss, {i, j});
            g0 += ij2;
            g.Append(g0);

            //qreal peck_l = qAbs(peck_z-p.z);
            //     qreal t0_ms = MinToMilliSec(peck_l/1500);
            //     qreal t1_ms = MinToMilliSec(peck_l/feed.feed());
            //     qreal t2_ms = t0_ms+t1_ms;
            //     int maxdwellmillis = _pdwell;

            // if(isPeck){
            //     g0 = GoToZ(GMode::Rapid,{0,0,peck_z+safez}, peck_l, feed.feed());
            //     AppendGCode(&g, g0);
            //     if(isDwell2){
            //         int tdwell_ms = (t2_ms<maxdwellmillis)?maxdwellmillis-t2_ms:0;
            //         if(tdwell_ms>100){
            //             g0 = "G4 P"+QString::number(tdwell_ms);
            //             AppendGCode(&g, g0);
            //             _total_minutes+=MilliSecToMin(tdwell_ms);
            //         }
            //     }

            //     g0 = GoToZ(GMode::Linear,{0,0,p.z}, peck_l, feed.feed());
            //     AppendGCode(&g, g0);
            // }
            // if(isDwell){
            //     int tdwell_ms = maxdwellmillis;
            //     g0 = "G4 P"+QString::number(tdwell_ms);
            //     AppendGCode(&g, g0);
            //     _total_minutes+=MilliSecToMin(tdwell_ms);
            // }

            if(i<steps-2)
            {
                Point pu = tmm->_lastGeom._lastArc.p0();
                pu.z = tmm->_movZ;

                //if(isPeck2){
                g0 = GoTo::GoToZ(GMode::Rapid,{0,0,pu.z}, feed.feed(), tmm,tss);
                g.Append(g0);

                g0 = GoTo::GoToXYZ(GMode::Rapid, pu, feed.feed(), tmm,tss,{i, j});
                g.Append( g0);

                // } else{
                //     // ívbe kéne visszajönni
                //     g0 = GoToXYZ(GMode::Circular_ccw, pu, d, feed.feed());
                //     AppendGCode(&g, g0);

                //     g0 = GoToZ(GMode::Rapid,{0,0,last_z}, peck_l, feed.feed());
                //     AppendGCode(&g, g0);
                // }


                g0 = GoTo::GoToZ(GMode::Linear,{0,0,p.z}, feed.feed(), tmm,tss);
                g.Append( g0);
            }

            //last_z = p.z;
        }
    }

    //    if(isc){
    //        DeCompensate2(c_z, c_f);
    //    }

    //msg+= " arc_distance:"+QString::number(dt);


    g.append(Lift::Up(feed.feed(), tmm->_lastGeom._lastArc.p0().z, tmm,tss));

    QString h=StringHelper::Tabulate2(GCodeCommon::G2);
    zInfo(h+msg);
    return g.gcodes();
}

