#include "keyword.h"
#include "common/macrofactory/macro.h"


auto KeyWord::ToString(Word v) -> QString
{
    switch (v) {
    case Word::avg: return nameof(Word::avg);
    case Word::sum: return nameof(Word::sum);
    default: return QString();
    }
}

auto KeyWord::Parse(const QString &p) -> KeyWord::Word
{
    if(p==nameof(Word::avg).toLower()) return Word::avg;
    if(p==nameof(Word::sum).toLower()) return Word::sum;
    return Word::Undefined;
}
