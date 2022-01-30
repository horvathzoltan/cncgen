#ifndef FUNCTION_H
#define FUNCTION_H

#include <QList>
#include <QVariant>

class Function{
public:
    static QVariant avg(const QList<QVariant>& params){
        if(params.isEmpty()) return {};
        double a=0,b=0;
        bool isok;
        for(auto&p:params){
            auto d = p.toDouble(&isok);
            if(isok){ a+=d; b++;}
        }
        return (b!=0)?a/b:QVariant();
    }

    static QVariant sum(const QList<QVariant>& params){
        if(params.isEmpty()) return {};
        double a=0;
        bool isok;
        for(auto&p:params){
            auto d = p.toDouble(&isok);
            if(isok){ a+=d; }
        }
        return a;
    }
};

#endif // FUNCTION_H
