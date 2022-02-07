#ifndef MMODE_H
#define MMODE_H

#include <QString>

#include "parsestate.h"


struct MMode
{
public:
    static const QString key_xm;
    static const QString key_ym;

    //enum Mode:int{Unknown=-1,XMirror=0,YMirror};

    MMode();

    bool XM=false;
    bool YM=false;

    bool direction_ccw(){return XM!=YM;}

    static auto Parse(const QString &txt, MMode* m) -> ParseState;
    static auto ValidateLineType(const QString &txt) -> bool;

    auto ToString() -> QString;
};

#endif // MMODE_H
