#include "hole.h"
#include "common/macrofactory/macro.h"
#include <QStringList>
#include "gcode/gcode.h"

QString Hole::_lasterr;

Hole::Hole()
{
    _isValid=false;
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
    _isValid = true;
}

auto Hole::Parse(const QString &txt, XYMode mode, Hole* m) -> ParseState
{
    _lasterr.clear();
    if(!m) return ParseState::NoData;
    if(!txt.startsWith(key)) return ParseState::NoData;

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

        if(p[0].isNumber()) {
            point=Point::Parse(p, mode); continue;
        }
        if(p.startsWith('r')) {
            rpoint=Point::Parse(p, mode, L("r")); continue;
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
            GCode::ParseValue(p, L("s"), &feed.spindleSpeed); continue;
        }
        if(p.startsWith('f')){
            GCode::ParseValue(p, L("f"), &feed.f); continue;
        }
        // todo e0 szerencsésebb lenne ha 2 boolal térne vissza,
        // egyik a hasGap, ha egyáltalán gap a szintaxis szerint
        // az isOk prdig a sikeres parseolás
        if(p.startsWith('g')){
            gap = Gap::Parse(p); continue;
        }
    }

    bool positionErr = !point.isValid()&&!rpoint.isValid();

    if(positionErr) { _lasterr=L("nincs kezdőpont");return ParseState::NotParsed;}
    // todo b0 ha ugyanoda fúrunk egy másikat, ami
    // kisebb vagy rövidebb, mint a másik az felesleges
    // de amúgy simán lehet koordináta nélkül fúrni, ekkor ugyanoda kerül
    // !!! ha egy furat oda kerül, ahol már lett fúrva, és
    // sem az átmérő, sem a mélység nem nagyobb mint az előző, akkor semmit nem kell csinálni

    *m= {point, diameter, cut, feed, gap, rpoint};
    return ParseState::Parsed;
}

auto Hole::ToString() const -> QString
{
    auto msg = L("h");
    if (p.isValid()) msg+=' '+p.ToString();
    if (rp.isValid()) msg+=" r"+rp.ToString();
    if (diameter>0) msg+=" d"+ GCode::r(diameter);
    msg+= cut.ToString();
    msg+= feed.ToString();
    if(gap.isValid()) msg+=+' '+gap.ToString();
    return msg;
}
