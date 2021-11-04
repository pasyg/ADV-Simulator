#pragma once

#include <unordered_map>
#include <string_view>

#include "data/item.hpp"

std::string to_string(Item const name);

Item item_from_string(std::string_view const str);