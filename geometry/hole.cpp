#include "hole.h"

#include <QStringList>
#include "gcode/gcode.h"

auto Hole::Parse(const QString &txt, XYMode mode) -> Hole
{
    Hole m={};
    auto params=txt.split(' ');
    Point point;
    for(auto&p:params){
        if(GCode::ParseValue(p, QStringLiteral("z"), &m.cutZ)) continue;
        if(GCode::ParseValue(p, QStringLiteral("c"), &m.cutZ0)) continue;
        if(GCode::ParseValue(p, QStringLiteral("d"), &m.diameter)) continue;
        if(GCode::ParseValue(p, QStringLiteral("s"), &m.spindleSpeed)) continue;
        if(GCode::ParseValue(p, QStringLiteral("f"), &m.feed)) continue;
        if((point=Point::Parse(p, mode)).isValid()){
            m.p=point;
            continue; //point
        }
    }
    return m;
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
