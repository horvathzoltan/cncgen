#ifndef GENERATEGCODE_H
#define GENERATEGCODE_H

#include <QStringList>
#include <QVariant>

#include "geometry/line.h"
#include "geometry/box.h"
#include "geometry/hole.h"
#include "geometry/arc.h"

#include "gcode/tool.h"
#include "gcode/variable.h"
#include "gcode/string.h"
#include "parsestate.h"
#include "geometry/gmode.h"
#include "common/macrofactory/macro.h"

class GenerateGcode
{
public:
    static const QString G1;
    static const QString G2;
    static const QString T1;
    static const QString T_ERR;
    static const QString T_W;

    auto Generate(const QStringList& g) -> QStringList;
    auto AppendGCode(QStringList* gs, const QString &g, const QString& err={},const QString& comment={}) -> bool;
    qreal _total_time;
    qreal _total_length;
    qreal _total_cut;
private:
    bool _verbose = true;
    XYMode _XYMode;
    QStringList gcodes;
    qreal _movZ=10;
    qreal _maxZ=15;

    QMap<int, Tool> _tools;    
    int _selected_tool_ix;

// todo f0 Machine osztály ami az utolsó előtolás, fogás és a szerszám pozíciót tudja
// innen lehet tudni, hogy fel kell-e emelni vagy le kell e süllyeszteni amikor azt kérik

    Feed _selected_feed;
    Cut _selected_cut;

    int _last_tool_ix = -1;
    Feed _last_feed;    
    Cut _last_cut;

// todo f1 PositionRepo osztály, amiben vannak pozíció listák és a last(type) adja az utolsó aktuális elemet
// innen lehet tudni, hogy egy furatot elkészítettünk, oda másik ugyanolyat már nem kell kifúrni
    Point _lastHoleP;
    qreal _last_hole_diameter;

    Point _lastLineP0;
    Point _lastLineP1;

    Point _lastBoxP0;
    Point _lastBoxP1;
    BoxType::Type _lastBoxType;

    Point _lastArcP0;
    Point _lastArcP1;
    Point _lastArcO;

    Point _last_position;
    GMode::Mode _last_gmode;

    auto setXYMode(const QString &txt) -> bool;

    /*SetSelected*/
    void SetSelectedFeed(Feed feed);
    /*Validators*/
    auto ValidateTool() -> bool;
    auto CheckCut(QString*err) -> bool;
    /*Geomerty*/
    auto LineToGCode(const Line& m,QString *err) -> QString;
    auto HoleToGCode(const Hole& m,QString*err) -> QString;
    auto BoxToGCode(const Box& m,QString*err) -> QString;
    auto ArcToGCode(const Arc& m,QString*err) -> QString;
    auto SetToolToGCode(Tool m, QString *err) -> QString;
    auto SetFeedToGCode(QString *err = nullptr) -> QString;
    auto SetSpindleSpeedToGCode(QString *err = nullptr) -> QString;
    /*G Command*/
    auto ChangeToolToGCode() -> QString;
    auto SpindleStartToGCode() -> QString;
    auto SpindleStopToGCode() -> QString;
    auto LiftDownToGCode(qreal z) -> QString;
    auto LiftUpToGCode(const QVariant& z) -> QString;
    auto TravelXYToGCode(const Point& p) -> QString;
    auto SetXYModeToGCode() -> QString;
    auto GoToXY(GMode::Mode, const Point& p, qreal length) -> QString;
    auto GoToZ(GMode::Mode, const Point& p, qreal length) -> QString;
    auto GoToXYZ(GMode::Mode, const Point& p, qreal length) -> QString;
    /*Parse*/
    auto ParseCommentToGCode(const QString &str, QString *gcode, QString *err) -> bool;
    auto ParseArcToGCode(const QString& str, QString *gcode, QString *err) -> bool;
    auto ParseLineToGCode(const QString& str, QString *gcode, QString *err) -> bool;
    auto ParseBoxToGcode(const QString& str, QString *gcode, QString *err) -> bool;
    auto ParseHoleToGCode(const QString& str, QString *gcode, QString *err) -> bool;
    auto ParseStringToGCode(const QString& str, QString *gcode, QString *err) -> bool;
    auto ParseSetToolToGCode(const QString& str, QString *gcode, QString *err) -> bool;
    auto ParseSetFeedToGCode(const QString& str, QString *gcode, QString *err) -> bool;
    auto ParseSetSpindleSpeedToGCode(const QString& str, QString *gcode, QString *err) -> bool;
    auto ParseSetXYModeToGcode(const QString& str, QString *gcode, QString *err) -> bool;
public:
    struct Messages{
        const QString invalid_point = QStringLiteral("invalid point");
        const QString zero_feed = QStringLiteral("cutting movement with zero feed");
        const QString zero_spindleSpeed = QStringLiteral("cutting movement with zero spindleSpeed");
        const QString no_feed = nameof(no_feed);
        const QString no_speed = nameof(no_speed);
        const QString cannot_calculate = nameof(cannot_calculate);
        const QString movement_time = nameof(movement_time);
        const QString no_calc_length = QStringLiteral("not calculated movement length");
    } _messages;
    /*CUTS*/
    auto LinearCut(qreal z2)-> QStringList;
    void GoToCutposition(QStringList *g, const Point& p);
    auto HelicalCut(qreal total_depth, qreal path_r) -> QStringList;
    auto CircularArcCut(qreal total_depth) -> QStringList;
};

#endif // GENERATEGCODE_H
