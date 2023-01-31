#include <QCoreApplication>
#include <QAbstractEventDispatcher>
#include "helpers/logger.h"
#include "helpers/stringhelper.h"
#include "helpers/signalhelper.h"
#include "work1.h"
#include "helpers/nameof.h"


// -i gomb.txt -o gomb.gcode -t

auto main(int argc, char *argv[]) -> int
{
    SignalHelper::setShutDownSignal(SignalHelper::SIGINT_); // shut down on ctrl-c
    SignalHelper::setShutDownSignal(SignalHelper::SIGTERM_); // shut down on killall

#if defined (STRING) && defined (TARGI)
    auto poj = STRING(TARGI);
    zInfo(QStringLiteral("started ")+poj);
#else
    auto poj=L("manymany");
#endif

    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName(poj);

    bool isEventLoopNeeded = false;

    auto w1 =  new Work1(isEventLoopNeeded);

    Work1::Params p1 = Work1::Params::Parse(app);

    if(!w1->init(p1))
    {
        zInfo("cannot init "+nameof(w1));
        return 1;
    }

    //Work1::Result a;
    auto a = w1->doWork(); // indítás direkt
    //w1->start(); // indítás szálon
    zInfo(QStringLiteral("waiting..."));

    int e = isEventLoopNeeded?QCoreApplication::exec():0;

    zInfo(a.ToString());

    if(w1->_result.state==Work1::Result::State::NotCalculated &&
        !isEventLoopNeeded) zInfo(QStringLiteral("NoEventLoop"));

    if(!e) zInfo(QStringLiteral("Everything went ok."));
    return e;
}


