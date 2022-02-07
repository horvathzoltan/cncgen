#include "hole.h"
#include "common/macrofactory/macro.h"
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
           const Point &_rp)
{
    p = _p;
    diameter =_diameter;
    cut = _cut;
    feed = _feed;
    rp = _rp;
    gap = _gap;
   // _isValid = true;
}

auto Hole::Parse(const QString &txt, XYMode xymode, MMode mmode, Hole* m) -> ParseState
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

    for(int i=1;i<params.length();i++){
        auto&p = params[i];

        if(Point::Parse(p, xymode, mmode, {}, nullptr).state()!=ParseState::NoData) {
            Point p0;
            if(Point::Parse(p, xymode, mmode, {}, &p0).state()==ParseState::Parsed){
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
        if(Gap::Parse(p, nullptr).state()!=ParseState::NoData){
            Gap gp;
            if(Gap::Parse(p, &gp).state()==ParseState::Parsed){
                gap=gp;
            }
            continue;
        }
    }

    bool positionErr = !point.isValid()&&!rpoint.isValid();

    if(positionErr){st.addError(L("no position data"));}
    if(st.state()== ParseState::ParseError) return st;

    // todo f1 ha ugyanoda fúrunk egy másikat, ami
    // kisebb vagy rövidebb, mint a másik az felesleges
    // de amúgy simán lehet koordináta nélkül fúrni, ekkor ugyanoda kerül
    // !!! ha egy furat oda kerül, ahol már lett fúrva, és
    // sem az átmérő, sem a mélység nem nagyobb mint az előző, akkor semmit nem kell csinálni

    *m= {point, diameter, cut, feed, gap, rpoint};
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
