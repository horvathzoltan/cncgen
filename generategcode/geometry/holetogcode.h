#ifndef HOLETOGCODE_H
#define HOLETOGCODE_H

#include "generategcode/togcodemodel.h"
#include "generategcode/totalstats.h"
#include <QString>

#include <geometry/arc.h>
#include <geometry/box.h>
#include <geometry/hole.h>
#include <geometry/line.h>

class HoleToGCode
{
public:
    static bool ParseHole(const QString& str, QString *gcode, QString *err, ToGCodeModel *tmm,TotalStats *tss);

    static QString CreateHole(const Hole& m,QString*err, ToGCodeModel* mm,TotalStats *tss);
};

#endif // HOLETOGCODE_H
