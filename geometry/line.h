#ifndef LINE_H
#define LINE_H

#include <QString>
#include "point.h"
#include "gap.h"
#include <QList>

struct Line{
    Point p0;
    Point p1;
    qreal z;
    qreal s;
    qreal sp=-1;
    qreal f=-1;

    static Line Parse(const QString& txt, XYMode mode);
    QString ToString() const;
    QList<Line> Divide(const Gap& g, qreal tool_d);
};


#endif // LINE_H
