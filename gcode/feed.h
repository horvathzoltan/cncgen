#ifndef FEED_H
#define FEED_H

#include <QString>
#include "parsestate.h"

struct Feed
{
public:
    static constexpr QChar key_feed = 'f';
    static constexpr ushort keyUniCode_feed= key_feed.unicode();
    static constexpr QChar key_spindleSpeed = 's';
    static constexpr ushort keyUniCode_spindleSpeed= key_spindleSpeed.unicode();
    Feed();
    Feed(
        qreal _spindleSpeed,
        qreal _f
        );

    qreal spindleSpeed=-1;
    qreal f=-1;

    static auto ParseFeed(const QString &txt, Feed* tool) -> ParseState;
    static auto ParseSpindleSpeed(const QString &txt, Feed* tool) -> ParseState;

    QString ToString() const;

    /*ISVALID*/
public:
    bool isValid() const {return _isValid;}
private:
    bool _isValid;

    /*LASTERR*/
public:
    static QString lasterr(){return _lasterr;}
private:
    static QString _lasterr;
};

#endif // FEED_H
