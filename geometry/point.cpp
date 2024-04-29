#include "point.h"
#include <QStringList>
#include "gcode/gcode.h"
//#include "helpers/log.h"
#include "geomath.h"
#include "helpers/stringhelper.h"
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

ParseState Point::Parse(const QString &txt){
    return Point::Parse(txt, XYMode::Unknown, {},{}, nullptr, {});
}

ParseState Point::Parse(const QString &txt, const QString& key) {
    return Point::Parse(txt, XYMode::Unknown, {}, key,nullptr, {});
}

ParseState Point::Parse(const QString &txt,
                        XYMode xymode, MMode mmode,
                        const QString& key,
                        Point*p)
{
    return Point::Parse(txt,xymode, mmode,key,p,{});
}

ParseState Point::Parse(const QString &txt,
                  XYMode xymode, MMode mmode,
                  const QString& key,
                  Point*p, const Point& offset)
{
    ParseState st(ParseState::NoData);
    if(txt.isEmpty()) return st;

    if(!key.isEmpty() && !txt.startsWith(key)) return st;
    auto a = txt.mid(key.length()).trimmed();
    if(a.isEmpty()) return st;

    bool isValue = (a[0].isNumber()||a[0]=='$'||a[0]=='-'||a[0]=='+');
    if(!isValue)
    {
        return st;
    }

    st.setState(ParseState::NotParsed);
    if(!p) return st;

    double _x, _y, _z;
    bool parsed = GCode::ParseValueXYZ(a, &_x, &_y, &_z, xymode, mmode);
    if(!parsed){
         st.addError(L("nincs pozíció adat"));
    };
    if(st.state()== ParseState::ParseError) return st;
    *p={_x,_y,_z};

    *p = GeoMath::Translation(*p, offset);
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

auto  Point::ToStringXY(qreal r) const -> QString
{
    return "x"+GCode::r(x*r)+'y'+GCode::r(y*r);
}

auto Point::ToStringXYZ() const -> QString
{
    return ToStringXY()+ToStringZ();
}

auto Point::ToStringXYZ(qreal r) const -> QString
{
    return ToStringXY(r)+ToStringZ();
}

void Point::Translate(const Point &r)
{
    x+=r.x;
    y+=r.y;
    z+=r.z;
}
