#ifndef WORK1_H
#define WORK1_H

#include <QString>
#include <QThread>
#include <QCoreApplication>

class Work1 : public QThread
{
    Q_OBJECT

    void run() override;
public:
    Work1(bool isEventLoopNeeded);

    struct Params{
    public:
        QString inFile;
        QString outFile;
        bool isBackup;
        bool isTest = false;
        bool isPlot = false;

        bool IsValid();

        static Params Parse(const QCoreApplication& app);
    };

    struct Result{
        enum State:int {NotCalculated = -3, NoResult=-1, Ok=1};
        State state;
        int value;

        QString ToString();
    };

    bool init(Params p);
    Result doWork();
    Result _result{};

private:
    bool _isInited = false;
    bool _isEventLoopNeeded = false;
    Params params;
    Result doWork2();

signals:
    void finished();
};

#endif // WORK1_H
