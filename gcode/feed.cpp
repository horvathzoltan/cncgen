#include "feed.h"

#include "gcode/gcode.h"

//Feed::Feed()
//{
//    _isValid=false;
//}

//Feed::Feed(qreal _spindleSpeed, qreal _f)
//{
//    spindleSpeed = _spindleSpeed;
//    f= _f;
//    _isValid=true;
//}

auto Feed::ToString() const -> QString
{
    QString msg;
    if (spindleSpeed>0) msg+=" s"+GCode::r(spindleSpeed);
    if (f>0) msg+=" f"+GCode::r(f);
    return msg;
}
