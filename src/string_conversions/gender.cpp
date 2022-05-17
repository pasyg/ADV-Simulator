#include "string_conversions/gender.hpp"

std::string_view to_string(Gender const name){
    switch (name)
    {
    case Gender::Male: return "M";
    case Gender::Female: return "F";
    case Gender::Genderless: return " ";
    default: return "ERROR gender";
        break;
    }
}

template<>
auto from_string(std::string_view const str) -> Gender{
    static const std::unordered_map<std::string_view, Gender> map{
        {"M", Gender::Male },
        {"F", Gender::Female },
        {"", Gender::Genderless }
    };

    return map.at(str);
}