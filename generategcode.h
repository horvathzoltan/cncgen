#ifndef GENERATEGCODE_H
#define GENERATEGCODE_H

#include <QStringList>
#include <QVariant>

#include "geometry/line.h"
#include "geometry/box.h"


class GenerateGcode
{
public:
    QStringList Generate(const QStringList& g);
private:    


    XYMode _XYMode = XY;
    QStringList gcodes;
    qreal _movZ=10;
    qreal _maxZ=15;

    enum ToolType:int{None,Milling,Drilling};

    struct Tool{
        ToolType type=None;
        int ix=-1;
        qreal d;
        qreal h;

        static Tool Parse(const QString&);
        QString ToString();
    };

    QMap<int, Tool> _tools;
    int _selected_tool_ix;
    int _selected_feed_rate;
    int _selected_spindle_speed;

    int _last_tool_ix = -1;
    qreal _last_feed_rate = -1;
    qreal _last_spindle_speed = -1;

    bool AppendGcode(const QString &g);
    bool setXYMode(const QString &txt);

    QString GenerateComment(const QString& txt);        




    struct Hole{
        Point p;
        qreal d;
        qreal z;
        qreal s;
        qreal sp=-1;
        qreal f=-1;

        static Hole Parse(const QString& txt, XYMode mode);
        QString ToString();
    };   


    /*Geomerty*/
    QString GenerateLineHorizontal(const QString& txt);
    QString GenerateHole(const QString& txt);
    QString GenerateBox(const QString& txt);
    /*G Command*/
    QString SetTool(const QString& txt);
    QString SetFeedRate(const QString& txt);
    QString SetSpindleSpeed(const QString& txt);
    QString SetSpindleSpeed();
    QString ChangeTool();
    QString SpindleStart();
    QString SpindleStop();
    QString SetFeed();
    /*Parse*/
    Point ParsePoint(const QString&txt);
    Line ParseLine(const QString&txt);
    Hole ParseHole(const QString&txt);
    Box ParseBox(const QString&txt);
    /*ToGcode*/
    QString LiftDown(qreal z);
    QString LiftUp(const QVariant& z);
    //QString LiftUp(Point p);
    QString TravelXY(Point p);
    static QChar ToolTypeToGCode(ToolType t);
    static QString ToolTypeToString(ToolType t);
};

#endif // GENERATEGCODE_H
