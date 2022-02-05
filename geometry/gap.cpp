#include "gap.h"

#include <QStringList>
#include "gcode/gcode.h"
#include "helpers/stringhelper.h"
#include "common/macrofactory/macro.h"

Gap::Gap()
{
    n=length=height=0;
   // _isValid=false;
}

Gap::Gap(int _n, qreal _l, qreal _h)
{
    n=_n;
    length=_l;
    height=_h;
//    _isValid = true;
}

auto Gap::Parse(const QString &txt, Gap *gap) -> ParseState
{
    ParseState st(ParseState::NoData);
    if(!txt.startsWith(key)) return st;
    auto params=txt.split(',');
    if(params.length()<3) return st;
    st.setState(ParseState::NotParsed);
    if(!gap) return st;

    bool isok_n, isok_l, isok_h;
    auto n = params[0].midRef(1).toInt(&isok_n);
    auto l = params[1].toDouble(&isok_l);
    auto h = params[2].toDouble(&isok_h);

    if(!isok_n){st.addError(L("no gap count"));}
    if(!isok_n){st.addError(L("no length"));}
    if(!isok_n){st.addError(L("no no height"));}
    if(st.state()== ParseState::ParseError) return st;

    *gap = {n,l,h};
    st.setState(ParseState::Parsed);
    return st;
}

auto Gap::ToString() const -> QString
{
    auto msg = QString(key);
    StringHelper::Append(&msg, GCode::i(n));
    StringHelper::Append(&msg, GCode::r(length),',');
    StringHelper::Append(&msg, GCode::r(height), ',');
    return msg;
}

bool Gap::isValid() const
{
    return n>0&&length>0&&height>0;
}
