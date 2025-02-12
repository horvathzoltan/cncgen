#include "gcode/string.h"
#include "gcode/gcode.h"

#include <QMap>
#include <QStringList>
#include "parsestate.h"

QString String::_lasterr;
const QString String::key = QStringLiteral("print");
const QString String::key_code = QStringLiteral("code");

String::String()
{
    _isValid=false;
}

String::String(const QString &str)
{
    _value = str;
    _isValid=true;
}

auto String::Parse(const QString &txt, String*m) -> ParseState
{
    _lasterr.clear();
    if(!m) return ParseState::NoData;
    if(!txt.startsWith(key) && !txt.startsWith(key_code)) return ParseState::NoData;

    int ix = txt.indexOf(' ');
    if(ix==-1) return ParseState::NotParsed;

    auto p=txt.mid(ix).trimmed();

    QString str;
    if(!GCode::ParseValue(p, QString(), &str)) return ParseState::NotParsed;

    *m={str};
    return ParseState::Parsed;
}
//p     0 2  0 2
//0123456789abcd
//m1: $ $m1  $m2
auto String::ToString(bool isComment) const -> QString
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

    return isComment?"("+v+")":v;
}
