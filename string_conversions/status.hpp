#pragma once

#include <string_view>

#include "include/status.hpp"

std::string_view to_string(Status const name);

Status from_string(std::string_view str);