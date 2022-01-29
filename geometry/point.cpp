#include "point.h"
#include <QStringList>
#include "gcode/gcode.h"

Point::Point()
{
    x=y=z=0;
    _isValid = false;
}

Point::Point(qreal _x, qreal _y, qreal _z)
{
    x=_x;
    y=_y;
    z=_z;
    _isValid=true;
}

auto Point::Parse(const QString &txt, XYMode mode) -> Point
{
    if(txt.isEmpty()) return {};
    double x, y, z;
    if(!GCode::ParseValueXYZ(txt, &x, &y, &z, mode)) return {};
    return {x,y,z};
}

auto Point::ToString() const -> QString
{
    return GCode::r(x)+','+GCode::r(y)+','+GCode::r(z);
}

auto Point::GoToZ(GMode::Mode i) -> QString
{
    return GMode::ToGCcode(i)+" z"+GCode::r(z);
}

auto  Point::GoToXY(GMode::Mode i) -> QString
{
    return GMode::ToGCcode(i)+" x"+GCode::r(x)+'y'+GCode::r(y);
}

auto Point::GoToXYZ(GMode::Mode i) -> QString
{
    return GMode::ToGCcode(i)+" x"+GCode::r(x)+'y'+GCode::r(y)+'z'+GCode::r(z);
}
