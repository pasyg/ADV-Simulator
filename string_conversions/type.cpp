#include "string_conversions/type.hpp"

std::string_view to_string(Type const name){
    switch(name){
        case Type::Typeless: return "Typeless";
        case Type::Normal: return "Normal";
        case Type::Flying: return "Flying";
        case Type::Bug: return "Bug";
        case Type::Poison: return "Poison";
        case Type::Rock: return "Rock";
        case Type::Ground: return "Ground";
        case Type::Fighting: return "Fighting";
        case Type::Ghost: return "Ghost";
        case Type::Steel: return "Steel";
        case Type::Dragon: return "Dragon";
        case Type::Fire: return "Fire";
        case Type::Water: return "Water";
        case Type::Electric: return "Electric";
        case Type::Grass: return "Grass";
        case Type::Ice: return "Ice";
        case Type::Psychic: return "Psychic";
        case Type::Dark: return "Dark";
        case Type::Fairy: return "Fairy";
    }
}