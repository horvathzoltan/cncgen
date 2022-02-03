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

private:
    qreal _spindleSpeed;
    qreal _feed;
    //bool _isValid;
    static QString _lasterr;
public:
    /*_spindleSpeed*/
    [[nodiscard]] auto spindleSpeed() const -> qreal {return _spindleSpeed;}
    void setSpindleSpeed(qreal s) {_spindleSpeed=s; }
    /*_feed*/
    [[nodiscard]] auto feed() const -> qreal {return _feed;}
    void setFeed(qreal f) { _feed=f;}
    /*_isValid*/
    [[nodiscard]] auto isValid() const -> bool;
    /*_lasterr*/
    static auto lasterr() -> QString{return _lasterr;}

//public:
    Feed();
    Feed(
        qreal spindleSpeed,
        qreal f
        );

    auto ParseIntoFeed(const QString &txt) -> ParseState;
    auto ParseIntoSpindleSpeed(const QString &txt) -> ParseState;

    [[nodiscard]] auto ToString() const -> QString;

    auto ToStringFeed() const -> QString;
    auto ToStringSpindleSpeed() const -> QString;

};

#endif // FEED_H
