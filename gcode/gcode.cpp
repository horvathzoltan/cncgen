#include "gcode.h"
#include <QStringList>
//#include "helpers/log.h"

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

auto GCode::ParseValue(const QString &p, const QChar &key, qreal *v) -> bool
{
    return ParseValue(p, QString(key), v);
}

auto GCode::ParseValue(const QString &p, const QString &key, qreal *v) -> bool
{
    bool isok = false;
    auto hasKey = !key.isEmpty();
    if(v && (!hasKey || p.startsWith(key))){
        int ix = p.indexOf('#', key.length());
        int len = -1;
        if(ix!=-1){
            len = ix-key.length();
        }

        QString a = p.mid(key.length(), len).trimmed();
        if(!a.isEmpty() && (a[0].isNumber() || a[0]=='-')){
            auto sp = a.toDouble(&isok);
            if(isok){
                *v = sp;
                return true;
            }
        }
        QVariant variable;
        if(a.startsWith('$')&&a.length()>1 &&(variable = GCode::_variables.value(a.mid(1))).isValid())
        {
            *v=variable.toDouble();
            return true;
        }
    }    
    return false;
}

// a = 44 ok
// a =44 nem ok
auto GCode::ParseValue(const QString &p, const QString &key, int *v) -> bool
{
    bool isok = false;
    auto hasKey = !key.isEmpty();
    if(v && (!hasKey || p.startsWith(key))){
        int ix = p.indexOf('#', key.length());
        int len = -1;
        if(ix!=-1){
            len = ix-key.length();
        }

        QString a = p.mid(key.length(), len).trimmed();
        //auto a = p.mid(key.length()).trimmed();
        if(!a.isEmpty() && a[0].isNumber()){
            auto sp = a.toInt(&isok);
            if(isok){*v = sp;}
        }
    }
    return isok;
}

auto GCode::ParseValues(const QString &p, const QString &key, QList<int>*v) -> bool
{
    bool isok = false;
    auto hasKey = !key.isEmpty();
    if(v && (!hasKey || p.startsWith(key))){
        //auto a = p.mid(key.length()).trimmed();
        int ix = p.indexOf('#', key.length());
        int len = -1;
        if(ix!=-1){
            len = ix-key.length();
        }

        QString a = p.mid(key.length(), len).trimmed();
        if(!a.isEmpty() && a[0].isNumber()){
            auto b = a.split(',');
            for(int i=0;i<b.length();i++){
                auto sp = b[i].toInt(&isok);
                if(isok){v->append(sp);}
                }
        }
    }
    return isok;
}

auto GCode::ParseValue(const QString &p, const QString &key, QString *v) -> bool
{
    bool isok = false;
    auto hasKey = !key.isEmpty();
    if(v && (!hasKey || p.startsWith(key))){
        //auto a = p.mid(key.length()).trimmed();
        int ix = p.indexOf('#', key.length());
        int len = -1;
        if(ix!=-1){
                len = ix-key.length();
        }

        QString a = p.mid(key.length(), len).trimmed();
        if(a.isEmpty()){
            *v=a;//.toString();
            isok=true;
        } else {
            if(a.startsWith('\"')&&a.endsWith('\"')){
                a = a.mid(1, a.length()-2);
                if(!a.contains('\"')){
                    *v = a;//.toString();
                    isok=true;
                }
            }
        }

    }
    return isok;
}

auto GCode::ParseValueXYZ(const QString &p, qreal *x, qreal*y, qreal *z, XYMode mode, MMode mm) -> bool
{
    if(mode.mode==XYMode::Unknown) return false;
    QStringList ns = p.split(',');

    bool isok = false;
    if(x && y && ns.length()>=2){
        //bool isok_a, isok_b, isok_c=false;
        //double a = ns[0].toDouble(&isok_a);
        double a=0,b=0,c=0;
        QString aa = ns[0];
        bool isok_a = GCode::ToDouble(aa, &a);
        bool isok_b = GCode::ToDouble(ns[1], &b);
        //double b = ns[1].toDouble(&isok_b);
        bool has_c = (ns.length()>=3&&!ns[2].isEmpty());
        //bool has_c = (ns.length()>=3);
        //double c = has_c?ns[2].toDouble(&isok_c):0;
        bool isok_c=has_c?GCode::ToDouble(ns[2], &c):false;

        isok = isok_a && isok_b && (has_c?isok_c:true);
        if(isok){
            switch(mode.mode){
            case XYMode::XY:
                if(isok_a) if(x)*x=a;
                if(isok_b) if(y)*y=b;
                break;
            case XYMode::YX:
                if(isok_a) if(y)*y=a;
                if(isok_b) if(x)*x=b;
                break;
            default:break;
            }
            if(!has_c) {
                //*z=0;
            }
            else if(isok_c){
                if(z)*z=c;
            }
            if(mm.XM){*x=-*x;}
            if(mm.YM){*y=-*y;}
        }
    }
    //zInfo(L("XYZ:")+p+(isok?" ok":" err"));
    return isok;
}


auto GCode::ToDouble(const QString& a, qreal *v) -> bool
{
    if(!v) return false;
    if(a.isEmpty()) return false;
    if(a[0].isNumber()||a[0]=='-'||a[0]=='+'){
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

    if(a.startsWith('$')&&a.length()>1)
    {
        QString ami = a.mid(1);
        QVariant variable = GCode::_variables.value(ami);
        bool isValid = variable.isValid();
        if(isValid){
            *v=variable.toDouble();
            return true;
            }
    }
    return false;
}


