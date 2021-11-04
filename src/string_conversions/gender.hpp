#pragma once

#include <unordered_map>
#include <string_view>

#include "data/gender.hpp"

std::string to_string(Gender const name);

Gender gender_from_string(std::string_view const str);