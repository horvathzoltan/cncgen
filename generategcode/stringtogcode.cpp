#include "helpers/logger.h"
#include "gcodecommon.h"
#include "stringtogcode.h"

#include <gcode/string.h>

#include <helpers/stringhelper.h>

auto StringToGcode::ParseString(const QString& str, QString *gcode, QString *err, bool isComment)-> bool
{
    Q_UNUSED(err)
    String m;
    auto s = String::Parse(str, &m);
    if(s.state()==ParseState::NoData) return false;
    zInfo(GCodeCommon::T1+str);
    if(s.state() == ParseState::Parsed )
    {
        auto mm = m.ToString(isComment);
        if(gcode)*gcode=mm;//.ToString();
        auto msg1 = GCodeCommon::G1+mm;//.ToString();
        StringHelper::Tabulate(&msg1, GCodeCommon::G2);
        zInfo(msg1);
    }
    QString msg;
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg+" "+s.ToString());
    return true;
}
