#include "arc.h"

#include <QStringList>
#include <QVarLengthArray>
//#include "gcode/gcode.h"
//#include "geometry/geomath.h"
//#include "helpers/log.h"
#include "helpers/stringhelper.h"
#include "helpers/macro.h"
//QString Arc::_lasterr;


Arc::Arc()
{
  //_cut;
    //_isValid=false;
}

Arc::Arc(const Point &_p0,
         const Point &_p1,
         const Point &_o,
         Cut _cut,
         Feed _feed,
         const Point& _rp
         )
{
    p0 = _p0;
    p1 = _p1;
    o = _o;
    cut = _cut;
    feed = _feed;
    rp=_rp;
    //_isValid = true;
}

auto Arc::Parse(const QString &txt, XYMode xymode, Arc *a, MMode mmode, Point *offset) -> ParseState
{
    //_lasterr.clear();
    ParseState st(ParseState::NoData);
    if(!txt.startsWith(key)) return st;
    st.setState(ParseState::NotParsed);
    if(!a) return st;

    QVarLengthArray<Point> points;
    auto params=txt.split(' ');
    Cut cut;
    Feed feed;
    QString rpointTxt;
    Point rpoint;

    for(int i=1;i<params.length();i++){
        auto&p = params[i];
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
        if(cut.ParseInto(p,&st)) continue;

        if(Feed::Parse(p, &feed).state()!=ParseState::NoData){
            continue;
        }

//        if(p.startsWith('z')){
//            GCode::ParseValue(p, L("z"), &cut.z); continue;
//        }
//        if(p.startsWith('c')){
//            GCode::ParseValue(p, L("c"), &cut.z0); continue;
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
    }
    bool hasPoints = points.length()>=3;
    bool positionErr = !hasPoints&&!rpoint.isValid();
    if(positionErr){ st.addError(L("nincsenek pontok"));}
    if(st.state()== ParseState::ParseError) return st;

    *a={
        hasPoints?points[1]:Point(),
        hasPoints?points[0]:Point(),
        hasPoints?points[2]:Point(),
        cut, feed, rpoint};

    if(xymode.mode==XYMode::YX){
        auto i = a->p0;
        a->p0=a->p1;
        a->p1=i;
    }

    if(mmode.direction_ccw()){
        auto i = a->p0;
        a->p0=a->p1;
        a->p1=i;
    }
    st.setState(ParseState::Parsed);
    return st;
}

auto Arc::ToString() const -> QString
{
    QString msg(key);
    if (p0.isValid()){StringHelper::Append(&msg, p0.ToString());}
    if (p1.isValid()){StringHelper::Append(&msg, p1.ToString());}
    if (o.isValid()){StringHelper::Append(&msg,o.ToString());}
    if (rp.isValid()){StringHelper::Append(&msg,"r"+rp.ToString());}
    StringHelper::Append(&msg,cut.ToString());
    StringHelper::Append(&msg,feed.ToString());
    return msg;
}

//auto Arc::Divide(const Gap& g, qreal tool_d) -> QList<Arc>
//{
//    if(g.n<1) return QList<Line>();
//    qreal length = GeoMath::Distance(p0, p1);
//    if(length<=g.n*g.length) return {};
//    int slices = g.n+1;
//    if((length-g.n*g.length)/slices<tool_d) return {}; // ha a gapek közti részben nem fér el a szerszám

//    QList<Line> m;

//    Point kp= p0;
//    Point kp2= p0;
//    qreal offset = (g.length+tool_d)/2;
//    qreal l = length/slices;
//    qreal o1 = (l-offset)/l;
//    qreal o2 = (l+offset)/l;

//    zInfo("gaps:"+GCode::r(slices));
//    //    zInfo("offset:"+GCode::r(offset));
//    //    zInfo("length:"+GCode::r(length));
//    //    zInfo("l:"+GCode::r(l));
//    //    zInfo("o1:"+GCode::r(o1));
//    //    zInfo("o2:"+GCode::r(o2));

//    for(int i=1;i<slices;i++){
//        //zInfo("i:"+GCode::r(i));
//        auto o = static_cast<qreal>(i)/(slices);
//        //zInfo("o:"+GCode::r(o));
//        Point op ={0,0,0};
//        bool isok = GeoMath::Divider(p0,p1,o,&op);
//        if(!isok) continue;
//        //Line l = {kp, op, z, s, sp, f};
//        Point op1 ={0,0,0};
//        bool isok2 = GeoMath::Divider(kp,op,o1,&op1);
//        if(!isok2) continue;
//        // line:kp2->op1
//        Line l = {kp2, op1, cut, feed};
//        m.append(l);
//        Point op2 ={0,0,0};
//        bool isok3 = GeoMath::Divider(kp,op,o2,&op2);
//        if(!isok3) continue;
//        kp = op;
//        kp2 = op2;
//        //gap:op1->op2
//        //        Line gap = {op1, op2, z-g.h, s, sp, f};
//        //        m.append(gap);
//    }
//    Line lx = {kp2, p1, cut, feed};
//    m.append(lx);
//    zInfo(L("gap_")+": " + ToString());
//    for(int i=0;i<m.length();i++){
//        zInfo(L("gap")+QString::number(i)+": " + m[i].ToString());
//    }
//    return m;
//}


//auto Arc::ToGCode(QString* err) -> QString
////auto GenerateGcode::GenerateArc(const Point &p0, const Point& p1, const Point&o, qreal h ,QString* err) -> QString
//{
//    QString msg = "G: "+ToString();
//    zInfo(msg);

//    /*POSITION*/
//    if(p1==p0){
//        if(err){*err=L("start and end points are equal");} return {};
//    }
//    if(p0==o){
//        if(err){*err=L("start and origo are equal");} return {};
//    }
//    if(p1==o){
//        if(err){*err=L("end pouint and origo are equal");} return {};
//    }
//    auto d01 = GeoMath::Distance(p0,p1);
//    /*CUT*/
//    if(_last_cut.z==-1 && m.cut.z==-1){
//        if(err){*err=L("no total cut depth");} return {};
//    }
//    if(_last_cut.z0==-1 && m.cut.z0==-1){if(err)*err=L("no cut depth"); return {};}
//    if(m.cut.z!=-1) _last_cut.z = m.cut.z;
//    if(m.cut.z0!=-1) _last_cut.z0 = m.cut.z0;
//    if(!CheckCut(err)) return{};
//    /*FEED*/
//    SetSelectedFeed(m.feed);
//    /*TOOL*/
//    if(!ValidateTool()) {if(err)*err=L("no tool"); return {};}
//    Tool t = _tools[_selected_tool_ix];
//    if(d01<t.d){
//        if(err){*err=L("wrong length: ")+GCode::r(d01)+
//                " tool: "+t.ToString();
//        }
//    }

//    msg=L("->")+ p0.ToString()+' '+m.p1.ToString()+' '+m.o.ToString();

//    msg+= " h:"+GCode::r(m.cut.z);
//    int steps = qCeil(m.cut.z/_last_cut.z0)+1;
//    msg+= " steps:"+QString::number(steps);

//    QStringList g(L("(arc begin)"));

//    g.append(TravelXYToGCode(m.p0));
//    g.append(LiftDownToGCode(m.p0.z));
//    Point p;
//    GMode::Mode mode;
//    QString ij;
//    qreal i,j,i1,j1,i0,j0;
//    i1=m.o.x-m.p0.x;
//    j1=m.o.y-m.p0.y;

//    i0=m.o.x-m.p1.x;
//    j0=m.o.y-m.p1.y;

//    for(int step=0;step<steps;step++){
//        if(!(step%2))
//        {
//            p=m.p1;
//            mode = GMode::Circular;
//            i=i1;
//            j=j1;
//        }
//        else
//        {
//            p=m.p0;
//            mode = GMode::Circular_ccw;
//            i=i0;
//            j=j0;
//        }
//        QString ij2 = "i"+GCode::r(i)+" j"+GCode::r(j);
//        qreal z = p.z-(step+1)*_last_cut.z0;
//        qreal zz = p.z-m.cut.z;
//        if(z<zz){
//            p.z = zz;
//        } else {
//            p.z = z;
//        }
//        g.append(GoToXYZ(mode, p)+' '+ij2);
//    }
//    g.append(LiftUpToGCode(m.p0.z));

//    zInfo(msg);
//    return g.join('\n');
//}


