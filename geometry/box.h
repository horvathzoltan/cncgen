#ifndef BOX_H
#define BOX_H

#include <QList>
#include "gap.h"
#include "line.h"
#include "boxtype.h"

struct Box{
    Box();
    Box(const Point& _p0,
        const Point& _p1,
        const Gap& _gap,
        BoxType::Type _type,
        Cut _cut,
        qreal _corner_diameter,
        Feed _feed
        );

    QList<Line> lines;
    Point p0;
    Point p1;
    Gap gap;
    BoxType::Type type = BoxType::Outline;
    Cut cut;
    qreal corner_diameter=-1;
    // todo 4 struct ToolSpeed
    Feed feed;

    static Box Parse(const QString& txt, XYMode mode);
    QString ToString() const;

    /*ISVALID*/
public:
    bool isValid() const {return _isValid;}
private:
    bool _isValid;

    /*LASTERR*/
public:
    static QString lasterr(){return _lasterr;}
private:
    static QString _lasterr;
};



#endif // BOX_H
