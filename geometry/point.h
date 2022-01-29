#ifndef POINT_H
#define POINT_H

#include <QString>
#include "xymode.h"
#include "gmode.h"

struct Point{
    qreal x;
    qreal y;
    qreal z;

    Point();
    Point(qreal, qreal, qreal);

    static Point Parse(const QString&, XYMode m);
    QString ToString() const;
    //QString ToGcode();
    QString GoToZ(GMode::Mode i);
    QString GoToXY(GMode::Mode i);
    QString GoToXYZ(GMode::Mode i);

    //QString LiftDown();
    //QString LiftUp(qreal mov_z);
    bool isValid(){return _isValid;}
private:
    bool _isValid;
};

#endif // POINT_H
