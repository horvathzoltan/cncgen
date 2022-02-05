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
};

#endif // COMMENT_H
