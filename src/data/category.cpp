#include "category.hpp"


Category move_category(const Type type){
    switch(type){
        case Type::Normal:
        case Type::Flying:
        case Type::Bug:
        case Type::Poison:
        case Type::Rock:
        case Type::Ground:
        case Type::Fighting:
        case Type::Ghost:
        case Type::Steel:
            return Category::Physical;
            break;
        case Type::Dragon:
        case Type::Fire:
        case Type::Water:
        case Type::Electric:
        case Type::Grass:
        case Type::Ice:
        case Type::Psychic:
        case Type::Dark:
            return Category::Special;
            break;
        default:
            return Category::Unknown;
            break;
    }
}