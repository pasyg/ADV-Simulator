#include "define.hpp"

#include "data/type.hpp"

constexpr float no_effect = 0;
constexpr float not_very_effective = 0.5;
constexpr float regular = 1.0;
constexpr float super_effective = 2.0;

const float effectiveness(Type const &atktype, Type const &deftype);