#include "helpers/logger.h"
#include "feedtogcode.h"
#include "gcodecommon.h"

#include <helpers/stringhelper.h>

bool FeedToGCode::ParseFeed(const QString& str, ToGCodeModel* tmm)//, QString *gcode, QString *err)
{
    auto s = Feed::Parse(str, &tmm->_selected_feed3);
    if(s.state()==ParseState::NoData) return false;
    zInfo(GCodeCommon::T1+str);

    QString msg;
    StringHelper::Append(&msg, s.ToString(), '\n');
    if(!msg.isEmpty())zInfo(msg);
    return true;
}


bool FeedToGCode::SetToGCode(qreal feed, QString *g, QString* err, ToGCodeModel* tmm)
{
    bool ok = Feed::Check(feed, tmm->_fmin, tmm->_fmax, err);
    if(!ok) {
        if(feed>tmm->_fmax){
            zInfo("feed is too high:"+QString::number(feed));
            feed=tmm->_fmax;
        } else {
            zInfo("feed is too low:"+QString::number(feed));
            //feed=_fmax;
        }
    }
    if(tmm->_last_feed3.feed() != feed)
    {
        tmm->_last_feed3.setFeed(feed);
        if(g) *g = Feed::ToStringFeed(feed);
    }
    return true;
}
