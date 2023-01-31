#ifndef PARSESTATE_H
#define PARSESTATE_H

#include <QStringList>
//#include "helpers/stringhelper.h"

class ParseState
{
public:
    enum State{Unknown,NoData,NotParsed,ParseError,Parsed};

    ParseState();
    ParseState(State s);
private:
    State _state;
    QStringList _err;
    QStringList _warn;
public:
    State state(){return _state;}
    void setState(State s){_state = s;};
    void addError(const QString& s);
    void addWarn(const QString& s);
    QString ToString() const;
};


#endif // PARSESTATE_H
