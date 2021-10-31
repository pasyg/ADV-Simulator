#include "item.hpp"

bool const damage_boosting(const Item item){
    switch(item){
        case Item::blackbelt:
        case Item::sharpbeak:
        case Item::metalcoat:
        case Item::poisonbarb:
        case Item::softsand:
        case Item::silkscarf:
        case Item::spelltag:
        case Item::blackglasses:
        case Item::charcoal:
        case Item::magnet:
        case Item::dragonfang:
        case Item::miracleseed:
        case Item::mysticwater:
        case Item::seaincense:
        case Item::nevermeltice:
        case Item::twistedspoon:
            return true;
        default:
            return false;
    }
}