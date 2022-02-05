#include "common/macrofactory/macro.h"
#include "size.h"
#include "gcode/gcode.h"
#include "parsestate.h"

const QString Size::key = L("size");


Size::Size()
{
    w=h=-1;
}

Size::Size(qreal _w, qreal _h)
{
    w=_w;
    h=_h;
}

auto Size::Parse(const QString &txt, Size *s) -> ParseState
{
    ParseState st(ParseState::NoData);
    if(!txt.startsWith(key)) return st;
    st.setState(ParseState::NotParsed);
    if(!s) return st;

    auto a = txt.mid(key.length());
    qreal _w, _h;
    if(!GCode::ParseValueXYZ(a, &_w, &_h, nullptr, XYMode::XY)){
        st.addError(L("nincsenek pontok"));
    }

    if(st.state()== ParseState::ParseError) return st;
    *s = {_w,_h};
    st.setState(ParseState::Parsed);
    return st;
}
