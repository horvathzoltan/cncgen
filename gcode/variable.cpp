#include "variable.h"
#include "helpers/stringhelper.h"
#include "gcode/gcode.h"
#include "gcode/expression.h"
#include "helpers/macro.h"

VariableRepository::VariableRepository()
= default;

void VariableRepository::Clear()
{
    _values.clear();
    //_expressions.clear();
}

//01234
//maki=majom
auto VariableRepository::Parse(const QString &p) -> bool
{
    QVariant a;
    int ix0 = p.indexOf('=');
    int ix1 = p.indexOf('\"');
    if(ix0==-1) return false;
    if(ix1!=-1 && ix1<ix0) return false;
    auto key = p.left(ix0).trimmed();
    if(!StringHelper::isLetterOrNumber(key)) return false;
    if(KeyWord::Parse(key)!=KeyWord::Undefined) return false;
    auto value = p.mid(ix0+1).trimmed();
    QString str;
    QString function_str;
    qreal r;
    int i;
    Expression expression;
    if(GCode::ParseValue(value, QString(), &str)){
        _values[key]=str;
    } else if(GCode::ParseValue(value, QString(), &r)){
        _values[key]=r;
    } else if(GCode::ParseValue(value, QString(), &i)){
        _values[key]=i;
    } else {
        expression = Expression::Parse(value);
        QVariant exp_result;
        if((exp_result = expression.Calculate()).isValid()){
            _values[key]=exp_result;
        } else{
            _values[key]={};//expression.ToString();
        }
    }
    return true;
}

auto VariableRepository::value(const QString &key) const -> QVariant
{
    return _values.value(key);
}

auto VariableRepository::contains(const QString &key) const -> bool
{
    return _values.contains(key);
}

QString VariableRepository::ToString(const QString& key)
{
    QVariant variable;
    if((variable = GCode::_variables.value(key)).isValid()){
        return variable.toString();
    }
    return L("=???");
}
