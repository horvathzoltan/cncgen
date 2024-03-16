#ifndef COMMENTTOGCODE_H
#define COMMENTTOGCODE_H

#include <QString>


class CommentToGCode
{
public:
    static bool ParseComment(const QString &str, QString *gcode, QString *err);
};

#endif // COMMENTTOGCODE_H
