#ifndef POINT_H
#define POINT_H

#include <QString>
#include "xymode.h"
#include "gmode.h"

struct Point{
    qreal x;
    qreal y;
    qreal z;

    Point();
    Point(qreal, qreal, qreal);

    static Point Parse(const QString&, XYMode m, const QString& key={});
    QString ToString() const;
    //QString ToGcode();
    QString GoToZ(GMode::Mode i);
    QString GoToXY(GMode::Mode i);
    QString GoToXYZ(GMode::Mode i);

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

#endif // POINT_H
