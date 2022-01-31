#ifndef CUT_H
#define CUT_H

#include <QString>

struct Cut
{
public:
//    Cut();
//    Cut(
//        qreal _z,
//        qreal _z0
//        );

    qreal z=-1;
    qreal z0=-1;

    //static Cut Parse(const QString& txt);
    QString ToString() const;

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
};

#endif // CUT_H
