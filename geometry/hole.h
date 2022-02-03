#ifndef HOLE_H
#define HOLE_H

#include <QString>
#include "xymode.h"
#include "point.h"
#include "gcode/cut.h"
#include "gcode/feed.h"
#include "gap.h"
#include "parsestate.h"

struct Hole{
    static constexpr QChar key = 'h';
    static constexpr ushort keyUniCode= key.unicode();

    Hole();
    Hole(const Point& _p,
         qreal _diameter,
         Cut _cut,
         Feed _feed,
         const Gap& _gap,
         const Point& _rp={}
        );
    Point p;
    qreal diameter=-1;

    Cut cut={};
    Feed feed={};
    Point rp={};
//todo 70 name - kell mindennek név
    static ParseState Parse(const QString& txt, XYMode mode, Hole*);
    QString ToString() const;
    Gap gap;

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
