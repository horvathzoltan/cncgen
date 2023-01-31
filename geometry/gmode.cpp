#include "gmode.h"


auto GMode::ToGCcode(Mode i) -> QString{
    switch(i){
    case Rapid:return QStringLiteral("G0");
    case Linear:return QStringLiteral("G1");
    case Circular:return QStringLiteral("G2");
    case Circular_ccw:return QStringLiteral("G3");
    default: return QString();
    }
}

