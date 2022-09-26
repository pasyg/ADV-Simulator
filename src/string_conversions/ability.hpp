#pragma once

#include <unordered_map>
#include <string_view>

#include "data/abilities.hpp"

#include "string_conversions/from_string.hpp"

std::string_view to_string(Ability const name);

template<>
auto from_string<Ability>(std::string_view const str) -> Ability;