#ifndef GOTO_H
#define GOTO_H

#include "generategcode/togcodemodel.h"
#include "generategcode/totalstats.h"
#include "gcodemanager.h"
#include <QString>

#include <geometry/gmode.h>
#include <geometry/point.h>

#include <QVariant>


class GoTo
{
public:
    enum LengthMode:int{XYZ=0,XY,Z};

    struct IJModel{
        qreal i;
        qreal j;
    };

    static const qreal RFEED;
    static qreal t_muvelet;
    /*moves*/

    static QString GoToXY(GMode::Mode, const Point& p, qreal feed,ToGCodeModel *tmm,TotalStats *tss, IJModel ij);
    static QString GoToZ(GMode::Mode, const Point& p, qreal feed,ToGCodeModel *tmm,TotalStats *tss);
    static QString GoToXYZ(GMode::Mode, const Point& p, qreal feed,ToGCodeModel *tmm,TotalStats *tss, IJModel ij);

    static void GoToCutposition(GCodeManager *g, const Point& p, const Feed& feed,ToGCodeModel *tmm,TotalStats *tss);

    static qreal GetLength(GMode::Mode i, const Point& p, GoTo::LengthMode lm, ToGCodeModel* tmm, IJModel ij);

    static QString TravelXYToGCode(qreal feed, const Point& p,ToGCodeModel *tmm,TotalStats *tss);

};

#endif // GOTO_H
