#include "helicalcut.h"

#include "helpers/logger.h"
#include <generategcode/compensation.h>
#include <generategcode/feedtogcode.h>
#include <generategcode/gcodecommon.h>
#include <generategcode/gcodemanager.h>
#include <generategcode/goto.h>
#include <generategcode/lift.h>

#include <helpers/stringhelper.h>
#include <QtMath>
#include <gcode/gcode.h>

QStringList HelicalCut::CreateCut(qreal path_r, const Feed& o_feed,const Cut& o_cut, bool a, bool aljasimi, bool isPeca,ToGCodeModel* tmm, TotalStats *tss)
{
    GCodeManager g(QStringLiteral("(helical cut)"));
    QString msg;

    qreal length = path_r*2*M_PI; //fogás hossz
    Compensation::CompensateModel c = Compensation::Compensate2(length, o_cut, o_feed, tmm);
    Feed feed = o_feed;
    Cut cut = o_cut;
    if(c.isCompensated){
        feed.setFeed(c.c_f);
        cut.z0=c.c_z;

        c.ToGCode(&g, o_cut, o_feed);
    }

    Point p = GeoMath::Translation(tmm->_lastGeom._lastHoleP, -path_r, 0, 0);

    GoTo::GoToCutposition(&g, p, feed, tmm,tss);

    int steps_0 = cut.steps();

    if(aljasimi){
        steps_0 += GCodeCommon::SIMI;
    }

    msg+= "cut:"+tmm->_lastGeom._lastHoleP.ToString()+"r="+GCode::r(path_r);
    msg+= " total_depth:"+QString::number(cut.z);//total_depth
    msg+= " steps:"+QString::number(steps_0);

    qreal last_z = p.z;

    bool isPeck = false;
    bool isPeck2 = false;
    bool isPeck3 = true;//false;
    bool isPeck4 = false;

    Tool t = tmm->selectedTool();

    auto lpeck = t.d*tmm->dPeck/10;
    //    auto lpeck2 = t.d*dPeck2/10;

    if(isPeca)
    {
        if(length>t.d*2){
            /*  if(l<=lpeck){
                isPeck = true;
                if(l<=lpeck2){
                    isPeck2 = true;
                }
            }*/
            if(length<=lpeck){
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
    } else {
        g.append("(no_peck)");
        isPeck3 = false;
        isPeck4 = false;
    }

    for(int i=0;i<steps_0;i++){
        //Point pp=p;
        qreal z = tmm->_lastGeom._lastHoleP.z-(i+1)*cut.z0;//kiszámol
        qreal zz = tmm->_lastGeom._lastHoleP.z-cut.z;//total_depth//_last_cut.z;
        if(z<=zz){    //beállítjuk a p-t
            p.z = zz;
        } else {
            p.z = z;
        }

        //qreal lz = pp.z-p.z;
        //qreal l1 = qSqrt(l*l+lz*lz); // út hossz

        if(aljasimi && last_z==p.z){
            isPeck3 = false;
            feed.setFeed(tmm->_fmin);
            QString g1;
            bool ok = FeedToGCode::SetToGCode(feed.feed(), &g1, nullptr, tmm);
            if(ok && !g1.isEmpty()){
                g1+= L(" (set feed)");
                g.Append( g1);
            }
        }


        QString g0;

        if(a){
            g0 = GoTo::GoToZ(GMode::Circular, p, feed.feed()/*, {path_r, 0}*/, tmm,tss) + " i" + GCode::r(path_r);
        } else{
            if(i%2==0){
                g0 = GoTo::GoToZ(GMode::Circular, p, feed.feed(), tmm,tss) + " i" + GCode::r(path_r);
            } else{
                g0 = GoTo::GoToZ(GMode::Circular_ccw, p, feed.feed(), tmm,tss) + " i" + GCode::r(path_r);
            }
        }                

        g.append(g0);

        tss->_total_length+=length;
        tss->_total_cut+=length;
        qreal t0_mins = length/feed.feed();
        tss->_total_minutes+=t0_mins;
        tss->_total_minutes+=GoTo::t_muvelet;

        bool do_peck = false;
        if(isPeck3){
            //bool isPeck0 = !(i % (isPeck4?PECKSTEPS_2:PECKSTEPS));
            bool isPeck0 = (i % (isPeck4?GCodeCommon::PECKSTEPS_2:GCodeCommon::PECKSTEPS))
                           == (isPeck4?GCodeCommon::PECKSTEPS_2:GCodeCommon::PECKSTEPS)-1;
            if(i>0 && isPeck0){
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
            g.Append( g0);
        }

        last_z = p.z;

    }


    //    if(isc){
    //        DeCompensate2(c_z, c_f);
    //    }

    g.Append(Lift::Up(feed.feed(), tmm->_lastGeom._lastHoleP.z, tmm,tss));

    QString h=StringHelper::Tabulate2(GCodeCommon::G2);
    zInfo(h+msg);
    return g.gcodes();
}
