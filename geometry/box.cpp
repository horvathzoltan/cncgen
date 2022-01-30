#include "box.h"
#include "gcode/gcode.h"

#include <QVarLengthArray>

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
    auto params=txt.split(' ');
    BoxType::Type type = BoxType::Undefined;
    Point point;
    QVarLengthArray<Point> points;
    Gap gap={};
    qreal cutZ=0;
    qreal cutZ0=0;
    qreal corner_diameter=-1;
    qreal spindleSpeed=-1;
    qreal feed=-1;

    for(int i=1;i<params.length();i++){
        auto&p =params[i];
        if(GCode::ParseValue(p, QStringLiteral("z"), &cutZ)) continue;
        if(GCode::ParseValue(p, QStringLiteral("c"), &cutZ0)) continue;
        if(GCode::ParseValue(p, QStringLiteral("s"), &spindleSpeed)) continue;
        if(GCode::ParseValue(p, QStringLiteral("f"), &feed)) continue;
        if(GCode::ParseValue(p, QStringLiteral("d"), &corner_diameter)) continue;
        if((point=Point::Parse(p, mode)).isValid()){
            points.append(point);
            continue;
        }
        if((type = BoxType::Parse(p)) != BoxType::Undefined)continue;
        if((gap = Gap::Parse(p)).isValid()) continue;
    }
    if(points.length()<2) return {};
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
    return QStringLiteral("b ")+
        BoxType::ToString(type)+' '+
        p0.ToString()+' '+p1.ToString()+
        " z"+GCode::r(cutZ)+
        " c"+GCode::r(cutZ0)+
        " s"+GCode::r(spindleSpeed)+
        " f"+GCode::r(feed)+
        ((type==BoxType::Corners)?(" d"+GCode::r(corner_diameter)):QString())+
        ' '+gap.ToString();
}


