#ifndef FEED_H
#define FEED_H

#include <QString>

struct Feed
{
public:
//    Feed();
//    Feed(
//        qreal _spindleSpeed,
//        qreal _f
//        );

    qreal spindleSpeed=-1;
    qreal f=-1;

//    static Feed Parse(const QString& txt);
    QString ToString() const;

    /*ISVALID*/
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

#endif // FEED_H
