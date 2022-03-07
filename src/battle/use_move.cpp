#include "battle.hpp"

void Battle::use_move(Team &atkteam, Team &defteam){
    int dmg = 0;
    int switch_target = 0;

    switch(atkteam.movechoice->get_move()){
        ///
        /// switches
        ///
        case Move::Switch0:
            atkteam.mon_in_battle->set_ability(atkteam.mon_in_battle->former_ability);
            atkteam.active_pokemon = 0;
            goto SWITCHIN;
        case Move::Switch1:
            atkteam.mon_in_battle->set_ability(atkteam.mon_in_battle->former_ability);
            atkteam.active_pokemon = 1;
            goto SWITCHIN;
        case Move::Switch2:
            atkteam.mon_in_battle->set_ability(atkteam.mon_in_battle->former_ability);
            atkteam.active_pokemon = 2;
            goto SWITCHIN;
        case Move::Switch3:
            atkteam.mon_in_battle->set_ability(atkteam.mon_in_battle->former_ability);
            atkteam.active_pokemon = 3;
            goto SWITCHIN;
        case Move::Switch4:
            atkteam.mon_in_battle->set_ability(atkteam.mon_in_battle->former_ability);
            atkteam.active_pokemon = 4;
            goto SWITCHIN;
        case Move::Switch5:
            atkteam.mon_in_battle->set_ability(atkteam.mon_in_battle->former_ability);
            atkteam.active_pokemon = 5;
        SWITCHIN:
            switch (atkteam.mon_in_battle->get_ability())
            {
            case Ability::Drizzle:
                this->weather = Weather::Rain;
                break;
            case Ability::Drought:
                this->weather = Weather::Sun;
                break;
            case Ability::Forecast:
                break;
            case Ability::Intimidate:
                defteam.set_boost(Statname::Atk, -1);
                break;
            case Ability::Sand_Stream:
                this->weather = Weather::Sand;
                break;
            case Ability::Trace:
                atkteam.mon_in_battle->former_ability = Ability::Trace;
                atkteam.mon_in_battle->set_ability(defteam.mon_in_battle->get_ability());
                break;
            default:
                break;
            }
        // splash...
        case Move::Splash: 
        case Move::Teleport: return;
        ///
        /// basic damage moves without further effects
        ///
        case Move::Super_Fang:
            dmg = static_cast<int>(defteam.mon_in_battle->get_current_hp() / 2.0);
            if(*defteam.mon_in_battle != Type::Ghost){
                defteam.mon_in_battle->reduce_hp(dmg);
            }
            return;
        case Move::Dragon_Rage:
            dmg = 40;
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Seismic_Toss:
            dmg = 100;
            if(*defteam.mon_in_battle != Type::Ghost){
                defteam.mon_in_battle->reduce_hp(dmg);
            }
            return;
        case Move::Night_Shade:
            dmg = 100;
            if(*defteam.mon_in_battle != Type::Normal){
                defteam.mon_in_battle->reduce_hp(dmg);
            }	
            return;
        case Move::Sonic_Boom:
            dmg = 20;
            if(*defteam.mon_in_battle != Type::Ghost){
                defteam.mon_in_battle->reduce_hp(dmg);
            }
            return;
        case Move::Endeavor:
            if(atkteam.mon_in_battle->get_current_hp() < defteam.mon_in_battle->get_current_hp()){
                defteam.mon_in_battle->reduce_hp(
                    defteam.mon_in_battle->get_current_hp() - atkteam.mon_in_battle->get_current_hp()
                );
            }
        return;
        case Move::Aerial_Ace:
        case Move::Aeroblast:
        case Move::Air_Cutter:
        case Move::Brick_Break:
        case Move::Crabhammer:
        case Move::Cross_Chop:
        case Move::Cut:
        case Move::Dragon_Claw:
        case Move::Drill_Peck:
        case Move::Earthquake:
        case Move::Egg_Bomb:
        case Move::Extreme_Speed:
        case Move::Fake_Out:
        case Move::Flame_Wheel:
        case Move::Frustration:
        case Move::Gust:
        case Move::Hidden_Power:
        case Move::Hit_Self:
        case Move::Horn_Attack:
        case Move::Hydro_Pump:
        case Move::Hyper_Fang:
        case Move::Hyper_Voice:
        case Move::Jump_Kick:
        case Move::Karate_Chop:
        case Move::Mach_Punch:
        case Move::Mega_Kick:
        case Move::Mega_Punch:
        case Move::Megahorn:
        case Move::Pay_Day:
        case Move::Peck:
        case Move::Pound:
        case Move::Quick_Attack:
        case Move::Return:
        case Move::Scratch:
        case Move::Shock_Wave:
        case Move::Slam:
        case Move::Slash:
        case Move::Strength:
        case Move::Surf:
        case Move::Swift:
        case Move::Tackle:
        case Move::Vice_Grip:
        case Move::Vine_Whip:
        case Move::Vital_Throw:
        case Move::Water_Gun:
        case Move::Waterfall:
        case Move::Wing_Attack:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        ///
        /// secondary effect damage moves
        ///
        // leech moves
        case Move::Absorb:
        case Move::Giga_Drain:
        case Move::Leech_Life:
        case Move::Mega_Drain:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            if(dmg > 1){
                atkteam.mon_in_battle->increase_hp(static_cast<int>(dmg / 2.0));
            }
            else{
                atkteam.mon_in_battle->increase_hp(static_cast<int>(1));
            }
                return;
        case Move::Acid:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            if(dmg > 0){
                if(get_random(1,10) == 1){
                    defteam.set_boost(Statname::Def, -1);
                }
            }
            return;
        case Move::Ancient_Power:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            if(dmg > 0){
                if(get_random(1,10) == 1){
                    defteam.set_boost(Statname::Atk, 1);
                    defteam.set_boost(Statname::Def, 1);
                    defteam.set_boost(Statname::Satk, 1);
                    defteam.set_boost(Statname::Sdef, 1);
                    defteam.set_boost(Statname::Spe, 1);
                }
            }
            return;
        case Move::Aurora_Beam:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            if(get_random(1,10) == 1){
                defteam.set_boost(Statname::Atk, 1);
            }
            return;
        case Move::Astonish:
        case Move::Bite:
        case Move::Rock_Slide:
            dmg = calculate_damage(atkteam, defteam);
            if(dmg > 0){
                defteam.mon_in_battle->reduce_hp(dmg);
                if(get_random(1,10) < 4){
                    defteam.flinch = true;
                }
            }
            return;
        case Move::Blast_Burn:
        case Move::Frenzy_Plant:
        case Move::Hydro_Cannon:
        case Move::Hyper_Beam:
            dmg = calculate_damage(atkteam, defteam);
            if(dmg > 0){
                defteam.mon_in_battle->reduce_hp(dmg);
                atkteam.recharge = 2;
            }
            return;
        case Move::Blaze_Kick:
        case Move::Ember:
        case Move::Fire_Blast:
        case Move::Fire_Punch:
        case Move::Flamethrower:
        case Move::Heat_Wave:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            if(dmg > 0){
                if(get_random(1,10)){
                    if(defteam.mon_in_battle->get_status() == Status::Healthy){
                        defteam.mon_in_battle->set_status(Status::Burn, defteam.safeguard);
                    }
                }
            }
            return;
        case Move::Blizzard:
        case Move::Ice_Beam:
        case Move::Ice_Punch:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Body_Slam:
        case Move::Thunder:
            dmg = calculate_damage(atkteam, defteam);
            if(dmg > 0){
                defteam.mon_in_battle->reduce_hp(dmg);
                if(defteam.mon_in_battle->get_status() == Status::Healthy){
                    if(get_random(1,10) < 4){
                        defteam.mon_in_battle->set_status(Status::Paralysis, defteam.safeguard);
                    }
                }
            }
            return;
        ////////////////// done until here
        case Move::Bone_Club:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Bubble:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Bubble_Beam:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Confusion:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Constrict:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Crunch:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Crush_Claw:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Dizzy_Punch:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Doom_Desire:
        case Move::Future_Sight:
            return;
        case Move::Double_Edge:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            atkteam.mon_in_battle->reduce_hp(static_cast<int>(dmg/3.0));
            return;
        case Move::Dragon_Breath:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Dream_Eater:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Dynamic_Punch:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Eruption:
        case Move::Flail:
        case Move::Reversal:
        case Move::Water_Spout:
            return;
        case Move::Explosion:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Extrasensory:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Facade:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::False_Swipe:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Feint_Attack:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Headbutt:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::High_Jump_Kick:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Icy_Wind:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Iron_Tail:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Knock_Off:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Leaf_Blade:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Lick:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Magical_Leaf:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Magnitude:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Metal_Claw:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Meteor_Mash:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Nature_Power:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Needle_Arm:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Octazooka:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Poison_Fang:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Poison_Tail:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Powder_Snow:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Psychic:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Pursuit:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Rapid_Spin:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            if(dmg > 0){
                
            }
            return;
        case Move::Razor_Leaf:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Rock_Smash:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Rock_Tomb:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Sacred_Fire:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Secret_Power:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Self_Destruct:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Shadow_Ball:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Shadow_Punch:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Signal_Beam:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Silver_Wind:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Sludge:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Sludge_Bomb:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Smog:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Spark:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Steel_Wing:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Struggle:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Submission:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Superpower:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Take_Down:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Thief:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Thunder_Punch:
        case Move::Thunder_Shock:
        case Move::Thunderbolt:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Tri_Attack:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Twister:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Volt_Tackle:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Water_Pulse:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;
        ////////////////// 
        case Move::Zap_Cannon:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            if(defteam.mon_in_battle->get_status() == Status::Healthy){
                defteam.mon_in_battle->set_status(Status::Paralysis, defteam.safeguard);
            }
            return;	
        case Move::Luster_Purge:
	    case Move::Mist_Ball:
	    case Move::Mud_Shot:
	    case Move::Mud_Slap:
	    case Move::Muddy_Water:
	    case Move::Poison_Sting:
	    case Move::Psybeam:	// 10% confusion
	    case Move::Psycho_Boost:
        case Move::Overheat:
            dmg = calculate_damage(atkteam, defteam);
            defteam.mon_in_battle->reduce_hp(dmg);
            return;	
	    case Move::Psywave:
            dmg = 10 * get_random(0, 10);
            dmg *= 50;
            dmg *= atkteam.mon_in_battle->get_level();
            dmg = static_cast<int>(dmg / 100.0);
            
            if(dmg < 1){
                dmg = 1;
            }
            defteam.mon_in_battle->reduce_hp(dmg);
            return;	
	    case Move::Rage:
	    case Move::Revenge:
	    case Move::Rock_Throw:
	    case Move::Rolling_Kick:
	    case Move::Sky_Uppercut:
	    case Move::Smelling_Salts: // double damage when opponent paralyzed
	    case Move::Stomp: // double damage on minimize target, don't care for now, lol
	    case Move::Weather_Ball:
        ///
        /// multihit
        ///
        case Move::Arm_Thrust:
        case Move::Barrage:
        case Move::Bone_Rush:
        case Move::Bullet_Seed:
        case Move::Comet_Punch:
        case Move::Fury_Attack:
        case Move::Fury_Swipes:
        case Move::Icicle_Spear:
        case Move::Pin_Missile:
        case Move::Rock_Blast:
        case Move::Spike_Cannon:
            for(int i = 0; i < get_random(2,5); ++i){
                dmg = calculate_damage(atkteam, defteam);
                defteam.mon_in_battle->reduce_hp(dmg);
            }
            return;
        case Move::Bonemerang:
        case Move::Double_Kick:
        case Move::Double_Slap:
        case Move::Twineedle:
            for(int i = 0; i < 2; ++i){
                dmg = calculate_damage(atkteam, defteam);
                defteam.mon_in_battle->reduce_hp(dmg);
            }
            return;
        case Move::Triple_Kick:
            for(int i = 0; i < 3; ++i){
                dmg = calculate_damage(atkteam, defteam);
                defteam.mon_in_battle->reduce_hp(dmg);
            }
            return;

        case Move::Rollout: // ewww
        case Move::Ice_Ball: // ewww


        ///
        /// selflock
        ///
        case Move::Outrage:
        case Move::Petal_Dance:
        case Move::Thrash:
        ///
        /// multiturn
        ///
        case Move::Bounce:
        case Move::Dig:
        case Move::Dive:
        case Move::Fly:
        case Move::Razor_Wind:
        case Move::Skull_Bash:
        case Move::Sky_Attack:
        case Move::Solar_Beam:
            if(atkteam.charged == 0){
                atkteam.charged = 1;
            }
            else{
                dmg = calculate_damage(atkteam, defteam);
                defteam.mon_in_battle->reduce_hp(dmg);
            }
            return;
        ///
        /// boost affecting moves
        ///
        ///
        /// ohko
        ///
        case Move::Fissure:
        case Move::Guillotine:
        case Move::Horn_Drill:
        case Move::Sheer_Cold:
        /// 
        /// trapping moves
        ///
        case Move::Bind:
        case Move::Block:
        case Move::Clamp:
        case Move::Fire_Spin:
        case Move::Mean_Look:
        case Move::Sand_Tomb:
        case Move::Spider_Web:
        case Move::Whirlpool:
        case Move::Wrap:

        case Move::Belly_Drum:
            atkteam.set_boost(Statname::Atk, 12);
            return;
        case Move::Bulk_Up:
            atkteam.set_boost(Statname::Atk, 1);
            atkteam.set_boost(Statname::Def, 1);
            return;
        case Move::Curse:
            atkteam.set_boost(Statname::Atk, 1);
            atkteam.set_boost(Statname::Def, 1);
            atkteam.set_boost(Statname::Spe, -1);
            return;
        case Move::Dragon_Dance:
            atkteam.set_boost(Statname::Atk, 1);
            atkteam.set_boost(Statname::Spe, 1);
            return;
        case Move::Howl:
            atkteam.set_boost(Statname::Atk, 1);
            return;
        case Move::Meditate:
            atkteam.set_boost(Statname::Atk, 1);
            return;
        case Move::Sharpen:
            atkteam.set_boost(Statname::Atk, 1);
            return;
        case Move::Swagger:
            defteam.set_boost(Statname::Atk, 1);
            atkteam.set_confusion();
            return;
        case Move::Swords_Dance:
            atkteam.set_boost(Statname::Atk, 2);
            return;

        case Move::Acid_Armor:
            atkteam.set_boost(Statname::Def, 2);
            return;
        case Move::Barrier:
            atkteam.set_boost(Statname::Def, 2);
            return;
        case Move::Cosmic_Power:
            atkteam.set_boost(Statname::Def, 1);
            atkteam.set_boost(Statname::Sdef, 1);
            return;
        case Move::Defense_Curl:
            atkteam.set_boost(Statname::Def, 1);
            return;
        case Move::Harden:
            atkteam.set_boost(Statname::Def, 1);
            return;
        case Move::Iron_Defense:
            atkteam.set_boost(Statname::Def, 2);
            return;
        case Move::Withdraw:
            atkteam.set_boost(Statname::Def, 1);
            return;

        case Move::Calm_Mind:
            atkteam.set_boost(Statname::Satk, 1);
            atkteam.set_boost(Statname::Sdef, 1);
            return;
        case Move::Growth:
            atkteam.set_boost(Statname::Satk, 1);
            return;
        case Move::Tail_Glow:
            atkteam.set_boost(Statname::Satk, 2);
            return;
        
        case Move::Amnesia:
            atkteam.set_boost(Statname::Sdef, 2);
            return;

        case Move::Agility:
            atkteam.set_boost(Statname::Spe, 2);
            return;

        case Move::Double_Team:
            atkteam.set_boost(Statname::Eva, 1);
            return;
        case Move::Minimize:
            atkteam.set_boost(Statname::Eva, 1);
            return;
////////////////////////////////////////////////////
        case Move::Focus_Energy:
////////////////////////////////////////////////////
        case Move::Charm:
            defteam.set_boost(Statname::Atk, -2);
            return;
        case Move::Feather_Dance:
            defteam.set_boost(Statname::Atk, -2);
            return;
        case Move::Growl:
            defteam.set_boost(Statname::Atk, -1);
            return;
        case Move::Tickle:
            defteam.set_boost(Statname::Atk, -1);
            defteam.set_boost(Statname::Satk, -1);
            return;

        case Move::Leer:
            defteam.set_boost(Statname::Def, -1);
            return;
        case Move::Screech:
            defteam.set_boost(Statname::Def, -2);
            return;
        case Move::Tail_Whip:
            defteam.set_boost(Statname::Def, -1);
            return;

        case Move::Fake_Tears:
        case Move::Metal_Sound:
            defteam.set_boost(Statname::Sdef, -2);
            return;

        case Move::Cotton_Spore:
        case Move::Scary_Face:
            defteam.set_boost(Statname::Spe, -2);
            return;
        case Move::String_Shot:
            defteam.set_boost(Statname::Spe, -1);
            return;

        case Move::Flash:
        case Move::Kinesis:
        case Move::Sand_Attack:
        case Move::Smokescreen:
            defteam.set_boost(Statname::Acc, -1);
            return;
        case Move::Sweet_Scent:
            defteam.set_boost(Statname::Eva, -1);
            return;

        case Move::Psych_Up:
            if(defteam.atkboost > atkteam.atkboost){
                atkteam.atkboost = defteam.atkboost;
            }
            if(defteam.defboost > atkteam.defboost){
                atkteam.defboost = defteam.defboost;
            }
            if(defteam.satkboost > atkteam.satkboost){
                atkteam.satkboost = defteam.satkboost;
            }
            if(defteam.sdefboost > atkteam.sdefboost){
                atkteam.sdefboost = defteam.sdefboost;
            }
            if(defteam.speboost > atkteam.speboost){
                atkteam.speboost = defteam.speboost;
            }
            return;
        case Move::Haze:
            atkteam.atkboost = 0;
            atkteam.defboost = 0;
            atkteam.satkboost = 0;
            atkteam.sdefboost = 0;
            atkteam.speboost = 0;
            atkteam.accboost = 0;
            atkteam.evaboost = 0;

            defteam.atkboost = 0;
            defteam.defboost = 0;
            defteam.satkboost = 0;
            defteam.sdefboost = 0;
            defteam.speboost = 0;
            defteam.accboost = 0;
            defteam.evaboost = 0;
            return;
        ///
        /// status moves
        ///

        // paralysis
        case Move::Glare:
            if(defteam.mon_in_battle->get_status() != Status::Healthy){
                if(*defteam.mon_in_battle != Type::Ghost){
                    defteam.mon_in_battle->set_status(Status::Paralysis, defteam.safeguard);
                }
            }
            return;
        case Move::Stun_Spore:
            if(defteam.mon_in_battle->get_status() != Status::Healthy){
                defteam.mon_in_battle->set_status(Status::Paralysis, defteam.safeguard);
            }
            return;
        case Move::Thunder_Wave:
            if(defteam.mon_in_battle->get_status() != Status::Healthy){
                if(*defteam.mon_in_battle != Type::Ground){
                    defteam.mon_in_battle->set_status(Status::Paralysis, defteam.safeguard);
                }
            }
            return;
        // sleep
        case Move::Grass_Whistle:
        case Move::Hypnosis:
        case Move::Lovely_Kiss:
        case Move::Sing:
        case Move::Sleep_Powder:
        case Move::Spore:
            if(defteam.mon_in_battle->get_status() != Status::Healthy){
                defteam.mon_in_battle->set_status(Status::Sleep_inflicted, defteam.safeguard);
            }
            return;
        case Move::Yawn:
            defteam.yawn = 2;
            return;
        case Move::Snore:
            if(atkteam.mon_in_battle->get_status() == Status::Sleep_inflicted ||
               atkteam.mon_in_battle->get_status() == Status::Sleep_self){
                dmg = calculate_damage(atkteam, defteam);
                defteam.mon_in_battle->reduce_hp(dmg);
               }
               return;
        case Move::Sleep_Talk:
        // poison
        case Move::Poison_Powder:
            if(defteam.mon_in_battle->get_status() != Status::Healthy){
                if(*defteam.mon_in_battle != Type::Steel && *defteam.mon_in_battle != Type::Poison){
                    defteam.mon_in_battle->set_status(Status::Poison, defteam.safeguard);
                }
            }
            return;
        case Move::Toxic:
            if(defteam.mon_in_battle->get_status() != Status::Healthy){
                if(*defteam.mon_in_battle != Type::Steel && *defteam.mon_in_battle != Type::Poison){
                    defteam.mon_in_battle->set_status(Status::Toxic_poison, defteam.safeguard);
                }
            }
            return;
        // burn
        case Move::Will_O_Wisp:
            if(defteam.mon_in_battle->get_status() != Status::Healthy){
                if(*defteam.mon_in_battle != Type::Fire){
                    defteam.mon_in_battle->set_status(Status::Burn, defteam.safeguard);
                }
            }
            return;
        case Move::Refresh:
            if(atkteam.mon_in_battle->get_status() != Status::Freeze){
                if(atkteam.mon_in_battle->get_status() != Status::Sleep_inflicted){
                    if(atkteam.mon_in_battle->get_status() != Status::Sleep_self){
                        atkteam.mon_in_battle->set_status(Status::Healthy, false);
                    }
                }
            }
            return;
        //confusion
        case Move::Confuse_Ray:
        case Move::Supersonic:
        case Move::Sweet_Kiss:
        case Move::Teeter_Dance:
            defteam.set_confusion();
            return;
        //related
        case Move::Aromatherapy:
        case Move::Heal_Bell:
            for(int i = 0; i < 6; ++i){
                if(atkteam.member[i].get_status() != Status::Fainted){
                    atkteam.member[i].set_status(Status::Healthy, false);
                }
            }
            atkteam.sleep_inflict = false;
            return;    
        case Move::Safeguard:     
            atkteam.safeguard = true;   
        ///
        /// healing moves
        ///
        case Move::Milk_Drink:
        case Move::Recover:
        case Move::Slack_Off:
        case Move::Soft_Boiled:
            atkteam.mon_in_battle->increase_hp(
                static_cast<int>(atkteam.mon_in_battle->get_stats().hp / 2.0));
            return;
        case Move::Moonlight:
        case Move::Morning_Sun:
        case Move::Synthesis:
            switch(this->weather){
                case Weather::Sun:
                    atkteam.mon_in_battle->increase_hp(
                        static_cast<int>(atkteam.mon_in_battle->get_stats().hp * (2.0 / 3.0)));
                case Weather::Clear:
                    atkteam.mon_in_battle->increase_hp(
                        static_cast<int>(atkteam.mon_in_battle->get_stats().hp / 2.0));
                default:
                    atkteam.mon_in_battle->increase_hp(
                        static_cast<int>(atkteam.mon_in_battle->get_stats().hp / 4.0));
            }
            return;
        case Move::Rest:
            if(atkteam.mon_in_battle->get_status() != Status::Sleep_inflicted &&
                atkteam.mon_in_battle->get_status() != Status::Sleep_self){
                    atkteam.mon_in_battle->set_status(Status::Sleep_self, false);
                    atkteam.mon_in_battle->increase_hp(999);
                }
            return;
        case Move::Wish:
            atkteam.wish = true;
            atkteam.wish_recovery = static_cast<int>(atkteam.mon_in_battle->get_stats().hp / 2.0);
            return;
        case Move::Ingrain:
            atkteam.ingrain = true;
            return;
        ///
        /// weather
        ///
        case Move::Hail:
            this->weather = Weather::Hail;
            this->weather_turns = 5;
            return;
        case Move::Rain_Dance:
            this->weather = Weather::Rain;
            this->weather_turns = 5;
            return;
        case Move::Sandstorm:
            this->weather = Weather::Sand;
            this->weather_turns = 5;
            return;
        case Move::Sunny_Day:
            this->weather = Weather::Sun;
            this->weather_turns = 5;
            return;
        ///
        /// weird sh*t
        ///
        case Move::Assist:
        case Move::Attract:
        case Move::Baton_Pass:
            // input to switch pokemon
            if(atkteam.mon_in_battle->substitute){
                atkteam.mon_in_battle->substitute = false;
                atkteam.member[switch_target].substitute = true;
                atkteam.member[switch_target].substitute_hp = atkteam.mon_in_battle->substitute_hp;
                atkteam.mon_in_battle->substitute_hp = 0;
            }
            atkteam.active_pokemon = switch_target;

        case Move::Beat_Up:
        case Move::Bide:
        case Move::Camouflage:
        case Move::Charge:
        case Move::Conversion:
        case Move::Conversion_2:
        case Move::Counter:
        case Move::Covet:
        case Move::Destiny_Bond:
        case Move::Detect:
        case Move::Disable:
        case Move::Encore:
        case Move::Endure:
        case Move::Flatter:
        case Move::Foresight:
        case Move::Focus_Punch:
        case Move::Follow_Me:
        case Move::Fury_Cutter:
        case Move::Grudge:
        case Move::Helping_Hand:
        case Move::Imprison:
        case Move::Leech_Seed:
            defteam.leechseed = true;
            return;
        case Move::Light_Screen:
            atkteam.lightscreen = true;
            return;
        case Move::Lock_On:
        case Move::Low_Kick:
        case Move::Magic_Coat:
        case Move::Memento:
            atkteam.mon_in_battle->reduce_hp(999);
            defteam.set_boost(Statname::Atk, 2);
            defteam.set_boost(Statname::Satk, 2);
            return;
        case Move::Mimic:
        case Move::Mind_Reader:
        case Move::Mirror_Coat:
        case Move::Mirror_Move:
        case Move::Mist:
        case Move::Mud_Sport:
        case Move::Nightmare:
        case Move::Odor_Sleuth:
        case Move::Pain_Split:
        case Move::Perish_Song:
        case Move::Present:
        case Move::Protect:
        case Move::Recycle:
        case Move::Reflect:
        case Move::Roar:
        case Move::Role_Play:
        case Move::Sketch:
        case Move::Skill_Swap:
        case Move::Uproar:
        case Move::Snatch:
        case Move::Spikes:
        case Move::Spit_Up:
        case Move::Spite:
        case Move::Stockpile:
        case Move::Substitute:
        case Move::Swallow:
        case Move::Taunt:
        case Move::Torment:
        case Move::Transform:
        case Move::Trick:
        case Move::Water_Sport:
        case Move::Whirlwind:
            return;
    }
}