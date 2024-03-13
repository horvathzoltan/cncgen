#include "helpers/textfilehelper.h"
#include "helpers/logger.h"

#include <QFileInfo>

#include <QTextStream>

void TextFileHelper::SetUtf8Encoding(QTextStream* st)
{
    if(st==nullptr) return;
#if QT_VERSION >= 0x050000 && QT_VERSION < 0x060000
    st->setCodec("UTF-8"); //5.15.2
#elif QT_VERSION >= 0x06
    st->setEncoding(QStringConverter::Utf8);
#endif
}

QString TextFileHelper::load(const QString& filename) {
    QFileInfo fi(filename);
    if(!fi.isAbsolute())
    {
        zInfo(QStringLiteral("path is not absolute: %1").arg(filename));
        return QString();
    }

    if(!fi.exists())
    {
        zInfo(QStringLiteral("file not exist: %1").arg(filename));
        return QString();
    }

    QFile f(filename);
    QString e0;

    // TODO ha relatív a filename, akkor abszolúttá kell tenni
    // egyébként megnyitható azaz

    if (f.open(QFile::ReadOnly | QFile::Text))  {
        zInfo(QStringLiteral("loaded: %1").arg(filename));
        QTextStream st(&f);
        SetUtf8Encoding(&st);
        e0 = st.readAll();
    }
    else{
        zInfo(QStringLiteral("cannot read file (%1): %2").arg(f.errorString(),filename));
        e0= QString();
    }
    return e0;
}

QStringList TextFileHelper::loadLines(const QString& filename) {
    QFileInfo fi(filename);
    if(!fi.isAbsolute())
    {
        zInfo(QStringLiteral("path is not absolute: %1").arg(filename));
        return QStringList();
    }

    if(!fi.exists())
    {
        zInfo(QStringLiteral("file not exist: %1").arg(filename));
        return QStringList();
    }

    QFile f(filename);
    QStringList e;

    // TODO ha relatív a filename, akkor abszolúttá kell tenni
    // egyébként megnyitható azaz

    if (f.open(QFile::ReadOnly | QFile::Text))  {
        zInfo(QStringLiteral("loaded: %1").arg(filename));
        QTextStream st(&f);
        SetUtf8Encoding(&st);

        while (!st.atEnd())
        {
            e << st.readLine();
        }
        f.close();

    }
    else{
        zInfo(QStringLiteral("cannot read file (%1): %2").arg(f.errorString(),filename));
        e= QStringList();
    }
    return e;
}


bool TextFileHelper::save(const QString& txt, const QString& fn, bool isAppend) {

    QFile f(fn);

    auto om = QIODevice::WriteOnly | QIODevice::Text; // openmode
    if(isAppend) om |= QIODevice::Append;

    if (!f.open(om)){
        zInfo(QStringLiteral("cannot write file (%1): %2").arg(f.errorString(),fn));
        return false;
        }

    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QTextStream out(&f);
    //out.setCodec(QTextCodec::codecForName("UTF-8"));
    //out.setGenerateByteOrderMark(true);
    out << txt;//.toUtf8();
    f.close();
    return true;
}

