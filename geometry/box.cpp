#include "box.h"
#include "gcode/gcode.h"
#include "common/macrofactory/macro.h"
#include <QVarLengthArray>
#include "helpers/stringhelper.h"


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
         Feed _feed,
         const Point& _rp)
{
    p0=_p0;
    p1=_p1;
    gap= _gap;
    type = _type;
    corner_diameter=_corner_diameter;
    cut=_cut;
    feed=_feed;
    rp=_rp;
    _isValid = true;
}

auto Box::Parse(const QString &txt, XYMode mode, Box *m) -> ParseState
{
    _lasterr.clear();
    if(!m) return ParseState::NoData;
    if(!txt.startsWith(key)) return ParseState::NoData;

    auto params=txt.split(' ');
    BoxType::Type type = BoxType::Undefined;
    Point point;
    QVarLengthArray<Point> points;
    Gap gap;
    Cut cut;
    qreal corner_diameter=-1;
    Feed feed;
    Point rpoint;

    for(int i=1;i<params.length();i++){
        auto&p = params[i];
        //if(i==1){
        auto type_temp = BoxType::Parse(p);
        if(type_temp!=type && type_temp!=BoxType::Undefined){ // az utolsó számít
            type = type_temp;
            continue;
            }

        if(p[0].isNumber()) {
            point=Point::Parse(p, mode);
            if(point.isValid()) points.append(point);
            continue;
        }
        if(p.startsWith('r')) {
            rpoint=Point::Parse(p, mode, L("r")); continue;
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
            qreal x;
            if(GCode::ParseValue(p, L("s"), &x)){
                feed.setSpindleSpeed(x);
                continue;
            }
        }
        if(p.startsWith('f')){
            qreal x;
            if(GCode::ParseValue(p, L("f"), &x)){
                feed.setFeed(x);
                continue;
            }
        }
        if(p.startsWith('g')){
            gap = Gap::Parse(p); continue;
        }
    }
    bool hasPoints = points.length()>=2;
    bool positionErr = !hasPoints&&!rpoint.isValid();
    bool isCornerErr = type==BoxType::Corners&&corner_diameter<=0;

    if(positionErr){ _lasterr=L("nincsenek pontok"); return ParseState::NotParsed;}
    if(isCornerErr){ _lasterr=L("no corner diameter"); return ParseState::NotParsed;}

    *m= {hasPoints?points[0]:Point(),
            hasPoints?points[1]:Point(),
            gap,
            type,
            cut,
            corner_diameter,
            feed,
            rpoint
    };
    return ParseState::Parsed;
}

auto Box::ToString() const -> QString
{
    QString msg(key);
    StringHelper::Append(&msg,BoxType::ToString(type));
    if (p0.isValid()){StringHelper::Append(&msg,p0.ToString());}
    if (p1.isValid()){StringHelper::Append(&msg,p1.ToString());}
    if (rp.isValid()){StringHelper::Append(&msg,"r"+rp.ToString());}
    StringHelper::Append(&msg,cut.ToString());
    StringHelper::Append(&msg,feed.ToString());
    if (type==BoxType::Corners){StringHelper::Append(&msg,"d"+GCode::r(corner_diameter));}
    if(gap.isValid()){StringHelper::Append(&msg,gap.ToString());}
    return msg;
}


