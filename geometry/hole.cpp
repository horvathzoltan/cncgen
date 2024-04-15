#include "hole.h"
//#include "helpers/macro.h"
#include <QStringList>
#include "gcode/gcode.h"
#include "helpers/stringhelper.h"

//QString Hole::_lasterr;

Hole::Hole()
{
   // _isValid=false;
}

Hole::Hole(const Point &_p,
           qreal _diameter,
           Cut _cut,
           Feed _feed,           
           const Gap &_gap,                    
           qreal _jg,
           const Point &_rp,
           bool _np,
           bool _ng,
           const QString& _name,
           int _mode,
           bool ns)
{
    p = _p;
    diameter =_diameter;
    cut = _cut;
    feed = _feed;
    rp = _rp;
    gap = _gap;
    _no_predrill=_np; // no predrill????
    ng=_ng;
    jointGap=_jg;
    name = _name;
    mode = _mode;
    _no_simi = ns;
   // _isValid = true;
}

ParseState Hole::Parse(const QString &txt, XYMode xymode, MMode mmode, Hole* m, const Point& offset)
{
    ParseState st(ParseState::NoData);
    if(!txt.startsWith(key)) return st;
    st.setState(ParseState::NotParsed);
    if(!m) return st;

    auto params=txt.split(' ');
    Point point;
    qreal diameter=-1;
    Gap gap;
    Cut cut;
    Feed feed;
    QString rpointTxt;
    Point rpoint;
    bool no_predrill = false;
    bool no_gaps = false;
    qreal jointGap=0;
    int mode = 1;
    bool no_simi = false;

    for(int i=1;i<params.length();i++){
        auto&p = params[i];
        if(p.isEmpty()) continue;

        if(Point::Parse(p).state()!=ParseState::NoData) {
            Point p0;
            if(Point::Parse(p, xymode, mmode, {}, &p0, offset).state()==ParseState::Parsed){
                if(p0.isValid()) point=p0;
            }
            continue;
        }
        if(p.startsWith('r')) {
            Point rp;
            QString u("-11.95");
            bool u1 = u[0].isNumber();
            qreal uu;
            bool isok_u = GCode::ToDouble(u, &uu);
            bool isok_u2;
            qreal u3 = u.toDouble(&isok_u2);

            auto pp = Point::Parse(p, xymode, mmode,L("r"), &rp);
            if(pp.state()==ParseState::Parsed)
            {
                rpoint = rp;
            };
            continue;
        }
        if(p.startsWith('d')){
            GCode::ParseValue(p, L("d"), &diameter); continue;
        }
        if(p.startsWith('m')){
            GCode::ParseValue(p, L("m"), &mode); continue;
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
        if(Gap::Parse(p, nullptr).state()!=ParseState::NoData){
            Gap gp;
            if(Gap::Parse(p, &gp).state()==ParseState::Parsed){
                gap=gp;
            }
            continue;
        }
        if(p=="np"){
            no_predrill=true;
            continue;
        }

        if(p=="ng"){
            no_gaps=true;
            continue;
        }
        if(p.toLower()=="ns"){
            no_simi = true;
            continue;
        }
    }

    bool positionErr = !point.isValid()&&!rpoint.isValid();

    if(positionErr){st.addError(L("no position data"));}
    if(st.state()== ParseState::ParseError) return st;   

    *m= {point, diameter, cut, feed, gap, jointGap, rpoint,
          no_predrill, no_gaps, "", mode, no_simi};
    st.setState(ParseState::Parsed);
    return st;
}

auto Hole::ToString() const -> QString
{
    auto msg = QString(key);
    if (p.isValid()){StringHelper::Append(&msg,p.ToString());}
    if (rp.isValid()){StringHelper::Append(&msg,"r"+rp.ToString());};
    if (diameter>0){StringHelper::Append(&msg,"d"+ GCode::r(diameter));}
    StringHelper::Append(&msg,cut.ToString());
    StringHelper::Append(&msg,feed.ToString());
    if(gap.isValid()){StringHelper::Append(&msg,gap.ToString());}
    return msg;
}

QString Hole::GetComment() const
{
    QString n0 = QStringLiteral("hole");
    if(!name.isEmpty()){
        n0+=":"+name;
    }
    QString n01 = '('+n0+')';
    return n01;
}
