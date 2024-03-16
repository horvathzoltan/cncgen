#ifndef GCODEMANAGER_H
#define GCODEMANAGER_H

#include <QStringList>


class GCodeManager
{
private:
    QStringList _gcodes;
public:
    GCodeManager();
    GCodeManager(const QString& s);

    QString toString(){return _gcodes.join('\n');}
    void clear(){_gcodes.clear();}
    bool Append(const QString &g, const QString& err={},const QString& comment={});
    static bool Append2(QStringList* gs, const QString &g, const QString& err={},const QString& comment={});

    void insert(int i, const QString& r){_gcodes.insert(i, r);}
    void append(const QString& r){_gcodes.append(r);}
    void append(const QStringList& r){_gcodes.append(r);}
    QStringList gcodes(){return _gcodes;}
};

#endif // GCODEMANAGER_H
