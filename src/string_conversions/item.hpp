#pragma once

#include <unordered_map>
#include <string_view>

#include "data/item.hpp"

#include "string_conversions/from_string.hpp"

std::string_view to_string(Item const name);

template<>
auto from_string<Item>(std::string_view const str) -> Item;