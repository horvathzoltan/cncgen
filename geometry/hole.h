#ifndef HOLE_H
#define HOLE_H

#include <QString>
#include "xymode.h"
#include "point.h"
#include "gcode/cut.h"
#include "gcode/feed.h"
#include "gap.h"
#include "parsestate.h"

struct Hole{
    static constexpr QChar key = 'h';
    static constexpr ushort keyUniCode= key.unicode();

    Hole();
    Hole(const Point& _p,
         qreal _diameter,
         Cut _cut,
         Feed _feed,
         const Gap& _gap,
         qreal _jg,
         const Point& _rp,//={},
         bool _np,//=false,
         bool _ng,//=false,
         const QString& _name,//=""
         int _mode
        );

    Point p;
    qreal diameter=-1;

    Cut cut={};
    Feed feed={};
    Point rp={};
    bool np=false;
    bool ng=false;
    qreal jointGap=0; // illesztési hézag
    QString name;
    int mode=0;

    static ParseState Parse(const QString& txt, XYMode xymode,
                            MMode mmode, Hole*, Point *offset);
    QString ToString() const;
    Gap gap;

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

    QString GetComment() const;
};

#endif // HOLE_H
