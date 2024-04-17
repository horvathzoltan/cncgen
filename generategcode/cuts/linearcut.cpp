#include "linearcut.h"

#include "helpers/logger.h"
#include <generategcode/compensation.h>
#include <generategcode/feedtogcode.h>
#include <generategcode/gcodecommon.h>
#include <generategcode/gcodemanager.h>
#include <generategcode/goto.h>
#include <generategcode/lift.h>

#include <helpers/stringhelper.h>

QStringList LinearCut::CreateCut(const Feed& o_feed, const Cut& o_cut, bool no_compensate, int menet, bool no_simi,ToGCodeModel* tmm,TotalStats *tss) {
    GCodeManager g(QStringLiteral("(linear cut)"));
    QString msg;

    qreal l = tmm->_lastGeom._lastLine.Distance();

    Feed feed = o_feed;
    Cut cut = o_cut;

    if(!no_compensate){
        Compensation::CompensateModel c = Compensation::Compensate2(l,  o_cut, o_feed, tmm);
        if(c.isCompensated){
            feed.setFeed(c.c_f);
            cut.z0=c.c_z;

            c.ToGCode(&g, o_cut, o_feed);
        }
    } else{
        zInfo("no_compensate")
    }

    Point p = tmm->_lastGeom._lastLine.p0();
    //if(safety){
    //     p.z+=_safez;
    //     total_depth+=_safez;
    //}



    //    if(_last_feed.feed()==513 && c_f==486){
    //        zInfo("hutty");
    //    }

    Tool t = tmm->selectedTool();
    //qreal peck_z = qMax(p.z, _lastGeom._lastLine.p1.z);
    //qreal zz = peck_z-cut.z;

    bool isPeck = false; // a hideg oldalon kezd
    bool isPeck2 = false; // a hideg oldalon kezd lasssabban
    bool isPeck3 = true;//false;
    bool isPeck4 = false;

    auto lpeck = t.d*tmm->dPeck;
    auto lpeck2 = t.d*tmm->dPeck2;

    if(l>t.d*2){
        if(l<=lpeck && !no_compensate){
            isPeck = true;
            if(l<=lpeck2){
                isPeck2 = true;
            }
        }
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

    //    qreal safez = _safez+1;

    GoTo::GoToCutposition(&g, p, feed, tmm,tss);

    //    qreal zo = p.z;


    int steps_0 = 0;
    if (menet<=0){
        steps_0 = cut.steps();
    } else if(menet<3) {
        steps_0 = 1;
    } else{
        steps_0 = menet;
    }

    if(!no_simi){
        steps_0 += GCodeCommon::SIMI;
    }

    msg+= "cut:"+tmm->_lastGeom._lastLine.toString();
    msg+= " total_depth:"+QString::number(cut.z);
    msg+= " steps:"+QString::number(steps_0);

    //qreal dt = 0;

    if(steps_0==1){
        //Point pd=p;
        p=tmm->_lastGeom._lastLine.p1();

        qreal zz = p.z-cut.z;
        p.z = zz;

        auto g0 = GoTo::GoToZ(GMode::Linear, p, feed.feed(), tmm,tss);
        g.Append( g0);

        //qreal d = GeoMath::Distance(pd,p);
        //dt+=d;
        g0 = GoTo::GoToXYZ(GMode::Linear, p, feed.feed(), tmm,tss,{});
        g.Append( g0);

        g0 =GoTo::GoToZ(GMode::Linear,{0,0,p.z}, feed.feed(), tmm,tss);
        g.Append( g0);

    }
    else if (steps_0>1){
        if(!isPeck){
            qreal last_z = p.z;
            for(int i=0;i<steps_0;i++){
                //if(i==steps_0-1 && !simi) continue;

                //Point pd=p;

                if(!(i%2))
                {
                    p=tmm->_lastGeom._lastLine.p1();
                }
                else
                {
                    p=tmm->_lastGeom._lastLine.p0();
                }

                qreal z = p.z-(i+1)*cut.z0;
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

                //qreal d = GeoMath::Distance(pd,p);
                //dt+=d;
                auto g0 = GoTo::GoToXYZ(GMode::Linear, p, feed.feed(), tmm,tss, {});
                g.Append( g0);

                bool do_peck = false;
                if(isPeck3 && !no_compensate){
                    bool isPeck0 = (i % (isPeck4?GCodeCommon::PECKSTEPS_2:GCodeCommon::PECKSTEPS)) ==
                                   (isPeck4?GCodeCommon::PECKSTEPS_2:GCodeCommon::PECKSTEPS)-1;
                    if(isPeck0){
                        do_peck = true;
                    }
                }

                if(do_peck){
                    auto g0 = GoTo::GoToZ(GMode::Rapid, {0,0,tmm->_peckZ}, feed.feed(),tmm,tss);
                    g.Append( g0);

                    g0 = "G4 P"+QString::number(GCodeCommon::PECKSTEP_MILLISEC);
                    g.Append( g0);
                    tss->_total_minutes+=TotalStats::MilliSecToMin(GCodeCommon::PECKSTEP_MILLISEC);

                    g0 =GoTo::GoToZ(GMode::Rapid, p, feed.feed(),tmm,tss);
                    g.Append( g0);
                }

                last_z = p.z;
            }
        }
        else{
            qreal last_z = p.z;
            bool as = false;
            int s=0;
            for(int i=0;i<steps_0;i++){
                //if(i==steps_0-1 && !simi) continue;

                //Point pd=p;

                p=tmm->_lastGeom._lastLine.p1();

                qreal z = p.z-(i+1)*cut.z0;
                qreal zz = p.z-cut.z;
                if(z<zz){
                    p.z = zz;
                } else {
                    p.z = z;
                }

                if((!no_simi) && last_z==p.z){
                    as=true;
                    isPeck3 = false;
                    feed.setFeed(tmm->_fmin);
                    QString g1;
                    bool ok = FeedToGCode::SetToGCode(feed.feed(), &g1,nullptr, tmm);
                    if(ok && !g1.isEmpty()){
                        g1+= QStringLiteral(" (set feed)");
                        g.Append( g1);
                    }
                }

                //qreal d = GeoMath::Distance(pd,p);
                //dt+=d;
                auto g0 = GoTo::GoToXYZ(GMode::Linear, p, feed.feed(), tmm,tss, {});
                g.Append( g0);

                //qreal peck_l = qAbs(peck_z-p.z);


                if(!as)
                {
                    Point pu = tmm->_lastGeom._lastLine.p0();
                    // peckhez lementjük - _movZ
                    pu.z = tmm->_peckZ;

                    //qreal mz;

                    if(isPeck2){
                        //qreal peck_l = qAbs(pu.z-p.z);
                        g0 =GoTo::GoToZ(GMode::Rapid,{0,0,pu.z}, feed.feed(), tmm,tss);
                        g.Append( g0);

                        g0 = GoTo::GoToXYZ(GMode::Rapid, pu, feed.feed(),tmm,tss, {});
                        g.Append( g0);

                        //mz=pu.z;

                    } else{

                        g0 =GoTo::GoToXYZ(GMode::Rapid, pu, feed.feed(), tmm,tss, {});
                        g.Append(g0);

                        //qreal peck_l = qAbs(pu.z-last_z);
                        g0 = GoTo::GoToZ(GMode::Rapid,{0,0,last_z}, feed.feed(), tmm,tss);
                        g.Append(g0);
                        // mz = last_z;
                    }

                    //qreal peck_l = qAbs(p.z-mz);
                    g0 = GoTo::GoToZ(GMode::Linear,{0,0,p.z}, feed.feed(), tmm,tss);
                    g.Append( g0);
                } else{
                    if(!(s%2))
                    {
                        p=tmm->_lastGeom._lastLine.p1();
                    }
                    else
                    {
                        p=tmm->_lastGeom._lastLine.p0();
                    }
                    s++;
                    auto g0 = GoTo::GoToXYZ(GMode::Linear, {p.x, p.y, zz}, feed.feed(), tmm,tss, {});
                    g.Append(g0);

                }

                //}
                last_z = p.z;
            }
        }
    }
    //    if(isc){
    //        DeCompensate2(c_z, c_f);
    //    }

    //msg+=" distance: "+QString::number(dt);

    g.Append( Lift::Up(feed.feed(), p.z, tmm,tss));

    QString h=StringHelper::Tabulate2(GCodeCommon::G2);
    zInfo(h+msg);
    return g.gcodes();
}
