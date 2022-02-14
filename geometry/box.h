#ifndef BOX_H
#define BOX_H

#include <QList>
#include "gap.h"
#include "line.h"
#include "boxtype.h"
#include "parsestate.h"
#include "size.h"

struct Box{
private:
    static constexpr QChar key = 'b';
    static constexpr ushort keyUniCode= key.unicode();
public:
    Box();
    Box(const Point& _p0,
        const Point& _p1,
        const Gap& _gap,
        BoxType::Type _type,
        Cut _cut,
        qreal _corner_diameter,
        Feed _feed,
        const Point& _rp,
        const Size& _size,
        qreal _jg
        );

    QList<Line> lines;
    Point p0;
    Point p1;
    Gap gap;
    BoxType::Type type = BoxType::Outline;
    Cut cut;
    qreal corner_diameter=-1; // ha csak a sarkait fúrjuk a furatátmérő
    Feed feed;
    Point rp;
    Size size;
    qreal jointGap=0; // illesztési hézag

    static auto Parse(const QString& txt, XYMode mode, MMode mmode, Box *m, Point *offset) -> ParseState;
    static auto Parse(const QString& txt) -> ParseState;
    QString ToString() const;

    /*ISVALID*/
public:
    [[nodiscard]] auto isValid() const -> bool {return _isValid;}
private:
    bool _isValid;

//    /*LASTERR*/
//public:
//    static QString lasterr(){return _lasterr;}
//private:
//    static QString _lasterr;
};



#endif // BOX_H
