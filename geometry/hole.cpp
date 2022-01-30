#include "hole.h"

#include <QStringList>
#include "gcode/gcode.h"

Hole::Hole()
{
    _isValid=false;
}

Hole::Hole(
    const Point &_p,
    qreal _cutZ,
    qreal _cutZ0,
    qreal _diameter,
    qreal _spindleSpeed,
    qreal _feed)
{
    p = _p;
    cutZ= _cutZ;
    cutZ0 = _cutZ0;
    diameter=_diameter;
    spindleSpeed=_spindleSpeed;
    feed=_feed;
    _isValid = true;
}

auto Hole::Parse(const QString &txt, XYMode mode) -> Hole
{    
    auto params=txt.split(' ');
    Point point;
    qreal cutZ=0;
    qreal cutZ0=0;
    qreal diameter=-1;
    qreal spindleSpeed=-1;
    qreal feed=-1;

    for(int i=1;i<params.length();i++){
        auto&p =params[i];
        if(GCode::ParseValue(p, QStringLiteral("z"), &cutZ)) continue;
        if(GCode::ParseValue(p, QStringLiteral("c"), &cutZ0)) continue;
        if(GCode::ParseValue(p, QStringLiteral("d"), &diameter)) continue;
        if(GCode::ParseValue(p, QStringLiteral("s"), &spindleSpeed)) continue;
        if(GCode::ParseValue(p, QStringLiteral("f"), &feed)) continue;
        if((point=Point::Parse(p, mode)).isValid()) continue;
    }
    return {point,
            cutZ, cutZ0,
            diameter,
            spindleSpeed, feed };
}

auto Hole::ToString() const -> QString
{
    return QStringLiteral("h ")+
        p.ToString()+
        " d"+ GCode::r(diameter)+
        " z"+ GCode::r(cutZ)+
        " c"+ GCode::r(cutZ0)+
        " s"+GCode::r(spindleSpeed)+
        " f"+GCode::r(feed);
}
