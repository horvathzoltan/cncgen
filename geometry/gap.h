#ifndef GAP_H
#define GAP_H

#include <QString>
#include "geometry/xymode.h"

struct Gap{
    int n;
    qreal l;
    qreal h;

    static Gap Parse(const QString& txt);
    QString ToString();
};

#endif // GAP_H
