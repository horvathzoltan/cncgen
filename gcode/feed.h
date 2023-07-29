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
    qreal _spindleSpeed=-1;
    qreal _feed=-1;
    bool _started=false;
public:    
    /*_spindleSpeed*/
    [[nodiscard]] auto spindleSpeed() const -> qreal {return _spindleSpeed;}
    void setSpindleSpeed(qreal s) {_spindleSpeed=s; }
    /*_feed*/
    [[nodiscard]] auto feed() const -> qreal {return _feed;}
    void setFeed(qreal f) { _feed=f;}
    /*_isValid*/
    [[nodiscard]] auto isValid() const -> bool;
    /*started*/
    [[nodiscard]] auto started() const -> bool {return _started;}
    void setStarted(bool f) { _started=f;}

    /*_lasterr*/
//public:
//    Feed();
//    Feed(
//        qreal spindleSpeed,
//        qreal f
//        );

    static auto Parse(const QString& p, Feed *feed=nullptr) -> ParseState;
//    auto ParseIntoFeed(const QString &txt) -> ParseState;
//    auto ParseIntoSpindleSpeed(const QString &txt) -> ParseState;

    [[nodiscard]] auto ToString() const -> QString;

    auto ToStringFeed() const -> QString;
    auto ToStringSpindleSpeed() const -> QString;

    static auto ToStringFeed(qreal feed) -> QString;
    static auto ToStringSpindleSpeed(qreal spindle_speed) -> QString;

    bool Check(qreal fmin, qreal fmax, QString *err = nullptr) const;
    static bool Check(qreal f, qreal fmin, qreal fmax, QString *err=nullptr);
};

#endif // FEED_H
