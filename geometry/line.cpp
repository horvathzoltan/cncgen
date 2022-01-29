#include "line.h"

#include <QStringList>
#include "gcode/gcode.h"
#include "geometry/geomath.h"
#include "common/logger/log.h"

auto Line::Parse(const QString &txt, XYMode mode) -> Line
{
    Line m={};
    auto params=txt.split(' ');
    int p_ix = 0;
    for(int i=1;i<params.length();i++){
        auto&p =params[i];
        if(p.startsWith('z')){
            bool isok;
            auto z = p.midRef(1).toDouble(&isok);
            if(isok) m.z = z;
        }
        else if(p.startsWith('s')&&p.length()>1&&p[1].isDigit()){
            bool isok;
            auto s = p.midRef(1).toDouble(&isok);
            if(isok) m.s = s;
        }
        else if(p.startsWith(QStringLiteral("sp"))){
            bool isok;
            auto sp = p.midRef(2).toDouble(&isok);
            if(isok) m.sp = sp;
        }
        else if(p.startsWith('f')){
            bool isok;
            auto f = p.midRef(1).toDouble(&isok);
            if(isok) m.f = f;
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

auto Line::ToString() const -> QString
{
    return
        "l "+p0.ToString()+' '+ p1.ToString()+
        " z"+ GCode::r(z)+
        " s"+GCode::r(s);
}

auto Line::Divide(const Gap& g, qreal tool_d) -> QList<Line>
{
    if(g.n<1) return QList<Line>();
    qreal length = GeoMath::Distance(p0, p1);
    if(length<=g.n*g.length) return {};
    int slices = g.n+1;
    if((length-g.n*g.length)/slices<tool_d) return {}; // ha a gapek közti részben nem fér el a szerszám

    QList<Line> m;

    Point kp= p0;
    Point kp2= p0;
    qreal offset = (g.length+tool_d)/2;
    qreal l = length/slices;
    qreal o1 = (l-offset)/l;
    qreal o2 = (l+offset)/l;

    zInfo("slices:"+GCode::r(slices));
    zInfo("offset:"+GCode::r(offset));
    zInfo("length:"+GCode::r(length));
    zInfo("l:"+GCode::r(l));
    zInfo("o1:"+GCode::r(o1));
    zInfo("o2:"+GCode::r(o2));

    for(int i=1;i<slices;i++){
        zInfo("i:"+GCode::r(i));
        auto o = static_cast<qreal>(i)/(slices);
        zInfo("o:"+GCode::r(o));
        Point op ={};
        bool isok = GeoMath::Divider(p0,p1,o,&op);
        if(!isok) continue;
        //Line l = {kp, op, z, s, sp, f};
        Point op1 ={};
        bool isok2 = GeoMath::Divider(kp,op,o1,&op1);
        if(!isok2) continue;
        // line:kp2->op1
        Line l = {kp2, op1, z, s, sp, f};
        m.append(l);
        Point op2 ={};
        bool isok3 = GeoMath::Divider(kp,op,o2,&op2);
        if(!isok3) continue;
        kp = op;
        kp2 = op2;
        //gap:op1->op2
//        Line gap = {op1, op2, z-g.h, s, sp, f};
//        m.append(gap);
    }
    Line lx = {kp2, p1, z, s, sp, f};
    m.append(lx);

    return m;
}


