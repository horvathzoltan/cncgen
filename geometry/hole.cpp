#include "hole.h"
#include "common/macrofactory/macro.h"
#include <QStringList>
#include "gcode/gcode.h"

QString Hole::_lasterr;

Hole::Hole()
{
    _isValid=false;
}

Hole::Hole(
    const Point &_p,
    qreal _diameter,
    Cut _cut,
    Feed _feed,
    const Point &_rp)
{
    p = _p;
    diameter=_diameter;
    cut = _cut;
    feed = _feed;
    rp=_rp;
    _isValid = true;
}

auto Hole::Parse(const QString &txt, XYMode mode) -> Hole
{
    _lasterr.clear();
    auto params=txt.split(' ');
    Point point;
    qreal diameter=-1;
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
    }

    bool positionErr = !point.isValid()&&!rpoint.isValid();

    if(positionErr) { _lasterr=L("nincs kezdőpont");return{};}
    // todo b ha ugyanoda fúrunk egy másikat, ami
    // kisebb vagy rövidebb, mint a másik az felesleges
    // de amúgy simán lehet koordináta nélkül fúrni, ekkor ugyanoda kerül
    // todo b0 ha a furat átmérő nagyobb, mint
    return {point, diameter, cut, feed, rpoint};
}

auto Hole::ToString() const -> QString
{
    auto msg = L("h");
    if (p.isValid()) msg+=' '+p.ToString();
    if (rp.isValid()) msg+=" r"+rp.ToString();
    if (diameter>0) msg+=" d"+ GCode::r(diameter);
    msg+= cut.ToString();
    msg+= feed.ToString();

    return msg;
}
