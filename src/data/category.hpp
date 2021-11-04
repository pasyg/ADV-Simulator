#include <cstdint>

#include "type.hpp"

enum class Category : std::uint8_t{
    Physical,
    Special,
    Status,
    Unknown
};

Category move_category(const Type type);