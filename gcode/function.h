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

    static QVariant add(const QList<QVariant>& params){
        if(params.isEmpty()) return {};
        if(params.length()<2) return {};
        bool isok0, isok1;
        auto d0 = params[0].toDouble(&isok0);
        auto d1 = params[1].toDouble(&isok1);
        if(isok0&&isok1){ return d0+d1; }
        return {};
    }

    static QVariant sub(const QList<QVariant>& params){
        if(params.isEmpty()) return {};
        if(params.length()<2) return {};
        bool isok0, isok1;
        auto d0 = params[0].toDouble(&isok0);
        auto d1 = params[1].toDouble(&isok1);
        if(isok0&&isok1){ return d0-d1; }
        return {};
    }

    static QVariant mul(const QList<QVariant>& params){
        if(params.isEmpty()) return {};
        if(params.length()<2) return {};
        bool isok0, isok1;
        auto d0 = params[0].toDouble(&isok0);
        auto d1 = params[1].toDouble(&isok1);
        if(isok0&&isok1){ return d0*d1; }
        return {};
    }

    static QVariant div(const QList<QVariant>& params){
        if(params.isEmpty()) return {};
        if(params.length()<2) return {};
        bool isok0, isok1;
        auto d0 = params[0].toDouble(&isok0);
        auto d1 = params[1].toDouble(&isok1);
        if(isok0&&isok1&&d1){return d0/d1;}
        return {};
    }
};

#endif // FUNCTION_H
