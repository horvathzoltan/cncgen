#ifndef GENERATEGCODE_H
#define GENERATEGCODE_H

#include <QStringList>
#include <QVariant>

#include "geometry/line.h"
#include "geometry/box.h"
#include "geometry/hole.h"

#include "gcode/tool.h"

class GenerateGcode
{
public:
    QStringList Generate(const QStringList& g);
private:
    bool _verbose = true;
    XYMode _XYMode = XY;
    QStringList gcodes;
    qreal _movZ=10;
    qreal _maxZ=15;

    QMap<int, Tool> _tools;
    int _selected_tool_ix;
    int _selected_feed_rate;
    int _selected_spindle_speed;

    int _last_tool_ix = -1;
    qreal _last_feed_rate = -1;
    qreal _last_spindle_speed = -1;
    qreal _last_hole_diameter;
    qreal _last_cutZ;
    qreal _last_cutZ0;

    bool AppendGcode(const QString &g);
    bool setXYMode(const QString &txt);

    QString GenerateComment(const QString& txt);

    /*Geomerty*/
    bool ValidateTool();
    QString GenerateLineHorizontal(const QString& txt);
    QString GenerateLineHorizontal(const Line& m);
    QString GenerateHole(const QString& txt);
    QString GenerateHole(const Hole& m);
    QString GenerateBox(const QString& txt);
    QString GenerateBox(const Box& m);
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

};

#endif // GENERATEGCODE_H
