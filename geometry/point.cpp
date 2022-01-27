#include "point.h"
#include <QStringList>
#include "gcode.h"

auto Point::Parse(const QString &txt, XYMode mode) -> Point
{
    if(txt.isEmpty()) return {0,0,0};
    QStringList ns = txt.split(',');
    if(ns.length()>=2){
        bool isok_a, isok_b, isok_c=false;
        auto a = ns[0].toDouble(&isok_a);
        auto b = ns[1].toDouble(&isok_b);
        bool has_c = (ns.length()>=3);
        auto c = has_c?ns[2].toDouble(&isok_c):0;
        if(mode==YX) return {b,a,c};
        return {a,b,c};
    }
    return {0,0,0};
}

auto Point::ToString() -> QString
{
    return QString::number(x)+','+QString::number(y)+','+QString::number(z);
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
