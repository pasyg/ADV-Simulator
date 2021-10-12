#include "ability.hpp"


std::string_view to_string(Ability const ability) {
	switch (ability) {
		case Ability::Stench: return "Stench";
		case Ability::Drizzle: return "Drizzle";
		case Ability::Speed_Boost: return "Speed Boost";
		case Ability::Battle_Armor: return "Battle Armor";
		case Ability::Sturdy: return "Sturdy";
		case Ability::Damp: return "Damp";
		case Ability::Limber: return "Limber";
		case Ability::Sand_Veil: return "Sand Veil";
		case Ability::Static: return "Static";
		case Ability::Volt_Absorb: return "Volt Absorb";
		case Ability::Water_Absorb: return "Water Absorb";
		case Ability::Oblivious: return "Oblivious";
		case Ability::Cloud_Nine: return "Cloud Nine";
		case Ability::Compound_Eyes: return "Compound Eyes";
		case Ability::Insomnia: return "Insomnia";
		case Ability::Color_Change: return "Color Change";
		case Ability::Immunity: return "Immunity";
		case Ability::Flash_Fire: return "Flash Fire";
		case Ability::Shield_Dust: return "Shield Dust";
		case Ability::Own_Tempo: return "Own Tempo";
		case Ability::Suction_Cups: return "Suction Cups";
		case Ability::Intimidate: return "Intimidate";
		case Ability::Shadow_Tag: return "Shadow Tag";
		case Ability::Rough_Skin: return "Rough Skin";
		case Ability::Wonder_Guard: return "Wonder Guard";
		case Ability::Levitate: return "Levitate";
		case Ability::Effect_Spore: return "Effect Spore";
		case Ability::Synchronize: return "Synchronize";
		case Ability::Clear_Body: return "Clear Body";
		case Ability::Natural_Cure: return "Natural Cure";
		case Ability::Lightning_Rod: return "Lightning Rod";
		case Ability::Serene_Grace: return "Serene Grace";
		case Ability::Swift_Swim: return "Swift Swim";
		case Ability::Chlorophyll: return "Chlorophyll";
		case Ability::Illuminate: return "Illuminate";
		case Ability::Trace: return "Trace";
		case Ability::Huge_Power: return "Huge Power";
		case Ability::Poison_Point: return "Poison Point";
		case Ability::Inner_Focus: return "Inner Focus";
		case Ability::Magma_Armor: return "Magma Armor";
		case Ability::Water_Veil: return "Water Veil";
		case Ability::Magnet_Pull: return "Magnet Pull";
		case Ability::Soundproof: return "Soundproof";
		case Ability::Rain_Dish: return "Rain Dish";
		case Ability::Sand_Stream: return "Sand Stream";
		case Ability::Pressure: return "Pressure";
		case Ability::Thick_Fat: return "Thick Fat";
		case Ability::Early_Bird: return "Early Bird";
		case Ability::Flame_Body: return "Flame Body";
		case Ability::Run_Away: return "Run Away";
		case Ability::Keen_Eye: return "Keen Eye";
		case Ability::Hyper_Cutter: return "Hyper Cutter";
		case Ability::Pickup: return "Pickup";
		case Ability::Truant: return "Truant";
		case Ability::Hustle: return "Hustle";
		case Ability::Cute_Charm: return "Cute Charm";
		case Ability::Plus: return "Plus";
		case Ability::Minus: return "Minus";
		case Ability::Forecast: return "Forecast";
		case Ability::Sticky_Hold: return "Sticky Hold";
		case Ability::Shed_Skin: return "Shed Skin";
		case Ability::Guts: return "Guts";
		case Ability::Marvel_Scale: return "Marvel Scale";
		case Ability::Liquid_Ooze: return "Liquid Ooze";
		case Ability::Overgrow: return "Overgrow";
		case Ability::Blaze: return "Blaze";
		case Ability::Torrent: return "Torrent";
		case Ability::Swarm: return "Swarm";
		case Ability::Rock_Head: return "Rock Head";
		case Ability::Drought: return "Drought";
		case Ability::Arena_Trap: return "Arena Trap";
		case Ability::Vital_Spirit: return "Vital Spirit";
		case Ability::White_Smoke: return "White Smoke";
		case Ability::Pure_Power: return "Pure Power";
		case Ability::Shell_Armor: return "Shell Armor";
		case Ability::Air_Lock: return "Air Lock";
		default: return "Error ability";
    }
}

