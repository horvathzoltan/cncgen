#ifndef HOLE_H
#define HOLE_H

#include <QString>
#include "xymode.h"
#include "point.h"

struct Hole{
    Point p;
    qreal d;
    qreal z;
    qreal s;
    qreal sp=-1;
    qreal f=-1;

    static Hole Parse(const QString& txt, XYMode mode);
    QString ToString();
};

#endif // HOLE_H
