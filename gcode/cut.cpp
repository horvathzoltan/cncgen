#include "cut.h"

#include "gcode/gcode.h"

//Cut::Cut()
//{
//    _isValid=false;
//}

//Cut::Cut(qreal _z, qreal _z0)
//{
//     z=_z;
//     z0=_z0;
//     _isValid=true;
//}

auto Cut::ToString() const -> QString
{
    QString msg;
    if (z>0) msg+=" z"+ GCode::r(z);
    if (z0>0) msg+=" c"+ GCode::r(z0);
    return msg;
}
