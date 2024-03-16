#include "helpers/logger.h"
#include "gcodecommon.h"
#include "xymodetogcode.h"

#include <geometry/xymode.h>
#include <helpers/stringhelper.h>

auto XYModeToGCode::ParseXYMode(const QString& str, QString *gcode, QString *err, ToGCodeModel* tmm) -> bool
{
    Q_UNUSED(err)
    //Feed m;
    auto s = XYMode::Parse(str, &tmm->_XYMode);
    if(s.state()==ParseState::NoData) return false;
    zInfo(GCodeCommon::T1+str);
    if(s.state() == ParseState::Parsed )
    {
        //_selected_feed.f=m.f;
        if(gcode)*gcode=SetXYModeToGCode(tmm);
    }
    QString msg;
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg);
    return true;
}


QString XYModeToGCode::SetXYModeToGCode(ToGCodeModel* tmm)
{
    return L("(set mode to ")+tmm->_XYMode.ToString()+')';
}
