#include "hole.h"

#include <QStringList>
#include "gcode/gcode.h"

auto Hole::Parse(const QString &txt, XYMode mode) -> Hole
{
    Hole m={};
    auto params=txt.split(' ');
    //int p_ix = 0;
    for(auto&p:params){
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
        else if(p.startsWith('d')){
            bool isok;
            auto d = p.midRef(1).toDouble(&isok);
            if(isok) m.d = d;
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
            m.p=Point::Parse(p, mode);
        }
    }
    return m;
}

auto Hole::ToString() -> QString
{
    return
        "h "+p.ToString()+
        " d"+ GCode::r(d)+
        " z"+ GCode::r(z)+
        " s"+ GCode::r(s);
}
