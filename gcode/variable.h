#ifndef VARIABLE_H
#define VARIABLE_H

#include <QVariant>

class VariableRepository
{
public:
    VariableRepository();

    void Clear();
    auto Parse(const QString& p) -> bool;
    QVariant value(const QString& key) const;
    bool contains(const QString& key) const;
    QVariant expression(const QString& key) const;
    QString ToString(const QString& key);
private:
    QMap<QString,QVariant> _values;
    //QMap<QString,Expression> _expressions;
};

#endif // VARIABLE_H
