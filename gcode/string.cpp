#include "gcode/string.h"
#include "gcode/gcode.h"

#include <QMap>
#include <QStringList>

String::String()
{
    _isValid=false;
}

String::String(const QString &str)
{
    _value = str;
    _isValid=true;
}

auto String::Parse(const QString &txt) -> String
{
    int ix = txt.indexOf(' ');
    if(ix==-1) return {};

    auto p=txt.mid(ix).trimmed();

    QString str;
    if(!GCode::ParseValue(p, QString(), &str)) return {};
    return {str};
}
//p     0 2  0 2
//0123456789abcd
//m1: $ $m1  $m2
auto String::ToString() const -> QString
{
    QMap<QString, QString> tokens;

    QString v;
    bool isToken=false;
    QString token;
    for(int i=0;i<_value.length();i++){
        auto&c=_value[i];
        bool isLastChar = i==(_value.length()-1);
        if(!isToken && c=='$'){
            isToken=true;
            token.clear();
            continue;//lenyeljük a dollárt
        }
        if(isToken){
            if(c==' ' || isLastChar)
            {
                isToken=false;
                if(c!=' ') token+=c;
                if(!token.isEmpty()){
                    v+=GCode::_variables.ToString(token);
//                    QVariant variable;
//                    if((variable = GCode::_variables.value(token)).isValid()){
//                         v+=variable.toString();
//                    } else v+=token+"=???";//variable.toString();
                }else{
                    v+='$'; // kiköptük a dollárt
                }
                if(isLastChar) continue;
            }
        }
        if(isToken) token+=c; else v+=c;
    }

    return "("+v+")";
}
