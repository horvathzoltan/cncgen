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

    static void Append(QString *s1, const QString& s2, QChar u=' '){
        if(!s1) return;
        if(!s1->endsWith(u)) s1->append(u);
        s1->append(s2);
    }

    static void Tabulate(QString *s1, const QString& s2){
        return;
        static const QChar c(' ');
        if(!s1) return;
        auto ix = s1->indexOf(c);
        if(ix==-1) return;
        auto n = s2.length()-ix-1;
        auto a = QString().fill(c, n);
        if(n>0) s1->insert(ix,a);
    }

};
#endif // STRINGHELPER_H
