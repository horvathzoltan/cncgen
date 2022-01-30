#ifndef STRINGHELPER_H
#define STRINGHELPER_H

#include <QString>

class StringHelper{
public:
    static auto isNumber(const QString& str) -> bool
    {
        for(auto&c:str) if(!c.isNumber()) return false;
        return true;
    }

    static auto isLetterOrNumber(const QString& str) -> bool
    {
        for(auto&c:str) if(!c.isLetterOrNumber()) return false;
        return true;
    }
};
#endif // STRINGHELPER_H
