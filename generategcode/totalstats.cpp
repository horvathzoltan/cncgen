#include "totalstats.h"


qreal TotalStats::MinToMilliSec(qreal a){
    return a*60000;
}

qreal TotalStats::MilliSecToMin(qreal a){
    return a/60000;
}

void TotalStats::Reset()
{
    _total_minutes=0;
    _total_length=0;
    _total_cut=0;
}

QString TotalStats::TotalTimeToGCode()
{
    return "(time[min]: "+QString::number(_total_minutes)+")";
}
