#ifndef GENERATEGCODE_H
#define GENERATEGCODE_H

#include <QStringList>
#include <QVariant>

class GenerateGcode
{
public:
    QStringList Generate(const QStringList& g);
private:
    enum XYMode:int{XY=0,YX};

    enum GMode:int{Rapid=0,Linear=1,Circular=2};

    XYMode _XYMode = XY;
    QStringList gcodes;
    qreal _movZ=10;

    bool AppendGcode(const QString &g);
    bool setXYMode(const QString &txt);

    QString GenerateComment(const QString& txt);

    struct Point{
        qreal x;
        qreal y;
        qreal z;

        static Point Parse(const QString&, XYMode m);
        QString ToString();
        //QString ToGcode();
        QString GoToZ(GMode i);
        QString GoToXY(GMode i);
        QString GoToXYZ(GMode i);

        //QString LiftDown();
        //QString LiftUp(qreal mov_z);

    };

    struct Line{
        Point p0;
        Point p1;
        qreal z;
        qreal s;

        static Line Parse(const QString&, XYMode m);
        QString ToString();
    };

    struct Hole{
        Point p;
        qreal d;
        qreal z;
        qreal s;

        static Hole Parse(const QString&, XYMode m);
        QString ToString();
    };

    QString GenerateLineHorizontal(const QString& txt);
    QString GenerateHole(const QString& txt);
    Point ParsePoint(const QString&txt);
    Line ParseLine(const QString&txt);
    static QString rToGcode(qreal);
    static QString Gcode(GMode i);
    QString LiftDown(qreal z);
    QString LiftUp(QVariant z);
    QString TravelXY(Point p);
};

#endif // GENERATEGCODE_H
