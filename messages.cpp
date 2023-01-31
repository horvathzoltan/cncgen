#include "messages.h"
#include "helpers/nameof.h"

const QString Messages::invalid_point = QStringLiteral("invalid point");
const QString Messages::zero_feed = QStringLiteral("cutting movement with zero feed");
const QString Messages::zero_spindleSpeed = QStringLiteral("cutting movement with zero spindleSpeed");
const QString Messages::no_feed = nameof(no_feed);
const QString Messages::no_speed = nameof(no_speed);
const QString Messages::cannot_calculate = nameof(cannot_calculate);
const QString Messages::movement_time = nameof(movement_time);
const QString Messages::no_calc_length = QStringLiteral("not calculated movement length");
const QString Messages::cannot_parse = nameof(cannot_parse);
const QString Messages::cutting_depth = nameof(cutting_depth);
const QString Messages::full_cutting_depth = nameof(full_cutting_depth);
const QString Messages::gap = nameof(gap);
const QString Messages::travelSafe = QStringLiteral("travel to safe place");


QString Messages::cannotParse(const QString &a, const QString &p)
{
    QString msg(cannot_parse);
    msg[0].toUpper();
    if(!a.isEmpty()){msg+' '+a;}
    msg += ":'"+p+'\'';
    msg = msg.replace('_',' ');
    return msg;
}
