#include "helpers/logger.h"
#include "feedtogcode.h"
#include "gcodemanager.h"
#include "goto.h"
#include "lift.h"
#include "spindle.h"

#include <messages.h>

const qreal GoTo::RFEED = 1500;
qreal GoTo::t_muvelet = 0.07/60;

void GoTo::GoToCutposition(GCodeManager *g, const Point& p, const Feed& feed,ToGCodeModel *tmm,TotalStats *tss){
    g->Append(TravelXYToGCode(feed.feed(), p, tmm,tss));
    g->Append(Spindle::StartToGCode(feed.spindleSpeed(),tmm));

    QString g0;
    bool ok = FeedToGCode::SetToGCode(feed.feed(), &g0, nullptr, tmm);
    if(ok && !g0.isEmpty()){
        g0+= QStringLiteral(" (set feed)");
        g->Append(g0);
    }

    g->Append(Lift::Down(feed.feed(), p.z, tmm,tss));
}

QString GoTo::GoToXYZ(GMode::Mode i, const Point& p, qreal feed,ToGCodeModel* tmm,TotalStats *tss, IJModel ij)
{
    if(!p.isValid()){
        zInfo(Messages::invalid_point);
        return {};
    }

    if(i==GMode::Undefined){ return {};}

    if((i==GMode::Mode::Linear||i==GMode::Mode::Rapid) &&
        tmm->_last_gmode==i &&
        tmm->_lastGeom._last_position.p()==p
        ){return {};}

    qreal v = 0;

    if((i==GMode::Mode::Linear||
         i==GMode::Mode::Circular||
         i==GMode::Mode::Circular_ccw)){

        if(feed<=0){
            zInfo(Messages::zero_feed);
        } else{
            v = feed;
        }
        //        if(feed<=0){
        //            zInfo(Messages::zero_spindleSpeed);
        //        }
    } else if(i==GMode::Rapid){
        v=RFEED;
    }


    qreal length = GetLength(i, p, LengthMode::XYZ, tmm, ij);

    tmm->_lastGeom._last_position.set(p);//.x, p.y, p.z);
    tmm->_last_gmode=i;

    if(length>0){
        tss->_total_length+=length;
        if(v<=0){
            zInfo(Messages::cannot_calculate+' '+Messages::movement_time+": "+Messages::no_speed)
        } else{
            if(i!=GMode::Rapid){
                tss->_total_cut+=length;
            }
            qreal t0_mins = length/v;
            tss->_total_minutes+=t0_mins;

            tss->_total_minutes+=t_muvelet;
        }
    } else {
        zInfo(Messages::no_calc_length)
    }

    QString a = (tmm->_ratio>0&&tmm->_ratio!=1)?p.ToStringXYZ(tmm->_ratio):p.ToStringXYZ();

    return GMode::ToGCcode(i)+' '+a;
}

QString GoTo::GoToXY(GMode::Mode i, const Point& p, qreal feed, ToGCodeModel *tmm,TotalStats *tss, IJModel ij)
{
    if(!p.isValid()){
        zInfo(Messages::invalid_point);
        return {};
    }

    if(i==GMode::Undefined){ return {};}

    if((i==GMode::Mode::Linear||i==GMode::Mode::Rapid) &&
        tmm->_last_gmode==i &&
        tmm->_lastGeom._last_position.p()==p
        ){return {};}

    qreal v = 0;

    if((i==GMode::Mode::Linear||
         i==GMode::Mode::Circular||
         i==GMode::Mode::Circular_ccw)){
        if(feed<=0){
            zInfo(Messages::zero_feed);
            //return {};
        }
        else{
            v = feed;
            // if(i==GMode::Mode::Linear)
            // {
            //     _total_cut+=length;
            // }
        }
        //        if(feed.spindleSpeed()<=0){
        //            zInfo(Messages::zero_spindleSpeed);
        //           // return {};
        //        }
    }
    else if(i==GMode::Rapid){
        v=RFEED;
    }

    qreal length = GetLength(i, p, LengthMode::XY,tmm, ij);

    tmm->_lastGeom._last_position.setXY(p.x,p.y);
    tmm->_last_gmode=i;


    if(length>0){
        tss->_total_length+=length;
        if(v<=0){
            zInfo(Messages::cannot_calculate+' '+Messages::movement_time+": "+Messages::no_speed)
        } else{
            if(i!=GMode::Rapid){
                tss->_total_cut+=length;
            }
            qreal t0_mins = length/v;
            tss->_total_minutes+=t0_mins;

            tss->_total_minutes+=t_muvelet;
        }

    } else {
        zInfo(Messages::no_calc_length)
    }

    QString a = (tmm->_ratio>0&&tmm->_ratio!=1)?p.ToStringXY(tmm->_ratio):p.ToStringXY();
    //QString a = p.ToStringXY();
    return GMode::ToGCcode(i)+' '+a;
}

QString GoTo::GoToZ(GMode::Mode i, const Point& p, qreal feed,ToGCodeModel *tmm, TotalStats *tss)
{
    if(!p.isValid()){
        zInfo(Messages::invalid_point);
        return {};
    }
    if(i==GMode::Undefined){ return {};}

    if((i==GMode::Mode::Linear||i==GMode::Mode::Rapid) &&
        tmm->_last_gmode==i &&
        tmm->_lastGeom._last_position.z()==p.z){return {};}

    qreal v = 0;


    if((i==GMode::Mode::Linear||
         i==GMode::Mode::Circular||
         i==GMode::Mode::Circular_ccw)){
        if(feed<=0){
            zInfo(Messages::zero_feed);
            //return {};
        }
        else{
            v = feed;
        }
        //        if(feed.spindleSpeed()<=0){
        //            zInfo(Messages::zero_spindleSpeed);
        //            // return {};
        //        }
    }
    else if(i==GMode::Rapid){
        v=RFEED;
    }

    qreal length = GetLength(i, p, LengthMode::Z,tmm, {});

    tmm->_lastGeom._last_position.setZ(p.z);
    tmm->_last_gmode=i;

    if(length>0){
        tss->_total_length+=length;
        if(v<=0){
            zInfo(Messages::cannot_calculate+' '+Messages::movement_time+": "+Messages::no_speed)
        } else{
            if(i!=GMode::Rapid){
                tss->_total_cut+=length;
            }
            qreal t0_mins = length/v;
            tss->_total_minutes+=t0_mins;

            tss->_total_minutes+=t_muvelet;
        }
    } else {
        zInfo(Messages::zero_spindleSpeed)
    }

    return GMode::ToGCcode(i)+' '+p.ToStringZ();
}

qreal GoTo::GetLength(GMode::Mode i, const Point& p, LengthMode lm, ToGCodeModel* tmm, IJModel ij){
    qreal length;
    switch (i){
    case GMode::Mode::Linear:
    case GMode::Mode::Rapid:
        switch(lm){
        case LengthMode::XYZ:
            length = tmm->_lastGeom._last_position.Distance(p);
            break;
        case LengthMode::XY:
            length = tmm->_lastGeom._last_position.DistanceXY(p);
            break;
        case LengthMode::Z:
            length = GeoMath::Distance(
                {0, 0, tmm->_lastGeom._last_position.z()},
                {0, 0, p.z});
            break;
        default: length = 0;
        }
        break;
    case GMode::Mode::Circular:
        switch(lm){
        case LengthMode::XY:
        case LengthMode::XYZ:{
            //auto length0 = tmm->_lastGeom._last_position.DistanceXY(p);

            Point p0 = tmm->_lastGeom._last_position.p();
            Point o = {p0.x + ij.i, p0.y+ij.j, p0.z};
            length = GeoMath::ArcLength(p0, p, o);
            break;
        }
        case LengthMode::Z:
            length = GeoMath::Distance(
                {0, 0, tmm->_lastGeom._last_position.z()},
                {0, 0, p.z});
            break;
        default: length = 0;
        }
        break;
        break;
    case GMode::Mode::Circular_ccw:
        switch(lm){
        case LengthMode::XY:
        case LengthMode::XYZ:{
            //auto length0 = tmm->_lastGeom._last_position.DistanceXY(p);

            Point p0 = tmm->_lastGeom._last_position.p();
            Point o = {p0.x + ij.i, p0.y+ij.j, p0.z};
            length = GeoMath::ArcLength(p, p0, o);
            break;
        }
        case LengthMode::Z:
            length = GeoMath::Distance(
                {0, 0, tmm->_lastGeom._last_position.z()},
                {0, 0, p.z});
            break;
        default: length = 0;
        }
        break;
        break;
    default:
        length = 0;
        break;
    }

    return length;
}

QString GoTo::TravelXYToGCode(qreal feed, const Point& p,ToGCodeModel *tmm,TotalStats *tss)
{
    GCodeManager g;
    QString err;

    auto g1 = Lift::Up(feed, {}, tmm,tss);
    g.Append(g1, "", "");
    //g.append(g1);
    //qreal l = GeoMath::Distance(_last_position, p);
    auto gcode = GoTo::GoToXY(GMode::Rapid, p, feed, tmm,tss, {});
    //if(!gcode.isEmpty())gcode+=" (travel)";
    g.Append(gcode, err, QStringLiteral("travel"));
    return g.toString();
}

