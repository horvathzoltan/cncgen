#include "lastgeom.h"

#include <geometry/geomath.h>

LastGeom::LastGeom() {}

void LastGeom::Reset()
{
    _lastLine.Reset();
    _lastBox.Reset();
    _lastArc.Reset();
    _last_position.Reset();
    _lastHoleP.Reset();
}

/*LINE*/
void LastGeom::LastLine::Reset(){
    _p0.Reset();
    _p1.Reset();
}

void LastGeom::LastLine::Store(){
    _stored_p0 = _p0;
    _stored_p1 = _p1;
}

void LastGeom::LastLine::Retrieve(){
    _p0 = _stored_p0;
    _p1 = _stored_p1;
}

QString LastGeom::LastLine::toString()
{
    return _p0.ToString()+' '+_p1.ToString();
}
/*ARC*/

void LastGeom::LastArc::Reset(){
    _p0.Reset();
    _p1.Reset();
    _o.Reset();
}

void LastGeom::LastArc::Store(){
    _stored_p0 = _p0;
    _stored_p1 = _p1;
    _stored_o = _o;
}

void LastGeom::LastArc::Retrieve(){
    _p0 = _stored_p0;
    _p1 = _stored_p1;
    _o = _stored_o;
}

QString LastGeom::LastArc::toString()
{
    return _p0.ToString()+"->"+_p1.ToString()+"o="+_o.ToString();
}

/*BOX*/

void LastGeom::LastBox::Reset(){
    _p0.Reset();
    _p1.Reset();
    _type = BoxType::Undefined;
}

void LastGeom::LastBox::Store(){
    _stored_p0 = _p0;
    _stored_p1 = _p1;
}

void LastGeom::LastBox::Retrieve(){
    _p0 = _stored_p0;
    _p1 = _stored_p1;
}

void LastGeom::LastPosition::Reset()
{
    _p.Reset();
}
