#ifndef GCODE_H
#define GCODE_H

#include <QString>
#include "geometry/xymode.h"
#include "geometry/boxtype.h"

class GCode{
public:
    static QString r(qreal x);
    static QString i(int x);
    static bool ParseValue(const QString&p, const QString&key, qreal*v);
    static bool ParseValue(const QString&p, const QString&key, int*v);
    static bool ParseValue(const QString&p, const QString&key, QString*v);
    static bool ParseValueXYZ(const QString &p, qreal *x, qreal*y, qreal *z, XYMode mode);
    //static bool ParseValue(const QString&p, BoxType::Type *v);
};

#endif // GCODE_H
