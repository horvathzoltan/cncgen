#ifndef STRING_H
#define STRING_H

#include "variable.h"

#include <QString>

class String
{
public:
    String();
    String(const QString& str);

    QString _value;
    static String Parse(const QString& txt);
    QString ToString() const;

/*ISVALID*/
public:
    bool isValid(){return _isValid;}
private:
    bool _isValid;

};

#endif // STRING_H
