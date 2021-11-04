#pragma once

#include <unordered_map>
#include <string_view>

#include "data/species.hpp"

std::string_view to_string(Species const name);

Species species_from_string(std::string_view const str);