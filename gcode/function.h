#ifndef FUNCTION_H
#define FUNCTION_H

#include <QList>
#include <QVariant>

#include "gcode/gcode.h"

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
        auto ds= ToDoubles(params);

        for(auto&d:ds) if(!qIsNaN(d))a+=d;
        return a;
    }

     static QList<double> ToDoubles(const QList<QVariant>& params){
         QList<double> l;
         for(auto&p:params){
             QString s0 = p.toString();
             double d0;
             bool isok=false;
             if(s0.startsWith('$')){
                 QString token = s0.mid(1);
                 d0 = GCode::_variables.value(token).toDouble(&isok);
             } else {
                 d0 = p.toDouble(&isok);
             }
             if(isok)
                 l.append(d0);
             else
                 l.append(qQNaN());
         }
         return l;
     }

    static QVariant add(const QList<QVariant>& params){
        if(params.isEmpty()) return {};
        if(params.length()<2) return {};

        auto d= ToDoubles(params);
        if(qIsNaN(d[0])||qIsNaN(d[1])) return {};
        return d[0]+d[1];
    }

    static QVariant sub(const QList<QVariant>& params){
        if(params.isEmpty()) return {};
        if(params.length()<2) return {};
        auto d= ToDoubles(params);
        if(qIsNaN(d[0])||qIsNaN(d[1])) return {};
        return d[0]-d[1];
    }

    static QVariant mul(const QList<QVariant>& params){
        if(params.isEmpty()) return {};
        if(params.length()<2) return {};
        auto d= ToDoubles(params);
        if(qIsNaN(d[0])||qIsNaN(d[1])) return {};
        return d[0]*d[1];
    }

    static QVariant div(const QList<QVariant>& params){
        if(params.isEmpty()) return {};
        if(params.length()<2) return {};        
        auto d= ToDoubles(params);
        if(qIsNaN(d[0])||qIsNaN(d[1])) return {};
        return d[0]/d[1];
    }
};

#endif // FUNCTION_H
