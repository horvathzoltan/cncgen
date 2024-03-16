#include "compensation.h"

bool Compensation::Compensate(qreal l, qreal z, qreal *z_out, qreal *f_out, qreal f_in, ToGCodeModel* mm)
{
    //qreal r = l/100;
    qreal e = z/l; // aktuális fogás
    qreal f = f_in;
    qreal rf = mm->_fmax/f;
    qreal emax = mm->_emax*rf; // max fogás az akt sebességnél: ennyi lehetne

    if(emax>=e){
        //ok, megeszi
        return false;
    }

    qreal r = e/emax;

    qreal f2 = f/r;
    if(f2>=mm->_fmin){
        *z_out=z;
        *f_out=f2;
        return true;
    }
    // túl lassú lenne le kell csökkenteni a fogást

    //if(_fratio<=0.5) _fratio=0.5;
    qreal rf2 = rf*mm->_fratio;
    *z_out=(z/r)/rf2;
    *f_out=f_in*rf2;
    return true;
}

Compensation::CompensateModel Compensation::Compensate2(qreal l, const Cut& cut, const Feed& feed, ToGCodeModel* mm){
    CompensateModel c;

    c.isCompensated = Compensate(l, cut.z0, &c.c_z, &c.c_f, feed.feed(), mm);

    return c;
}

void Compensation::CompensateModel::ToGCode(GCodeManager* g, const Cut& o_cut, const Feed& o_feed){
    if(isCompensated){
        if(c_z!=o_cut.z0){
            QString gc1 = QStringLiteral("compensate cut: %1 -> %2").arg(o_cut.z0).arg(c_z);
            g->append("("+gc1+")");
        }
        if(c_f!=o_feed.feed()){
            QString gc0 = QStringLiteral("compensate feed: %1 -> %2").arg(o_feed.feed()).arg(c_f);
            g->append("("+gc0+")");
        }
    }
}
