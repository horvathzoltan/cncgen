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

auto GeoMath::uSzog2(qreal A1, qreal B1) -> qreal
{
    if(B1==0) return M_PI_2;
    return atan(A1/B1);
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

// b-nél lévő szög
 qreal GeoMath::uSzog3D(qreal p0x, qreal p0y, qreal p0z,
                qreal cx, qreal cy, qreal cz,
                qreal p1x,  qreal p1y,  qreal p1z)

{
    // qreal abx = bx - ax;
    // qreal aby = by - ay;
    // qreal abz = bz - az;

    // qreal bcx = cx - bx;
    // qreal bcy = cy - by;
    // qreal bcz = cz - bz;

    // double abVec = sqrt(abx * abx + aby * aby + abz * abz);
    // double bcVec = sqrt(bcx * bcx + bcy * bcy + bcz * bcz);

    // double abNormx = abx / abVec;
    // double abNormy = aby / abVec;
    // double abNormz = abz / abVec;

    // double bcNormx = bcx / bcVec;
    // double bcNormy = bcy / bcVec;
    // double bcNormz = bcz / bcVec;

    // double res = abNormx * bcNormx + abNormy * bcNormy + abNormz * bcNormz;

    // qreal a = acos(res);
    // return a;

     qreal p0c = sqrt(pow(cx-p0x,2)+pow(cy-p0y,2)); // p0->c (b)
     qreal p1c = sqrt(pow(cx-p1x,2)+pow(cy-p1y,2)); // p1->c (a)
     qreal p0p1 = sqrt(pow(p1x-p0x,2)+pow(p1y-p0y,2)); // p0->p1 (c)
     qreal a = acos((p1c*p1c+p0c*p0c-p0p1*p0p1)/(2*p1c*p0c));
     return a;

    // z1 = 0;
    // z2 = 0;
    // z3 = 0;
    // float dot_product = (x1-x2)*(x2-x3) + (y1-y2)*(y2-y3)+ (z1-z2)*(z2-z3);
    // float mod_denom1 = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
    // float mod_denom2 = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3) + (z2-z3)*(z2-z3));
    // float cosnum = (dot_product/((mod_denom1)*(mod_denom2)));
    // float cos = acos(cosnum);
    // return cos;
}

auto GeoMath::uIvhossz(qreal p0x, qreal p0y, qreal p0z,
                       qreal p1x, qreal p1y, qreal p1z,
                       qreal ox,  qreal oy,  qreal oz,
                       qreal *l)-> bool
{
    auto alpha = uSzog3D(
        p0x, p0y, p0z,
        ox, oy, oz,
        p1x, p1y, p1z);

    auto r = uTavolsagXYZ(p0x, p0y, p0z, ox, oy, oz);

    *l = r*alpha;

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
