#pragma once

#include <string_view>

#include "natures.hpp"

std::string_view to_string(Nature const name);

Nature nature_from_string(std::string_view str);