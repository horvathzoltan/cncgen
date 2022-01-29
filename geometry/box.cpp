#include "box.h"
#include "gcode/gcode.h"

auto Box::Parse(const QString &txt, XYMode mode) -> Box
{
    Box m={};
    auto params=txt.split(' ');
    int p_ix = 0;    
    BoxType::Type type;
    Point point;
    Gap gap;
    for(int i=1;i<params.length();i++){
        auto&p =params[i];
        if(GCode::ParseValue(p, QStringLiteral("z"), &m.cutZ)) continue;
        if(GCode::ParseValue(p, QStringLiteral("c"), &m.cutZ0)) continue;
        if(GCode::ParseValue(p, QStringLiteral("s"), &m.spindleSpeed)) continue;
        if(GCode::ParseValue(p, QStringLiteral("f"), &m.feed)) continue;
        if(GCode::ParseValue(p, QStringLiteral("d"), &m.corner_diameter)) continue;
        if((point=Point::Parse(p, mode)).isValid()){
            if(p_ix==0){
                m.p0=point;
            }
            else if(p_ix==1){
                m.p1=point;
            }
            p_ix++;
            continue; //point
        }
        if((type = BoxType::Parse(p)) != BoxType::Undefined){
            m.type = type;
            continue;
        }
        if((gap = Gap::Parse(p)).isValid()){
            m.gap = gap;
        }
    }
    return m;
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


