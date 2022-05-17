#include "string_conversions/string_conversions.hpp"

std::string operator+(std::string string, std::string_view app){
    return string.append(app);
}