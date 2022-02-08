#include "point.h"
#include <QStringList>
#include "gcode/gcode.h"
#include "common/logger/log.h"
#include "geomath.h"

//QString Point::_lasterr;

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
                  XYMode xymode, MMode mmode,
                  const QString& key,
                  Point*p, Point *offset) -> ParseState
{
    ParseState st(ParseState::NoData);
    if(!key.isEmpty() && !txt.startsWith(key)) return st;
    auto a = txt.mid(key.length());
    if(!(a[0].isNumber()||a[0]=='$'||a[0]=='-'||a[0]=='+')) {return st;}
    st.setState(ParseState::NotParsed);
    if(!p) return st;

    double _x, _y, _z;        
    if(!GCode::ParseValueXYZ(a, &_x, &_y, &_z, xymode, mmode)){
         st.addError(L("nincs pozíció adat"));
    };
    if(st.state()== ParseState::ParseError) return st;
    *p={_x,_y,_z};

    if(offset){*p = GeoMath::Translation(*p, *offset);}
    st.setState(ParseState::Parsed);
    return st;
}

auto Point::ToString() const -> QString
{
    return GCode::r(x)+','+GCode::r(y)+','+GCode::r(z);
}


auto Point::ToStringZ() const -> QString
{
    return "z"+GCode::r(z);
}

auto  Point::ToStringXY() const -> QString
{
    return "x"+GCode::r(x)+'y'+GCode::r(y);
}

auto Point::ToStringXYZ() const -> QString
{
    return ToStringXY()+ToStringZ();
}
