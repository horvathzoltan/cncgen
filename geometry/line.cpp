#include "line.h"

#include <QStringList>
#include "gcode/gcode.h"
#include "geometry/geomath.h"
#include "helpers/logger.h"
#include "helpers/stringhelper.h"
#include "messages.h"

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
           const Gap& _gap,
           const Point& _rp,
           const QString& _name,
           bool _noc
           )
{
    p0 = _p0;
    p1 = _p1;
    cut = _cut;
    feed = _feed;
    rp=_rp;
    gap=_gap;
    _isValid = true;
    name = _name;
    no_overcut = _noc;
}

auto Line::Parse(const QString &txt, XYMode xymode, MMode mmode, Line *m, Point *offset) -> ParseState
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
    Gap gap;
    QString name;
    bool noc=false;

    for(int i=1;i<params.length();i++){
        auto&p = params[i];
        if(Point::Parse(p).state()!=ParseState::NoData) {
            Point p0;
            if(Point::Parse(p, xymode, mmode,{}, &p0, offset).state()==ParseState::Parsed){
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
        // todo 21 mindenhol megírni a releváns hibaüzenetet
        cut.ParseInto(p, &st);
        if(Feed::Parse(p, &feed).state()!=ParseState::NoData){
            continue;
        }

        if(p.startsWith("n\"")){
            QString a;
            bool ok = GCode::ParseValue(p, L("n"), &a);
            if(ok) name=a;
            continue;
        }

        if(p.toUpper()=="noc"){
            noc = true;
            }

        if(Gap::Parse(p, nullptr).state()!=ParseState::NoData){
            Gap gp;
            if(Gap::Parse(p, &gp).state()==ParseState::Parsed){
                gap=gp;
            } else{
                st.addWarn(Messages::cannotParse(Messages::gap,p));
            }
            continue;
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
        feed, gap,
        rpoint,
        name, noc};

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
    if(gap.isValid()){StringHelper::Append(&msg,gap.ToString());}
    return msg;
}

auto Line::Divide(const Gap& g, qreal tool_d) -> QList<Line>
{
    if(g.n<1) return QList<Line>();
    qreal length = GeoMath::Distance(p0, p1);
    if(length<=g.n*g.length) return {};
    int slices = g.n+1;
    qreal gl = (length - (g.n * g.length)) / slices;

    if(gl< tool_d) return {}; // ha a gapek közti részben nem fér el a szerszám

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
        qreal o = static_cast<qreal>(i) / (slices);
        //zInfo("o:"+GCode::r(o));
        Point op ={0,0,0};
        bool isok = GeoMath::Divider(p0,p1,o,&op);
        if(!isok) continue;
        //Line l = {kp, op, z, s, sp, f};
        Point op1 ={0,0,0};
        bool isok2 = GeoMath::Divider(kp,op,o1,&op1);
        if(!isok2) continue;
        // line:kp2->op1
        Line l = {kp2, op1, cut, feed,{}, {}, name+" slice:"+QString::number(i), false};
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
    Line lx = {kp2, p1, cut, feed,{},{}, name + " slice:last", false};
    m.append(lx);
    zInfo(L("gap_")+": " + ToString());
    for(int i=0;i<m.length();i++){
        zInfo(L("gap")+QString::number(i)+": " + m[i].ToString());
    }
    return m;
}

qreal Line::Length()
{
    auto d =  GeoMath::Distance(p0,p1);
    return d;
}


QString Line::GetComment() const
{
    QString n0 = QStringLiteral("line");
    if(!name.isEmpty()){
        n0+=":"+name;
    }
    QString n01 = '('+n0+')';
    return n01;
}

