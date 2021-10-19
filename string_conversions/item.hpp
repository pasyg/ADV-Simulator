#pragma once

#include <string_view>

#include "include/item.hpp"

std::string to_string(Item const name);

Item from_string(std::string_view str);