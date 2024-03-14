#ifndef LASTGEOM_H
#define LASTGEOM_H

#include <geometry/boxtype.h>
#include <geometry/point.h>


class LastGeom
{
public:
    LastGeom();

    struct LastLine{
        Point p0;
        Point p1;

        QString toString();
    };


    struct LastBox{
        Point p0;
        Point p1;
        BoxType::Type type;

        qreal Diastance();
    };



    struct LastArc{
        Point p0;
        Point p1;
        Point o;

        QString toString();
        qreal ArcLength();
    };

    Point _last_position;
    LastLine _lastLine;
    LastBox _lastBox;
    LastArc _lastArc;

//private:

public:
    void Reset();
};

#endif // LASTGEOM_H
