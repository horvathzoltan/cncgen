#ifndef LINETOGCODE_H
#define LINETOGCODE_H

#include "generategcode/togcodemodel.h"
#include "generategcode/totalstats.h"
#include <QString>

#include <geometry/arc.h>
#include <geometry/box.h>
#include <geometry/hole.h>
#include <geometry/line.h>

class LineToGCode
{
public:
    static bool ParseLine(const QString& str, QString *gcode, QString *err, ToGCodeModel *tmm,TotalStats *tss);

    static QString CreateLine(const Line& m,QString *err, ToGCodeModel* tmm, TotalStats *tss);
    static QString CreateLines(const QList<Line>& m,QString *err,ToGCodeModel* mm,TotalStats *tss);

};

#endif // LINETOGCODE_H
