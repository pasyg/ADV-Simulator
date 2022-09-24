#pragma once

#include <unordered_map>
#include <string_view>

#include "data/moves.hpp"

#include "string_conversions/from_string.hpp"

std::string_view to_string(Move const move);

template<>
auto from_string<Move>(std::string_view const str) -> Move;
