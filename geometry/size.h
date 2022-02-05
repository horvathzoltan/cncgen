#ifndef SIZE_H
#define SIZE_H

#include <QString>
#include "parsestate.h"

class Size
{
public:
private:
    static const QString key;
    qreal w;
    qreal h;
public:
    Size();
    Size(qreal _w, qreal _h);
public:
    static auto Parse(const QString& txt, Size *s = nullptr) -> ParseState;
    auto isValid() const -> bool { return w>0&&h>0;}

    auto width() const ->qreal { return w;}
    auto height() const ->qreal { return h;}
};

#endif // SIZE_H
