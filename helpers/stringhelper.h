#ifndef STRINGHELPER_H
#define STRINGHELPER_H

#include <QString>

#define STRINGIFY(msg) #msg
#define STRING(msg) QStringLiteral(STRINGIFY(msg))
#define L(msg) QStringLiteral(msg)

class StringHelper{
public:
    static auto isNumber(const QString& str) -> bool;

    static auto isLetterOrNumber(const QString& str) -> bool;

    static void Append(QString *s1, const QString& s2, QChar u=' ');

    static void Tabulate(QString *s1, const QString& s2);

    static QString Tabulate2(const QString& s);

};
#endif // STRINGHELPER_H
