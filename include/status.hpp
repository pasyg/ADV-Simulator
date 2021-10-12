#pragma once

#include <cstdint>

enum Status : std::uint8_t {
	healthy,
    fainted,
    paralysis,
	freeze,
	sleep_self,
	sleep_inflicted,
	confusion,
	burn,
	poison,
	toxic_poison,
};