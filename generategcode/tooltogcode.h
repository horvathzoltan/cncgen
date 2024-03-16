#ifndef TOOLTOGCODE_H
#define TOOLTOGCODE_H

#include "generategcode/togcodemodel.h"
#include "generategcode/totalstats.h"
#include <QString>
#include <gcode/cut.h>
#include <geometry/gap.h>


class ToolToGCode
{
public:
    static bool ParseTool(const QString& str, QString *gcode, QString *err, ToGCodeModel* mm,TotalStats *tss);

    static void SetToolToPen(QList<Point*> p, Gap *gap, Cut* c, Feed *feed,  ToGCodeModel *tmm);
    static QString SetToGCode(Tool m, QString *err,ToGCodeModel* mm,TotalStats *tss);
    static QString ChangeToGCode(ToGCodeModel *tmm,TotalStats *tss);
};

#endif // TOOLTOGCODE_H
