#pragma once

#include <string_view>

#include "include/type.hpp"

std::string_view to_string(Type const name);

Type from_string(std::string_view str);