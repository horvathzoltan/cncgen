#ifndef XYMODE_H
#define XYMODE_H

#include <QString>

#include "parsestate.h"




struct XYMode{
public:
    static const QString key_xyz;
    static const QString key_yxz;

    enum Mode:int{XY=0,YX};

    XYMode();
    XYMode(Mode m);

    Mode mode;

    static auto Parse(const QString &txt, XYMode* m) -> ParseState;
    static auto ValidateLineType(const QString &txt) -> bool;

    auto ToString() -> QString;
};



#endif // XYMODE_H
