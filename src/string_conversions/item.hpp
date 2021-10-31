#pragma once

#include <string_view>

#include "data/item.hpp"

std::string to_string(Item const name);

Item item_from_string(std::string_view str);