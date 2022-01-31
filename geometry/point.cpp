#include "point.h"
#include <QStringList>
#include "gcode/gcode.h"
#include "common/logger/log.h"

QString Point::_lasterr;

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

auto Point::Parse(const QString &txt,
                  XYMode mode,
                  const QString& key) -> Point
{
    _lasterr.clear();
    if(txt.isEmpty()) return {};
    auto hasKey = !key.isEmpty();

    if(!hasKey || txt.startsWith(key)){
        auto a = hasKey?txt.mid(key.length()):txt;
        double x, y, z;
//        if(txt.startsWith('r')&&txt.contains("$m1")){
//            zInfo(L("rxyz:")+txt);
//        }
        if(!GCode::ParseValueXYZ(a, &x, &y, &z, mode)) return {};
        return {x,y,z};
    }
    _lasterr=L("nincs pozíció adat");
    return {};
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
