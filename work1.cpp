#include "work1.h"
#include "common/logger/log.h"
#include "common/helper/textfilehelper/textfilehelper.h"
#include <QCoreApplication>
#include <QDir>
#include <QThread>
#include "generategcode.h"
#include "QDebug"
#include <helpers/filenamehelper.h>
#include "common/helper/CommandLineParserHelper/commandlineparserhelper.h"
#include <QDateTime>

auto Work1::Params::Parse(const QCoreApplication& app) -> Work1::Params
{
    QCommandLineParser parser;

    parser.setApplicationDescription(QStringLiteral("command line test1 app."));
    parser.addHelpOption();
    parser.addVersionOption();

    const QString OPTION_IN = QStringLiteral("input");
    const QString OPTION_OUT = QStringLiteral("output");
    const QString OPTION_BACKUP = QStringLiteral("backup");
    const QString OPTION_TEST = QStringLiteral("test");

    com::helper::CommandLineParserHelper::addOption(&parser, OPTION_IN, QStringLiteral("geometry file as input"));
    com::helper::CommandLineParserHelper::addOption(&parser, OPTION_OUT, QStringLiteral("g-code file as output"));
    com::helper::CommandLineParserHelper::addOptionBool(&parser, OPTION_BACKUP, QStringLiteral("set if backup is needed"));
    com::helper::CommandLineParserHelper::addOptionBool(&parser, OPTION_TEST, QStringLiteral("set to activate test mode"));

    parser.process(app);

    return {
        parser.value(OPTION_IN),
        parser.value(OPTION_OUT),
        parser.isSet(OPTION_BACKUP),
        parser.isSet(OPTION_TEST)
    };
}

Work1::Work1(bool isEventLoopNeeded)
{
    _isEventLoopNeeded = isEventLoopNeeded;
    //connect(this, &Work1::finished, this, &QObject::deleteLater);
    if(isEventLoopNeeded) QObject::connect(this, &Work1::finished, QCoreApplication::instance(), QCoreApplication::quit, Qt::QueuedConnection);

    this->_result = {};
    //else {
    //connect(this, &Work1::resultReady, this, &Work1::handleResults);

    //connect(this, &Work1::finished, this, &QObject::deleteLater);
    //}
}

auto Work1::init(Work1::Params p) -> bool
{
    _isInited = false;
    if(!p.IsValid()) return false;
    params = p;
    _result = { Result::State::NotCalculated, -1};
    _isInited = true;
    return true;
}

auto Work1::Params::IsValid() -> bool
{
    QStringList err;
//    if(inFile.isEmpty())
//    {
//        err.append(QStringLiteral("inFile is empty"));
//    }
//    if(inFile.isEmpty())
//    {
//        err.append(QStringLiteral("outFile is empty"));
//    }
    if(!err.isEmpty()) zInfo(err)
            return err.isEmpty();
}



auto Work1::Result::ToString() -> QString
{
    if(state==Ok) return QStringLiteral("a: ")+QString::number(value);
    if(state==NoResult) return nameof(NoResult);
    if(state==NotCalculated) return nameof(NotCalculated);
    return QStringLiteral("unknown");
}

auto Work1::doWork() -> Result
{
    if(!_isInited) return {Result::State::NoResult, 0};
    auto e = doWork2();
    if(_isEventLoopNeeded) emit finished();
    return e;
}

void Work1::run() {
    if(!_isInited) return;
    if(!_isEventLoopNeeded) return;
    _result = doWork2();
    if(_isEventLoopNeeded) emit finished();
}

auto Work1::doWork2() -> Result
{
    QString workingFolder = params.isTest?FileNameHelper::GetTestFolderPath():qApp->applicationDirPath();

    if(params.outFile.isEmpty()){
        QFileInfo fi(params.inFile);
        QString bn = fi.baseName();
        params.outFile=bn + ".gcode";
    }
    zInfo("workingFolder: "+workingFolder);
    zInfo(QStringLiteral("params: %1, %2, %3, %4")
              .arg(params.inFile)
              .arg(params.outFile)
              .arg(params.isBackup)
              .arg(params.isTest));

    auto d = QDir(workingFolder);

    auto geomLines = com::helper::TextFileHelper::loadLines(d.filePath(params.inFile));

    if(geomLines.isEmpty()) return {Result::State::NoResult, 56};

    GenerateGcode g;
    QStringList gcodes = g.Generate(geomLines);

    if(!gcodes.isEmpty()){
        auto headLines = com::helper::TextFileHelper::loadLines(d.filePath(
            QStringLiteral("head.gcode")));

        QTime tm(0,0);
        tm = tm.addSecs(g._total_time*60);
        QStringList outLines({
            L("(GCode generated by cncgen - https://github.com/horvathzoltan/cncgen)"),
            L("(type: GCode from geometry)"),
            L("(input file: ")+params.inFile+')',
            L("(output file: ")+params.outFile+')',
            L("(created on: ")+QDateTime::currentDateTime().toString()+')',
            L("(total time: ")+tm.toString("hh:mm:ss.zzz")+")",
            L("(total cut: ")+QString::number(g._total_cut)+"mm)",
            L("(total length: ")+QString::number(g._total_length)+"mm)"
        });

        for(auto&l:headLines){
            if(l==QStringLiteral("(***)")){
                for(auto&l2:gcodes) outLines.append(l2);
            } else {
                outLines.append(l);
            }
        }

        if(!outLines.isEmpty()) {
            com::helper::TextFileHelper::save(outLines.join('\n'), d.filePath(params.outFile));
        }
    }
    return {Result::State::Ok, 55};
}

