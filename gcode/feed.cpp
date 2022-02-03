#include "feed.h"

#include "gcode/gcode.h"

QString Feed::_lasterr;

Feed::Feed()
{
    _isValid=false;
}

Feed::Feed(qreal _spindleSpeed, qreal _f)
{
    spindleSpeed = _spindleSpeed;
    f= _f;
    _isValid=true;
}

auto Feed::ToString() const -> QString
{
    QString msg;
    if (spindleSpeed>0) msg+=" s"+GCode::r(spindleSpeed);
    if (f>0) msg+=" f"+GCode::r(f);
    return msg;
}


auto Feed::ParseFeed(const QString &txt, Feed* m) -> ParseState
{
    _lasterr.clear();
    if(!m) return ParseState::NoData;
    if(!txt.startsWith(key_feed)) return ParseState::NoData;

    bool isok;
    auto x = txt.midRef(1).toDouble(&isok);
    if(!isok || x<=0) return ParseState::NotParsed;
    m->f=x;
    return ParseState::Parsed;
}

auto Feed::ParseSpindleSpeed(const QString &txt, Feed* m) -> ParseState
{
    _lasterr.clear();
    if(!m) return ParseState::NoData;
    if(!txt.startsWith(key_spindleSpeed)) return ParseState::NoData;

    bool isok;
    auto x = txt.midRef(1).toDouble(&isok);
    if(!isok || x<=0) return ParseState::NotParsed;

    m->spindleSpeed=x;
    return ParseState::Parsed;
}
