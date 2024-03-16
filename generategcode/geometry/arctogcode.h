#ifndef ARCTOGCODE_H
#define ARCTOGCODE_H

#include "generategcode/togcodemodel.h"
#include "generategcode/totalstats.h"
#include <QString>

#include <geometry/arc.h>
#include <geometry/box.h>
#include <geometry/hole.h>
#include <geometry/line.h>

class ArcToGCode
{
public:
    static bool ParseArc(const QString& str, QString *gcode, QString *err, ToGCodeModel *tmm,TotalStats *tss);
    static QString CreateArc(const Arc& m,QString*err, ToGCodeModel* mm,TotalStats *tss);
};

#endif // ARCTOGCODE_H
