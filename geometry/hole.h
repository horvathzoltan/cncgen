#ifndef HOLE_H
#define HOLE_H

#include <QString>
#include "xymode.h"
#include "point.h"

struct Hole{
    Point p;
    qreal diameter=-1;
    qreal cutZ=-1;
    qreal cutZ0=-1;
    qreal spindleSpeed=-1;
    qreal feed=-1;

    static Hole Parse(const QString& txt, XYMode mode);
    QString ToString() const;
};

#endif // HOLE_H
