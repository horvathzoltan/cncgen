#ifndef GENERATEGCODE_H
#define GENERATEGCODE_H

#include <QStringList>

class GenerateGcode
{
public:
    QStringList Generate(const QStringList& g);
private:
    enum XYMode:int{XY=0,YX};

    XYMode _XYMode = XY;
    QStringList gcodes;

    bool AppendGcode(const QString &g);
    bool setXYMode(const QString &txt);

    QString GenerateComment(const QString& txt);

    struct Point{
        qreal x;
        qreal y;
        qreal z;

        static Point Parse(const QString&, XYMode m);
        QString ToString();
    };

    struct Line{
        Point p0;
        Point p1;
        qreal z;
        qreal s;

        static Line Parse(const QString&, XYMode m);
        QString ToString();
    };

    QString GenerateLineHorizontal(const QString& txt);
    QString GenerateHole(const QString& txt);
    Point ParsePoint(const QString&txt);
    Line ParseLine(const QString&txt);
};

#endif // GENERATEGCODE_H
