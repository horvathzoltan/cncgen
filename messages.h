#ifndef MESSAGES_H
#define MESSAGES_H

#include <QString>



struct Messages{
    QString tr();
    static const QString invalid_point;// = QStringLiteral("invalid point");
    static const QString zero_feed;// = QStringLiteral("cutting movement with zero feed");
    static const QString zero_spindleSpeed;//= QStringLiteral("cutting movement with zero spindleSpeed");
    static const QString no_feed;// = nameof(no_feed);
    static const QString no_speed;// = nameof(no_speed);
    static const QString cannot_calculate;// = nameof(cannot_calculate);
    static const QString movement_time;// = nameof(movement_time);
    static const QString no_calc_length;// = QStringLiteral("not calculated movement length");
    static const QString cannot_parse;// = QStringLiteral("not calculated movement length");
    static const QString cutting_depth;
    static const QString full_cutting_depth;
    static const QString gap;
    static const QString travelSafe;

    static QString cannotParse(const QString& a, const QString& p);
};

#endif // MESSAGES_H
