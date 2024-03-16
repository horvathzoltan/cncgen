#ifndef TOOL_H
#define TOOL_H

#include <QString>
#include "parsestate.h"

struct Tool{
    static constexpr QChar key = 't';
    static constexpr ushort keyUniCode= key.unicode();

    enum Type:int{None,Milling,Drilling};

    Type type=None;
    int ix=-1;
    qreal d=0;
    qreal h=0;

    static ParseState Parse(const QString&, Tool*);
    QString ToString();
    static QChar TypeToGCode(Type t);
    static QString TypeToString(Type t);

    void setD(qreal v){d = v;}
    /*ISVALID*/
//public:
//    bool isValid() const {return _isValid;}
//private:
//    bool _isValid;

    /*LASTERR*/
//public:
//    static QString lasterr(){return _lasterr;}
//private:
//    static QString _lasterr;
};

#endif // TOOL_H
