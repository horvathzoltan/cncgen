#ifndef POINT_H
#define POINT_H

#include <QString>
#include "xymode.h"
#include "mmode.h"

struct Point{
    qreal x;
    qreal y;
    qreal z;

    Point();
    Point(qreal, qreal, qreal);

    static auto Parse(const QString &txt) -> ParseState;
    static auto Parse(const QString &txt, const QString& key) ->ParseState;
    static auto Parse(const QString&, XYMode xmode, MMode mmode,
                      const QString& key, Point *, Point *) -> ParseState;

    [[nodiscard]] auto ToString() const -> QString;
    [[nodiscard]] auto ToStringZ() const -> QString;
    [[nodiscard]] auto ToStringXY() const -> QString;
    [[nodiscard]] auto ToStringXY(qreal r) const -> QString;
    [[nodiscard]] auto ToStringXYZ() const -> QString;
    [[nodiscard]] auto ToStringXYZ(qreal r) const -> QString;

    auto operator ==(const Point& p) const -> bool {
        return x==p.x&&y==p.y&&z==p.z;
    }

    void Translate(const Point& r);
    /*ISVALID*/
public:
    [[nodiscard]] auto isValid() const -> bool {return _isValid;}
private:
    bool _isValid;

    /*LASTERR*/
//public:
//    static auto lasterr() -> QString {return _lasterr;}
//private:
//    static QString _lasterr;
};

#endif // POINT_H
