#pragma once

#include "abilities.hpp"
#include "conversion.hpp"

#include <string_view>

auto to_string(Ability const name) -> std::string_view;

template<>
auto from_string<Ability>(std::string_view const str) -> Ability;
