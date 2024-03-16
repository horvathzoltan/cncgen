#include "helpers/logger.h"
#include "spindle.h"

#include <gcode/gcode.h>

QString Spindle::StartToGCode(qreal spindle_speed, ToGCodeModel *tmm)
{
    auto const M3 = QStringLiteral("m3");

    if(spindle_speed<=0) return {};


    QString err;
    QString sp;
    bool set_ok = SetSpeedToGCode(spindle_speed, &sp, &err, tmm);

    if(set_ok){
        QString g = M3;
        QString comment;

        if(!sp.isEmpty()){ // kellett speedet állítani
            tmm->_last_feed3.setSpindleSpeed(spindle_speed);

            g+=+" "+sp;
            if(!comment.isEmpty()) comment+=", ";
            comment +="set spindle speed";

        } else{
            if(tmm->_last_feed3.started()){
                return {};
            }

        }
        tmm->_last_feed3.setStarted(true);

        if(!comment.isEmpty()) comment+=", ";
        comment += "spindle start";
        g+=" ("+comment+")";
        return g;
    }

    return {};
}

QString Spindle::StopToGCode(ToGCodeModel *tmm)
{
    tmm->_last_feed3.setStarted(false);
    return QStringLiteral("m5 (spindle stop)");
}

bool Spindle::SetSpeedToGCode(qreal spindle_speed, QString *g, QString* err, ToGCodeModel* tmm)
{
    if(spindle_speed<=0){
        if(err) *err = QStringLiteral("no spindle speed available");
        return false;
    }
    if(tmm->_last_feed3.spindleSpeed() != spindle_speed){
        if(g) *g= Feed::ToStringSpindleSpeed(spindle_speed);
    }
    return true;
}
