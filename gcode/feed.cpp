#include "feed.h"
#include "gcode.h"
#include "messages.h"
#include "helpers/stringhelper.h"

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


auto Feed::Parse(const QString& txt, Feed *a) -> ParseState
{
    ParseState st(ParseState::NoData);
    if(!txt.startsWith(key_feed) &&
        !txt.startsWith(key_spindleSpeed)) return st;
    st.setState(ParseState::NotParsed);
    if(!a) return st;
    //bool feed_ok=false, speed_ok=false;
    if(txt.startsWith(Feed::keyUniCode_feed)){
        qreal x;        
        if(GCode::ParseValue(txt, key_feed, &x)){
            st.setState(ParseState::Parsed);
            a->_feed=x;
        }else{st.addWarn(Messages::cannotParse(Messages::full_cutting_depth,txt));}
    }else if(txt.startsWith(Feed::keyUniCode_spindleSpeed)){
        qreal x;
        if(GCode::ParseValue(txt, key_spindleSpeed, &x)){
            st.setState(ParseState::Parsed);
            a->_spindleSpeed = x;
        }else{
            st.addWarn(Messages::cannotParse(Messages::full_cutting_depth,txt));
        }
    }
    return st;
}


//auto Feed::ParseIntoFeed(const QString &txt) -> ParseState
//{
////    _lasterr.clear();
//    if(!txt.startsWith(key_feed)) return ParseState::NoData;

//    bool isok;
//    auto x = txt.midRef(1).toDouble(&isok);
//    if(!isok || x<=0) return ParseState::NotParsed;
//    _feed=x;
//    return ParseState::Parsed;
//}

//auto Feed::ParseIntoSpindleSpeed(const QString &txt) -> ParseState
//{
//    //_lasterr.clear();
//    if(!txt.startsWith(key_spindleSpeed)) return ParseState::NoData;

//    bool isok;
//    auto x = txt.midRef(1).toDouble(&isok);
//    if(!isok || x<=0) return ParseState::NotParsed;

//    _spindleSpeed=x;
//    return ParseState::Parsed;
//}


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

auto Feed::ToStringFeed(qreal f) -> QString
{
    return "f"+GCode::r(f);
}

auto Feed::ToStringSpindleSpeed(qreal s) -> QString
{
    return "s"+GCode::r(s);
}


bool Feed::Check(qreal fmin, qreal fmax, QString *err ) const
{
    bool ok = Check(_feed, fmin, fmax, err);
    if(!ok) return false;
    if(_spindleSpeed<=0){
        if(err) *err= "(no spindle speed available error)";
        return false;
    }
    return true;
}

bool Feed::Check(qreal f, qreal fmin, qreal fmax, QString *err )
{
    if(f<=0){
        if(err) *err="(no feed available error)";
        return false;
    }
    if(f<fmin){
        if(err) *err= "(feed too low error)";
        return false;
    }
    if(f>fmax){
        if(err) *err= "(feed too high error)";
        return false;
    }

    return true;
}
