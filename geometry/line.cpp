#include "line.h"

#include <QStringList>
#include "gcode/gcode.h"
#include "geometry/geomath.h"
#include "common/logger/log.h"

QString Line::_lasterr;

Line::Line()
{
    cutZ=cutZ0=0;
    _isValid=false;
}

Line::Line(const Point &_p0,
           const Point &_p1,
           qreal _cutZ,
           qreal _cutZ0,
           qreal _spindleSpeed,
           qreal _feed)
{
    p0 = _p0;
    p1 = _p1;
    cutZ= _cutZ;
    cutZ0 = _cutZ0;
    spindleSpeed=_spindleSpeed;
    feed=_feed;
    _isValid = true;
}

auto Line::Parse(const QString &txt, XYMode mode) -> Line
{
    _lasterr.clear();
    QVarLengthArray<Point> points;
    auto params=txt.split(' ');    
    qreal cutZ=-1;
    qreal cutZ0=-1;
    qreal spindleSpeed=-1;
    qreal feed=-1;

    for(int i=1;i<params.length();i++){
        auto&p = params[i];
        if(p[0].isNumber()){
            points.append(Point::Parse(p, mode)); continue;
        }
        if(p.startsWith('z')){
            GCode::ParseValue(p, L("z"), &cutZ); continue;
        }
        if(p.startsWith('c')){
            GCode::ParseValue(p, L("c"), &cutZ0); continue;
        }
        if(p.startsWith('s')){
            GCode::ParseValue(p, L("s"), &spindleSpeed); continue;
        }
        if(p.startsWith('f')){
            GCode::ParseValue(p, L("f"), &feed); continue;
        }
    }
    bool positionErr = points.length()<2;

    if(positionErr){ _lasterr=L("nincsenek pontok"); return {};}
    return {points[0], points[1], cutZ, cutZ0, spindleSpeed, feed};
}

auto Line::ToString() const -> QString
{
    return
        "l "+p0.ToString()+' '+ p1.ToString()+
        " z"+ GCode::r(cutZ)+
        " s"+GCode::r(cutZ0);
}

auto Line::Divide(const Gap& g, qreal tool_d) -> QList<Line>
{
    if(g.n<1) return QList<Line>();
    qreal length = GeoMath::Distance(p0, p1);
    if(length<=g.n*g.length) return {};
    int slices = g.n+1;
    if((length-g.n*g.length)/slices<tool_d) return {}; // ha a gapek közti részben nem fér el a szerszám

    QList<Line> m;

    Point kp= p0;
    Point kp2= p0;
    qreal offset = (g.length+tool_d)/2;
    qreal l = length/slices;
    qreal o1 = (l-offset)/l;
    qreal o2 = (l+offset)/l;

    zInfo("gaps:"+GCode::r(slices));
//    zInfo("offset:"+GCode::r(offset));
//    zInfo("length:"+GCode::r(length));
//    zInfo("l:"+GCode::r(l));
//    zInfo("o1:"+GCode::r(o1));
//    zInfo("o2:"+GCode::r(o2));

    for(int i=1;i<slices;i++){
        //zInfo("i:"+GCode::r(i));
        auto o = static_cast<qreal>(i)/(slices);
        //zInfo("o:"+GCode::r(o));
        Point op ={};
        bool isok = GeoMath::Divider(p0,p1,o,&op);
        if(!isok) continue;
        //Line l = {kp, op, z, s, sp, f};
        Point op1 ={};
        bool isok2 = GeoMath::Divider(kp,op,o1,&op1);
        if(!isok2) continue;
        // line:kp2->op1
        Line l = {kp2, op1, cutZ, cutZ0, spindleSpeed, feed};
        m.append(l);
        Point op2 ={};
        bool isok3 = GeoMath::Divider(kp,op,o2,&op2);
        if(!isok3) continue;
        kp = op;
        kp2 = op2;
        //gap:op1->op2
//        Line gap = {op1, op2, z-g.h, s, sp, f};
//        m.append(gap);
    }
    Line lx = {kp2, p1, cutZ, cutZ0, spindleSpeed, feed};
    m.append(lx);

    return m;
}


