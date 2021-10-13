#pragma once

#include <string_view>

#include "include/natures.hpp"

std::string_view to_string(Nature const name);

Nature from_string(std::string_view str);