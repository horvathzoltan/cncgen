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

    static ParseState Parse(const QString &txt);
    static ParseState Parse(const QString &txt, const QString& key);
    static ParseState Parse(
        const QString&, XYMode xmode, MMode mmode,const QString& key, Point *);
    static ParseState Parse(
        const QString&, XYMode xmode, MMode mmode,const QString& key, Point *,const Point& offset);


    [[nodiscard]] QString ToString() const;
    [[nodiscard]] QString ToStringZ() const;
    [[nodiscard]] QString ToStringXY() const;
    [[nodiscard]] QString ToStringXY(qreal r) const;
    [[nodiscard]] QString ToStringXYZ() const;
    [[nodiscard]] QString ToStringXYZ(qreal r) const;

    auto operator ==(const Point& p) const -> bool {
        return x==p.x&&y==p.y&&z==p.z;
    }

    void Translate(const Point& r);
    void Reset(){x=0;y=0;z=0;}

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
