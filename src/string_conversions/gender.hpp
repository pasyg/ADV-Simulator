#pragma once

#include <unordered_map>
#include <string>
#include <string_view>

#include "data/gender.hpp"

#include "string_conversions/from_string.hpp"

std::string_view to_string(Gender const name);

template<>
auto from_string<Gender>(std::string_view const str) -> Gender;