#include "mmode.h"

const QString MMode::key_xm = QStringLiteral("xm");
const QString MMode::key_ym = QStringLiteral("ym");


MMode::MMode()
{

}

auto MMode::Parse(const QString &txt, MMode* m) -> ParseState
{
    ParseState st(ParseState::NoData);
    if(!ValidateLineType(txt)) return st;
    st.setState(ParseState::NotParsed);
    if(!m) return st;

    if(txt==key_xm){
        m->XM=true;
        st.setState(ParseState::Parsed);
    }else if(txt==key_ym){
        m->YM=true;
        st.setState(ParseState::Parsed);
    }
    return st;
}

auto MMode::ValidateLineType(const QString &txt) -> bool
{
    return txt.startsWith(key_xm)||txt.startsWith(key_ym);
}

auto MMode::ToString() -> QString
{
    if(XM) return QStringLiteral("XM");
    if(YM) return QStringLiteral("YM");
    return {};
}
