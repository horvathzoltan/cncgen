#ifndef STRING_H
#define STRING_H

#include "variable.h"

#include <QString>
#include "parsestate.h"

class String
{
public:
    static const QString key;
    static const QString key_code;

    String();
    String(const QString& str);

    QString _value;
    static auto Parse(const QString &txt, String*m) -> ParseState;

    QString ToString(bool isComment = true) const;

/*ISVALID*/
public:
    bool isValid(){return _isValid;}
private:
    bool _isValid;

    /*LASTERR*/
public:
    static QString lasterr(){return _lasterr;}
private:
    static QString _lasterr;
};

#endif // STRING_H
