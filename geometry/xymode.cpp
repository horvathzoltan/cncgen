#include "xymode.h"

const QString XYMode::key_xyz = QStringLiteral("xyz");
const QString XYMode::key_yxz = QStringLiteral("yxz");
//QString XYMode::_lasterr;

XYMode::XYMode()
{
    mode=Unknown;
}

XYMode::XYMode(Mode m)
{
    mode=m;
}

auto XYMode::Parse(const QString &txt, XYMode* m) -> ParseState
{
    ParseState st(ParseState::NoData);
    if(!ValidateLineType(txt)) return st;
    st.setState(ParseState::NotParsed);
    if(!m) return st;

    if(txt==key_xyz){
        m->mode=XY;
        st.setState(ParseState::Parsed);
    }else if(txt==key_yxz){
        m->mode=YX;
        st.setState(ParseState::Parsed);
    }
    return st;
}

auto XYMode::ValidateLineType(const QString &txt) -> bool
{
    return txt.startsWith(key_xyz)||txt.startsWith(key_yxz);
}

auto XYMode::ToString() -> QString
{
    if(mode==XY) return QStringLiteral("XYZ");
    if(mode==YX) return QStringLiteral("YXZ");
    return {};
}
