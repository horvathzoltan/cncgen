#ifndef STRINGTOGCODE_H
#define STRINGTOGCODE_H

#include <QString>


class StringToGcode
{
public:
    static bool ParseString(const QString& str, QString *gcode, QString *err);
};

#endif // STRINGTOGCODE_H
