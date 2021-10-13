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
        default: return "ERROR type";
    }
}

Type from_string(std::string_view str){
    if(str == "Typeless"){
        return Type::Typeless;
    }
    else if(str == "Normal"){
        return Type::Normal;
    }
    else if(str == "Flying"){
        return Type::Flying;
    }
    else if(str == "Bug"){
        return Type::Bug;
    }
    else if(str == "Poison"){
        return Type::Poison;
    }
    else if(str == "Rock"){
        return Type::Rock;
    }
    else if(str == "Ground"){
        return Type::Ground;
    }
    else if(str == "Fighting"){
        return Type::Fighting;
    }
    else if(str == "Ghost"){
        return Type::Ghost;
    }
    else if(str == "Steel"){
        return Type::Steel;
    }
    else if(str == "Dragon"){
        return Type::Dragon;
    }
    else if(str == "Fire"){
        return Type::Fire;
    }
    else if(str == "Water"){
        return Type::Water;
    }
    else if(str == "Electric"){
        return Type::Electric;
    }
    else if(str == "Grass"){
        return Type::Grass;
    }
    else if(str == "Ice"){
        return Type::Ice;
    }
    else if(str == "Psychic"){
        return Type::Psychic;
    }
    else if(str == "Dark"){
        return Type::Dark;
    }
    else{
        return Type::Fairy;
    }
}