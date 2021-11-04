#include "string_conversions/gender.hpp"

std::string to_string(Gender const name){
    switch (name)
    {
    case Gender::male: return "M";
    case Gender::female: return "F";
    case Gender::genderless: return " ";
    default: return "ERROR gender";
        break;
    }
}

Gender gender_from_string(std::string_view const str){

    static std::unordered_map<std::string_view, Gender> map{
        
        {"M", Gender::male },
        {"F", Gender::female },
        {"", Gender::genderless }
    };

    return map[str];
}