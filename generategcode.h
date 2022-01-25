#ifndef GENERATEGCODE_H
#define GENERATEGCODE_H

#include <QStringList>

class GenerateGcode
{
public:    
    static QStringList Generate(const QStringList& g);
private:
    static QString GenerateComment(const QString& txt);

    struct Point{
        qreal x;
        qreal y;
        qreal z;
    };

    struct Line{
        Point p0;
        Point p1;
        qreal z;
        qreal s;
    };

    static QString GenerateLineHorizontal(const QString& txt);
};

#endif // GENERATEGCODE_H
