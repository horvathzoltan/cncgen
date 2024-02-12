#ifndef GENERATEGCODE_H
#define GENERATEGCODE_H

#include <QStringList>
#include <QVariant>

#include "geometry/line.h"
#include "geometry/box.h"
#include "geometry/hole.h"
#include "geometry/arc.h"

#include "gcode/tool.h"
//#include "gcode/variable.h"
//#include "gcode/string.h"
//#include "parsestate.h"
#include "geometry/gmode.h"
#include "geometry/mmode.h"
//#include "helpers/macro.h"
#include <QDir>

class GenerateGcode
{
public:
    enum Compensation:int{
        none=0, speed=1, depth=2
    };

    enum LengthMode:int{XYZ,XY,Z
    };

//    Compensation GetCompensation(qreal l, qreal z);
//    qreal CompensateSpeed(qreal l, qreal z);
    bool Compensate(qreal l, qreal z, qreal *s3, qreal *f3, qreal f_in);

    struct CompensateModel{
        qreal c_f = -1;
        qreal c_z = -1;
        bool isCompensated;

        void ToGCode(QStringList* g, const Cut& o_cut, const Feed& o_feed);
    };

    CompensateModel Compensate2(qreal l, const Cut& cut, const Feed& feed);

    static qreal t_muvelet;
    static double dPeck;
    static double dPeck2;

    static const QString G1;
    static const QString G2;
    static const QString T1;
    static const QString T_ERR;
    static const QString T_W;

    static const QString safeKey;
    static const QString offsetKey;
    static const QString safezKey;
    static const QString overcutKey;
    static const QString safebKey;
    static const QString ratioKey;
    static const QString preMillStepsKey;
    static const QString movzKey;
    static const QString maxzKey;
    static const QString nameKey;

    static const QString emaxKey;
    static const QString fmaxKey;
    static const QString fminKey;
    static const QString fratioKey;
    static const QString pdwellKey;

    void Init();
    auto Generate(const QStringList& g) -> QStringList;
    auto AppendGCode(QStringList* gs, const QString &g, const QString& err={},const QString& comment={}) -> bool;
    qreal _total_minutes; //mm per perc
    qreal _total_length;
    qreal _total_cut;
    void SetIsPlot(bool v){_isPlot = v;}
private:
    QDir _workingFolder = {};
    bool _verbose = true;
    bool _isPlot = false;
    XYMode _XYMode;
    MMode _MMode;
    //MMode _mmode;
    QStringList gcodes;

//    qreal _movZ=2;
//    qreal _maxZ=4;

    Point _safe_place = {0,0,0};

    QMap<int, Tool> _tools;    
    int _selected_tool_ix;

    Feed _selected_feed3;
    Cut _selected_cut;

    int _last_tool_ix = -1;
    Feed _last_feed3;
    Cut _last_cut3;

    Point _lastHoleP;
    qreal _last_hole_diameter;

    struct LastLine{
        Point p0;
        Point p1;
    };

    LastLine _lastLine;
    qreal _safez=0;
    qreal _safeb=0;
    qreal _overcut =0;
    qreal _movZ=2;
    qreal _maxZ=4;
    qreal _emax=0.1/100;
    qreal _fmax=500;
    qreal _fmin=200;
    qreal _fratio =0.7;
    int _pdwell=500;

    struct LastBox{
        Point p0;
        Point p1;
        BoxType::Type type;
    };

    LastBox _lastBox;

    struct LastArc{
        Point p0;
        Point p1;
        Point o;
    };

    LastArc _lastArc;

    Point _last_position;
    GMode::Mode _last_gmode;

    Point _offset_xyz;

    qreal _ratio = 1;
    int _preMillSteps = 3;

    QString _includeFn = {};

    auto setXYMode(const QString &txt) -> bool;

    /*SetSelected*/
    //void SetSelectedFeed(Feed feed);
    /*Validators*/
    auto ValidateTool() -> bool;
    //auto CheckCut(const Cut& cut, QString*err) -> bool;
    /*Geomerty*/
    auto LineToGCode(const Line& m,QString *err) -> QString;
    auto HoleToGCode(const Hole& m,QString*err) -> QString;
    auto BoxToGCode(const Box& m,QString*err) -> QString;
    auto ArcToGCode(const Arc& m,QString*err) -> QString;
    auto SetToolToGCode(Tool m, QString *err) -> QString;
    bool SetFeedToGCode(qreal feed, QString *g, QString *err = nullptr);
    bool SetSpindleSpeedToGCode(qreal spindle_speed, QString *g, QString *err = nullptr);
    /*G Command*/
    auto ChangeToolToGCode() -> QString;
    auto SpindleStartToGCode(qreal spindle_speed) -> QString;
    auto SpindleStopToGCode() -> QString;
    auto LiftDownToGCode(qreal feed, qreal z) -> QString;
    auto LiftUpToGCode(qreal feed, const QVariant& z) -> QString;
    auto TravelXYToGCode(qreal feed, const Point& p) -> QString;
    auto SetXYModeToGCode() -> QString;

    struct ij { qreal i; qreal j;};

    QString GoToXY(GMode::Mode, const Point& p, qreal feed, ij = {});
    QString GoToZ(GMode::Mode, const Point& p, qreal feed, ij = {});
    QString GoToXYZ(GMode::Mode, const Point& p, qreal feed, ij = {});

    qreal GetLength(GMode::Mode i, const Point& p, LengthMode lm);

    auto Dwell(int p) -> QString;
    /*Parse*/
    auto ParseCommentToGCode(const QString &str, QString *gcode, QString *err) -> bool;

    /*GEOM*/
    auto ParseArcToGCode(const QString& str, QString *gcode, QString *err) -> bool;
    auto ParseLineToGCode(const QString& str, QString *gcode, QString *err) -> bool;
    auto ParseBoxToGcode(const QString& str, QString *gcode, QString *err) -> bool;
    auto ParseHoleToGCode(const QString& str, QString *gcode, QString *err) -> bool;

    auto ParseStringToGCode(const QString& str, QString *gcode, QString *err) -> bool;
    auto ParseSetToolToGCode(const QString& str, QString *gcode, QString *err) -> bool;
    auto ParseSetFeedToGCode(const QString& str, QString *gcode, QString *err) -> bool;
    auto ParseSetSpindleSpeedToGCode(const QString& str, QString *gcode, QString *err) -> bool;
    auto ParseSetXYModeToGcode(const QString& str, QString *gcode, QString *err) -> bool;
    auto ParseSetMModeToGcode(const QString &str, QString *gcode, QString *err) -> bool;    
public:
    void setWorkingFolder(const QDir &a){ _workingFolder = a; }

    /*moves*/
    void GoToCutposition(QStringList *g, const Point& p, const Feed& feed);
    /*CUTS*/
    QStringList LinearCut(const Feed& feed, const Cut& cut, bool no_compensate, int menet);
    QStringList HelicalCut(qreal path_r, const Feed& feed,const Cut& cut, bool a);
    QStringList CircularArcCut(const Feed& feed,const Cut& cut);

    QString TotalTimeToGCode();
    static qreal MinToMilliSec(qreal a);
    static qreal MilliSecToMin(qreal a);

    QStringList GapSegmentsCut(QList<Line> gap_segments);
};

#endif // GENERATEGCODE_H
