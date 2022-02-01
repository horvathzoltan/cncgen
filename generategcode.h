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
    bool CheckCut(QString*err);
private:
    bool _verbose = true;
    XYMode _XYMode = XY;
    QStringList gcodes;
    qreal _movZ=10;
    qreal _maxZ=15;        

    QMap<int, Tool> _tools;    
    int _selected_tool_ix;

// todo f1 Machine osztály ami az utolsó előtolás, fogás és a szerszám pozíciót tudja
// innen lehet tudni, hogy fel kell-e emelni vagy le kell e süllyeszteni amikor azt kérik

    Feed _selected_feed;
    Cut _selected_cut;

    int _last_tool_ix = -1;
    Feed _last_feed;    
    Cut _last_cut;

// todo f0 PositionRepo osztály, amiben vannak pozíció listák és a last(type) adja az utolsó aktuális elemet
// innen lehet tudni, hogy egy furatot elkészítettünk, oda másik ugyanolyat már nem kell kifúrni
    Point _lastHoleP;
    qreal _last_hole_diameter;

    Point _lastLineP0;
    Point _lastLineP1;

    Point _lastBoxP0;
    Point _lastBoxP1;
    BoxType::Type _lastBoxType;

    //VariableRepository _variables;
    bool AppendGcode(const QString &g, const QString& err);
    auto setXYMode(const QString &txt) -> bool;

    QString GenerateComment(const QString& txt);

    /*Geomerty*/
    bool ValidateTool();
    QString GenerateLineHorizontal(const QString& txt,QString *err);
    QString GenerateLineHorizontal(const Line& m,QString *err);
    QString GenerateHole(const QString& txt,QString*err);
    QString GenerateHole(const Hole& m,QString*err);
    QString GenerateBox(const QString& txt,QString*err);
    QString GenerateBox(const Box& m,QString*err);
    QString GeneratePrintString(const QString& txt);
    QString GeneratePrintString(const String& m);
    QString GenerateArc(const Point &p0, const Point& p1, const Point&o, qreal h ,QString*err);
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
    //QString lasterr(){return _lasterr;};
private:
    //QString _lasterr;
};

#endif // GENERATEGCODE_H
