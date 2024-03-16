#ifndef LINEARCUT_H
#define LINEARCUT_H

#include "generategcode/togcodemodel.h"
#include <gcode/cut.h>
#include <gcode/feed.h>
#include <generategcode/totalstats.h>


class LinearCut
{
public:
    static QStringList CreateCut(const Feed& feed, const Cut& cut, bool no_compensate, int menet, bool no_simi, ToGCodeModel* mm,TotalStats *tss);
};

#endif // LINEARCUT_H
