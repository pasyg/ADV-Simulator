#pragma once

#include <string_view>

template<typename T>
auto from_string(std::string_view string) -> T;