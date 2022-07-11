#include "battle.hpp"

void Battle::opp_boost(Team &team, const Statname stat, const int boost, const int chance){
	switch(stat){
		case Statname::Acc:
			if(team.active()->get_ability() == Ability::Keen_Eye){
				return;
			}
		break;
		default:
			switch(team.active()->get_ability()){
				case Ability::Clear_Body:
				case Ability::White_Smoke:
				case Ability::Hyper_Cutter:
					if(boost < 0){
						return;
					}
				default: break;
			}
		if(this->transition.randomChance(chance, 100)){
			team.set_boost(stat, boost);
		}
	}
}

void Battle::contact_move(Team &atkteam, Team &defteam){
	if(!is_contact_move(atkteam.movechoice->get_move())){
		return;
	}
	
	switch(defteam.active()->get_ability()){
		case Ability::Cute_Charm:
			if(this->transition.randomChance(3, 10)){
				atkteam.infatuated = true;
			}
		case Ability::Effect_Spore:
			if(this->transition.randomChance(1, 10)){
				switch(this->transition.random(3)){
					case 0: 
						atkteam.active()->set_status(Status::Poison, atkteam.safeguard);
						if(atkteam.active()->get_ability() == Ability::Synchronize){
							defteam.active()->set_status(Status::Poison, defteam.safeguard);
						}
						break;
					case 1:
						atkteam.active()->set_status(Status::Sleep_inflicted, atkteam.safeguard);
						if(atkteam.active()->get_ability() == Ability::Synchronize){
							defteam.active()->set_status(Status::Sleep_inflicted, defteam.safeguard);
						}
						break;
					case 2:
						atkteam.active()->set_status(Status::Paralysis, atkteam.safeguard);
						if(atkteam.active()->get_ability() == Ability::Synchronize){
							defteam.active()->set_status(Status::Paralysis, defteam.safeguard);
						}
						break;
					}
				}
			break;
        	case Ability::Flame_Body: 
        		if(this->transition.randomChance(3, 10)){ 
        			atkteam.active()->set_status(Status::Burn, atkteam.safeguard);
        		} 
        		break;
        	case Ability::Poison_Point: 
        		if(this->transition.randomChance(3, 10)){ 
        			atkteam.active()->set_status(Status::Poison, atkteam.safeguard);
        		} 
        		break;
        	case Ability::Static: 
        		if(this->transition.randomChance(3, 10)){ 
        			atkteam.active()->set_status(Status::Paralysis, atkteam.safeguard);
        		} 
        		break;
        	case Ability::Rough_Skin: 
        		atkteam.active()->reduce_hp(atkteam.active()->get_stats().hp / 16.0); 
        		break;
        	}
}

void Battle::switch_in(Team &atkteam, Team &defteam, const int target){
	atkteam.meanlook = false;
	atkteam.active()->set_ability(atkteam.active()->former_ability);
	if(atkteam.active()->get_ability() == Ability::Natural_Cure){
		atkteam.active()->status == Status::Healthy;
	}
	
	atkteam.active_pokemon = target;
	
	switch(atkteam.active()->get_ability()){
		case Ability::Drizzle:
			this->weather = Weather::Rain;
			break;
		case Ability::Drought:
			this->weather = Weather::Sun;
			break;
		case Ability::Forecast:
			// weird sh*t
			break;
		case Ability::Intimidate:
			opp_boost(defteam, Statname::Atk, -1, 100);
			break;
		case Ability::Sand_Stream:
			this->weather = Weather::Sand;
			break;
		case Ability::Trace:
			atkteam.active()->set_former_ability(Ability::Trace);
			atkteam.active()->set_ability(defteam.active()->get_ability());
			break;
		default:
			break;
		}
}

int Battle::calculate_accuracy(Team &atkteam, Team &defteam){
	int accuracy = move_accuracy(atkteam.movechoice->get_move(), this->weather);
	
	if(atkteam.active()->get_ability() == Ability::Compound_Eyes){ 
		accuracy *= 1.3; 
	}
	if(atkteam.active()->get_ability() == Ability::Hustle && atkteam.movechoice->category == MoveCategory::Physical){
		accuracy *= 0.8;
	}
	if(defteam.active()->get_item() == Item::Brightpowder || defteam.active()->get_item() == Item::Laxincense){
		accuracy *= 0.9;
	}


	switch(atkteam.movechoice->get_move()){
		case Move::Switch:
		case Move::Switch0:
		case Move::Switch1:
		case Move::Switch2:
		case Move::Switch3:
		case Move::Switch4:
		case Move::Switch5:
		    accuracy = 0;
		    break;
		default:
		    move_log(atkteam, defteam);
		    break;
	}			
	    
	if(accuracy > 0 && !atkteam.lockon){
	   	int stages = atkteam.get_boost(Statname::Acc) - defteam.get_boost(Statname::Eva);
	   	
        if(stages > 6){ 
            stages = 6; 
        }
        if(stages < -6){ 
            stages = -6; 
        }
	    switch(stages){
            case 6:
                accuracy *= 3;
                break;
            case 5:
                accuracy = static_cast<int>(accuracy * 266 / 100);
                break;
            case 4:
                accuracy = static_cast<int>(accuracy * 250 / 100);
                break;
            case 3:
                accuracy = static_cast<int>(accuracy * 200 / 100);
                break;
            case 2:
                accuracy = static_cast<int>(accuracy * 166 / 100);
                break;
            case 1:
                accuracy = static_cast<int>(accuracy * 133 / 100);
                break;
            case 0:
                break;
            case -1:
                accuracy = static_cast<int>(accuracy * 75 / 100);
                break;
            case -2:
                accuracy = static_cast<int>(accuracy * 60 / 100);
                break;
            case -3:
                accuracy = static_cast<int>(accuracy * 50 / 100);
                break;
            case -4:
                accuracy = static_cast<int>(accuracy * 43 / 100);
                break;
            case -5:
                accuracy = static_cast<int>(accuracy * 36 / 100);
                break;
            case -6:
                accuracy = static_cast<int>(accuracy * 33 / 100);
                break;
        }
    }
    return accuracy;
}

int Battle::used_pp(Team &atkteam, Team &defteam){
    int pp = 1;
    if(defteam.active()->get_ability() == Ability::Pressure){
        switch(atkteam.movechoice->get_move()){
            case Move::Belly_Drum:
            case Move::Bulk_Up:
            case Move::Curse:
            case Move::Dragon_Dance:
            case Move::Howl:
            case Move::Meditate:
            case Move::Sharpen:
            case Move::Swords_Dance:
            case Move::Acid_Armor:
            case Move::Barrier:
            case Move::Amnesia:
            case Move::Iron_Defense:
            case Move::Cosmic_Power:
            case Move::Defense_Curl:
            case Move::Harden:
            case Move::Withdraw:
            case Move::Calm_Mind:
            case Move::Growth:
            case Move::Tail_Glow:
            case Move::Agility:
            case Move::Double_Team:
            case Move::Minimize:
            case Move::Focus_Energy:
            case Move::Haze:
            case Move::Sleep_Talk:
            case Move::Refresh:
            case Move::Milk_Drink:
            case Move::Recover:
            case Move::Slack_Off:
            case Move::Soft_Boiled:
            case Move::Moonlight:
            case Move::Morning_Sun:
            case Move::Synthesis:
            case Move::Rest:
            case Move::Wish:
            case Move::Ingrain:
            case Move::Hail:
            case Move::Rain_Dance:
            case Move::Sunny_Day:
            case Move::Sandstorm:
            case Move::Assist:
            case Move::Baton_Pass:
            case Move::Bide:
            case Move::Camouflage:
            case Move::Conversion:
            case Move::Conversion_2:
            case Move::Detect:
            case Move::Protect:
            case Move::Endure:
            case Move::Follow_Me:
            case Move::Imprison:
            case Move::Mist:
            case Move::Mud_Sport:
            case Move::Perish_Song:
            case Move::Recycle:
            case Move::Reflect:
            case Move::Role_Play:
            case Move::Stockpile:
            case Move::Substitute:
            case Move::Swallow:
                break;
            default:
                pp = 2;
        }
    }

    return pp;
}

void Battle::try_set_status(Team &team, Status status){
    if(team.active()->get_status() == Status::Healthy){
        team.active()->set_status(status, team.safeguard);
    }
}

void Battle::use_move(Team &atkteam, Team &defteam){ 

    // get rid of these sh*tters
    auto weather_log_upkeep = [&](Weather weather){
        this->logger << "|weather|" << to_string(weather) << "\n";
    };

    auto weather_log_from = [&](Weather weather){
        this->logger << "|weather|" << to_string(weather) << "\n";
    };
    // sound moves are ineffective vs soundproof
    if(is_sound_move(atkteam.movechoice->get_move())){ 
        if(defteam.active()->get_ability() == Ability::Soundproof){
            return;
        }
    }
    
    // contact move have specific effects vs some abilities
    this->contact_move(atkteam, defteam);

    int serene_grace = 1;
    if(atkteam.active()->get_ability() == Ability::Serene_Grace){ serene_grace = 2; }
    
    // use up 1 PP or 2 for certain moves vs Pressure
    int pp_reduce = used_pp(atkteam, defteam);
    atkteam.movechoice->reduce_pp(pp_reduce);

    if(defteam.active()->get_ability() == Ability::Flash_Fire && atkteam.movechoice->get_type() == Type::Fire){
        defteam.flash_fire = true;
    }
    if(defteam.active()->get_ability() == Ability::Color_Change){
        defteam.active()->former_type = std::move(defteam.active()->type);
        defteam.active()->type[0] = atkteam.movechoice->get_type();
        defteam.active()->type[1] = Type::Typeless;
    }

    int dmg = 0;
    int switch_target = 0;
    int accuracy = calculate_accuracy(atkteam, defteam);

    if(!this->transition.randomChance(accuracy, 100)){ 
        miss_log(); 
        return;
    }
    if(atkteam.active()->get_item() == Item::Choiceband){
        atkteam.move_locked = true;
        atkteam.locked_move = atkteam.movechoice;
    }
    
    // for multihit moves
    int hits = 0;

    switch(atkteam.movechoice->get_move()){
        ///
        /// switches
        ///
        case Move::Switch0:
            switch_in(atkteam, defteam, 0);
            switch_log(atkteam);
            return;
        case Move::Switch1:
            switch_in(atkteam, defteam, 1);
            switch_log(atkteam);
            return;
        case Move::Switch2:
            switch_in(atkteam, defteam, 2);
            switch_log(atkteam);
            return;
        case Move::Switch3:
            switch_in(atkteam, defteam, 3);
            switch_log(atkteam);
            return;
        case Move::Switch4:
            switch_in(atkteam, defteam, 4);
            switch_log(atkteam);
            return;
        case Move::Switch5:
            switch_in(atkteam, defteam, 5);
            switch_log(atkteam);
            return;
        // splash...
        case Move::Splash: 
        case Move::Teleport: return;
        ///
        /// basic damage moves without further effects
        ///
        case Move::Super_Fang:
            dmg = static_cast<int>(defteam.active()->get_current_hp() / 2.0);
            if(*defteam.active() != Type::Ghost){
                defteam.active()->reduce_hp(dmg);
            }
            return;
        case Move::Dragon_Rage:
            dmg = 40;
            return;
        case Move::Seismic_Toss:
            if(*defteam.active() != Type::Ghost){
                defteam.active()->reduce_hp(atkteam.active()->get_level());
                atk_damage_log(defteam);
            }
            return;
        case Move::Night_Shade:
            if(*defteam.active() != Type::Normal){
                defteam.active()->reduce_hp(atkteam.active()->get_level());
                atk_damage_log(defteam);
            }	
            return;
        case Move::Sonic_Boom:
            if(*defteam.active() != Type::Ghost){
                defteam.active()->reduce_hp(20);
                atk_damage_log(defteam);
            }
            return;
        case Move::Endeavor:
            if(atkteam.active()->get_current_hp() < defteam.active()->get_current_hp()){
                defteam.active()->reduce_hp(
                    defteam.active()->get_current_hp() - atkteam.active()->get_current_hp()
                );
                atk_damage_log(defteam);
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
            if(dmg > 1){
                atkteam.active()->increase_hp(static_cast<int>(dmg / 2.0));
            }
            else{
                atkteam.active()->increase_hp(static_cast<int>(1));
            }
                return;
        case Move::Acid:
            dmg = calculate_damage(atkteam, defteam);
            if(dmg > 0 && defteam.active()->get_ability() != Ability::Shield_Dust){
                opp_boost(defteam, Statname::Def, -1, 10 * serene_grace);
            }
            return;
        case Move::Ancient_Power:
            dmg = calculate_damage(atkteam, defteam);
            if(dmg > 0){
                if(this->transition.randomChance(serene_grace, 10)){
                    atkteam.set_boost(Statname::Atk, 1);
                    atkteam.set_boost(Statname::Def, 1);
                    atkteam.set_boost(Statname::Satk, 1);
                    atkteam.set_boost(Statname::Sdef, 1);
                    atkteam.set_boost(Statname::Spe, 1);
                }
            }
            return;
        case Move::Aurora_Beam:
            dmg = calculate_damage(atkteam, defteam);
            opp_boost(defteam, Statname::Atk, 1, 10 * serene_grace);
            return;
        case Move::Astonish:
        case Move::Bite:
        case Move::Rock_Slide:
            dmg = calculate_damage(atkteam, defteam);
            if(dmg > 0 && defteam.active()->get_ability() != Ability::Shield_Dust){
                if(defteam.active()->get_ability() != Ability::Inner_Focus){   
                    if(this->transition.randomChance(3 * serene_grace, 10)){   
                        defteam.flinch = true;
                    }
                }
            }
            return;
        case Move::Blast_Burn:
        case Move::Frenzy_Plant:
        case Move::Hydro_Cannon:
        case Move::Hyper_Beam:
            dmg = calculate_damage(atkteam, defteam);
            if(calculate_damage(atkteam, defteam) > 0){
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
            if(dmg > 0 && defteam.active()->get_ability() != Ability::Shield_Dust){
                if(this->transition.randomChance(serene_grace, 10)){
                    // Should have function try_set_status()
                    try_set_status(defteam, Status::Burn);
                }
            }
            return;
        case Move::Blizzard:
        case Move::Ice_Beam:
        case Move::Ice_Punch:
            dmg = calculate_damage(atkteam, defteam);
            if(dmg > 0 && defteam.active()->get_ability() != Ability::Shield_Dust){
                if(this->transition.randomChance(serene_grace, 10)){
                    try_set_status(defteam, Status::Freeze);
                }
            }
            return;
        case Move::Body_Slam:
        case Move::Thunder:
            dmg = calculate_damage(atkteam, defteam);
            if(dmg > 0 && defteam.active()->get_ability() != Ability::Shield_Dust){
                if(this->transition.randomChance(3 * serene_grace, 10)){
                    try_set_status(defteam, Status::Paralysis);
                }
            }
            return;
        ////////////////// done until here
        case Move::Bone_Club:
            dmg = calculate_damage(atkteam, defteam);
            if(dmg > 0 && defteam.active()->get_ability() != Ability::Shield_Dust){
                if(defteam.active()->get_ability() != Ability::Inner_Focus){   
                    if(this->transition.randomChance(serene_grace, 10)){   
                        defteam.flinch = true;
                    }
                }
            }
            return;
        case Move::Bubble:
        case Move::Bubble_Beam:
        case Move::Constrict:
            dmg = calculate_damage(atkteam, defteam);
            if(dmg > 0 && defteam.active()->get_ability() != Ability::Shield_Dust){
                opp_boost(defteam, Statname::Spe, -1, 10 * serene_grace);
            }
            return;
        case Move::Confusion:
            dmg = calculate_damage(atkteam, defteam);
            if(dmg > 0 && defteam.active()->get_ability() != Ability::Shield_Dust){
                if(this->transition.randomChance(serene_grace, 10)){
                    defteam.set_confusion(); // Reminder to look at confusion, sleep, encore, etc
                }
            }
            return;
        case Move::Crunch:
            dmg = calculate_damage(atkteam, defteam);
            if(dmg > 0 && defteam.active()->get_ability() != Ability::Shield_Dust){
                opp_boost(defteam, Statname::Sdef, -1, 30 * serene_grace);
            }
            return;
        case Move::Crush_Claw:
            dmg = calculate_damage(atkteam, defteam);
            if(dmg > 0 && defteam.active()->get_ability() != Ability::Shield_Dust){
                opp_boost(defteam, Statname::Def, -1, 50 * serene_grace);
            }
            return;
        case Move::Dizzy_Punch:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Doom_Desire:
        case Move::Future_Sight:
            return;
        case Move::Double_Edge:
            dmg = calculate_damage(atkteam, defteam);
            atkteam.active()->reduce_hp(static_cast<int>(dmg/3.0));
            return;
        case Move::Dragon_Breath:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Dream_Eater:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Dynamic_Punch:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Eruption:
        case Move::Flail:
        case Move::Reversal:
        case Move::Water_Spout:
            return;
        case Move::Self_Destruct:
        case Move::Explosion:
            if(defteam.active()->get_ability() == Ability::Damp) { return; }
            dmg = calculate_damage(atkteam, defteam);
            atkteam.active()->set_status(Status::Fainted, false);
            atkteam.active()->reduce_hp(9999);
            return;
        case Move::Extrasensory:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Facade:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::False_Swipe:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Feint_Attack:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Headbutt:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::High_Jump_Kick:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Icy_Wind:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Iron_Tail:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Knock_Off:
            dmg = calculate_damage(atkteam, defteam);
            if(defteam.active()->get_ability() != Ability::Sticky_Hold && dmg > 0){
                defteam.active()->previous_item = defteam.active()->get_item();
                defteam.active()->set_item(Item::None);
            }
            return;
        case Move::Leaf_Blade:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Lick:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Magical_Leaf:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Magnitude:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Metal_Claw:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Meteor_Mash:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Nature_Power:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Needle_Arm:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Octazooka:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Poison_Fang:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Poison_Tail:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Powder_Snow:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Psychic:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Pursuit:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Rapid_Spin:
            dmg = calculate_damage(atkteam, defteam);
            if(dmg > 0){
                atkteam.spikes = 0;
            }
            return;
        case Move::Razor_Leaf:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Rock_Smash:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Rock_Tomb:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Sacred_Fire:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Secret_Power:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Shadow_Ball:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Shadow_Punch:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Signal_Beam:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Silver_Wind:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Sludge:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Sludge_Bomb:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Smog:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Spark:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Steel_Wing:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Struggle:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Submission:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Superpower:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Take_Down:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Thief:
            dmg = calculate_damage(atkteam, defteam);
            if(dmg > 0){
                if(atkteam.active()->get_item() == Item::None && defteam.active()->get_ability() != Ability::Sticky_Hold){
                    atkteam.active()->set_item(defteam.active()->get_item());
                    defteam.active()->set_item(Item::None);
                }
            }   
            return;
        case Move::Thunder_Punch:
        case Move::Thunder_Shock:
        case Move::Thunderbolt:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Tri_Attack:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Twister:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Volt_Tackle:
            dmg = calculate_damage(atkteam, defteam);
            return;
        case Move::Water_Pulse:
            dmg = calculate_damage(atkteam, defteam);
            return;
        ////////////////// 
        case Move::Zap_Cannon:
            dmg = calculate_damage(atkteam, defteam);
            try_set_status(defteam, Status::Paralysis);
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
            atkteam.set_boost(Statname::Satk, -2);
            return;	
	    case Move::Psywave:
            dmg = 10 * this->transition.random(11); // TODO Confirm this is not '10'
            dmg *= 50;
            dmg *= atkteam.active()->get_level();
            dmg = static_cast<int>(dmg / 100.0);
            
            if(dmg < 1){
                dmg = 1;
            }
            return;	
	    case Move::Rage:
	    case Move::Revenge:
	    case Move::Rock_Throw:
	    case Move::Rolling_Kick:
	    case Move::Sky_Uppercut:
	    case Move::Smelling_Salts:  // double damage when opponent paralyzed
	    case Move::Stomp:           // double damage on minimize target, don't care for now, lol
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
            switch(this->transition.random(7)){
                case 0:
                case 1:
                case 2:
                    hits = 2;
                    break;
                case 3:
                case 4:
                case 5:
                    hits = 3;
                    break;
                case 6:
                    hits = 4;
                    break;
                case 7:
                    hits = 5;
                    break;
            }
            for(int i = 0; i < hits; ++i){
                dmg = calculate_damage(atkteam, defteam);
            }
            return;
        case Move::Bonemerang:
        case Move::Double_Kick:
        case Move::Double_Slap:
        case Move::Twineedle:
            for(int i = 0; i < 2; ++i){
                dmg = calculate_damage(atkteam, defteam);
            }
            return;
        case Move::Triple_Kick:
            for(int i = 0; i < 3; ++i){
                dmg = calculate_damage(atkteam, defteam);
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
            if(atkteam.charged == false){
                atkteam.charged = true;
            }
            else{
                dmg = calculate_damage(atkteam, defteam);
                
                atkteam.charged = false;
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
        case Move::Clamp:
        case Move::Fire_Spin:
        case Move::Sand_Tomb:
        case Move::Whirlpool:
        case Move::Wrap:
            dmg = calculate_damage(atkteam, defteam);
            if(dmg <= 0){ return; }
            
            if(defteam.wrap <= 0){ defteam.wrap = get_random(2, 5); } // Need to lookup
        case Move::Block:
        case Move::Mean_Look:
        case Move::Spider_Web:
            defteam.meanlook = true;
            return;

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
        case Move::Meditate:
        case Move::Sharpen:
            atkteam.set_boost(Statname::Atk, 1);
            return;
        case Move::Swagger:
            opp_boost(defteam, Statname::Atk, 2, 100);
            atkteam.set_confusion();
            return;
        case Move::Swords_Dance:
            atkteam.set_boost(Statname::Atk, 2);
            return;
        case Move::Acid_Armor:
        case Move::Barrier:
        case Move::Iron_Defense:
            atkteam.set_boost(Statname::Def, 2);
            return;
        case Move::Cosmic_Power:
            atkteam.set_boost(Statname::Def, 1);
            atkteam.set_boost(Statname::Sdef, 1);
            return;
        case Move::Defense_Curl:
        case Move::Harden:
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
        case Move::Minimize:
            atkteam.set_boost(Statname::Eva, 1);
            return;
////////////////////////////////////////////////////
        case Move::Focus_Energy:
////////////////////////////////////////////////////
        case Move::Charm:
        case Move::Feather_Dance:
            opp_boost(defteam, Statname::Atk, -2, 100);
            return;
        case Move::Growl:
            opp_boost(defteam, Statname::Atk, -1, 100);
            return;
        case Move::Tickle:
            opp_boost(defteam, Statname::Atk, -1, 100);
            opp_boost(defteam, Statname::Satk, -1, 100);
            return;
        case Move::Leer:
        case Move::Tail_Whip:
            opp_boost(defteam, Statname::Def, -1, 100);
            return;
        case Move::Screech:
            opp_boost(defteam, Statname::Def, -2, 100);
            return;
        case Move::Fake_Tears:
        case Move::Metal_Sound:
            opp_boost(defteam, Statname::Sdef, -2, 100);
            return;
        case Move::Cotton_Spore:
        case Move::Scary_Face:
            opp_boost(defteam, Statname::Spe, -2, 100);
            return;
        case Move::String_Shot:
            opp_boost(defteam, Statname::Spe, -1, 100);
            return;
        case Move::Flash:
        case Move::Kinesis:
        case Move::Sand_Attack:
        case Move::Smokescreen:
            opp_boost(defteam, Statname::Acc, -1, 100);
            return;
        case Move::Sweet_Scent:
            opp_boost(defteam, Statname::Eva, -1, 100);
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
            if(*defteam.active() != Type::Ghost){
                try_set_status(defteam, Status::Paralysis);
            }
            return;
        case Move::Stun_Spore:
                try_set_status(defteam, Status::Paralysis);
            return;
        case Move::Thunder_Wave:
            if(*defteam.active() != Type::Ground){
                try_set_status(defteam, Status::Paralysis);
            }
            return;
        // sleep
        case Move::Grass_Whistle:
        case Move::Hypnosis:
        case Move::Lovely_Kiss:
        case Move::Sing:
        case Move::Sleep_Powder:
        case Move::Spore:
                try_set_status(defteam, Status::Sleep_inflicted);
            return;
        case Move::Yawn:
            defteam.yawn = 2;
            return;
        case Move::Snore:
            if(atkteam.active()->get_status() == Status::Sleep_inflicted ||
               atkteam.active()->get_status() == Status::Sleep_self){
                dmg = calculate_damage(atkteam, defteam);
                
               }
               return;
        case Move::Sleep_Talk:
        // poison
        case Move::Poison_Powder:
            if(*defteam.active() != Type::Steel && *defteam.active() != Type::Poison){
                try_set_status(defteam, Status::Paralysis);
            }
            return;
        case Move::Toxic:
            if(*defteam.active() != Type::Steel && *defteam.active() != Type::Poison){
                try_set_status(defteam, Status::Paralysis);
                defteam.turns_on_the_field = 1;
            }
            return;
        // burn
        case Move::Will_O_Wisp:
            if(*defteam.active() != Type::Fire){
                try_set_status(defteam, Status::Burn);
            }
            return;
        case Move::Refresh:
            if(atkteam.active()->get_status() != Status::Freeze){
                if(atkteam.active()->get_status() != Status::Sleep_inflicted){
                    if(atkteam.active()->get_status() != Status::Sleep_self){
                        atkteam.active()->set_status(Status::Healthy, false);
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
            for(auto&& member : atkteam.member){
                if(member.get_status() != Status::Fainted){
                    member.set_status(Status::Healthy, false);
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
            atkteam.active()->increase_hp(
                static_cast<int>(atkteam.active()->get_stats().hp / 2.0));
            return;
        case Move::Moonlight:
        case Move::Morning_Sun:
        case Move::Synthesis:
            switch(this->weather){
                case Weather::Sun:
                    atkteam.active()->increase_hp(
                        static_cast<int>(atkteam.active()->get_stats().hp * (2.0 / 3.0)));
                case Weather::Clear:
                    atkteam.active()->increase_hp(
                        static_cast<int>(atkteam.active()->get_stats().hp / 2.0));
                default:
                    atkteam.active()->increase_hp(
                        static_cast<int>(atkteam.active()->get_stats().hp / 4.0));
            }
            return;
        case Move::Rest:
            if(atkteam.active()->get_status() != Status::Sleep_inflicted &&
                atkteam.active()->get_status() != Status::Sleep_self){
                    atkteam.active()->set_status(Status::Sleep_self, false);
                    atkteam.active()->increase_hp(999);
                }
            return;
        case Move::Wish:
            atkteam.wish = true;
            atkteam.wish_recovery = static_cast<int>(atkteam.active()->get_stats().hp / 2.0);
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
            if(atkteam.active()->substitute){
                atkteam.active()->set_sub(false);
                atkteam.member[switch_target].substitute = true;
                atkteam.member[switch_target].substitute_hp = atkteam.active()->substitute_hp;
                atkteam.active()->set_sub_hp(0);
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
            if(*defteam.active() != Type::Grass){
                defteam.leechseed = true;
            }
            return;
        case Move::Light_Screen:
            atkteam.lightscreen = true;
            return;
        case Move::Lock_On:
        case Move::Low_Kick:
        case Move::Magic_Coat:
        case Move::Memento:
            atkteam.active()->reduce_hp(999);
            opp_boost(defteam, Statname::Atk, -2, 100);
            opp_boost(defteam, Statname::Satk, -2, 100);
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
            atkteam.active()->create_substitute();
            substitute_log(atkteam);
            return;
        case Move::Swallow:
        case Move::Taunt:
            if(defteam.taunt <= 0){ defteam.taunt = 2; };
            return;
        case Move::Torment:
        case Move::Transform:
        case Move::Water_Sport:
        case Move::Trick:
            if(defteam.active()->get_ability() != Ability::Sticky_Hold){
                Item tmp = defteam.active()->get_item();
                defteam.active()->set_item(atkteam.active()->get_item());
                atkteam.active()->set_item(tmp);
            }
            return;
        case Move::Roar:
        case Move::Whirlwind:
            if(defteam.active()->get_ability() != Ability::Suction_Cups){
                std::vector<int> targets = {};
                for(int i = 0; i < 6; ++i){
                    if(defteam.member[i].current_hp > 0) {
                        targets.push_back(i);
                    }
                }
                if(targets.size() > 1){
                    switch_in(defteam, atkteam, this->transition.random(targets.size()));
                }
            }
            return;
    }
}

bool Battle::is_sound_move(Move move){
    switch(move){
        case Move::Boomburst:
        case Move::Bug_Buzz:
        case Move::Chatter:
        case Move::Clanging_Scales:
        case Move::Clangorous_Soulblaze:
        case Move::Confide:
        case Move::Disarming_Voice:
        case Move::Echoed_Voice:
        case Move::Grass_Whistle:
        case Move::Growl:
        case Move::Heal_Bell:
        case Move::Howl:
        case Move::Hyper_Voice:
        case Move::Metal_Sound:
        case Move::Noble_Roar:
        case Move::Parting_Shot:
        case Move::Perish_Song:
        case Move::Relic_Song:
        case Move::Roar:
        case Move::Round:
        case Move::Screech:
        case Move::Sing:
        case Move::Snarl:
        case Move::Snore:
        case Move::Sparkling_Aria:
        case Move::Supersonic:
        case Move::Uproar:
            return true;
        default:
            return false;
    }
}

bool Battle::is_contact_move(Move move){
    switch(move){
        case Move::Pound:
        case Move::Karate_Chop:
        case Move::Double_Slap:
        case Move::Comet_Punch:
        case Move::Mega_Punch:
        case Move::Fire_Punch:
        case Move::Ancient_Power:
        case Move::Overheat:
        case Move::Ice_Punch:
        case Move::Thunder_Punch:
        case Move::Scratch:
        case Move::Vice_Grip:
        case Move::Guillotine:
        case Move::Cut:
        case Move::Wing_Attack:
        case Move::Fly:
        case Move::Bind:
        case Move::Slam:
        case Move::Vine_Whip:
        case Move::Stomp:
        case Move::Double_Kick:
        case Move::Mega_Kick:
        case Move::Jump_Kick:
        case Move::Rolling_Kick:
        case Move::Headbutt:
        case Move::Horn_Attack:
        case Move::Fury_Attack:
        case Move::Horn_Drill:
        case Move::Tackle:
        case Move::Body_Slam:
        case Move::Wrap:
        case Move::Take_Down:
        case Move::Thrash:
        case Move::Double_Edge:
        case Move::Bite:
        case Move::Peck:
        case Move::Drill_Peck:
        case Move::Submission:
        case Move::Low_Kick:
        case Move::Counter:
        case Move::Seismic_Toss:
        case Move::Strength:
        case Move::Petal_Dance:
        case Move::Dig:
        case Move::Quick_Attack:
        case Move::Rage:
        case Move::Bide:
        case Move::Lick:
        case Move::Waterfall:
        case Move::Clamp:
        case Move::Skull_Bash:
        case Move::Constrict:
        case Move::High_Jump_Kick:
        case Move::Leech_Life:
        case Move::Dizzy_Punch:
        case Move::Crabhammer:
        case Move::Fury_Swipes:
        case Move::Hyper_Fang:
        case Move::Super_Fang:
        case Move::Slash:
        case Move::Struggle:
        case Move::Triple_Kick:
        case Move::Thief:
        case Move::Flame_Wheel:
        case Move::Flail:
        case Move::Reversal:
        case Move::Mach_Punch:
        case Move::Feint_Attack:
        case Move::Outrage:
        case Move::Rollout:
        case Move::False_Swipe:
        case Move::Spark:
        case Move::Fury_Cutter:
        case Move::Steel_Wing:
        case Move::Return:
        case Move::Frustration:
        case Move::Dynamic_Punch:
        case Move::Megahorn:
        case Move::Pursuit:
        case Move::Rapid_Spin:
        case Move::Iron_Tail:
        case Move::Metal_Claw:
        case Move::Vital_Throw:
        case Move::Cross_Chop:
        case Move::Crunch:
        case Move::Extreme_Speed:
        case Move::Rock_Smash:
        case Move::Facade:
        case Move::Focus_Punch:
        case Move::Smelling_Salts:
        case Move::Superpower:
        case Move::Revenge:
        case Move::Brick_Break:
        case Move::Knock_Off:
        case Move::Endeavor:
        case Move::Dive:
        case Move::Arm_Thrust:
        case Move::Blaze_Kick:
        case Move::Ice_Ball:
        case Move::Needle_Arm:
        case Move::Poison_Fang:
        case Move::Crush_Claw:
        case Move::Meteor_Mash:
        case Move::Astonish:
        case Move::Shadow_Punch:
        case Move::Sky_Uppercut:
        case Move::Aerial_Ace:
        case Move::Dragon_Claw:
        case Move::Bounce:
        case Move::Poison_Tail:
        case Move::Covet:
        case Move::Volt_Tackle:
        case Move::Leaf_Blade:
        case Move::Wake_Up_Slap:
        case Move::Hammer_Arm:
        case Move::Gyro_Ball:
        case Move::Pluck:
        case Move::U_turn:
        case Move::Close_Combat:
        case Move::Payback:
        case Move::Assurance:
        case Move::Trump_Card:
        case Move::Wring_Out:
        case Move::Punishment:
        case Move::Last_Resort:
        case Move::Sucker_Punch:
        case Move::Flare_Blitz:
        case Move::Force_Palm:
        case Move::Poison_Jab:
        case Move::Night_Slash:
        case Move::Aqua_Tail:
        case Move::X_Scissor:
        case Move::Dragon_Rush:
        case Move::Drain_Punch:
        case Move::Brave_Bird:
        case Move::Giga_Impact:
        case Move::Bullet_Punch:
        case Move::Avalanche:
        case Move::Shadow_Claw:
        case Move::Thunder_Fang:
        case Move::Ice_Fang:
        case Move::Fire_Fang:
        case Move::Shadow_Sneak:
        case Move::Zen_Headbutt:
        case Move::Rock_Climb:
        case Move::Power_Whip:
        case Move::Cross_Poison:
        case Move::Iron_Head:
        case Move::Grass_Knot:
        case Move::Bug_Bite:
        case Move::Wood_Hammer:
        case Move::Aqua_Jet:
        case Move::Head_Smash:
        case Move::Double_Hit:
        case Move::Crush_Grip:
        case Move::Shadow_Force:
        case Move::Storm_Throw:
        case Move::Heavy_Slam:
        case Move::Flame_Charge:
        case Move::Low_Sweep:
        case Move::Foul_Play:
        case Move::Chip_Away:
        case Move::Sky_Drop:
        case Move::Circle_Throw:
        case Move::Acrobatics:
        case Move::Retaliate:
        case Move::Dragon_Tail:
        case Move::Wild_Charge:
        case Move::Drill_Run:
        case Move::Dual_Chop:
        case Move::Heart_Stamp:
        case Move::Horn_Leech:
        case Move::Sacred_Sword:
        case Move::Razor_Shell:
        case Move::Heat_Crash:
        case Move::Steamroller:
        case Move::Tail_Slap:
        case Move::Head_Charge:
        case Move::Gear_Grind:
        case Move::Bolt_Strike:
        case Move::V_create:
        case Move::Flying_Press:
        case Move::Fell_Stinger:
        case Move::Phantom_Force:
        case Move::Draining_Kiss:
        case Move::Play_Rough:
        case Move::Nuzzle:
        case Move::Hold_Back:
        case Move::Infestation:
        case Move::Power_Up_Punch:
        case Move::Dragon_Ascent:
        case Move::Catastropika:
        case Move::First_Impression:
        case Move::Darkest_Lariat:
        case Move::Ice_Hammer:
        case Move::High_Horsepower:
        case Move::Solar_Blade:
        case Move::Throat_Chop:
        case Move::Anchor_Shot:
        case Move::Lunge:
        case Move::Fire_Lash:
        case Move::Power_Trip:
        case Move::Smart_Strike:
        case Move::Trop_Kick:
        case Move::Dragon_Hammer:
        case Move::Brutal_Swing:
        case Move::Malicious_Moonsault:
        case Move::Soul_Stealing_7_Star_Strike:
        case Move::Pulverizing_Pancake:
        case Move::Psychic_Fangs:
        case Move::Stomping_Tantrum:
        case Move::Accelerock:
        case Move::Liquidation:
        case Move::Spectral_Thief:
        case Move::Sunsteel_Strike:
        case Move::Zing_Zap:
        case Move::Multi_Attack:
        case Move::Plasma_Fists:
        case Move::Searing_Sunraze_Smash:
        case Move::Lets_Snuggle_Forever:
        case Move::Zippy_Zap:
        case Move::Floaty_Fall:
        case Move::Sizzly_Slide:
        case Move::Veevee_Volley:
        case Move::Double_Iron_Bash:
            return true;
        default:
            return false;
    }
}