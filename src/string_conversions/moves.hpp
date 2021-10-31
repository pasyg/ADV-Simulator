#pragma once

#include <string_view>

#include "moves.hpp"

std::string_view to_string(Move const name);

Move from_string(std::string_view str);
