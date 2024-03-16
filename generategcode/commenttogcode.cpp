#include "helpers/logger.h"

#include "commenttogcode.h"
#include "gcodecommon.h"

#include <gcode/comment.h>

#include <helpers/stringhelper.h>

auto CommentToGCode::ParseComment(const QString& str, QString *gcode, QString *err) -> bool
{
    Q_UNUSED(err)
    Comment m;
    auto s = Comment::Parse(str, &m);
    if(s.state()==ParseState::NoData) return false;
    zInfo(GCodeCommon::T1+str);
    if(s.state() == ParseState::Parsed )
    {
        if(gcode)*gcode=m.text;
    }
    QString msg;
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg);
    return true;
}
