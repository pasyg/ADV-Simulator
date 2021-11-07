#include "string_conversions/gender.hpp"

std::string to_string(Gender const name){
    switch (name)
    {
    case Gender::Male: return "M";
    case Gender::Female: return "F";
    case Gender::Genderless: return " ";
    default: return "ERROR gender";
        break;
    }
}

Gender gender_from_string(std::string_view const str){

    static const std::unordered_map<std::string_view, Gender> map{
        
        {"M", Gender::Male },
        {"F", Gender::Female },
        {"", Gender::Genderless }
    };

    return map.at(str);
}