#ifndef LINE_H
#define LINE_H

#include <QString>
#include "point.h"
#include "gap.h"
#include <QList>
#include "gcode/cut.h"
#include "gcode/feed.h"
#include "parsestate.h"

struct Line{
    static constexpr QChar key = 'l';
    static constexpr ushort keyUniCode= key.unicode();

    Line();
    Line(const Point& _p0,
         const Point& _p1,
         Cut _cut,
         Feed _feed,
         const Gap& _gap,
         const Point& _rp,
         const QString& _name,
         bool _no_overcut,
         bool _no_compensate,
         int menet,
         bool ns
         );
    Point p0;
    Point p1;
    Cut cut;
    Feed feed;
    Point rp;
    Gap gap;
    QString name;

    bool no_overcut = false;
    bool no_compensate = false;
    int menet = -1;
    bool no_simi = false;

    static ParseState Parse(const QString& txt, XYMode xymode,MMode mmode, Line *l,const Point& offset);
    QString ToString() const;    
    QList<Line> Divide(const Gap& g, qreal tool_d);
    QString GetComment() const;
    /*ISVALID*/
public:
    bool isValid() const {return _isValid;}
    qreal Length();
private:
    bool _isValid;

    /*LASTERR*/
//public:
//    static QString lasterr(){return _lasterr;}
//private:
//    static QString _lasterr;
};


#endif // LINE_H
