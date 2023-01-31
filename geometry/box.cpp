#include "box.h"
#include "gcode/gcode.h"
#include "helpers/macro.h"
#include <QVarLengthArray>
#include "helpers/stringhelper.h"
#include "geometry/size.h"

//QString Box::_lasterr;

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
         const Point& _rp,
         const Size& _size,
         qreal _jg,
         bool _nl[4])
{
    p0=_p0;
    p1=_p1;
    gap= _gap;
    type = _type;
    corner_diameter=_corner_diameter;
    cut=_cut;
    feed=_feed;
    rp=_rp;
    size=_size;
    jointGap=_jg;
    nl[0]=_nl[0];
    nl[1]=_nl[1];
    nl[2]=_nl[2];
    nl[3]=_nl[3];
    _isValid = true;
}

auto Box::Parse(const QString &txt) -> ParseState{
    return Parse(txt, XYMode::Unknown, {},nullptr, nullptr);
}

auto Box::Parse(const QString &txt, XYMode xymode, MMode mmode,Box *m, Point *offset) -> ParseState
{
    ParseState st(ParseState::NoData);
    if(!txt.startsWith(key)) return st;
    st.setState(ParseState::NotParsed);
    if(!m) return st;

    auto params=txt.split(' ');
    BoxType::Type type = BoxType::Undefined;
    QVarLengthArray<Point> points;
    Gap gap;
    Cut cut;
    qreal corner_diameter=-1;
    Feed feed;
    Point rpoint;
    Size size;
    qreal jointGap=0;

    bool nl[]={1,1,1,1};

    for(int i=1;i<params.length();i++){
        auto&p = params[i];
        //if(i==1){
        auto type_temp = BoxType::Parse(p);
        if(type_temp!=type && type_temp!=BoxType::Undefined){ // az utolsó számít
            type = type_temp;
            continue;
            }

        if(Point::Parse(p).state()!=ParseState::NoData) {
            Point p0;
            if(Point::Parse(p, xymode,mmode, {}, &p0, offset).state()==ParseState::Parsed){
                if(p0.isValid()) points.append(p0);
            }
            continue;
        }
        if(p.startsWith('r')) {
            Point rp;
            if(Point::Parse(p, xymode, mmode,L("r"), &rp, nullptr).state()==ParseState::Parsed)
            {
                rpoint = rp;
            };
            continue;
        }

        if(Size::Parse(p).state()!=ParseState::NoData) {
            Size s0;
            auto pp = Size::Parse(p, xymode, mmode, &s0);
            if(pp.state()==ParseState::Parsed){size=s0;}
            continue;
        }
//        if(Size::Parse(p,&size).state()!=ParseState::NoData) {
//            continue;
//        }
        if(p.startsWith('d')){
            GCode::ParseValue(p, L("d"), &corner_diameter);
            continue;
        }
        if(cut.ParseInto(p,&st)) continue;
        if(Feed::Parse(p, &feed).state()!=ParseState::NoData){
            continue;
        }

        if(p.startsWith("jg")){
            qreal a;
            if(GCode::ParseValue(p, L("jg"), &a)){
                jointGap=a;
            }
            continue;
        }

        if(p.startsWith("nl")){
            QList<int> a;
            if(GCode::ParseValues(p, L("nl"), &a)){
                if(a.count()>0){nl[0]=a[0];}
                if(a.count()>1){nl[1]=a[1];}
                if(a.count()>2){nl[2]=a[2];}
                if(a.count()>3){nl[3]=a[3];}
            }
            continue;
        }

//        if(p.startsWith('z')){
//            GCode::ParseValue(p, L("z"), &cut.z);
//            continue;
//        }
//        if(p.startsWith('c')){ //corners -
//            GCode::ParseValue(p, L("c"), &cut.z0);
//            continue;
//        }
//        if(p.startsWith('s')){
//            qreal x;
//            if(GCode::ParseValue(p, L("s"), &x)){
//                feed.setSpindleSpeed(x);
//                continue;
//            }
//        }
//        if(p.startsWith('f')){
//            qreal x;
//            if(GCode::ParseValue(p, L("f"), &x)){
//                feed.setFeed(x);
//                continue;
//            }
//        }
        if(Gap::Parse(p, nullptr).state()!=ParseState::NoData){
            Gap gp;
            if(Gap::Parse(p, &gp).state()==ParseState::Parsed){
                gap=gp;
            }
            continue;
        }

    }
    bool hasPoints = points.length()>=2||(points.length()==1&&size.isValid());
    bool positionErr = !hasPoints&&!rpoint.isValid();
    bool isCornerErr = type==BoxType::Corners&&corner_diameter<=0;

    if(positionErr){
        st.addError(L("no position data"));
    }
    if(isCornerErr){st.addError(L("no corner diameter"));}

    if(st.state()== ParseState::ParseError) return st;

    *m= {
        points.length()>0?points[0]:Point(),
        points.length()>1?points[1]:Point(),
        gap,
        type,
        cut,
        corner_diameter,
        feed,
        rpoint,
        size,
        jointGap,
        nl
    };

    st.setState(ParseState::Parsed);
    return st;
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


