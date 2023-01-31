#include "keyword.h"
#include "helpers/nameof.h"


auto KeyWord::ToString(Word v) -> QString
{
    switch (v) {
    case Word::Undefined: return {};
    case Word::avg: return nameof(Word::avg);
    case Word::sum: return nameof(Word::sum);
    case Word::sub: return nameof(Word::sub);
    case Word::add: return nameof(Word::add);
    case Word::mul: return nameof(Word::mul);
    case Word::div: return nameof(Word::div);
    }
    return QString();
}

auto KeyWord::Parse(const QString &p) -> KeyWord::Word
{
    if(p==nameof(Word::avg).toLower()) return Word::avg;
    if(p==nameof(Word::sum).toLower()) return Word::sum;
    if(p==nameof(Word::sub).toLower()) return Word::sub;
    if(p==nameof(Word::add).toLower()) return Word::add;
    if(p==nameof(Word::mul).toLower()) return Word::mul;
    if(p==nameof(Word::div).toLower()) return Word::div;
    return Word::Undefined;
}
