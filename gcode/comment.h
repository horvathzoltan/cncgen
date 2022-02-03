#ifndef COMMENT_H
#define COMMENT_H

#include <QString>
#include "parsestate.h"

struct Comment
{
public:
    constexpr static const QChar key = '(';
    constexpr static const auto keyUniCode = key.unicode();

    Comment();
    Comment(const QString& _txt);

    static auto Parse(const QString& txt, Comment *l) -> ParseState;

    QString text;
    /*ISVALID*/
//public:
    bool isValid() const {return _isValid;}
private:
    bool _isValid;

    /*LASTERR*/
public:
    static auto lasterr() -> QString{return _lasterr;}
private:
    static QString _lasterr;
};

#endif // COMMENT_H
