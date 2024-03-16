// #include "compensate.h"


// bool Compensation::Compensate(qreal l, qreal z, qreal *z_out, qreal *f_out, qreal f_in, ToGCodeModel* mm)
// {
//     //qreal r = l/100;
//     qreal e = z/l; // aktuális fogás
//     qreal f = f_in;
//     qreal rf = _toGCodeModel._fmax/f;
//     qreal emax = _emax*rf; // max fogás az akt sebességnél: ennyi lehetne

//     if(emax>=e){
//         //ok, megeszi
//         return false;
//     }

//     qreal r = e/emax;

//     qreal f2 = f/r;
//     if(f2>=_toGCodeModel._fmin){
//         *z_out=z;
//         *f_out=f2;
//         return true;
//     }
//     // túl lassú lenne le kell csökkenteni a fogást

//     //if(_fratio<=0.5) _fratio=0.5;
//     qreal rf2 = rf*_fratio;
//     *z_out=(z/r)/rf2;
//     *f_out=f_in*rf2;
//     return true;
// }
