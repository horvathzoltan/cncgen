#ifndef GCODE_H
#define GCODE_H

#include <QString>
#include "geometry/xymode.h"
#include "geometry/mmode.h"
#include "geometry/boxtype.h"
#include "gcode/variable.h"

class GCode{
public:
    //static bool init(VariableRepository *variables);

    static QString r(qreal x);
    static QString i(int x);
    static bool ParseValue(const QString &p, const QChar &key, qreal *v);
    static bool ParseValue(const QString&p, const QString&key, qreal*v);
    static bool ParseValue(const QString&p, const QString&key, int*v);
    static bool ParseValues(const QString&p, const QString&key, QList<int>*v);
    static bool ParseValue(const QString&p, const QString&key, QString*v);
    static bool ParseValueXYZ(const QString &p, qreal *x, qreal*y, qreal *z, XYMode mode, MMode mm);
    //static bool ParseValue(const QString&p, BoxType::Type *v);
    static bool ToDouble(const QString &a, qreal *v);
    //static bool Clear();
//private:
    //static bool _isinited;
    //static VariableRepository* _variables;
    static VariableRepository _variables;
};

#endif // GCODE_H
