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
        qreal _jg,
        bool _nl[4],
        qreal rounding,
        int _rjoin,
        qreal _vcorner_x,
        qreal _vcorner_y,
        const QString& _name,
        bool _nr[4], bool _no_compensate, int _menet
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
    qreal rounding=0; // sarkok lekerekítése
    int rjoin=0;//szabad vég: 0 szabadon, 1: befele íves, kifele íves
    qreal vcorner_x=0;
    qreal vcorner_y=0;
    QString name;
    bool no_compensate = false;
    int menet=-1;

    static constexpr ushort keyUniCode= key.unicode();

    bool nl[4]={1,1,1,1};
    bool nr[4]={1,1,1,1};

    static auto Parse(const QString& txt, XYMode mode, MMode mmode, Box *m, Point *offset) -> ParseState;
    static auto Parse(const QString& txt) -> ParseState;
    QString ToString() const;
    QString GetComment() const;
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
