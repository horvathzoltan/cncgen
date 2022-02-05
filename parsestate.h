#ifndef PARSESTATE_H
#define PARSESTATE_H

#include <QStringList>


class ParseState
{
public:
    enum State{Unknown,NoData,NotParsed,ParseError,Parsed};

    ParseState(){_state=State::Unknown;}
    ParseState(State s){_state=s;}
private:
    State _state;
    QStringList _err;

public:
    State state(){return _state;}
    QStringList err(){return _err;}

    void setState(State s){_state = s;};
    void addError(const QString& s)
    {
        _state=ParseError;
        _err.append(s);}
};


#endif // PARSESTATE_H
