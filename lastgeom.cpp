#include "lastgeom.h"

#include <geometry/geomath.h>

LastGeom::LastGeom() {}

void LastGeom::Reset()
{
    _lastLine={};
    _lastBox={{},{},BoxType::Undefined};
    _lastArc={.p0={}, .p1={}, .o={}};
    _last_position = {};
}

QString LastGeom::LastLine::toString()
{
    return p0.ToString()+' '+p1.ToString();
}

QString LastGeom::LastArc::toString()
{
    return p0.ToString()+"->"+p1.ToString()+"o="+o.ToString();
}

qreal LastGeom::LastArc::ArcLength()
{
    return GeoMath::ArcLength(p0,p1, o);
}

qreal LastGeom::LastBox::Diastance()
{
    return GeoMath::Distance(p0, p1);
}
