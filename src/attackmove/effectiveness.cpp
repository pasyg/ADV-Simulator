#include "effectiveness.hpp"


const float effectiveness(Type const &atktype, Type const &deftype)
{
    switch (atktype) 
	{
		case Type::Bug: switch (deftype) 
		{
			case Type::Bug: return constants::regular;
			case Type::Dark: return constants::super_effective;
			case Type::Dragon: return constants::regular;
			case Type::Electric: return constants::regular;
			case Type::Fairy: return constants::not_very_effective;
			case Type::Fighting: return constants::not_very_effective;
			case Type::Fire: return constants::not_very_effective;
			case Type::Flying: return constants::not_very_effective;
			case Type::Ghost: return constants::not_very_effective;
			case Type::Grass: return constants::super_effective;
			case Type::Ground: return constants::regular;
			case Type::Ice: return constants::regular;
			case Type::Normal: return constants::regular;
			case Type::Poison: return constants::not_very_effective;
			case Type::Psychic: return constants::super_effective;
			case Type::Rock: return constants::regular;
			case Type::Steel: return constants::not_very_effective;
			case Type::Water: return constants::regular;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR BUG effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Dark: switch (deftype) 
		{
			case Type::Bug: return constants::regular;
			case Type::Dark: return constants::not_very_effective;
			case Type::Dragon: return constants::regular;
			case Type::Electric: return constants::regular;
			case Type::Fairy: return constants::not_very_effective;
			case Type::Fighting: return constants::not_very_effective;
			case Type::Fire: return constants::regular;
			case Type::Flying: return constants::regular;
			case Type::Ghost: return constants::super_effective;
			case Type::Grass: return constants::regular;
			case Type::Ground: return constants::regular;
			case Type::Ice: return constants::regular;
			case Type::Normal: return constants::regular;
			case Type::Poison: return constants::regular;
			case Type::Psychic: return constants::super_effective;
			case Type::Rock: return constants::regular;
			case Type::Steel: return constants::not_very_effective;
			case Type::Water: return constants::regular;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR DARK effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Dragon: switch (deftype) 
		{
			case Type::Bug: return constants::regular;
			case Type::Dark: return constants::regular;
			case Type::Dragon: return constants::super_effective;
			case Type::Electric: return constants::regular;
			case Type::Fairy: return constants::no_effect;
			case Type::Fighting: return constants::regular;
			case Type::Fire: return constants::regular;
			case Type::Flying: return constants::regular;
			case Type::Ghost: return constants::regular;
			case Type::Grass: return constants::regular;
			case Type::Ground: return constants::regular;
			case Type::Ice: return constants::regular;
			case Type::Normal: return constants::regular;
			case Type::Poison: return constants::regular;
			case Type::Psychic: return constants::regular;
			case Type::Rock: return constants::regular;
			case Type::Steel: return constants::not_very_effective;
			case Type::Water: return constants::regular;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR DRAGON effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Electric: switch (deftype) 
		{
			case Type::Bug: return constants::regular;
			case Type::Dark: return constants::regular;
			case Type::Dragon: return constants::not_very_effective;
			case Type::Electric: return constants::not_very_effective;
			case Type::Fairy: return constants::regular;
			case Type::Fighting: return constants::regular;
			case Type::Fire: return constants::regular;
			case Type::Flying: return constants::super_effective;
			case Type::Ghost: return constants::regular;
			case Type::Grass: return constants::not_very_effective;
			case Type::Ground: return constants::no_effect;
			case Type::Ice: return constants::regular;
			case Type::Normal: return constants::regular;
			case Type::Poison: return constants::regular;
			case Type::Psychic: return constants::regular;
			case Type::Rock: return constants::regular;
			case Type::Steel: return constants::regular;
			case Type::Water: return constants::super_effective;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR ELECTRIC effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Fairy: switch (deftype) 
		{
			case Type::Bug: return constants::regular;
			case Type::Dark: return constants::super_effective;
			case Type::Dragon: return constants::super_effective;
			case Type::Electric: return constants::regular;
			case Type::Fairy: return constants::regular;
			case Type::Fighting: return constants::super_effective;
			case Type::Fire: return constants::not_very_effective;
			case Type::Flying: return constants::regular;
			case Type::Ghost: return constants::regular;
			case Type::Grass: return constants::regular;
			case Type::Ground: return constants::regular;
			case Type::Ice: return constants::regular;
			case Type::Normal: return constants::regular;
			case Type::Poison: return constants::not_very_effective;
			case Type::Psychic: return constants::regular;
			case Type::Rock: return constants::regular;
			case Type::Steel: return constants::not_very_effective;
			case Type::Water: return constants::regular;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR FAIRY effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Fighting: switch (deftype) 
		{
			case Type::Bug: return constants::not_very_effective;
			case Type::Dark: return constants::super_effective;
			case Type::Dragon: return constants::regular;
			case Type::Electric: return constants::regular;
			case Type::Fairy: return constants::not_very_effective;
			case Type::Fighting: return constants::regular;
			case Type::Fire: return constants::regular;
			case Type::Flying: return constants::not_very_effective;
			case Type::Ghost: return constants::no_effect;
			case Type::Grass: return constants::regular;
			case Type::Ground: return constants::regular;
			case Type::Ice: return constants::super_effective;
			case Type::Normal: return constants::super_effective;
			case Type::Poison: return constants::not_very_effective;
			case Type::Psychic: return constants::not_very_effective;
			case Type::Rock: return constants::super_effective;
			case Type::Steel: return constants::super_effective;
			case Type::Water: return constants::regular;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR FIGHTING effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Fire: switch (deftype) 
		{
			case Type::Bug: return constants::super_effective;
			case Type::Dark: return constants::regular;
			case Type::Dragon: return constants::not_very_effective;
			case Type::Electric: return constants::regular;
			case Type::Fairy: return constants::regular;
			case Type::Fighting: return constants::regular;
			case Type::Fire: return constants::not_very_effective;
			case Type::Flying: return constants::regular;
			case Type::Ghost: return constants::regular;
			case Type::Grass: return constants::super_effective;
			case Type::Ground: return constants::regular;
			case Type::Ice: return constants::super_effective;
			case Type::Normal: return constants::regular;
			case Type::Poison: return constants::regular;
			case Type::Psychic: return constants::regular;
			case Type::Rock: return constants::not_very_effective;
			case Type::Steel: return constants::super_effective;
			case Type::Water: return constants::not_very_effective;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR FIRE effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Flying: switch (deftype) 
		{
			case Type::Bug: return constants::super_effective;
			case Type::Dark: return constants::regular;
			case Type::Dragon: return constants::regular;
			case Type::Electric: return constants::not_very_effective;
			case Type::Fairy: return constants::regular;
			case Type::Fighting: return constants::super_effective;
			case Type::Fire: return constants::regular;
			case Type::Flying: return constants::regular;
			case Type::Ghost: return constants::regular;
			case Type::Grass: return constants::super_effective;
			case Type::Ground: return constants::regular;
			case Type::Ice: return constants::regular;
			case Type::Normal: return constants::regular;
			case Type::Poison: return constants::regular;
			case Type::Psychic: return constants::regular;
			case Type::Rock: return constants::not_very_effective;
			case Type::Steel: return constants::not_very_effective;
			case Type::Water: return constants::regular;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR FLYING effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Ghost: switch (deftype) 
		{
			case Type::Bug: return constants::regular;
			case Type::Dark: return constants::not_very_effective;
			case Type::Dragon: return constants::regular;
			case Type::Electric: return constants::regular;
			case Type::Fairy: return constants::regular;
			case Type::Fighting: return constants::regular;
			case Type::Fire: return constants::regular;
			case Type::Flying: return constants::regular;
			case Type::Ghost: return constants::super_effective;
			case Type::Grass: return constants::regular;
			case Type::Ground: return constants::regular;
			case Type::Ice: return constants::regular;
			case Type::Normal: return constants::no_effect;
			case Type::Poison: return constants::regular;
			case Type::Psychic: return constants::super_effective;
			case Type::Rock: return constants::regular;
			case Type::Steel: return constants::not_very_effective;
			case Type::Water: return constants::regular;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR GHOST effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Grass: switch (deftype) 
		{
			case Type::Bug: return constants::not_very_effective;
			case Type::Dark: return constants::regular;
			case Type::Dragon: return constants::not_very_effective;
			case Type::Electric: return constants::regular;
			case Type::Fairy: return constants::regular;
			case Type::Fighting: return constants::regular;
			case Type::Fire: return constants::not_very_effective;
			case Type::Flying: return constants::not_very_effective;
			case Type::Ghost: return constants::regular;
			case Type::Grass: return constants::not_very_effective;
			case Type::Ground: return constants::super_effective;
			case Type::Ice: return constants::regular;
			case Type::Normal: return constants::regular;
			case Type::Poison: return constants::not_very_effective;
			case Type::Psychic: return constants::regular;
			case Type::Rock: return constants::super_effective;
			case Type::Steel: return constants::not_very_effective;
			case Type::Water: return constants::super_effective;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR GRASS effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Ground: switch (deftype) 
		{
			case Type::Bug: return constants::not_very_effective;
			case Type::Dark: return constants::regular;
			case Type::Dragon: return constants::regular;
			case Type::Electric: return constants::super_effective;
			case Type::Fairy: return constants::regular;
			case Type::Fighting: return constants::regular;
			case Type::Fire: return constants::super_effective;
			case Type::Flying: return constants::no_effect;
			case Type::Ghost: return constants::regular;
			case Type::Grass: return constants::not_very_effective;
			case Type::Ground: return constants::regular;
			case Type::Ice: return constants::regular;
			case Type::Normal: return constants::regular;
			case Type::Poison: return constants::super_effective;
			case Type::Psychic: return constants::regular;
			case Type::Rock: return constants::super_effective;
			case Type::Steel: return constants::super_effective;
			case Type::Water: return constants::regular;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR GROUND effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Ice: switch (deftype) 
		{
			case Type::Bug: return constants::regular;
			case Type::Dark: return constants::regular;
			case Type::Dragon: return constants::super_effective;
			case Type::Electric: return constants::regular;
			case Type::Fairy: return constants::regular;
			case Type::Fighting: return constants::regular;
			case Type::Fire: constants::not_very_effective;
			case Type::Flying: return constants::super_effective;
			case Type::Ghost: return constants::regular;
			case Type::Grass: return constants::super_effective;
			case Type::Ground: return constants::super_effective;
			case Type::Ice: return constants::not_very_effective;
			case Type::Normal: return constants::regular;
			case Type::Poison: return constants::regular;
			case Type::Psychic: return constants::regular;
			case Type::Rock: return constants::regular;
			case Type::Steel: return constants::not_very_effective;
			case Type::Water: return constants::not_very_effective;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR ICE effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Normal: switch (deftype) 
		{
			case Type::Bug: return constants::regular;
			case Type::Dark: return constants::regular;
			case Type::Dragon: return constants::regular;
			case Type::Electric: return constants::regular;
			case Type::Fairy: return constants::regular;
			case Type::Fighting: return constants::regular;
			case Type::Fire: return constants::regular;
			case Type::Flying: return constants::regular;
			case Type::Ghost: return constants::no_effect;
			case Type::Grass: return constants::regular;
			case Type::Ground: return constants::regular;
			case Type::Ice: return constants::regular;
			case Type::Normal: return constants::regular;
			case Type::Poison: return constants::regular;
			case Type::Psychic: return constants::regular;
			case Type::Rock: return constants::not_very_effective;
			case Type::Steel: return constants::not_very_effective;
			case Type::Water: return constants::regular;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR NORMAL effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Poison: switch (deftype) 
		{
			case Type::Bug: return constants::regular;
			case Type::Dark: return constants::regular;
			case Type::Dragon: return constants::regular;
			case Type::Electric: return constants::regular;
			case Type::Fairy: return constants::super_effective;
			case Type::Fighting: return constants::regular;
			case Type::Fire: return constants::regular;
			case Type::Flying: return constants::regular;
			case Type::Ghost: return constants::not_very_effective;
			case Type::Grass: return constants::super_effective;
			case Type::Ground: return constants::not_very_effective;
			case Type::Ice: return constants::regular;
			case Type::Normal: return constants::regular;
			case Type::Poison: return constants::not_very_effective;
			case Type::Psychic: return constants::regular;
			case Type::Rock: return constants::not_very_effective;
			case Type::Steel: return constants::no_effect;
			case Type::Water: return constants::regular;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR POISON effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Psychic: switch (deftype) 
		{
			case Type::Bug: return constants::regular;
			case Type::Dark: return constants::no_effect;
			case Type::Dragon: return constants::regular;
			case Type::Electric: return constants::regular;
			case Type::Fairy: return constants::regular;
			case Type::Fighting: return constants::super_effective;
			case Type::Fire: return constants::regular;
			case Type::Flying: return constants::regular;
			case Type::Ghost: return constants::regular;
			case Type::Grass: return constants::regular;
			case Type::Ground: return constants::regular;
			case Type::Ice: return constants::regular;
			case Type::Normal: return constants::regular;
			case Type::Poison: return constants::super_effective;
			case Type::Psychic: return constants::not_very_effective;
			case Type::Rock: return constants::regular;
			case Type::Steel: return constants::not_very_effective;
			case Type::Water: return constants::regular;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR PSYCHIC effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Rock: switch (deftype) 
		{
			case Type::Bug: return constants::super_effective;
			case Type::Dark: return constants::regular;
			case Type::Dragon: return constants::regular;
			case Type::Electric: return constants::regular;
			case Type::Fairy: return constants::regular;
			case Type::Fighting: return constants::not_very_effective;
			case Type::Fire: return constants::super_effective;
			case Type::Flying: return constants::super_effective;
			case Type::Ghost: return constants::regular;
			case Type::Grass: return constants::regular;
			case Type::Ground: return constants::not_very_effective;
			case Type::Ice: return constants::super_effective;
			case Type::Normal: return constants::regular;
			case Type::Poison: return constants::regular;
			case Type::Psychic: return constants::regular;
			case Type::Rock: return constants::regular;
			case Type::Steel: return constants::not_very_effective;
			case Type::Water: return constants::regular;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR ROCK effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Steel: switch (deftype) 
		{
			case Type::Bug: return constants::regular;
			case Type::Dark: return constants::regular;
			case Type::Dragon: return constants::regular;
			case Type::Electric: return constants::not_very_effective;
			case Type::Fairy: return constants::super_effective;
			case Type::Fighting: return constants::regular;
			case Type::Fire: return constants::not_very_effective;
			case Type::Flying: return constants::regular;
			case Type::Ghost: return constants::regular;
			case Type::Grass: return constants::regular;
			case Type::Ground: return constants::regular;
			case Type::Ice: return constants::super_effective;
			case Type::Normal: return constants::regular;
			case Type::Poison: return constants::regular;
			case Type::Psychic: return constants::regular;
			case Type::Rock: return constants::super_effective;
			case Type::Steel: return constants::not_very_effective;
			case Type::Water: return constants::not_very_effective;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR STEEL effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Water: switch (deftype) 
		{
			case Type::Bug: return constants::regular;
			case Type::Dark: return constants::regular;
			case Type::Dragon: return constants::not_very_effective;
			case Type::Electric: return constants::regular;
			case Type::Fairy: return constants::regular;
			case Type::Fighting: return constants::regular;
			case Type::Fire: return constants::super_effective;
			case Type::Flying: return constants::regular;
			case Type::Ghost: return constants::regular;
			case Type::Grass: return constants::not_very_effective;
			case Type::Ground: return constants::super_effective;
			case Type::Ice: return constants::regular;
			case Type::Normal: return constants::regular;
			case Type::Poison: return constants::regular;
			case Type::Psychic: return constants::regular;
			case Type::Rock: return constants::super_effective;
			case Type::Steel: return constants::regular;
			case Type::Water: return constants::not_very_effective;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR WATER effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Typeless: switch(deftype) 
		{
			case Type::Bug: return constants::regular;
			case Type::Dark: return constants::regular;
			case Type::Dragon: return constants::regular;
			case Type::Electric: return constants::regular;
			case Type::Fairy: return constants::regular;
			case Type::Fighting: return constants::regular;
			case Type::Fire: return constants::regular;
			case Type::Flying: return constants::regular;
			case Type::Ghost: return constants::regular;
			case Type::Grass: return constants::regular;
			case Type::Ground: return constants::regular;
			case Type::Ice: return constants::regular;
			case Type::Normal: return constants::regular;
			case Type::Poison: return constants::regular;
			case Type::Psychic: return constants::regular;
			case Type::Rock: return constants::regular;
			case Type::Steel: return constants::regular;
			case Type::Water: return constants::regular;
			case Type::Typeless: return constants::regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR TYPELESS effectiveness.cpp");
				#endif
				return 0; 
		}
		
		default:
			#ifdef _DEBUG
			//debug_log("ERROR ATKTYPE effectiveness.cpp");
			#endif
			return 0; 
	}
}