#ifndef KEYWORD_H
#define KEYWORD_H

#include <QString>

class KeyWord{
public:
    enum Word{Undefined=-1,avg=0,sum,sub,add, mul, div, overdrill};

    static QString ToString(Word type);
    static Word Parse(const QString &p);
};

#endif // KEYWORD_H
