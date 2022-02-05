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

auto Size::Parse(const QString &txt, XYMode mode, Size *s) -> ParseState
{
    ParseState st(ParseState::NoData);
    if(!txt.startsWith(key)) return st;
    st.setState(ParseState::NotParsed);
    if(!s) return st;    
    if(mode.mode==XYMode::Unknown) return st;

    auto a = txt.mid(key.length());
    qreal _w, _h;
    if(!GCode::ParseValueXYZ(a, &_w, &_h, nullptr, XYMode::XY)){
        st.addError(L("nincs méret adat"));
    }
    if(st.state()== ParseState::ParseError) return st;
    switch(mode.mode){
    case XYMode::XY:
        *s = {_w,_h};
        break;
    case XYMode::YX:
        *s = {_h,_w};
        break;
    default:break;
    }
    st.setState(ParseState::Parsed);
    return st;
}
