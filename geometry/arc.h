#ifndef ARC_H
#define ARC_H

#include <QString>
#include "point.h"
#include "gap.h"
#include <QList>
#include "gcode/cut.h"
#include "gcode/feed.h"
#include "parsestate.h"
#include "geometry/mmode.h"

//struct ArcData{
//    Point p0;
//    Point p1;
//    Point o;
//    Cut cut;
//    Feed feed;
//    Point rp;
//};

struct Arc
{
    constexpr static const QChar key = 'a';
    constexpr static const auto keyUniCode = key.unicode();

    Arc();
    Arc(const Point& _p0,
        const Point& _p1,
        const Point& _o,
        Cut _cut,
        Feed _feed,
        const Point& _rp = {}
        );

    Point p0;
    Point p1;
    Point o;
    Cut cut;
    Feed feed;
    Point rp;

    static auto Parse(const QString& txt, XYMode mode, Arc*, MMode mmode) -> ParseState;
    QString ToString() const;
    //auto ToGCode(QString* err) -> QString;
    // todo e7 Arc::Divide
    //QList<Arc> Divide(const Gap& g, qreal tool_d);

    bool isValid() const {return (p0.isValid()&&p1.isValid()&&o.isValid())||rp.isValid();}
    /*ISVALID*/
//public:
//    bool isValid() const {return _isValid;}
//private:
//    bool _isValid;

    /*LASTERR*/
//public:
//    static QString lasterr(){return _lasterr;}
//private:
//    static QString _lasterr;
};

#endif // ARC_H
