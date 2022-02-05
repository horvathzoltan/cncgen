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

auto GeoMath::ArcLength(const Point &p0, const Point& p1, const Point& o) -> qreal
{
    qreal d;
    uIvhossz(p0.x, p0.y, p0.z, p1.x, p1.y, p1.z, o.x, o.y, o.z, &d);
    return d;
}

auto GeoMath::uTavolsagXYZ(qreal p0x, qreal p0y, qreal p0z, qreal p1x, qreal p1y, qreal p1z)-> qreal
{
    qreal a = p1x-p0x;
    qreal b = p1y-p0y;
    qreal c = p1z-p0z;
    return qSqrt(a*a+b*b+c*c);
}

auto GeoMath::uSzog(qreal A1, qreal B1) -> qreal
{
    if(A1==0 && B1>0) {return 0;}
    if(A1>0 && B1==0) {return M_PI_2;}
    if(A1==0 && B1<0){return M_PI;}
    if(A1<0 && B1==0){return 1.5*M_PI;}
    if(A1>0 && B1>0){return atan(A1/B1);}
    if(B1<0 && A1!=0){return M_PI+atan(A1/B1);}
    return 2*M_PI+atan(A1/B1);
}

auto GeoMath::Polar(const Point &p0, const Point& p1, qreal szog, qreal tavolsag, Point *p3) ->bool
{
    if(p3==nullptr) return false;
    return uPolarisSZXY(p0.y, p0.x, p1.y, p1.x, szog, tavolsag, &p3->y, &p3->x);
}

auto GeoMath::uPolarisSZXY(qreal p0x, qreal p0y, qreal p1x, qreal p1y, qreal szog, qreal tavolsag, qreal *x, qreal *y)-> bool
{
    double A, B, alpha;

    A=p1y-p0y; // ez most irányvektor!!!
    B=p1x-p0x;
    alpha=uSzog(A,B); // irányszög
    *x=p0x+tavolsag*cos(alpha+szog);
    *y=p0y+tavolsag*sin(alpha+szog);
    return true;
}

auto GeoMath::uIvhossz(qreal p0x, qreal p0y, qreal p0z,
                       qreal p1x, qreal p1y, qreal p1z,
                       qreal ox,  qreal oy,  qreal oz,
                       qreal *l)-> bool
{
    double A, B, alpha;

    A=p1y-p0y; // ez most irányvektor!!!
    B=p1x-p0x;
    alpha=uSzog(A,B); // irányszög

    auto r = uTavolsagXYZ(p0x, p0x, p0z, ox, oy, oz);

    *l = alpha*r;

    return true;        
}

auto GeoMath::Translation(const Point&p, qreal x, qreal y, qreal z)->Point
{
    return {p.x+x, p.y+y, p.z+z};
}

auto GeoMath::Translation(const Point&p, const Point&q)->Point
{
    return Translation(p, q.x, q.y, q.z);
}
