#ifndef GAP_H
#define GAP_H

#include <QString>
#include "geometry/xymode.h"

struct Gap{
    static constexpr QChar key = 'g';
    static constexpr ushort keyUniCode= key.unicode();

    Gap();
    Gap(int, qreal, qreal);
    int n; // gapek száma
    qreal length; // hossz
    qreal height; // magasság

    static auto Parse(const QString &txt, Gap*) -> ParseState;
    QString ToString() const;

/*ISVALID*/
//public:
    auto isValid() const ->bool;
//private:
//    bool _isValid;
};

#endif // GAP_H
