#include "effectiveness.hpp"


const float effectiveness(Type const &atktype, Type const &deftype){
    switch (atktype) {
		case Type::Bug: switch (deftype) {
			case Type::Bug: return regular;
			case Type::Dark: return super_effective;
			case Type::Dragon: return regular;
			case Type::Electric: return regular;
			case Type::Fairy: return not_very_effective;
			case Type::Fighting: return not_very_effective;
			case Type::Fire: return not_very_effective;
			case Type::Flying: return not_very_effective;
			case Type::Ghost: return not_very_effective;
			case Type::Grass: return super_effective;
			case Type::Ground: return regular;
			case Type::Ice: return regular;
			case Type::Normal: return regular;
			case Type::Poison: return not_very_effective;
			case Type::Psychic: return super_effective;
			case Type::Rock: return regular;
			case Type::Steel: return not_very_effective;
			case Type::Water: return regular;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR BUG effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Dark: switch (deftype) {
			case Type::Bug: return regular;
			case Type::Dark: return not_very_effective;
			case Type::Dragon: return regular;
			case Type::Electric: return regular;
			case Type::Fairy: return not_very_effective;
			case Type::Fighting: return not_very_effective;
			case Type::Fire: return regular;
			case Type::Flying: return regular;
			case Type::Ghost: return super_effective;
			case Type::Grass: return regular;
			case Type::Ground: return regular;
			case Type::Ice: return regular;
			case Type::Normal: return regular;
			case Type::Poison: return regular;
			case Type::Psychic: return super_effective;
			case Type::Rock: return regular;
			case Type::Steel: return not_very_effective;
			case Type::Water: return regular;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR DARK effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Dragon: switch (deftype) {
			case Type::Bug: return regular;
			case Type::Dark: return regular;
			case Type::Dragon: return super_effective;
			case Type::Electric: return regular;
			case Type::Fairy: return no_effect;
			case Type::Fighting: return regular;
			case Type::Fire: return regular;
			case Type::Flying: return regular;
			case Type::Ghost: return regular;
			case Type::Grass: return regular;
			case Type::Ground: return regular;
			case Type::Ice: return regular;
			case Type::Normal: return regular;
			case Type::Poison: return regular;
			case Type::Psychic: return regular;
			case Type::Rock: return regular;
			case Type::Steel: return not_very_effective;
			case Type::Water: return regular;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR DRAGON effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Electric: switch (deftype) {
			case Type::Bug: return regular;
			case Type::Dark: return regular;
			case Type::Dragon: return not_very_effective;
			case Type::Electric: return not_very_effective;
			case Type::Fairy: return regular;
			case Type::Fighting: return regular;
			case Type::Fire: return regular;
			case Type::Flying: return super_effective;
			case Type::Ghost: return regular;
			case Type::Grass: return not_very_effective;
			case Type::Ground: return no_effect;
			case Type::Ice: return regular;
			case Type::Normal: return regular;
			case Type::Poison: return regular;
			case Type::Psychic: return regular;
			case Type::Rock: return regular;
			case Type::Steel: return regular;
			case Type::Water: return super_effective;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR ELECTRIC effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Fairy: switch (deftype) {
			case Type::Bug: return regular;
			case Type::Dark: return super_effective;
			case Type::Dragon: return super_effective;
			case Type::Electric: return regular;
			case Type::Fairy: return regular;
			case Type::Fighting: return super_effective;
			case Type::Fire: return not_very_effective;
			case Type::Flying: return regular;
			case Type::Ghost: return regular;
			case Type::Grass: return regular;
			case Type::Ground: return regular;
			case Type::Ice: return regular;
			case Type::Normal: return regular;
			case Type::Poison: return not_very_effective;
			case Type::Psychic: return regular;
			case Type::Rock: return regular;
			case Type::Steel: return not_very_effective;
			case Type::Water: return regular;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR FAIRY effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Fighting: switch (deftype) {
			case Type::Bug: return not_very_effective;
			case Type::Dark: return super_effective;
			case Type::Dragon: return regular;
			case Type::Electric: return regular;
			case Type::Fairy: return not_very_effective;
			case Type::Fighting: return regular;
			case Type::Fire: return regular;
			case Type::Flying: return not_very_effective;
			case Type::Ghost: return no_effect;
			case Type::Grass: return regular;
			case Type::Ground: return regular;
			case Type::Ice: return super_effective;
			case Type::Normal: return super_effective;
			case Type::Poison: return not_very_effective;
			case Type::Psychic: return not_very_effective;
			case Type::Rock: return super_effective;
			case Type::Steel: return super_effective;
			case Type::Water: return regular;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR FIGHTING effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Fire: switch (deftype) {
			case Type::Bug: return super_effective;
			case Type::Dark: return regular;
			case Type::Dragon: return not_very_effective;
			case Type::Electric: return regular;
			case Type::Fairy: return regular;
			case Type::Fighting: return regular;
			case Type::Fire: return not_very_effective;
			case Type::Flying: return regular;
			case Type::Ghost: return regular;
			case Type::Grass: return super_effective;
			case Type::Ground: return regular;
			case Type::Ice: return super_effective;
			case Type::Normal: return regular;
			case Type::Poison: return regular;
			case Type::Psychic: return regular;
			case Type::Rock: return not_very_effective;
			case Type::Steel: return super_effective;
			case Type::Water: return not_very_effective;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR FIRE effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Flying: switch (deftype) {
			case Type::Bug: return super_effective;
			case Type::Dark: return regular;
			case Type::Dragon: return regular;
			case Type::Electric: return not_very_effective;
			case Type::Fairy: return regular;
			case Type::Fighting: return super_effective;
			case Type::Fire: return regular;
			case Type::Flying: return regular;
			case Type::Ghost: return regular;
			case Type::Grass: return super_effective;
			case Type::Ground: return regular;
			case Type::Ice: return regular;
			case Type::Normal: return regular;
			case Type::Poison: return regular;
			case Type::Psychic: return regular;
			case Type::Rock: return not_very_effective;
			case Type::Steel: return not_very_effective;
			case Type::Water: return regular;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR FLYING effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Ghost: switch (deftype) {
			case Type::Bug: return regular;
			case Type::Dark: return not_very_effective;
			case Type::Dragon: return regular;
			case Type::Electric: return regular;
			case Type::Fairy: return regular;
			case Type::Fighting: return regular;
			case Type::Fire: return regular;
			case Type::Flying: return regular;
			case Type::Ghost: return super_effective;
			case Type::Grass: return regular;
			case Type::Ground: return regular;
			case Type::Ice: return regular;
			case Type::Normal: return no_effect;
			case Type::Poison: return regular;
			case Type::Psychic: return super_effective;
			case Type::Rock: return regular;
			case Type::Steel: return not_very_effective;
			case Type::Water: return regular;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR GHOST effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Grass: switch (deftype) {
			case Type::Bug: return not_very_effective;
			case Type::Dark: return regular;
			case Type::Dragon: return not_very_effective;
			case Type::Electric: return regular;
			case Type::Fairy: return regular;
			case Type::Fighting: return regular;
			case Type::Fire: return not_very_effective;
			case Type::Flying: return not_very_effective;
			case Type::Ghost: return regular;
			case Type::Grass: return not_very_effective;
			case Type::Ground: return super_effective;
			case Type::Ice: return regular;
			case Type::Normal: return regular;
			case Type::Poison: return not_very_effective;
			case Type::Psychic: return regular;
			case Type::Rock: return super_effective;
			case Type::Steel: return not_very_effective;
			case Type::Water: return super_effective;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR GRASS effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Ground: switch (deftype) {
			case Type::Bug: return not_very_effective;
			case Type::Dark: return regular;
			case Type::Dragon: return regular;
			case Type::Electric: return super_effective;
			case Type::Fairy: return regular;
			case Type::Fighting: return regular;
			case Type::Fire: return super_effective;
			case Type::Flying: return no_effect;
			case Type::Ghost: return regular;
			case Type::Grass: return not_very_effective;
			case Type::Ground: return regular;
			case Type::Ice: return regular;
			case Type::Normal: return regular;
			case Type::Poison: return super_effective;
			case Type::Psychic: return regular;
			case Type::Rock: return super_effective;
			case Type::Steel: return super_effective;
			case Type::Water: return regular;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR GROUND effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Ice: switch (deftype) {
			case Type::Bug: return regular;
			case Type::Dark: return regular;
			case Type::Dragon: return super_effective;
			case Type::Electric: return regular;
			case Type::Fairy: return regular;
			case Type::Fighting: return regular;
			case Type::Fire: not_very_effective;
			case Type::Flying: return super_effective;
			case Type::Ghost: return regular;
			case Type::Grass: return super_effective;
			case Type::Ground: return super_effective;
			case Type::Ice: return not_very_effective;
			case Type::Normal: return regular;
			case Type::Poison: return regular;
			case Type::Psychic: return regular;
			case Type::Rock: return regular;
			case Type::Steel: return not_very_effective;
			case Type::Water: return not_very_effective;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR ICE effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Normal: switch (deftype) {
			case Type::Bug: return regular;
			case Type::Dark: return regular;
			case Type::Dragon: return regular;
			case Type::Electric: return regular;
			case Type::Fairy: return regular;
			case Type::Fighting: return regular;
			case Type::Fire: return regular;
			case Type::Flying: return regular;
			case Type::Ghost: return no_effect;
			case Type::Grass: return regular;
			case Type::Ground: return regular;
			case Type::Ice: return regular;
			case Type::Normal: return regular;
			case Type::Poison: return regular;
			case Type::Psychic: return regular;
			case Type::Rock: return not_very_effective;
			case Type::Steel: return not_very_effective;
			case Type::Water: return regular;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR NORMAL effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Poison: switch (deftype) {
			case Type::Bug: return regular;
			case Type::Dark: return regular;
			case Type::Dragon: return regular;
			case Type::Electric: return regular;
			case Type::Fairy: return super_effective;
			case Type::Fighting: return regular;
			case Type::Fire: return regular;
			case Type::Flying: return regular;
			case Type::Ghost: return not_very_effective;
			case Type::Grass: return super_effective;
			case Type::Ground: return not_very_effective;
			case Type::Ice: return regular;
			case Type::Normal: return regular;
			case Type::Poison: return not_very_effective;
			case Type::Psychic: return regular;
			case Type::Rock: return not_very_effective;
			case Type::Steel: return no_effect;
			case Type::Water: return regular;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR POISON effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Psychic: switch (deftype) {
			case Type::Bug: return regular;
			case Type::Dark: return no_effect;
			case Type::Dragon: return regular;
			case Type::Electric: return regular;
			case Type::Fairy: return regular;
			case Type::Fighting: return super_effective;
			case Type::Fire: return regular;
			case Type::Flying: return regular;
			case Type::Ghost: return regular;
			case Type::Grass: return regular;
			case Type::Ground: return regular;
			case Type::Ice: return regular;
			case Type::Normal: return regular;
			case Type::Poison: return super_effective;
			case Type::Psychic: return not_very_effective;
			case Type::Rock: return regular;
			case Type::Steel: return not_very_effective;
			case Type::Water: return regular;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR PSYCHIC effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Rock: switch (deftype) {
			case Type::Bug: return super_effective;
			case Type::Dark: return regular;
			case Type::Dragon: return regular;
			case Type::Electric: return regular;
			case Type::Fairy: return regular;
			case Type::Fighting: return not_very_effective;
			case Type::Fire: return super_effective;
			case Type::Flying: return super_effective;
			case Type::Ghost: return regular;
			case Type::Grass: return regular;
			case Type::Ground: return not_very_effective;
			case Type::Ice: return super_effective;
			case Type::Normal: return regular;
			case Type::Poison: return regular;
			case Type::Psychic: return regular;
			case Type::Rock: return regular;
			case Type::Steel: return not_very_effective;
			case Type::Water: return regular;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR ROCK effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Steel: switch (deftype) {
			case Type::Bug: return regular;
			case Type::Dark: return regular;
			case Type::Dragon: return regular;
			case Type::Electric: return not_very_effective;
			case Type::Fairy: return super_effective;
			case Type::Fighting: return regular;
			case Type::Fire: return not_very_effective;
			case Type::Flying: return regular;
			case Type::Ghost: return regular;
			case Type::Grass: return regular;
			case Type::Ground: return regular;
			case Type::Ice: return super_effective;
			case Type::Normal: return regular;
			case Type::Poison: return regular;
			case Type::Psychic: return regular;
			case Type::Rock: return super_effective;
			case Type::Steel: return not_very_effective;
			case Type::Water: return not_very_effective;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR STEEL effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Water: switch (deftype) {
			case Type::Bug: return regular;
			case Type::Dark: return regular;
			case Type::Dragon: return not_very_effective;
			case Type::Electric: return regular;
			case Type::Fairy: return regular;
			case Type::Fighting: return regular;
			case Type::Fire: return super_effective;
			case Type::Flying: return regular;
			case Type::Ghost: return regular;
			case Type::Grass: return not_very_effective;
			case Type::Ground: return super_effective;
			case Type::Ice: return regular;
			case Type::Normal: return regular;
			case Type::Poison: return regular;
			case Type::Psychic: return regular;
			case Type::Rock: return super_effective;
			case Type::Steel: return regular;
			case Type::Water: return not_very_effective;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR WATER effectiveness.cpp");
				#endif
				return 0; 
		}
		case Type::Typeless: switch(deftype) {
			case Type::Bug: return regular;
			case Type::Dark: return regular;
			case Type::Dragon: return regular;
			case Type::Electric: return regular;
			case Type::Fairy: return regular;
			case Type::Fighting: return regular;
			case Type::Fire: return regular;
			case Type::Flying: return regular;
			case Type::Ghost: return regular;
			case Type::Grass: return regular;
			case Type::Ground: return regular;
			case Type::Ice: return regular;
			case Type::Normal: return regular;
			case Type::Poison: return regular;
			case Type::Psychic: return regular;
			case Type::Rock: return regular;
			case Type::Steel: return regular;
			case Type::Water: return regular;
			case Type::Typeless: return regular;
			default:
				#ifdef _DEBUG
				debug_log("ERROR TYPELESS effectiveness.cpp");
				#endif
				return 0; 
		}
		
		default:
			#ifdef _DEBUG
			debug_log("ERROR ATKTYPE effectiveness.cpp");
			#endif
			return 0; 
	}
}