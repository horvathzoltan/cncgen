#ifndef LINE_H
#define LINE_H

#include <QString>
#include "point.h"
#include "gap.h"
#include <QList>
#include "gcode/cut.h"
#include "gcode/feed.h"

struct Line{
    Line();
    Line(const Point& _p0,
         const Point& _p1,
         Cut _cut,
         Feed _feed,
         const Point& _rp = {}
         );
    Point p0;
    Point p1;
    Cut cut;
    Feed feed;
    Point rp;

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
