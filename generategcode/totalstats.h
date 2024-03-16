#ifndef TOTALSTATS_H
#define TOTALSTATS_H

#include "qglobal.h"
#include <QString>

struct TotalStats{
    qreal _total_minutes; //mm per perc
    qreal _total_length;
    qreal _total_cut;

    QString TotalTimeToGCode();

    static qreal MinToMilliSec(qreal a);
    static qreal MilliSecToMin(qreal a);
    
    void Reset();
};

#endif // TOTALSTATS_H
