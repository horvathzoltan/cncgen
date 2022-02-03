#ifndef XYMODE_H
#define XYMODE_H

#include <QChar>



enum XYMode:int{XY=0,YX};

class XYModeKeys{
public:
    constexpr static const QChar key1 = 'x';
    constexpr static const auto keyUniCode1 = key1.unicode();
    constexpr static const QChar key2 = 'y';
    constexpr static const auto keyUniCode2 = key2.unicode();
};



#endif // XYMODE_H
