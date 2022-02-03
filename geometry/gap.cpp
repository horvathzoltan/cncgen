#include "gap.h"

#include <QStringList>
#include "gcode/gcode.h"
#include "helpers/stringhelper.h"

Gap::Gap()
{
    n=length=height=0;
    _isValid=false;
}

Gap::Gap(int _n, qreal _l, qreal _h)
{
    n=_n;
    length=_l;
    height=_h;
    _isValid = true;
}

auto Gap::Parse(const QString &txt) -> Gap
{
    if(!txt.startsWith('g')) return{};
    auto params=txt.split(',');
    if(params.length()<3) return {};

    bool isok_n, isok_l, isok_h;
    auto n = params[0].midRef(1).toInt(&isok_n);
    auto l = params[1].toDouble(&isok_l);
    auto h = params[2].toDouble(&isok_h);

    bool isok = isok_n && isok_l && isok_h;
    if(!isok) return {};

    return {n,l,h};
}

auto Gap::ToString() const -> QString
{
    auto msg = QString(key);
    StringHelper::Append(&msg, GCode::i(n));
    StringHelper::Append(&msg, GCode::r(length),',');
    StringHelper::Append(&msg, GCode::r(height), ',');
    return msg;
}
