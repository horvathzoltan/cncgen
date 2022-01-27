#include "gap.h"

#include <QStringList>
#include "gcode/gcode.h"

auto Gap::Parse(const QString &txt) -> Gap
{
    Gap m={};
    auto params=txt.split(',');
    if(params.length()<3) return m;

    bool isok;
    auto n = params[0].midRef(1).toInt(&isok);
    if(isok) m.n = n;

    auto l = params[1].toDouble(&isok);
    if(isok) m.l = l;

    auto h = params[2].toDouble(&isok);
    if(isok) m.h = h;

    return m;
}

QString Gap::ToString()
{
    return "g"+GCode::i(n)+','+GCode::r(l)+','+GCode::r(h);
}
