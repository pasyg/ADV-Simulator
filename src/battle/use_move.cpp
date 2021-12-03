#include "battle.hpp"


void Battle::use_move(const bool teamindex){
    int dmg = 0;

    switch(this->team[teamindex]->movechoice->get_move()){
        ///
        /// switches
        ///
        case Move::Switch0:
            this->team[teamindex]->active_pokemon = 0;
            return;
        case Move::Switch1:
            this->team[teamindex]->active_pokemon = 1;
            return;
        case Move::Switch2:
            this->team[teamindex]->active_pokemon = 2;
            return;
        case Move::Switch3:
            this->team[teamindex]->active_pokemon = 3;
            return;
        case Move::Switch4:
            this->team[teamindex]->active_pokemon = 4;
            return;
        case Move::Switch5:
            this->team[teamindex]->active_pokemon = 5;
            return;
        // splash...
        case Move::Splash: return;
        ///
        /// basic damage moves without further effects
        ///
        case Move::Super_Fang:
            dmg = static_cast<int>(this->team[!teamindex]->member[this->team[!teamindex]->active_pokemon].get_current_hp() / 2.0);
            if(this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Ghost &&
               this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Ghost){
                this->team[!teamindex]->member[this->team[!teamindex]->active_pokemon].reduce_hp(dmg);
            }
            return;
        case Move::Seismic_Toss:
            dmg = 100;
            if(this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Ghost &&
               this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Ghost){
                this->team[!teamindex]->member[this->team[!teamindex]->active_pokemon].reduce_hp(dmg);
            }
            return;
        case Move::Night_Shade:
            dmg = 100;
            if(this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Normal &&
               this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Normal){
                this->team[!teamindex]->member[this->team[!teamindex]->active_pokemon].reduce_hp(dmg);
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
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        ///
        /// secondary effect damage moves
        ///
        // leech moves
        case Move::Absorb:
        case Move::Giga_Drain:
        case Move::Leech_Life:
        case Move::Mega_Drain:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            if(dmg > 1){
                this->team[teamindex]->mon_in_battle->increase_hp(static_cast<int>(dmg / 2.0));
            }
            else{
                this->team[teamindex]->mon_in_battle->increase_hp(static_cast<int>(1));
            }
                return;
        case Move::Acid:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            if(dmg > 0){
                if(get_random(1,10) == 1){
                    this->team[!teamindex]->set_boost(Statname::Def, -1);
                }
            }
            return;
        case Move::Ancient_Power:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            if(dmg > 0){
                if(get_random(1,10) == 1){
                    this->team[!teamindex]->set_boost(Statname::Atk, 1);
                    this->team[!teamindex]->set_boost(Statname::Def, 1);
                    this->team[!teamindex]->set_boost(Statname::Satk, 1);
                    this->team[!teamindex]->set_boost(Statname::Sdef, 1);
                    this->team[!teamindex]->set_boost(Statname::Spe, 1);
                }
            }
            return;
        case Move::Aurora_Beam:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            if(get_random(1,10) == 1){
                this->team[!teamindex]->set_boost(Statname::Atk, 1);
            }
            return;
        case Move::Astonish:
        case Move::Bite:
        case Move::Rock_Slide:
            dmg = calculate_damage(teamindex);
            if(dmg > 0){
                this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
                if(get_random(1,10) < 4){
                    this->team[!teamindex]->flinch = true;
                }
            }
            return;
        case Move::Blast_Burn:
        case Move::Frenzy_Plant:
        case Move::Hydro_Cannon:
        case Move::Hyper_Beam:
            dmg = calculate_damage(teamindex);
            if(dmg > 0){
                this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
                this->team[teamindex]->recharge = 2;
            }
            return;
        case Move::Blaze_Kick:
        case Move::Ember:
        case Move::Fire_Blast:
        case Move::Fire_Punch:
        case Move::Flamethrower:
        case Move::Heat_Wave:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            if(dmg > 0){
                if(get_random(1,10)){
                    if(this->team[!teamindex]->mon_in_battle->get_status() == Status::Healthy){
                        this->team[!teamindex]->mon_in_battle->set_status(Status::Burn);
                    }
                }
            }
            return;
        case Move::Blizzard:
        case Move::Ice_Beam:
        case Move::Ice_Punch:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Body_Slam:
        case Move::Thunder:
            dmg = calculate_damage(teamindex);
            if(dmg > 0){
                this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
                if(this->team[!teamindex]->mon_in_battle->get_status() == Status::Healthy){
                    if(get_random(1,10) < 4){
                        this->team[!teamindex]->mon_in_battle->set_status(Status::Paralysis);
                    }
                }
            }
            return;
        ////////////////// done until here
        case Move::Bone_Club:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Bubble:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Bubble_Beam:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Confusion:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Constrict:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Crunch:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Crush_Claw:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Dizzy_Punch:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Doom_Desire:
        case Move::Future_Sight:
            return;
        case Move::Double_Edge:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Dragon_Breath:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Dream_Eater:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Dynamic_Punch:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Eruption:
        case Move::Flail:
        case Move::Reversal:
        case Move::Water_Spout:
            return;
        case Move::Explosion:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Extrasensory:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Facade:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::False_Swipe:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Feint_Attack:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Headbutt:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::High_Jump_Kick:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Icy_Wind:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Iron_Tail:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Knock_Off:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Leaf_Blade:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Lick:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Magical_Leaf:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Magnitude:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Metal_Claw:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Meteor_Mash:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Nature_Power:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Needle_Arm:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Octazooka:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Overheat:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Poison_Fang:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Poison_Tail:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Powder_Snow:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Psychic:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Pursuit:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Rapid_Spin:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Razor_Leaf:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Rock_Smash:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Rock_Tomb:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Sacred_Fire:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Secret_Power:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Self_Destruct:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Shadow_Ball:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Shadow_Punch:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Signal_Beam:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Silver_Wind:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Sludge:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Sludge_Bomb:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Smog:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Spark:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Steel_Wing:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Struggle:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Submission:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Superpower:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Take_Down:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Thief:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Thunder_Punch:
        case Move::Thunder_Shock:
        case Move::Thunderbolt:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Tri_Attack:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Twister:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Volt_Tackle:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        case Move::Water_Pulse:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            return;
        ////////////////// 
        case Move::Zap_Cannon:
            dmg = calculate_damage(teamindex);
            this->team[!teamindex]->mon_in_battle->reduce_hp(dmg);
            if(this->team[!teamindex]->mon_in_battle->get_status() == Status::Healthy){
                this->team[!teamindex]->mon_in_battle->set_status(Status::Paralysis);
            }
            return;
        ///
        /// multihit
        ///
        case Move::Arm_Thrust:
        case Move::Barrage:
        case Move::Bone_Rush:
        case Move::Bonemerang:
        case Move::Bullet_Seed:
        case Move::Comet_Punch:
        case Move::Double_Kick:
        case Move::Double_Slap:
        case Move::Fury_Attack:
        case Move::Fury_Swipes:
        case Move::Ice_Ball: // ewww
        case Move::Icicle_Spear:
        case Move::Pin_Missile:
        case Move::Rock_Blast:
        case Move::Rollout: // ewww
        case Move::Spike_Cannon:
        case Move::Triple_Kick:
        case Move::Twineedle:


        ///
        /// selflock
        ///

        ///
        /// multiturn
        ///
        
        ///
        /// boost affecting moves
        ///
        case Move::Belly_Drum:
            this->team[teamindex]->set_boost(Statname::Atk, 12);
            return;
        case Move::Bulk_Up:
            this->team[teamindex]->set_boost(Statname::Atk, 1);
            this->team[teamindex]->set_boost(Statname::Def, 1);
            return;
        case Move::Curse:
            this->team[teamindex]->set_boost(Statname::Atk, 1);
            this->team[teamindex]->set_boost(Statname::Def, 1);
            this->team[teamindex]->set_boost(Statname::Spe, -1);
            return;
        case Move::Dragon_Dance:
            this->team[teamindex]->set_boost(Statname::Atk, 1);
            this->team[teamindex]->set_boost(Statname::Spe, 1);
            return;
        case Move::Howl:
            this->team[teamindex]->set_boost(Statname::Atk, 1);
            return;
        case Move::Meditate:
            this->team[teamindex]->set_boost(Statname::Atk, 1);
            return;
        case Move::Sharpen:
            this->team[teamindex]->set_boost(Statname::Atk, 1);
            return;
        case Move::Swagger:
            this->team[!teamindex]->set_boost(Statname::Atk, 1);
            this->team[teamindex]->set_confusion();
            return;
        case Move::Swords_Dance:
            this->team[teamindex]->set_boost(Statname::Atk, 2);
            return;

        case Move::Acid_Armor:
            this->team[teamindex]->set_boost(Statname::Def, 2);
            return;
        case Move::Barrier:
            this->team[teamindex]->set_boost(Statname::Def, 2);
            return;
        case Move::Cosmic_Power:
            this->team[teamindex]->set_boost(Statname::Def, 1);
            this->team[teamindex]->set_boost(Statname::Sdef, 1);
            return;
        case Move::Defense_Curl:
            this->team[teamindex]->set_boost(Statname::Def, 1);
            return;
        case Move::Harden:
            this->team[teamindex]->set_boost(Statname::Def, 1);
            return;
        case Move::Iron_Defense:
            this->team[teamindex]->set_boost(Statname::Def, 2);
            return;
        case Move::Withdraw:
            this->team[teamindex]->set_boost(Statname::Def, 1);
            return;

        case Move::Calm_Mind:
            this->team[teamindex]->set_boost(Statname::Satk, 1);
            this->team[teamindex]->set_boost(Statname::Sdef, 1);
            return;
        case Move::Growth:
            this->team[teamindex]->set_boost(Statname::Satk, 1);
            return;
        case Move::Tail_Glow:
            this->team[teamindex]->set_boost(Statname::Satk, 2);
            return;
        
        case Move::Amnesia:
            this->team[teamindex]->set_boost(Statname::Sdef, 2);
            return;

        case Move::Agility:
            this->team[teamindex]->set_boost(Statname::Spe, 2);
            return;

        case Move::Double_Team:
            this->team[teamindex]->set_boost(Statname::Eva, 1);
            return;
        case Move::Minimize:
            this->team[teamindex]->set_boost(Statname::Eva, 1);
            return;
////////////////////////////////////////////////////
        case Move::Focus_Energy:
////////////////////////////////////////////////////
        case Move::Charm:
            this->team[!teamindex]->set_boost(Statname::Atk, -2);
            return;
        case Move::Feather_Dance:
            this->team[!teamindex]->set_boost(Statname::Atk, -2);
            return;
        case Move::Growl:
            this->team[!teamindex]->set_boost(Statname::Atk, -1);
            return;
        case Move::Tickle:
            this->team[!teamindex]->set_boost(Statname::Atk, -1);
            this->team[!teamindex]->set_boost(Statname::Satk, -1);
            return;

        case Move::Leer:
            this->team[!teamindex]->set_boost(Statname::Def, -1);
            return;
        case Move::Screech:
            this->team[!teamindex]->set_boost(Statname::Def, -2);
            return;
        case Move::Tail_Whip:
            this->team[!teamindex]->set_boost(Statname::Def, -1);
            return;

        case Move::Fake_Tears:
        case Move::Metal_Sound:
            this->team[!teamindex]->set_boost(Statname::Sdef, -2);
            return;

        case Move::Cotton_Spore:
        case Move::Scary_Face:
            this->team[!teamindex]->set_boost(Statname::Spe, -2);
            return;
        case Move::String_Shot:
            this->team[!teamindex]->set_boost(Statname::Spe, -1);
            return;

        case Move::Flash:
        case Move::Kinesis:
        case Move::Sand_Attack:
        case Move::Smokescreen:
            this->team[!teamindex]->set_boost(Statname::Acc, -1);
            return;
        case Move::Sweet_Scent:
            this->team[!teamindex]->set_boost(Statname::Eva, -1);
            return;

        case Move::Psych_Up:
            if(this->team[!teamindex]->atkboost > this->team[teamindex]->atkboost){
                this->team[teamindex]->atkboost = this->team[!teamindex]->atkboost;
            }
            if(this->team[!teamindex]->defboost > this->team[teamindex]->defboost){
                this->team[teamindex]->defboost = this->team[!teamindex]->defboost;
            }
            if(this->team[!teamindex]->satkboost > this->team[teamindex]->satkboost){
                this->team[teamindex]->satkboost = this->team[!teamindex]->satkboost;
            }
            if(this->team[!teamindex]->sdefboost > this->team[teamindex]->sdefboost){
                this->team[teamindex]->sdefboost = this->team[!teamindex]->sdefboost;
            }
            if(this->team[!teamindex]->speboost > this->team[teamindex]->speboost){
                this->team[teamindex]->speboost = this->team[!teamindex]->speboost;
            }
            return;
        case Move::Haze:
            this->team[teamindex]->atkboost = 0;
            this->team[teamindex]->defboost = 0;
            this->team[teamindex]->satkboost = 0;
            this->team[teamindex]->sdefboost = 0;
            this->team[teamindex]->speboost = 0;
            this->team[teamindex]->accboost = 0;
            this->team[teamindex]->evaboost = 0;

            this->team[!teamindex]->atkboost = 0;
            this->team[!teamindex]->defboost = 0;
            this->team[!teamindex]->satkboost = 0;
            this->team[!teamindex]->sdefboost = 0;
            this->team[!teamindex]->speboost = 0;
            this->team[!teamindex]->accboost = 0;
            this->team[!teamindex]->evaboost = 0;
            return;
        ///
        /// status moves
        ///
        case Move::Glare:
            if(this->team[!teamindex]->mon_in_battle->get_status() != Status::Healthy){
                switch(this->team[!teamindex]->mon_in_battle->get_type()[0]){
                    case Type::Ghost:
                        return;
                    default:
                        switch(this->team[!teamindex]->mon_in_battle->get_type()[1]){
                            case Type::Ghost:
                                return;
                            default:
                                this->team[!teamindex]->mon_in_battle->set_status(Status::Paralysis);
                        }
                }
            }
            return;
        case Move::Grass_Whistle:
        case Move::Hypnosis:
        case Move::Lovely_Kiss:
        case Move::Sing:
        case Move::Sleep_Powder:
        case Move::Spore:
            if(this->team[!teamindex]->mon_in_battle->get_status() != Status::Healthy){
                this->team[!teamindex]->mon_in_battle->set_status(Status::Sleep_inflicted);
            }
            return;
        case Move::Poison_Powder:
            if(this->team[!teamindex]->mon_in_battle->get_status() != Status::Healthy){
                switch(this->team[!teamindex]->mon_in_battle->get_type()[0]){
                    case Type::Poison:
                    case Type::Steel:
                        return;
                    default:
                        switch(this->team[!teamindex]->mon_in_battle->get_type()[1]){
                            case Type::Poison:
                            case Type::Steel:
                                return;
                            default:
                                this->team[!teamindex]->mon_in_battle->set_status(Status::Poison);
                        }
                }
            }
            return;
        case Move::Stun_Spore:
            if(this->team[!teamindex]->mon_in_battle->get_status() != Status::Healthy){
                this->team[!teamindex]->mon_in_battle->set_status(Status::Paralysis);
            }
            return;
        case Move::Thunder_Wave:
            if(this->team[!teamindex]->mon_in_battle->get_status() != Status::Healthy){
                switch(this->team[!teamindex]->mon_in_battle->get_type()[0]){
                    case Type::Ground:
                        return;
                    default:
                        switch(this->team[!teamindex]->mon_in_battle->get_type()[1]){
                            case Type::Ground:
                                return;
                            default:
                                this->team[!teamindex]->mon_in_battle->set_status(Status::Paralysis);
                        }
                }
            }
            return;
        case Move::Toxic:
            if(this->team[!teamindex]->mon_in_battle->get_status() != Status::Healthy){
                switch(this->team[!teamindex]->mon_in_battle->get_type()[0]){
                    case Type::Poison:
                    case Type::Steel:
                        return;
                    default:
                        switch(this->team[!teamindex]->mon_in_battle->get_type()[1]){
                            case Type::Poison:
                            case Type::Steel:
                                return;
                            default:
                                this->team[!teamindex]->mon_in_battle->set_status(Status::Toxic_poison);
                        }
                }
            }
            return;
        case Move::Will_O_Wisp:
            if(this->team[!teamindex]->mon_in_battle->get_status() != Status::Healthy){
                switch(this->team[!teamindex]->mon_in_battle->get_type()[0]){
                    case Type::Fire:
                        return;
                    default:
                        switch(this->team[!teamindex]->mon_in_battle->get_type()[1]){
                            case Type::Fire:
                                return;
                            default:
                                this->team[!teamindex]->mon_in_battle->set_status(Status::Burn);
                        }
                }
            }
            return;
        case Move::Yawn:
            this->team[!teamindex]->yawn = 2;
            return;
        case Move::Refresh:
            if(this->team[teamindex]->mon_in_battle->get_status() != Status::Freeze){
                if(this->team[teamindex]->mon_in_battle->get_status() != Status::Sleep_inflicted){
                    if(this->team[teamindex]->mon_in_battle->get_status() != Status::Sleep_self){
                        this->team[teamindex]->mon_in_battle->set_status(Status::Healthy);
                    }
                }
            }
            return;
        ///
        /// healing moves
        ///
        case Move::Milk_Drink:
        case Move::Recover:
        case Move::Slack_Off:
        case Move::Soft_Boiled:
            this->team[teamindex]->mon_in_battle->increase_hp(
                static_cast<int>(this->team[teamindex]->mon_in_battle->get_stats().hp / 2.0));
            return;
        case Move::Moonlight:
        case Move::Morning_Sun:
        case Move::Synthesis:
            switch(this->weather){
                case Weather::Sun:
                    this->team[teamindex]->mon_in_battle->increase_hp(
                        static_cast<int>(this->team[teamindex]->mon_in_battle->get_stats().hp * (2.0 / 3.0)));
                case Weather::Clear:
                    this->team[teamindex]->mon_in_battle->increase_hp(
                        static_cast<int>(this->team[teamindex]->mon_in_battle->get_stats().hp / 2.0));
                default:
                    this->team[teamindex]->mon_in_battle->increase_hp(
                        static_cast<int>(this->team[teamindex]->mon_in_battle->get_stats().hp / 4.0));
            }
            return;
        case Move::Rest:
            if(this->team[teamindex]->mon_in_battle->get_status() != Status::Sleep_inflicted &&
                this->team[teamindex]->mon_in_battle->get_status() != Status::Sleep_self){
                    this->team[teamindex]->mon_in_battle->set_status(Status::Sleep_self);
                    this->team[teamindex]->mon_in_battle->increase_hp(999);
                }
            return;
        case Move::Wish:
            this->team[teamindex]->wish = true;
            this->team[teamindex]->wish_recovery = static_cast<int>(this->team[teamindex]->mon_in_battle->get_stats().hp / 2.0);
            return;
        case Move::Ingrain:
            this->team[teamindex]->ingrain = true;
            return;
        case Move::Aromatherapy:
        case Move::Heal_Bell:
            for(int i = 0; i < 6; ++i){
                if(this->team[teamindex]->member[i].get_status() != Status::Fainted){
                    this->team[teamindex]->member[i].set_status(Status::Healthy);
                }
            }
            this->team[teamindex]->sleep_inflict = false;
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
            return;
    }
}