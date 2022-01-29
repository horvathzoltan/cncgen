#ifndef BOXTYPE_H
#define BOXTYPE_H

#include <QString>

class BoxType{
public:
    enum Type:int {Undefined=-1, Outline=0, Inline, Corners};

    static QString ToString(Type type);
    static BoxType::Type Parse(const QString &p);
};

#endif // BOXTYPE_H
