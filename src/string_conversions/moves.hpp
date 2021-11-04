#pragma once

#include <unordered_map>
#include <string_view>

#include "data/moves.hpp"

std::string_view to_string(Move const move);

Move move_from_string(std::string_view const str);
