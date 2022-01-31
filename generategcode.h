#ifndef GENERATEGCODE_H
#define GENERATEGCODE_H

#include <QStringList>
#include <QVariant>

#include "geometry/line.h"
#include "geometry/box.h"
#include "geometry/hole.h"

#include "gcode/tool.h"
#include "gcode/variable.h"
#include "gcode/string.h"

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
    Feed _selected_feed;
    Cut _selected_cut;

    int _last_tool_ix = -1;
    Feed _last_feed;
    qreal _last_hole_diameter;
    Cut _last_cut;


    Point _lastHoleP;

    Point _lastLineP0;
    Point _lastLineP1;

    Point _lastBoxP0;
    Point _lastBoxP1;

    //VariableRepository _variables;
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
    QString GeneratePrintString(const QString& txt);
    QString GeneratePrintString(const String& m);

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
    QString lasterr(){return _lasterr;};
private:
    QString _lasterr;
};

#endif // GENERATEGCODE_H
