#ifndef XYMODETOGCODE_H
#define XYMODETOGCODE_H

#include "togcodemodel.h"

#include <QString>


class XYModeToGCode
{
public:
    static bool ParseXYMode(const QString& str, QString *gcode, QString *err, ToGCodeModel* tmm);

    static QString SetXYModeToGCode(ToGCodeModel* tmm);
};

#endif // XYMODETOGCODE_H
