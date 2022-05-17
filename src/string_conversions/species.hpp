#pragma once

#include <unordered_map>
#include <string_view>

#include "data/species.hpp"

#include "string_conversions/from_string.hpp"

std::string_view to_string(Species const name);

template<>
auto from_string<Species>(std::string_view const str) -> Species;