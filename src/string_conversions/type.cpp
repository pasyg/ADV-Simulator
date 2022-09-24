#include "string_conversions/type.hpp"

std::string_view to_string(Type const name){
    switch(name){
        case Type::Typeless:    return "Typeless";
        case Type::Normal:      return "Normal";
        case Type::Flying:      return "Flying";
        case Type::Bug:         return "Bug";
        case Type::Poison:      return "Poison";
        case Type::Rock:        return "Rock";
        case Type::Ground:      return "Ground";
        case Type::Fighting:    return "Fighting";
        case Type::Ghost:       return "Ghost";
        case Type::Steel:       return "Steel";
        case Type::Dragon:      return "Dragon";
        case Type::Fire:        return "Fire";
        case Type::Water:       return "Water";
        case Type::Electric:    return "Electric";
        case Type::Grass:       return "Grass";
        case Type::Ice:         return "Ice";
        case Type::Psychic:     return "Psychic";
        case Type::Dark:        return "Dark";
        case Type::Fairy:       return "Fairy";
        default:                return "ERROR type";
    }
}

template<>
auto from_string(std::string_view const str) -> Type{
   static const std::unordered_map<std::string_view, Type> map{
       { "Normal", Type::Normal },
       { "Flying", Type::Flying },
       { "Bug", Type::Bug },
       { "Poison", Type::Poison },
       { "Rock", Type::Rock },
       { "Ground", Type::Ground },
       { "Fighting", Type::Fighting },
       { "Ghost", Type::Ghost },
       { "Steel", Type::Steel },
       { "Dragon", Type::Dragon },
       { "Fire", Type::Fire },
       { "Water", Type::Water },
       { "Electric", Type::Electric },
       { "Grass", Type::Grass },
       { "Ice", Type::Ice },
       { "Psychic", Type::Psychic },
       { "Dark", Type::Dark },
       { "Fairy", Type::Fairy },
       { "Typeless", Type::Typeless }
   };
   
   return map.at(str);
}