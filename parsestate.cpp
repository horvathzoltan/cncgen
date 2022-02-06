#include "parsestate.h"

ParseState::ParseState(){_state=State::Unknown;}

ParseState::ParseState(State s){_state=s;}

void ParseState::addError(const QString &s)
{
    _state=ParseError;
    _err.append(s);
}

void ParseState::addWarn(const QString &s)
{
    _warn.append(s);
}

auto ParseState::ToString() const -> QString{
    QString msg;
    if(!_err.isEmpty()){
        for(auto&e:_err)
        {
            StringHelper::Append(&msg, "E:"+e, '\n');
        }
    }
    if(!_warn.isEmpty()){
        for(auto&e:_warn){
            StringHelper::Append(&msg, "W:"+e, '\n');
        }
    }
    return msg;
}
