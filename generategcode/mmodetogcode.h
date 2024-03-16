#ifndef MMODETOGCODE_H
#define MMODETOGCODE_H

#include "togcodemodel.h"

#include <QString>


class MModeToGCode
{
public:
    static bool ParseMMode(const QString &str, QString *gcode, QString *err, ToGCodeModel *tmm);
};

#endif // MMODETOGCODE_H
