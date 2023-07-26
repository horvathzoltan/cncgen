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
    //qreal movZ(){ return _movZ; }
    //qreal maxZ(){ return _maxZ; }
private:
    QMap<QString,QVariant> _values;
    //QMap<QString,Expression> _expressions;
    //qreal _movZ=2;
    //qreal _maxZ=4;
};

#endif // VARIABLE_H
