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
    qreal _cutZ,
    qreal _cutZ0,
    qreal _spindleSpeed,
    qreal _feed,
    const Point &_rp)
{
    p = _p;
    diameter=_diameter;
    cutZ= _cutZ;
    cutZ0 = _cutZ0;
    spindleSpeed=_spindleSpeed;
    feed=_feed;
    rp=_rp;
    _isValid = true;
}

auto Hole::Parse(const QString &txt, XYMode mode) -> Hole
{
    _lasterr.clear();
    auto params=txt.split(' ');
    Point point;
    qreal cutZ=-1;
    qreal cutZ0=-1;
    qreal diameter=-1;
    qreal spindleSpeed=-1;
    qreal feed=-1;
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
            GCode::ParseValue(p, L("z"), &cutZ); continue;
        }
        if(p.startsWith('c')){
            GCode::ParseValue(p, L("c"), &cutZ0); continue;
        }
        if(p.startsWith('s')){
            GCode::ParseValue(p, L("s"), &spindleSpeed); continue;
        }
        if(p.startsWith('f')){
            GCode::ParseValue(p, L("f"), &feed); continue;
        }
    }

    bool positionErr = !point.isValid()&&!rpoint.isValid();

    if(positionErr) { _lasterr=L("nincs kezdőpont");return{};}
    // todo b ha ugyanoda fúrunk egy másikat, ami
    // kisebb vagy rövidebb, mint a másik az felesleges
    // de amúgy simán lehet koordináta nélkül fúrni, ekkor ugyanoda kerül

    return {point,
            diameter,
            cutZ, cutZ0,
            spindleSpeed, feed,
            rpoint};
}

auto Hole::ToString() const -> QString
{
    auto msg = L("h");
    if (p.isValid()) msg+=' '+p.ToString();
    if (diameter>0) msg+=" d"+ GCode::r(diameter);
    if (cutZ>0) msg+=" z"+ GCode::r(cutZ);
    if (cutZ0>0) msg+=" c"+ GCode::r(cutZ0);
    if (spindleSpeed>0) msg+=" s"+GCode::r(spindleSpeed);
    if (feed>0) msg+=" f"+GCode::r(feed);
    if (rp.isValid()) msg+=" r"+rp.ToString();
    return msg;
}
