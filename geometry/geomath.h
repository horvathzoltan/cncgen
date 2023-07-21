#ifndef GEOMATH_H
#define GEOMATH_H

#include <geometry/point.h>

class GeoMath
{
public:
    static bool Divider(const Point &p0, const Point& p1, qreal o, Point *p3);
    static qreal Distance(const Point &p0, const Point& p1);
    static bool Polar(const Point &p0, const Point& p1, qreal szog, qreal tavolsag, Point *p3);
    static qreal ArcLength(const Point &p0, const Point &p1, const Point &o);
    static Point Translation(const Point &p, const Point& p2);
    static Point Translation(const Point &p, qreal x, qreal y, qreal z=0);
private:
    static qreal uSzog(qreal A1, qreal B1);
    static qreal uSzog2(qreal A1, qreal B1);
    static bool uOsztopontXY(qreal p0x, qreal p0y, qreal p0z, qreal p1x, qreal p1y, qreal p1z, qreal o, qreal *x, qreal *y, qreal *z);
    static qreal uTavolsagXYZ(qreal p0x, qreal p0y, qreal p0z, qreal p1x, qreal p1y, qreal p1z);
    static bool uPolarisSZXY(qreal p0x, qreal p0y, qreal p1x, qreal p1y, qreal szog, qreal tavolsag, qreal *x, qreal *y);
    static bool uIvhossz(qreal p0x, qreal p0y, qreal p0z, qreal p1x, qreal p1y, qreal p1z, qreal ox, qreal oy, qreal oz, qreal *l);
    static qreal uSzog3D(qreal p0x, qreal p0y, qreal p0z,
                  qreal p1x, qreal p1y, qreal p1z,
                  qreal ox,  qreal oy,  qreal oz);
};


#endif // GEOMATH_H
/*
 * double uSzog(double A1, double B1){
  double alpha1;

if(A1==0 && B1>0)
    alpha1=0;
else if(A1>0 && B1==0)
    alpha1=PI/2;
else if(A1==0 && B1<0)
    alpha1=PI;
else if(A1<0 && B1==0)
    alpha1=1.5*PI;
else if(A1>0 && B1>0)
    alpha1=atan(A1/B1);
else if(B1<0 && A1!=0)
    alpha1=PI+atan(A1/B1);
else
    alpha1=2*PI+atan(A1/B1);

return alpha1;
}

void uPolarisSZXY(double p0x, double p0y, double p1x, double p1y, double szog, double tavolsag, double *x, double *y){
  double A, B, alpha;

    A=p1y-p0y; // ez most irányvektor!!!
    B=p1x-p0x;
    alpha=uSzog(A,B); // irányszög
    *x=p0x+tavolsag*cos(alpha+szog);
    *y=p0y+tavolsag*sin(alpha+szog);
  }

unsigned int uKorskalazas(unsigned int flag, unsigned int param2){
  uTabla pl;
  double x, y, mm;
  unsigned int i, ix;
  uPontLista *k;
  KPR *kpr;

kpr = umap->muvbuf;
if(kpr->n<2 || kpr->n == NULL_INT)
    return ADATHIBA;
uTablaInit(&pl, sizeof(uPontLista));
  uKijelolt2PontLista(&umap->kijelolt, &pl);
k = (uPontLista*)(pl.tabla);
mm = (2*PI)/kpr->n;
for(i=0;i<kpr->n;i++){
    uPolarisSZXY(k->x, k->y, k->x+100, k->y, (double)i*mm, kpr->r, &x, &y);
    if(!uPontLetrehoz(x, y, k->h, kpr->pontszam, kpr->kod, &ix, ELO | DAT)){
        uFree(&pl);
        return HIBA;
    }
    if((kpr->nov != NULL_INT) && (kpr->pontszam != NULL_INT))
        kpr->pontszam+=kpr->nov;
}
uFree(&pl);
return UJ;
}
*/
