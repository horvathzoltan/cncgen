#ifndef GEOMATH_H
#define GEOMATH_H

#include <geometry/point.h>

class GeoMath
{
public:
    static bool Divider(const Point &p0, const Point& p1, qreal o, Point *p3);
    static qreal Distance(const Point &p0, const Point& p1);
private:
    static bool uOsztopontXY(qreal p0x, qreal p0y, qreal p0z, qreal p1x, qreal p1y, qreal p1z, qreal o, qreal *x, qreal *y, qreal *z);
    static qreal uTavolsagXYZ(qreal p0x, qreal p0y, qreal p0z, qreal p1x, qreal p1y, qreal p1z);
};

#endif // GEOMATH_H
