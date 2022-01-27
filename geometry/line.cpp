#include "line.h"

#include <QStringList>
#include "gcode.h"

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

auto Line::ToString() -> QString
{
    return
        "l "+p0.ToString()+' '+ p1.ToString()+
        " z"+ GCode::r(z)+
        " s"+GCode::r(s);
}
