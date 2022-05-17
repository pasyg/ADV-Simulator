#pragma once

#include <unordered_map>
#include <string_view>

#include "data/type.hpp"

#include "string_conversions/from_string.hpp"

std::string_view to_string(Type const name);

template<>
auto from_string<Type>(std::string_view const str) -> Type;