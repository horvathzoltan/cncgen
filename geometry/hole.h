#ifndef HOLE_H
#define HOLE_H

#include <QString>
#include "xymode.h"
#include "point.h"

struct Hole{
    Hole();
    Hole(const Point& _p,
        qreal _cutZ,
        qreal _cutZ0,
        qreal _diameter,
        // todo 4 struct ToolSpeed
        qreal _spindleSpeed,
        qreal _feed,
        const Point& _rp={}
        );
    Point p;
    qreal diameter=-1;
    qreal cutZ=-1;
    qreal cutZ0=-1;
    qreal spindleSpeed=-1;
    qreal feed=-1;
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
