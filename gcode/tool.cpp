#include "helpers/nameof.h"
#include "tool.h"
#include "gcode.h"

//QString Tool::_lasterr;

auto Tool::Parse(const QString &txt, Tool* tool) -> ParseState
{

    ParseState st(ParseState::NoData);
    //_lasterr.clear();
    if(!tool) return st;
    if(!txt.startsWith(key)) return st;
    st.setState(ParseState::NotParsed);


    Tool m={};
    auto params=txt.split(' ');
    bool isok;
    auto ix = params[0].mid(1).toInt(&isok);
    if(isok && ix>=0 && ix<=6) m.ix = ix;

    QString k = "t"+QString::number(m.ix);

    for(int i=1;i<params.length();i++){
        auto&p = params[i];
        if(p.startsWith('d')&&p.length()>1){
            bool isok;
            auto d = p.mid(1).toDouble(&isok);
            if(isok){
                m.d = d;
                GCode::_variables.setValue(k+"d",m.d);
            }
        } else if(p.startsWith('h')){
            bool isok;
            auto h = p.mid(1).toDouble(&isok);
            if(isok){
                m.h = h;
                GCode::_variables.setValue(k+"h",m.h);
            }
        } else if(p==u'd'){
            m.type = Drilling;
        }
        else if(p==u'm'){
            m.type = Milling;
        }
    }    

    *tool = m;

    st.setState(ParseState::Parsed);
    return st;
}

auto Tool::ToString() -> QString
{
    QString msg = "t"+QString::number(ix);
    if(type!=None){
        msg += ' '+
            TypeToGCode(type)+' '+
            " d"+GCode::r(d)+
            " h"+GCode::r(h);
    }
    return msg;
}

auto Tool::TypeToGCode(Tool::Type t) -> QChar
{
    switch(t){
    case Tool::Type::Milling: return 'm';
    case Tool::Type::Drilling: return 'd';
    default: return QChar();
    }
}

auto Tool::TypeToString(Type t) -> QString
{
    switch(t){
    case Tool::Type::Milling: return nameof(Tool::Type::Milling);
    case Tool::Type::Drilling: return nameof(Tool::Type::Drilling);
    default: return QString();
    }
}
