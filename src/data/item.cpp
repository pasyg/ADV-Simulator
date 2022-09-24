#include "item.hpp"

bool const damage_boosting(const Item item){
    switch(item){
        case Item::Blackbelt:
        case Item::Sharpbeak:
        case Item::Metalcoat:
        case Item::Poisonbarb:
        case Item::Softsand:
        case Item::Silkscarf:
        case Item::Spelltag:
        case Item::Blackglasses:
        case Item::Charcoal:
        case Item::Magnet:
        case Item::Dragonfang:
        case Item::Miracleseed:
        case Item::Mysticwater:
        case Item::Seaincense:
        case Item::Nevermeltice:
        case Item::Twistedspoon:
            return true;
        default:
            return false;
    }
}