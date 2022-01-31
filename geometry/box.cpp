#include "box.h"
#include "gcode/gcode.h"
#include "common/macrofactory/macro.h"
#include <QVarLengthArray>

QString Box::_lasterr;

Box::Box()
{
    //cut={};
    _isValid=false;
}

Box::Box(const Point &_p0,
         const Point &_p1,
         const Gap &_gap,
         BoxType::Type _type,
         Cut _cut,
         qreal _corner_diameter,
         Feed _feed)
{
    p0=_p0;
    p1=_p1;
    gap= _gap;
    type = _type;

    corner_diameter=_corner_diameter;
    cut=_cut;
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
    Cut cut;
    qreal corner_diameter=-1;
    Feed feed;

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
            GCode::ParseValue(p, L("z"), &cut.z);
            continue;
        }
        if(p.startsWith('c')){ //corners
            GCode::ParseValue(p, L("c"), &cut.z0);
            continue;
        }
        if(p.startsWith('s')){
            GCode::ParseValue(p, L("s"), &feed.spindleSpeed);
            continue;
        }
        if(p.startsWith('f')){
            GCode::ParseValue(p, L("f"), &feed.f);
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
            cut,
            corner_diameter,
            feed };
}

auto Box::ToString() const -> QString
{
    return L("b ")+
        BoxType::ToString(type)+' '+
        p0.ToString()+' '+p1.ToString()+
        cut.ToString()+
        feed.ToString()+
        ((type==BoxType::Corners)?(" d"+GCode::r(corner_diameter)):QString())+
        ' '+gap.ToString();
}


