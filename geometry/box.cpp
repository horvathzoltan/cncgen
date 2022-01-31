#include "box.h"
#include "gcode/gcode.h"
#include "common/macrofactory/macro.h"
#include <QVarLengthArray>

QString Box::_lasterr;

Box::Box()
{
    cutZ=cutZ0=0;
    _isValid=false;
}

Box::Box(const Point &_p0,
         const Point &_p1,
         const Gap &_gap,
         BoxType::Type _type,
         qreal _cutZ,
         qreal _cutZ0,
         qreal _corner_diameter,
         qreal _spindleSpeed,
         qreal _feed)
{
    p0=_p0;
    p1=_p1;
    gap= _gap;
    type = _type;
    cutZ= _cutZ;
    cutZ0 = _cutZ0;
    corner_diameter=_corner_diameter;
    spindleSpeed=_spindleSpeed;
    feed=_feed;
    _isValid = true;
}

auto Box::Parse(const QString &txt, XYMode mode) -> Box
{
    _lasterr.clear();
    auto params=txt.split(' ');
    BoxType::Type type = BoxType::Undefined;
    Point point;
    QVarLengthArray<Point> points;
    Gap gap={};
    qreal cutZ=-1;
    qreal cutZ0=-1;
    qreal corner_diameter=-1;
    qreal spindleSpeed=-1;
    qreal feed=-1;

    for(int i=1;i<params.length();i++){
        auto&p = params[i];
        if(i==1){
            type = BoxType::Parse(p);
            continue;
            }

        if(p[0].isNumber()) {
            point=Point::Parse(p, mode);
            if(point.isValid()) points.append(point);
            continue;
        }
        if(p.startsWith('d')){
            GCode::ParseValue(p, L("d"), &corner_diameter);
            continue;
        }
        if(p.startsWith('z')){
            GCode::ParseValue(p, L("z"), &cutZ);
            continue;
        }
        if(p.startsWith('c')){ //corners
            GCode::ParseValue(p, L("c"), &cutZ0);
            continue;
        }
        if(p.startsWith('s')){
            GCode::ParseValue(p, L("s"), &spindleSpeed);
            continue;
        }
        if(p.startsWith('f')){
            GCode::ParseValue(p, L("f"), &feed);
            continue;
        }
        if(p.startsWith('g')){
            gap = Gap::Parse(p); continue;
        }
    }

    bool positionErr = points.length()<2;
    bool isCornerErr = type==BoxType::Corners&&corner_diameter<=0;

    if(positionErr){ _lasterr=L("nincsenek pontok"); return {};}
    if(isCornerErr){ _lasterr=L("no corner diameter"); return {};}
    return {points[0],
            points[1],
            gap,
            type,
            cutZ, cutZ0,
            corner_diameter,
            spindleSpeed, feed };
}

auto Box::ToString() const -> QString
{
    return L("b ")+
        BoxType::ToString(type)+' '+
        p0.ToString()+' '+p1.ToString()+
        " z"+GCode::r(cutZ)+
        " c"+GCode::r(cutZ0)+
        " s"+GCode::r(spindleSpeed)+
        " f"+GCode::r(feed)+
        ((type==BoxType::Corners)?(" d"+GCode::r(corner_diameter)):QString())+
        ' '+gap.ToString();
}


