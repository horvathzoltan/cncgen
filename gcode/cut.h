#ifndef CUT_H
#define CUT_H

#include <QString>
#include "parsestate.h"

struct Cut
{
public:
    constexpr static const QChar key_TotalDepth = 'z';
    constexpr static const auto keyUniCode_TotalDepth = key_TotalDepth.unicode();
    constexpr static const QChar key_CuttingDepth = 'c';
    constexpr static const auto keyUniCode_CuttingDepth = key_CuttingDepth.unicode();
//    Cut();
//    Cut(
//        qreal _z,
//        qreal _z0
//        );

    qreal z=-1;
    qreal z0=-1;

    //static Cut Parse(const QString& txt);
    [[nodiscard]] auto ToString() const -> QString;

    auto ParseInto(const QString& p, ParseState* st) -> bool;
//    /*ISVALID*/
//public:
//    bool isValid() const {return _isValid;}
//private:
//    bool _isValid;

//    /*LASTERR*/
//public:
//    static QString lasterr(){return _lasterr;}
//private:
//    static QString _lasterr;
    int steps();

    enum CheckR:int{invalid=-1,valid = 0, wrong=1};
    CheckR Check(QString *err) const;
    void Z_Correction();
};

#endif // CUT_H
