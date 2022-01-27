#include "work1.h"
#include "common/logger/log.h"
#include "common/helper/textfilehelper/textfilehelper.h"
#include <QCoreApplication>
#include <QDir>
#include <QThread>
#include "generategcode.h"

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
    zInfo(QStringLiteral("params: %1, %2, %3").arg(params.inFile).arg(params.outFile).arg(params.isBackup));    

    auto d = QDir(qApp->applicationDirPath());

    auto geomLines = com::helper::TextFileHelper::loadLines(d.filePath(params.inFile));

    if(geomLines.isEmpty()) return {Result::State::NoResult, 56};

    GenerateGcode g;
    QStringList gcodes = g.Generate(geomLines);

    auto headLines = com::helper::TextFileHelper::loadLines(d.filePath(
        QStringLiteral("head.gcode")));

    QStringList outLines;

    for(auto&l:headLines){
        if(l==QStringLiteral("(***)")){
            for(auto&l2:gcodes) outLines.append(l2);
        } else {
            outLines.append(l);
        }
    }

    com::helper::TextFileHelper::save(outLines.join('\n'), d.filePath(params.outFile));

    return {Result::State::Ok, 55};
}
