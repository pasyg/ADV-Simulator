#include "define.hpp"

#include "data/type.hpp"

constexpr float no_effect = 0;
constexpr float not_very_effective = 0.5;
constexpr float regular = 1;
constexpr float super_effective = 2;

const float effectiveness(Type const atktype, Type const deftype);