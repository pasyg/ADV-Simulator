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

Ability ability_from_string(std::string_view str){
	if(str == "Stench"){
		return Ability::Stench;
	}
	else if(str == "Drizzle"){
		return Ability::Drizzle;
	}
	else if(str == "SpeedBoost"){
		return Ability::Speed_Boost;
	}
	else if(str == "BattleArmor"){
		return Ability::Battle_Armor;
	}
	else if(str == "Sturdy"){
		return Ability::Sturdy;
	}
	else if(str == "Damp"){
		return Ability::Damp;
	}
	else if(str == "Limber"){
		return Ability::Limber;
	}
	else if(str == "SandVeil"){
		return Ability::Sand_Veil;
	}
	else if(str == "Static"){
		return Ability::Static;
	}
	else if(str == "VoltAbsorb"){
		return Ability::Volt_Absorb;
	}
	else if(str == "WaterAbsorb"){
		return Ability::Water_Absorb;
	}
	else if(str == "Oblivious"){
		return Ability::Oblivious;
	}
	else if(str == "CloudNine"){
		return Ability::Cloud_Nine;
	}
	else if(str == "CompoundEyes"){
		return Ability::Compound_Eyes;
	}
	else if(str == "Insomnia"){
		return Ability::Insomnia;
	}
	else if(str == "ColorChange"){
		return Ability::Color_Change;
	}
	else if(str == "Immunity"){
		return Ability::Immunity;
	}
	else if(str == "FlashFire"){
		return Ability::Flash_Fire;
	}
	else if(str == "ShieldDust"){
		return Ability::Shield_Dust;
	}
	else if(str == "OwnTempo"){
		return Ability::Own_Tempo;
	}
	else if(str == "SuctionCups"){
		return Ability::Suction_Cups;
	}
	else if(str == "Intimidate"){
		return Ability::Intimidate;
	}
	else if(str == "ShadowTag"){
		return Ability::Shadow_Tag;
	}
	else if(str == "RoughSkin"){
		return Ability::Rough_Skin;
	}
	else if(str == "WonderGuard"){
		return Ability::Wonder_Guard;
	}
	else if(str == "Levitate"){
		return Ability::Levitate;
	}
	else if(str == "EffectSpore"){
		return Ability::Effect_Spore;
	}
	else if(str == "Synchronize"){
		return Ability::Synchronize;
	}
	else if(str == "ClearBody"){
		return Ability::Clear_Body;
	}
	else if(str == "NaturalCure"){
		return Ability::Natural_Cure;
	}
	else if(str == "LightningRod"){
		return Ability::Lightning_Rod;
	}
	else if(str == "SereneGrace"){
		return Ability::Serene_Grace;
	}
	else if(str == "SwiftSwim"){
		return Ability::Swift_Swim;
	}
	else if(str == "Chlorophyll"){
		return Ability::Chlorophyll;
	}
	else if(str == "Illuminate"){
		return Ability::Illuminate;
	}
	else if(str == "Trace"){
		return Ability::Trace;
	}
	else if(str == "HugePower"){
		return Ability::Huge_Power;
	}
	else if(str == "PoisonPoint"){
		return Ability::Poison_Point;
	}
	else if(str == "InnerFocus"){
		return Ability::Inner_Focus;
	}
	else if(str == "MagmaArmor"){
		return Ability::Magma_Armor;
	}
	else if(str == "WaterVeil"){
		return Ability::Water_Veil;
	}
	else if(str == "MagnetPull"){
		return Ability::Magnet_Pull;
	}
	else if(str == "Soundproof"){
		return Ability::Soundproof;
	}
	else if(str == "RainDish"){
		return Ability::Rain_Dish;
	}
	else if(str == "SandStream"){
		return Ability::Sand_Stream;
	}
	else if(str == "Pressure"){
		return Ability::Pressure;
	}
	else if(str == "ThickFat"){
		return Ability::Thick_Fat;
	}
	else if(str == "EarlyBird"){
		return Ability::Early_Bird;
	}
	else if(str == "FlameBody"){
		return Ability::Flame_Body;
	}
	else if(str == "RunAway"){
		return Ability::Run_Away;
	}
	else if(str == "KeenEye"){
		return Ability::Keen_Eye;
	}
	else if(str == "HyperCutter"){
		return Ability::Hyper_Cutter;
	}
	else if(str == "Pickup"){
		return Ability::Pickup;
	}
	else if(str == "Truant"){
		return Ability::Truant;
	}
	else if(str == "Hustle"){
		return Ability::Hustle;
	}
	else if(str == "CuteCharm"){
		return Ability::Cute_Charm;
	}
	else if(str == "Plus"){
		return Ability::Plus;
	}
	else if(str == "Minus"){
		return Ability::Minus;
	}
	else if(str == "Forecast"){
		return Ability::Forecast;
	}
	else if(str == "StickyHold"){
		return Ability::Sticky_Hold;
	}
	else if(str == "ShedSkin"){
		return Ability::Shed_Skin;
	}
	else if(str == "Guts"){
		return Ability::Guts;
	}
	else if(str == "MarvelScale"){
		return Ability::Marvel_Scale;
	}
	else if(str == "LiquidOoze"){
		return Ability::Liquid_Ooze;
	}
	else if(str == "Overgrow"){
		return Ability::Overgrow;
	}
	else if(str == "Blaze"){
		return Ability::Blaze;
	}
	else if(str == "Torrent"){
		return Ability::Torrent;
	}
	else if(str == "Swarm"){
		return Ability::Swarm;
	}
	else if(str == "RockHead"){
		return Ability::Rock_Head;
	}
	else if(str == "Drought"){
		return Ability::Drought;
	}
	else if(str == "ArenaTrap"){
		return Ability::Arena_Trap;
	}
	else if(str == "VitalSpirit"){
		return Ability::Vital_Spirit;
	}
	else if(str == "WhiteSmoke"){
		return Ability::White_Smoke;
	}
	else if(str == "PurePower"){
		return Ability::Pure_Power;
	}
	else if(str == "ShellArmor"){
		return Ability::Shell_Armor;
	}
	else{
		return Ability::Air_Lock;
	}
}