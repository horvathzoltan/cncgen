#include "common/logger/log.h"
#include "generategcode.h"
#include <QtMath>

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
            case u'h':AppendGcode(GenerateHole(l));break;
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

auto GenerateGcode::rToGcode(qreal x) -> QString{
    return QString::number(x, 'f', 3);
}

//QString GenerateGcode::Point::ToGcode()
//{
//    return 'x'+rToGcode(x)+' '+'y'+rToGcode(y)+' '+'z'+rToGcode(z);
//}

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

QString GenerateGcode::Gcode(GMode i){
    switch(i){
        case Rapid:return "G0";
        case Linear:return "G1";
        case Circular:return "G2";
    }
}

QString GenerateGcode::Point::GoToZ(GMode i)
{
    return Gcode(i)+" z"+rToGcode(z);
}

QString GenerateGcode::Point::GoToXY(GMode i)
{
    return Gcode(i)+" x"+rToGcode(x)+'y'+rToGcode(y);
}

QString GenerateGcode::Point::GoToXYZ(GMode i)
{
    return Gcode(i)+" x"+rToGcode(x)+'y'+rToGcode(y)+'z'+rToGcode(z);
}

QString GenerateGcode::LiftUp(QVariant z=QVariant())
{
    QStringList g;

    if(!z.isNull())g.append(Gcode(Linear)+ " z"+rToGcode(z.value<double>())+" (pull)");
    g.append(Gcode(Rapid)+ " z"+rToGcode(_movZ)+" (lift up)");

    return g.join('\n');
}

QString GenerateGcode::LiftDown(qreal z)
{
    QStringList g;

    g.append(Gcode(Rapid)+ " z"+rToGcode(z+1)+" (lift down)");
    g.append(Gcode(Linear)+ " z"+rToGcode(z)+" (push)");

    return g.join('\n');
}

QString GenerateGcode::TravelXY(Point p)
{
    QStringList g;

    g.append(LiftUp());
    g.append(p.GoToXY(Rapid)+" (travel)");

    return g.join('\n');
}

/*GENERATE GEOMETRY*/

auto GenerateGcode::GenerateLineHorizontal(const QString &txt) -> QString
{
    if(!txt.startsWith('l')) return QString();    

    auto m = ParseLine(txt);
    auto msg = "G:"+m.ToString();

    QStringList g;
    Point p = m.p0;

    g.append(TravelXY(p));
    g.append(LiftDown(m.p0.z));

    int steps = qCeil(m.z/m.s)+1;
    QString msg2 = " (steps="+QString::number(steps)+')';

    for(int i=0;i<steps;i++){
        if(!(i%2))
        {
            p=m.p1;
        }
        else
        {
            p=m.p0;
        }
        qreal z = p.z-(i+1)*m.s;

        if(z<p.z-m.z) p.z = p.z-m.z; else p.z = z;

        g.append(p.GoToXYZ(Linear));
    }

    g.append(LiftUp(m.p1.z));

    zInfo(msg +' ' + msg2);
    zInfo(g);
    return g.join('\n');
}

/*
(luk 3)

O 2108
G01 F300.00
g00 z2
G00 X#101Y#102
g00 z0
#100=0
M98 P2208 L[2.8/0.15]
G00 z2
G01 F150.00
M99

O2208
#100=[#100-0.15]
G01z#100
G2 X#101Y#102 i0.5000j0
M99


(luk 5)

O 2109
G01 F300.00
g00 z2
G00 X#101Y#102
g00 z0
#100=0
#103=[[#103/2.0]-1.0]
M98 P2209 L[2.8/0.15]
G00 z2
G01 F150.00
M99

O2209
#100=[#100-0.15]
G01z#100
G2 X#101Y#102 i#103j0
M99
*/
auto GenerateGcode::GenerateHole(const QString &txt) -> QString
{
    if(!txt.startsWith('h')) return QString();

    auto m = ParseHole(txt);
    auto msg = "G:"+m.ToString();

    QStringList g;
    Point p = m.p0;

    g.append(TravelXY(p));
    g.append(LiftDown(m.p0.z));

    int steps = qCeil(m.z/m.s)+1;
    QString msg2 = " (steps="+QString::number(steps)+')';

    for(int i=0;i<steps;i++){
        if(!(i%2))
        {
            p=m.p1;
        }
        else
        {
            p=m.p0;
        }
        qreal z = p.z-(i+1)*m.s;

        if(z<p.z-m.z) p.z = p.z-m.z; else p.z = z;

        g.append(p.GoToXYZ(Linear));
    }

    g.append(LiftUp(m.p1.z));

    zInfo(msg +' ' + msg2);
    //zInfo(g);
    return g.join('\n');
}
