#ifndef LIFT_H
#define LIFT_H

#include "generategcode/togcodemodel.h"
#include "generategcode/totalstats.h"
#include "qglobal.h"

#include <QVariant>
class Lift
{
public:
    static QString Up(qreal feed, const QVariant& z,ToGCodeModel *tmm,TotalStats *tss);
    static QString Down(qreal feed, qreal z,ToGCodeModel *tmm,TotalStats *tss);
};

#endif // LIFT_H
