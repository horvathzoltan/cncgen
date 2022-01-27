#include "geomath.h"
#include <QtMath>

auto GeoMath::Divider(const Point &p0, const Point& p1, qreal o, Point *p3) -> bool
{
    if(p3==nullptr) return false;
    return uOsztopontXY(p0.x, p0.y, p0.z, p1.x, p1.y, p1.z, o, &p3->x, &p3->y, &p3->z);
}

auto GeoMath::uOsztopontXY(qreal p0x, qreal p0y, qreal p0z, qreal p1x, qreal p1y, qreal p1z, qreal o, qreal *x, qreal *y, qreal *z)->bool
{

    if(o){
        *x = p0x+(p1x-p0x)*o;
        *y = p0y+(p1y-p0y)*o;
        *z = p0z+(p1z-p0z)*o;
        return true;
    }
    return false;
}


auto GeoMath::Distance(const Point &p0, const Point& p1) -> qreal
{
    return uTavolsagXYZ(p0.x, p0.y, p0.z, p1.x, p1.y, p1.z);
}

auto GeoMath::uTavolsagXYZ(qreal p0x, qreal p0y, qreal p0z, qreal p1x, qreal p1y, qreal p1z)-> qreal
{
    qreal a = p1x-p0x;
    qreal b = p1y-p0y;
    qreal c = p1z-p0z;
    return qSqrt(a*a+b*b+c*c);
}
