#pragma once

#include <unordered_map>

#include "data/weather.hpp"

#include "string_conversions/from_string.hpp"

std::string_view to_string(Weather const name);

template<>
auto from_string<Weather>(std::string_view const str) -> Weather;