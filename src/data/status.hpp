#pragma once

#include <cstdint>

enum class Status : std::uint8_t {
	Healthy,
    Fainted,
    Paralysis,
	Freeze,
	Sleep_self,
	Sleep_inflicted,
	Confusion,
	Burn,
	Poison,
	Toxic_poison
};