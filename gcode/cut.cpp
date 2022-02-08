#include "cut.h"

#include "gcode/gcode.h"
#include "messages.h"

//Cut::Cut()
//{
//    _isValid=false;
//}

//Cut::Cut(qreal _z, qreal _z0)
//{
//     z=_z;
//     z0=_z0;
//     _isValid=true;
//}

auto Cut::ToString() const -> QString
{
    QString msg;
    if (z>0) msg+=" z"+ GCode::r(z);
    if (z0>0) msg+=" c"+ GCode::r(z0);
    return msg;
}



bool Cut::ParseInto(const QString& p, ParseState* st)
{
    if(!st) return false;

    if(p.startsWith('z')){
        if(!GCode::ParseValue(p, QStringLiteral("z"), &z)){
            st->addWarn(Messages::cannotParse(Messages::full_cutting_depth,p));
        }
        return true;
    }
    if(p.startsWith('c')){
        if(!GCode::ParseValue(p, QStringLiteral("c"), &z0)){
            st->addWarn(Messages::cannotParse(Messages::cutting_depth,p));
        }
        return true;
    }
    return false;
}
