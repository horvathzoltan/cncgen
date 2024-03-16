#ifndef BOXTOGCODE_H
#define BOXTOGCODE_H

#include "generategcode/togcodemodel.h"
#include "generategcode/totalstats.h"
#include <QString>

#include <geometry/arc.h>
#include <geometry/box.h>
#include <geometry/hole.h>
#include <geometry/line.h>

class BoxToGCode
{
public:
    static bool ParseBox(const QString& str, QString *gcode, QString *err, ToGCodeModel *tmm,TotalStats *tss);

    static QString CreateBox(const Box& m,QString*err, ToGCodeModel* mm,TotalStats *tss);
};

#endif // BOXTOGCODE_H
