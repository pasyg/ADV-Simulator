#pragma once

#include <cstdint>

enum class Type : std::uint8_t {

	//physical types
	Normal,
	Flying,
	Bug,
	Poison,
	Rock,
	Ground,
	Fighting,
	Ghost,

	//special types
	Dragon,
	Fire,
	Water,
	Electric,
	Grass,
	Ice,
	Psychic,

	//later gens
	Dark,
	Fairy,
	Steel,
	Typeless
};