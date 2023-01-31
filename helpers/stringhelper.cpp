#include "stringhelper.h"

auto StringHelper::isNumber(const QString &str) -> bool
{
    for(auto&c:str) if(!c.isNumber()) return false;
    return true;
}

auto StringHelper::isLetterOrNumber(const QString &str) -> bool
{
    for(auto&c:str){
        if(c=='_') continue;
        if(!c.isLetterOrNumber()) return false;
    }
    return true;
}

void StringHelper::Append(QString *s1, const QString &s2, QChar u){
    if(!s1) return;
    if(s2.isEmpty()) return;
    if(!u.isNull()&& !s1->endsWith(u) && !s1->isEmpty()) s1->append(u);
    s1->append(s2);
}

void StringHelper::Tabulate(QString *s1, const QString &s2){
    return;
    static const QChar c(' ');
    if(!s1) return;
    auto ix = s1->indexOf(c);
    if(ix==-1) return;
    auto n = s2.length()-ix-1;
    auto a = QString().fill(c, n);
    if(n>0) s1->insert(ix,a);
}

QString StringHelper::Tabulate2(const QString &s){
    auto l = s.length();
    auto a= QString().fill(' ', l);
    return a;
}
