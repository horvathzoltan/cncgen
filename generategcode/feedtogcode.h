#ifndef FEEDTOGCODE_H
#define FEEDTOGCODE_H

#include "generategcode/togcodemodel.h"
#include "qglobal.h"

class FeedToGCode
{
public:
    static bool ParseFeed(const QString& str, ToGCodeModel* tmm);//, QString *gcode, QString *err);

    static bool SetToGCode(qreal feed, QString *g, QString *err, ToGCodeModel* mm);
};

#endif // FEEDTOGCODE_H
