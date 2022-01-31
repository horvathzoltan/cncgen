#include "gcode.h"
#include <QStringList>
#include "common/logger/log.h"

//bool _isInited = false;
VariableRepository GCode::_variables={};

//bool GCode::Clear()
//{
//    _variables.Clear();
//    return true;
//}

auto GCode::r(qreal x) -> QString{
    return QString::number(x, 'f', 3);
}

auto GCode::i(int x) -> QString{
    return QString::number(x);
}

auto GCode::ParseValue(const QString &p, const QString &key, qreal *v) -> bool
{
    bool isok = false;
    auto hasKey = !key.isEmpty();
    if(v && (!hasKey || p.startsWith(key))){
        auto a = hasKey?p.midRef(key.length()):&p;
        if(!a.isEmpty() && a[0].isNumber()){
            auto sp = a.toDouble(&isok);
            if(isok) *v = sp;
        }
    }
    return isok;
}

auto GCode::ParseValue(const QString &p, const QString &key, int *v) -> bool
{
    bool isok = false;
    auto hasKey = !key.isEmpty();
    if(v && (!hasKey || p.startsWith(key))){
        auto a = hasKey?p.midRef(key.length()):&p;
        if(!a.isEmpty() && a[0].isNumber()){
            auto sp = a.toInt(&isok);
            if(isok) *v = sp;
        }
    }
    return isok;
}

auto GCode::ParseValue(const QString &p, const QString &key, QString *v) -> bool
{
    bool isok = false;
    auto hasKey = !key.isEmpty();
    if(v && (!hasKey || p.startsWith(key))){
        auto a = hasKey?p.midRef(key.length()):&p;
        if(a.isEmpty()){
            *v=a.toString();
            isok=true;
        } else {
            if(a.startsWith('\"')&&a.endsWith('\"')){
                a = a.mid(1, a.length()-2);
                if(!a.contains('\"')){
                    *v = a.toString();
                    isok=true;
                }
            }
        }

    }
    return isok;
}

auto GCode::ParseValueXYZ(const QString &p, qreal *x, qreal*y, qreal *z, XYMode mode) -> bool
{
    bool isok = false;
    QStringList ns = p.split(',');

    if(x && y && z && ns.length()>=2){
        //bool isok_a, isok_b, isok_c=false;
        //double a = ns[0].toDouble(&isok_a);
        double a,b,c;
        bool isok_a = GCode::ToDouble(ns[0], &a);
        bool isok_b = GCode::ToDouble(ns[1], &b);
        //double b = ns[1].toDouble(&isok_b);
        bool has_c = (ns.length()>=3);
        //double c = has_c?ns[2].toDouble(&isok_c):0;
        bool isok_c=has_c?GCode::ToDouble(ns[2], &c):false;
        isok = isok_a && isok_b && (has_c?isok_c:true);
        if(isok){            
            switch(mode){
            case XY:
                if(isok_a) *x=a;
                if(isok_b) *y=b;
                break;
            case YX:
                if(isok_a) *y=a;
                if(isok_b) *x=b;
                break;
            }
            if(!has_c) { *z=0;
            }
            else if(isok_c){
                *z=c;
            }
        }
    }
    //zInfo(L("XYZ:")+p+(isok?" ok":" err"));
    return isok;
}


auto GCode::ToDouble(const QString& a, qreal *v) -> bool
{
    if(!v) return false;
    if(a.isEmpty()) return false;
    if(a[0].isNumber()){
        bool isok;
        qreal b = a.toDouble(&isok);
        if(isok){
            *v=b;
            return true;
        }
    }
//    if(a=="$m1"){
//        zInfo(L("$m1:")+a);
//    }
    QVariant variable;
    if(a.startsWith('$')&&a.length()>1 &&(variable = GCode::_variables.value(a.mid(1))).isValid())
    {
        *v=variable.toDouble();
        return true;
    }
    return false;
}


