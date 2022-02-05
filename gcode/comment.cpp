#include "comment.h"


Comment::Comment()
{    
}


Comment::Comment(const QString &_txt)
{
    text=_txt;
}


auto Comment::Parse(const QString &txt, Comment *m) -> ParseState
{
    ParseState st(ParseState::NoData);
    if(!txt.startsWith(key)) return st;
    st.setState(ParseState::NotParsed);
    if(!m) return st;

    if(!txt.endsWith(')')){*m={txt+')'};}
    else{*m={txt};}

    st.setState(ParseState::Parsed);
    return st;
}
