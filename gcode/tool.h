#ifndef TOOL_H
#define TOOL_H

#include <QString>

struct Tool{
    enum Type:int{None,Milling,Drilling};

    Type type=None;
    int ix=-1;
    qreal d;
    qreal h;

    static Tool Parse(const QString&);
    QString ToString();
    static QChar TypeToGCode(Type t);
    static QString TypeToString(Type t);
};

#endif // TOOL_H
