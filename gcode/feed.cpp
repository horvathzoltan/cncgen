#include "feed.h"

#include "gcode/gcode.h"

//QString Feed::_lasterr;

auto Feed::isValid() const -> bool
{
    return _feed>=0 && _spindleSpeed>=0;
}

//Feed::Feed()
//{
//    _spindleSpeed = -1;
//    _feed = -1;
//    //_isValid=false;
//}

//Feed::Feed(qreal spindleSpeed, qreal f)
//{
//    _spindleSpeed = spindleSpeed;
//    _feed= f;
//    //_isValid=true;
//}


bool Feed::ParseInto(const QString& p, ParseState* st)
{
    if(!st) return false;

    if(p.startsWith(Feed::keyUniCode_feed)){
        if(ParseSetFeedToGCode(p, &gcode, &err)){
            AppendGCode(&gcodes, gcode, err);
            return true;
        }
    }
    if(p.startsWith(Feed::keyUniCode_spindleSpeed)){
        if(ParseSetSpindleSpeedToGCode(p, &gcode, &err)){
            AppendGCode(&gcodes, gcode, err);
            return true;
        }
    }
    return false;
}


auto Feed::ParseIntoFeed(const QString &txt) -> ParseState
{
//    _lasterr.clear();
    if(!txt.startsWith(key_feed)) return ParseState::NoData;

    bool isok;
    auto x = txt.midRef(1).toDouble(&isok);
    if(!isok || x<=0) return ParseState::NotParsed;
    _feed=x;
    return ParseState::Parsed;
}

auto Feed::ParseIntoSpindleSpeed(const QString &txt) -> ParseState
{
    //_lasterr.clear();
    if(!txt.startsWith(key_spindleSpeed)) return ParseState::NoData;

    bool isok;
    auto x = txt.midRef(1).toDouble(&isok);
    if(!isok || x<=0) return ParseState::NotParsed;

    _spindleSpeed=x;
    return ParseState::Parsed;
}


auto Feed::ToString() const -> QString
{
    QString msg;
    if (_spindleSpeed>0) msg+=" s"+GCode::r(_spindleSpeed);
    if (_feed>0) msg+=" f"+GCode::r(_feed);
    return msg;
}

auto Feed::ToStringFeed() const -> QString
{
    return "f"+GCode::r(_feed);
}

auto Feed::ToStringSpindleSpeed() const -> QString
{
    return "s"+GCode::r(_spindleSpeed);
}
