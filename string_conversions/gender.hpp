#pragma once

#include <string_view>

#include "include/gender.hpp"

std::string to_string(Gender const name);

Gender from_string(std::string_view str);