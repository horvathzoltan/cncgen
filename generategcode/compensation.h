#ifndef COMPENSATION_H
#define COMPENSATION_H

#include "gcode/cut.h"
#include "gcode/feed.h"
#include "generategcode/gcodemanager.h"
#include "qglobal.h"
#include "togcodemodel.h"

class Compensation
{
public:
    enum CompensationMode:int{none=0, speed=1, depth=2};

    struct CompensateModel{
        qreal c_f = -1;
        qreal c_z = -1;
        bool isCompensated;

        void ToGCode(GCodeManager* g, const Cut& o_cut, const Feed& o_feed);
    };

    static bool Compensate(qreal l, qreal z, qreal *s3, qreal *f3, qreal f_in, ToGCodeModel *m);
    static CompensateModel Compensate2(qreal l, const Cut& cut, const Feed& feed, ToGCodeModel *m);

};

#endif // COMPENSATION_H
