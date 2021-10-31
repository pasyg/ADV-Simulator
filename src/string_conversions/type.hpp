#pragma once

#include <string_view>

#include "data/type.hpp"

std::string_view to_string(Type const name);

Type type_from_string(std::string_view str);