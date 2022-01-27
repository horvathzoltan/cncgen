#ifndef BOX_H
#define BOX_H


#include <QList>
#include "gap.h"
#include "line.h"

struct Box{
    QList<Line> lines;
    Point p0;
    Point p1;
    Gap g;
    bool isOut=true;
    qreal z;
    qreal s;
    qreal sp=-1;
    qreal f=-1;

    static Box Parse(const QString& txt, XYMode mode);
    QString ToString();
};

#endif // BOX_H
