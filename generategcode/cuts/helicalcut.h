#ifndef HELICALCUT_H
#define HELICALCUT_H



#include <QStringList>
#include <gcode/cut.h>
#include <gcode/feed.h>
#include <generategcode/togcodemodel.h>
#include <generategcode/totalstats.h>

class HelicalCut
{
public:
    static QStringList CreateCut(qreal path_r, const Feed& feed,const Cut& cut, bool a, bool aljasimi, bool isPeck, ToGCodeModel* mm, TotalStats *tss);
};

#endif // HELICALCUT_H
