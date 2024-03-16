#ifndef CIRCULARARCCUT_H
#define CIRCULARARCCUT_H


#include "generategcode/togcodemodel.h"
#include "generategcode/totalstats.h"
#include <QStringList>
#include <gcode/cut.h>
#include <gcode/feed.h>

class CircularArcCut
{
public:
    static QStringList CreateCut(const Feed& feed,const Cut& cut, bool no_simi, ToGCodeModel* mm,TotalStats *tss);
};

#endif // CIRCULARARCCUT_H
