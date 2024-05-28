#ifndef GENERATEGCODE_H
#define GENERATEGCODE_H

#include <QStringList>
#include <QVariant>

#include <QDir>

#include <generategcode/gcodemanager.h>
#include <generategcode/goto.h>
#include <generategcode/togcodemodel.h>
#include <generategcode/totalstats.h>

#include <gcode/cut.h>

#include <geometry/gap.h>





class GenerateGcode
{
public:
    static const QString safeKey;
    static const QString offsetKey;
    static const QString safezKey;
    static const QString overcutKey;
    static const QString safebKey;
    static const QString ratioKey;
    static const QString preMillStepsKey;
    static const QString movzKey;
    static const QString peckzKey;
    static const QString maxzKey;
    static const QString nameKey;

    static const QString emaxKey;
    static const QString fmaxKey;
    static const QString fminKey;
    static const QString fratioKey;
    static const QString pdwellKey;

    static const QString peckslow;
    static const QString peckfast;
    static const QString pecktime;

    static const QString simi;

    void Init();
    auto Generate(const QStringList& g) -> QStringList;

    TotalStats _totalStats;

private:
    QDir _workingFolder = {};

    GCodeManager _gcodeManager;

    Cut _selected_cut;

    Cut _last_cut3;

    ToGCodeModel _toGCodeModel;


    QString _includeFn = {};

    auto setXYMode(const QString &txt) -> bool;       



public:
    void setWorkingFolder(const QDir &a){ _workingFolder = a; }


    /*CUTS*/
    void SetIsPlot(bool v){_toGCodeModel.SetIsPlot(v);};

};

#endif // GENERATEGCODE_H
