#ifndef TEXTFILEHELPER_H
#define TEXTFILEHELPER_H

#include <QStringList>
#include <QTextStream>

class TextFileHelper
{
public:
    static QString load(const QString& filename);
    static QStringList loadLines(const QString& filename);
    static bool save(const QString& txt, const QString& fileName, bool isAppend = false);
    static bool backup(const QString& filename);
private:
    static void SetUtf8Encoding(QTextStream *st);
};

#endif // TEXTFILEHELPER_H
