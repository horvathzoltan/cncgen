#ifndef SPINDLE_H
#define SPINDLE_H

#include "generategcode/togcodemodel.h"
#include "qglobal.h"
class Spindle
{
public:
    static QString StartToGCode(qreal spindle_speed, ToGCodeModel *tmm);
    static QString StopToGCode(ToGCodeModel *tmm);

    static bool SetSpeedToGCode(qreal spindle_speed, QString *g, QString *err, ToGCodeModel *tmm);
};

#endif // SPINDLE_H
