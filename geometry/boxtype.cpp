#include "boxtype.h"
#include "common/macrofactory/macro.h"

auto BoxType::ToString(Type type) -> QString
{
    switch (type) {
    case BoxType::Outline: return nameof(BoxType::Outline);
    case BoxType::Inline: return nameof(BoxType::Inline);
    case BoxType::Corners: return nameof(BoxType::Corners);
    default: return QString();
    }
}

auto BoxType::Parse(const QString &p) -> BoxType::Type
{
    if(p==nameof(BoxType::Outline).toLower()) return BoxType::Outline;
    if(p==nameof(BoxType::Inline).toLower()) return BoxType::Inline;
    if(p==nameof(BoxType::Corners).toLower()) return BoxType::Corners;
    return BoxType::Undefined;
}
