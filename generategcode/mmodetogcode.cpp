#include "helpers/logger.h"
#include "gcodecommon.h"
#include "mmodetogcode.h"

#include <geometry/mmode.h>

#include <helpers/stringhelper.h>

bool MModeToGCode::ParseMMode(const QString& str, QString *gcode, QString *err, ToGCodeModel *tmm)
{
    Q_UNUSED(err)
    //Feed m;
    auto s = MMode::Parse(str, &tmm->_MMode);
    if(s.state()==ParseState::NoData) return false;
    zInfo(GCodeCommon::T1+str);
    if(s.state() == ParseState::Parsed )
    {
        //_selected_feed.f=m.f;
        //if(gcode)*gcode=SetXYModeToGCode();
        *gcode='('+tmm->_MMode.ToString()+')';
    }
    QString msg;
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg);
    return true;
}
