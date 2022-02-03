#include "xymode.h"

const QString XYMode::key_xyz = QStringLiteral("xyz");
const QString XYMode::key_yxz = QStringLiteral("yxz");
//QString XYMode::_lasterr;

XYMode::XYMode()
{
    mode=XY;
}

XYMode::XYMode(Mode m)
{
    mode=m;
}

auto XYMode::Parse(const QString &txt, XYMode* m) -> ParseState
{
    //_lasterr.clear();
    if(!m) return ParseState::NoData;
    if(!ValidateLineType(txt)) return ParseState::NoData;

    if(txt==key_xyz){ m->mode=XY; return ParseState::Parsed;}
    if(txt==key_yxz){ m->mode=YX; return ParseState::Parsed;}
    return ParseState::NoData;
}

auto XYMode::ValidateLineType(const QString &txt) -> bool
{
    return txt.startsWith(key_xyz)||txt.startsWith(key_yxz);
}

auto XYMode::ToString() -> QString
{
    return mode==XY?QStringLiteral("XYZ"):QStringLiteral("YXZ");
}
