#ifndef BOX_H
#define BOX_H

#include <QList>
#include "gap.h"
#include "line.h"
#include "boxtype.h"

struct Box{    
    QList<Line> lines;
    Point p0;
    Point p1;
    Gap gap;
    BoxType::Type type = BoxType::Outline;
    qreal cutZ;
    qreal cutZ0;
    qreal corner_diameter=-1;
    // todo 4 struct ToolSpeed
    qreal spindleSpeed=-1;
    qreal feed=-1;

    static Box Parse(const QString& txt, XYMode mode);
    QString ToString() const;

    bool isValid(){return _isValid;}
private:
    bool _isValid;
};



#endif // BOX_H
