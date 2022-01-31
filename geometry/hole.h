#ifndef HOLE_H
#define HOLE_H

#include <QString>
#include "xymode.h"
#include "point.h"
#include "gcode/cut.h"
#include "gcode/feed.h"

struct Hole{
    Hole();
    Hole(const Point& _p,
         qreal _diameter,
         Cut _cut,
         Feed _feed,
        const Point& _rp={}
        );
    Point p;
    qreal diameter=-1;

    Cut cut={};
    Feed feed={};
    Point rp={};
//todo 7 name - kell mindennek név
    static Hole Parse(const QString& txt, XYMode mode);
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

#endif // HOLE_H
