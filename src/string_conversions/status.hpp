#pragma once

#include <string_view>

#include "data/status.hpp"

std::string_view to_string(Status const name);

Status status_from_string(std::string_view str);