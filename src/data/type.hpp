#pragma once

#include <cstdint>

enum class Type : std::uint8_t {

	// physical types
	Normal,
	Flying,
	Bug,
	Poison,
	Rock,
	Ground,
	Fighting,
	Ghost,
	Steel,

	// special types
	Dragon,
	Fire,
	Water,
	Electric,
	Grass,
	Ice,
	Psychic,
	Dark,

	// bonus
	Fairy,
	Typeless,
	None,
	//
	Hidden_Power
};