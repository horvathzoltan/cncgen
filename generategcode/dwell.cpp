#include "dwell.h"

QString Dwell::CreateDwell(int p,TotalStats *tss)
{
    qreal t0_mins = p/1000;
    tss->_total_minutes+=t0_mins;
    auto str =  "G04 P"+QString::number(p);

    return str;
}
