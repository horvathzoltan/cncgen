#include "line.h"

#include <QStringList>
#include "gcode/gcode.h"
#include "geometry/geomath.h"
#include "common/logger/log.h"
#include "helpers/stringhelper.h"

//QString Line::_lasterr;

Line::Line()
{
        //_cut;
    _isValid=false;
}

Line::Line(const Point &_p0,
           const Point &_p1,
           Cut _cut,
           Feed _feed,
           const Point& _rp
           )
{
    p0 = _p0;
    p1 = _p1;
    cut = _cut;
    feed = _feed;
    rp=_rp;
    _isValid = true;
}

auto Line::Parse(const QString &txt, XYMode mode, Line *m) -> ParseState
{
    ParseState st(ParseState::NoData);
    st.setState(ParseState::NotParsed);
    if(!txt.startsWith(key)) return st;
    st.setState(ParseState::NotParsed);
    if(!m) return st;

    QVarLengthArray<Point> points;
    auto params=txt.split(' ');
    Cut cut;
    Feed feed;
    QString rpointTxt;
    Point rpoint;

    for(int i=1;i<params.length();i++){
        auto&p = params[i];
        if(Point::Parse(p, mode, {}, nullptr).state()!=ParseState::NoData) {
            Point p0;
            if(Point::Parse(p, mode, {}, &p0).state()==ParseState::Parsed){
                if(p0.isValid()) points.append(p0);
            }
            continue;
        }
        if(p.startsWith('r')) {
            Point rp;
            if(Point::Parse(p, mode, L("r"), &rp).state()==ParseState::Parsed)
            {
                rpoint = rp;
            };
            continue;
        }
        if(p.startsWith('z')){
            GCode::ParseValue(p, L("z"), &cut.z); continue;
        }
        if(p.startsWith('c')){
            GCode::ParseValue(p, L("c"), &cut.z0); continue;
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
    }
    bool hasPoints = points.length()>=2;
    bool positionErr = !hasPoints&&!rpoint.isValid();
    if(positionErr){st.addError(L("no position data"));}
    if(st.state()== ParseState::ParseError) return st;

    *m= {
        hasPoints?points[0]:Point(),
        hasPoints?points[1]:Point(),
        cut,
        feed,
        rpoint};

    st.setState(ParseState::Parsed);
    return st;
}

auto Line::ToString() const -> QString
{
    auto msg = QString(key);
    if (p0.isValid()){StringHelper::Append(&msg,p0.ToString());}
    if (p1.isValid()){StringHelper::Append(&msg,p1.ToString());}
    if (rp.isValid()){StringHelper::Append(&msg,"r"+rp.ToString());}
    StringHelper::Append(&msg,cut.ToString());
    StringHelper::Append(&msg,feed.ToString());
    return msg;
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
        Point op ={0,0,0};
        bool isok = GeoMath::Divider(p0,p1,o,&op);
        if(!isok) continue;
        //Line l = {kp, op, z, s, sp, f};
        Point op1 ={0,0,0};
        bool isok2 = GeoMath::Divider(kp,op,o1,&op1);
        if(!isok2) continue;
        // line:kp2->op1
        Line l = {kp2, op1, cut, feed};
        m.append(l);
        Point op2 ={0,0,0};
        bool isok3 = GeoMath::Divider(kp,op,o2,&op2);
        if(!isok3) continue;
        kp = op;
        kp2 = op2;
        //gap:op1->op2
//        Line gap = {op1, op2, z-g.h, s, sp, f};
//        m.append(gap);
    }
    Line lx = {kp2, p1, cut, feed};
    m.append(lx);
    zInfo(L("gap_")+": " + ToString());
    for(int i=0;i<m.length();i++){
        zInfo(L("gap")+QString::number(i)+": " + m[i].ToString());
    }
    return m;
}


