#ifndef SIZE_H
#define SIZE_H

#include <QString>
#include <QVariant>
#include "parsestate.h"
#include "xymode.h"
#include "mmode.h"

class Size
{
public:
private:
    static const QString key;
    QVariant w;
    QVariant h;
public:
    Size();
    Size(qreal _w, qreal _h);
public:
    static auto Parse(const QString& txt, XYMode xymode=XYMode::Unknown, MMode mmode={}, Size *s = nullptr) -> ParseState;
    auto isValid() const -> bool { return w.isValid()&&h.isValid();}

    auto width() const ->qreal { return w.toDouble();}
    auto height() const ->qreal { return h.toDouble();}
};

#endif // SIZE_H
