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