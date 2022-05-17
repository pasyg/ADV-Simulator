// include file for all string conversions
#pragma once

#include "string_conversions/ability.hpp"
#include "string_conversions/gender.hpp"
#include "string_conversions/item.hpp"
#include "string_conversions/moves.hpp"
#include "string_conversions/nature.hpp"
#include "string_conversions/species.hpp"
#include "string_conversions/status.hpp"
#include "string_conversions/type.hpp"
#include "string_conversions/weather.hpp"

std::string operator+(std::string string, std::string_view app);