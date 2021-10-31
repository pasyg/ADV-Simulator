#pragma once

#include <string_view>

#include "data/abilities.hpp"

std::string_view to_string(Ability const name);

Ability ability_from_string(std::string_view str);