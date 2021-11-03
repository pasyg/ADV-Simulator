#pragma once

#include <string_view>

#include "data/moves.hpp"

std::string_view to_string(Move const name);

Move move_from_string(std::string_view str);
