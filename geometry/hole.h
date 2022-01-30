#ifndef HOLE_H
#define HOLE_H

#include <QString>
#include "xymode.h"
#include "point.h"

struct Hole{
    Hole();
    Hole(const Point& _p,
        qreal _cutZ,
        qreal _cutZ0,
        qreal _diameter,
        // todo 4 struct ToolSpeed
        qreal _spindleSpeed,
        qreal _feed
        );
    Point p;
    qreal diameter=-1;
    qreal cutZ=-1;
    qreal cutZ0=-1;
    qreal spindleSpeed=-1;
    qreal feed=-1;

    static Hole Parse(const QString& txt, XYMode mode);
    QString ToString() const;
    bool isValid(){return _isValid;}
private:
    bool _isValid;
};

#endif // HOLE_H
