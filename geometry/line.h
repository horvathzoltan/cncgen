#ifndef LINE_H
#define LINE_H

#include <QString>
#include "point.h"
#include "gap.h"
#include <QList>

struct Line{
    Line();
    Line(const Point& _p0,
         const Point& _p1,
         qreal _cutZ,
         qreal _cutZ0,
         //qreal _diameter,
         // todo 4 struct ToolSpeed
         qreal _spindleSpeed,
         qreal _feed
         );
    Point p0;
    Point p1;
    qreal cutZ;
    qreal cutZ0;
    qreal spindleSpeed=-1;
    qreal feed=-1;

    static Line Parse(const QString& txt, XYMode mode);
    QString ToString() const;
    QList<Line> Divide(const Gap& g, qreal tool_d);

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


#endif // LINE_H
