#pragma once

#include <unordered_map>
#include <string_view>

#include "data/status.hpp"

#include "string_conversions/from_string.hpp"

std::string_view to_string(Status const name);

template<>
auto from_string<Status>(std::string_view const str) -> Status;