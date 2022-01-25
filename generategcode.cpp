#include "generategcode.h"

QStringList GenerateGcode::Generate(const QStringList &g)
{
    QStringList e;
    for(auto&l:g){
        auto t = l.trimmed();
        if(t.isEmpty()) continue;
        if(t.startsWith('#')) continue;
        if(t.startsWith('(')){
            auto g = GenerateComment(l);
            if(!g.isEmpty()) e.append(g);
            continue;
        }
        if(t.startsWith("l")){
            auto g = GenerateLineHorizontal(l);
            if(!g.isEmpty()) e.append(g);
        }
        else if(t.startsWith("h"))
        {

        }
    }
    return e;
}

QString GenerateGcode::GenerateComment(const QString &txt)
{
    if(!txt.startsWith('(')) return "";
    if(!txt.startsWith(')')) return txt+')';
    return txt;
}


QString GenerateGcode::GenerateLineHorizontal(const QString &txt)
{
    if(!txt.startsWith('l')) return "";
    Line m;
    auto params=txt.split(' ');
    int p_ix = 0;
    for(auto&p:params){
        if(p.startsWith('z')){
            bool isok;
            auto z = p.midRef(1).toDouble(&isok);
            if(isok) m.z = z;
        }
        else if(p.startsWith('s')){
            bool isok;
            auto s = p.midRef(1).toDouble(&isok);
            if(isok) m.s = s;
        }
        else if(p[0].isDigit()){
            auto numbers = p.split(',');
            a,b,c;
            if(XYMode=xy)

            if(p_ix==0){}
        }
    }
    if(!txt.startsWith(')')) return txt+')';
    return txt;
}
