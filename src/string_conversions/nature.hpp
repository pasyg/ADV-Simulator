#pragma once

#include <unordered_map>
#include <string_view>

#include "natures.hpp"

#include "string_conversions/from_string.hpp"

std::string_view to_string(Nature const name);

template<>
auto from_string<Nature>(std::string_view const str) -> Nature;