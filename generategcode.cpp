#include "common/logger/log.h"
#include "generategcode.h"

auto GenerateGcode::Generate(const QStringList &g) -> QStringList
{
    gcodes.clear();
    for(auto l:g){
        l = l.trimmed().toLower();
        if(l.isEmpty()) continue;
        switch(l[0].unicode()){
            case u'#':break;
            case u'(':AppendGcode(GenerateComment(l));break;
            case u'y':
            case u'x':setXYMode(l);break;
            case u'l':AppendGcode(GenerateLineHorizontal(l));break;
            //case u'h':AppendGcode(GenerateHole(l));break;
        }
    }
    return gcodes;
}

auto GenerateGcode::AppendGcode(const QString &g) -> bool
{
    if(g.isEmpty()) return false;
    gcodes.append(g);
    return true;
}

auto GenerateGcode::setXYMode(const QString &txt) -> bool
{
    if(txt==QStringLiteral("xyz")){ _XYMode=XY; return true;}
    if(txt==QStringLiteral("yxz")){_XYMode=YX; return true;}
    return false;
}



auto GenerateGcode::ParsePoint(const QString &txt) -> GenerateGcode::Point
{
    return Point::Parse(txt, _XYMode);
}

auto GenerateGcode::ParseLine(const QString &txt) -> GenerateGcode::Line
{
    return Line::Parse(txt, _XYMode);
}

auto GenerateGcode::Point::Parse(const QString &txt, XYMode mode) -> GenerateGcode::Point
{
    if(txt.isEmpty()) return {0,0,0};
    auto ns = txt.split(',');
    if(ns.length()>=2){
        bool isok_a, isok_b, isok_c=false;
        auto a = ns[0].toDouble(&isok_a);
        auto b = ns[1].toDouble(&isok_b);
        bool has_c = (ns.length()>=3);
        auto c = has_c?ns[2].toDouble(&isok_c):0;
        if(mode==YX) return {b,a,c};
        return {a,b,c};
    }
    return {0,0,0};
}

auto GenerateGcode::Point::ToString() -> QString
{
    return QString::number(x)+','+QString::number(y)+','+QString::number(z);
}

auto GenerateGcode::Line::Parse(const QString &txt, XYMode mode) -> GenerateGcode::Line
{
    Line m={};
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
            if(p_ix==0){
                m.p0=Point::Parse(p, mode);
            }
            else if(p_ix==1){
                m.p1=Point::Parse(p, mode);
            }
            p_ix++;
        }
    }
    return m;
}

auto GenerateGcode::Line::ToString() -> QString
{
    return "l "+p0.ToString()+' '+ p1.ToString()+
        " z"+ QString::number(z)+" s"+QString::number(s);
}

/**/

auto GenerateGcode::GenerateComment(const QString &txt) -> QString
{
    if(!txt.startsWith('(')) return QString();
    if(!txt.endsWith(')')) return txt+')';
    return txt;
}

auto GenerateGcode::GenerateLineHorizontal(const QString &txt) -> QString
{
    if(!txt.startsWith('l')) return QString();
    auto m = ParseLine(txt);
    auto g = "G:"+m.ToString();
    zInfo(g);
    return g;
}
