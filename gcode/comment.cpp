#include "comment.h"

QString Comment::_lasterr;

Comment::Comment()
{
    _isValid=false;
}


Comment::Comment(const QString &_txt)
{
    text=_txt;
    _isValid=true;
}


ParseState Comment::Parse(const QString &txt, Comment *m)
{
    _lasterr.clear();
    if(!m) return ParseState::NoData;
    if(!txt.startsWith(key)) return ParseState::NoData;

    if(!txt.endsWith(')')){*m={txt+')'};}
    else{*m={txt};}
    return ParseState::Parsed;
}
