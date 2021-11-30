#include "battle.hpp"

void Battle::use_move(const bool teamindex){
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
            if(this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Ghost &&
               this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Ghost){
                this->team[!teamindex]->member[this->team[!teamindex]->active_pokemon].reduce_hp(
                    this->team[!teamindex]->member[this->team[!teamindex]->active_pokemon].get_current_hp() / 2);
            }
        case Move::Seismic_Toss:
            if(this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Ghost &&
               this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Ghost){
                this->team[!teamindex]->member[this->team[!teamindex]->active_pokemon].reduce_hp(100);
            }
        case Move::Night_Shade:
            if(this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Normal &&
               this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Normal){
                this->team[!teamindex]->member[this->team[!teamindex]->active_pokemon].reduce_hp(100);
            }	
        case Move::Aerial_Ace:
        case Move::Aeroblast:
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
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        ///
        /// secondary effecet damage moves
        ///
        case Move::Absorb:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Acid:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Air_Cutter:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Ancient_Power:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Arm_Thrust:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Astonish:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Aurora_Beam:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Bite:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Blast_Burn:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Blaze_Kick:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Blizzard:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Body_Slam:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Bone_Club:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Bubble:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Bubble_Beam:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Confusion:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Constrict:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Crunch:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Crush_Claw:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Dizzy_Punch:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Double_Edge:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Dragon_Breath:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Dream_Eater:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Dynamic_Punch:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Ember:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Explosion:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Extrasensory:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Facade:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::False_Swipe:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Feint_Attack:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Fire_Blast:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Fire_Punch:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Flamethrower:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Frenzy_Plant:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Giga_Drain:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Headbutt:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Heat_Wave:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::High_Jump_Kick:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Hydro_Cannon:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Hyper_Beam:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Ice_Beam:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Ice_Punch:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Icy_Wind:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Iron_Tail:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Knock_Off:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Leaf_Blade:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Leech_Life:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Lick:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Magical_Leaf:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Magnitude:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Mega_Drain:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Metal_Claw:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Meteor_Mash:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Nature_Power:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Needle_Arm:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Octazooka:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Overheat:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Poison_Fang:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Poison_Tail:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Powder_Snow:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Psychic:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Pursuit:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Rapid_Spin:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Razor_Leaf:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Rock_Slide:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Rock_Smash:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Rock_Tomb:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Sacred_Fire:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Secret_Power:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Self_Destruct:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Shadow_Ball:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Shadow_Punch:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Signal_Beam:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Silver_Wind:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Sludge:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Sludge_Bomb:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Smog:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Spark:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Steel_Wing:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Struggle:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Submission:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Superpower:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Take_Down:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Thief:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Thunder:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Thunder_Punch:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Thunder_Shock:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Thunderbolt:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Tri_Attack:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Twister:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Volt_Tackle:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Water_Pulse:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        case Move::Zap_Cannon:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            break;
        ///
        /// boost affecting moves
        ///
        case Move::Belly_Drum:
            this->team[teamindex]->set_boost(Statname::Atk, 12);
        case Move::Bulk_Up:
            this->team[teamindex]->set_boost(Statname::Atk, 1);
            this->team[teamindex]->set_boost(Statname::Def, 1);
        case Move::Curse:
            this->team[teamindex]->set_boost(Statname::Atk, 1);
            this->team[teamindex]->set_boost(Statname::Def, 1);
            this->team[teamindex]->set_boost(Statname::Spe, -1);
        case Move::Dragon_Dance:
            this->team[teamindex]->set_boost(Statname::Atk, 1);
            this->team[teamindex]->set_boost(Statname::Spe, 1);
        case Move::Howl:
            this->team[teamindex]->set_boost(Statname::Atk, 1);
        case Move::Meditate:
            this->team[teamindex]->set_boost(Statname::Atk, 1);
        case Move::Sharpen:
            this->team[teamindex]->set_boost(Statname::Atk, 1);
        case Move::Swagger:
            this->team[!teamindex]->set_boost(Statname::Atk, 1);
            this->team[teamindex]->set_confusion();
        case Move::Swords_Dance:
            this->team[teamindex]->set_boost(Statname::Atk, 2);

        case Move::Acid_Armor:
            this->team[teamindex]->set_boost(Statname::Def, 2);
        case Move::Barrier:
            this->team[teamindex]->set_boost(Statname::Def, 2);
        case Move::Cosmic_Power:
            this->team[teamindex]->set_boost(Statname::Def, 1);
            this->team[teamindex]->set_boost(Statname::Sdef, 1);
        case Move::Defense_Curl:
            this->team[teamindex]->set_boost(Statname::Def, 1);
        case Move::Harden:
            this->team[teamindex]->set_boost(Statname::Def, 1);
        case Move::Iron_Defense:
            this->team[teamindex]->set_boost(Statname::Def, 2);
        case Move::Withdraw:
            this->team[teamindex]->set_boost(Statname::Def, 1);

        case Move::Calm_Mind:
            this->team[teamindex]->set_boost(Statname::Satk, 1);
            this->team[teamindex]->set_boost(Statname::Sdef, 1);
        case Move::Growth:
            this->team[teamindex]->set_boost(Statname::Satk, 1);
        case Move::Tail_Glow:
            this->team[teamindex]->set_boost(Statname::Satk, 2);
        
        case Move::Amnesia:
            this->team[teamindex]->set_boost(Statname::Sdef, 2);

        case Move::Agility:
            this->team[teamindex]->set_boost(Statname::Spe, 2);

        case Move::Double_Team:
            this->team[teamindex]->set_boost(Statname::Eva, 1);
        case Move::Minimize:
            this->team[teamindex]->set_boost(Statname::Eva, 1);

        case Move::Focus_Energy:

        case Move::Charm:
            this->team[!teamindex]->set_boost(Statname::Atk, -2);
        case Move::Feather_Dance:
            this->team[!teamindex]->set_boost(Statname::Atk, -2);
        case Move::Growl:
            this->team[!teamindex]->set_boost(Statname::Atk, -1);
        case Move::Tickle:
            this->team[!teamindex]->set_boost(Statname::Atk, -1);
            this->team[!teamindex]->set_boost(Statname::Satk, -1);

        case Move::Leer:
            this->team[!teamindex]->set_boost(Statname::Def, -1);
        case Move::Screech:
            this->team[!teamindex]->set_boost(Statname::Def, -2);
        case Move::Tail_Whip:
            this->team[!teamindex]->set_boost(Statname::Def, -1);

        case Move::Fake_Tears:
            this->team[!teamindex]->set_boost(Statname::Sdef, -2);
        case Move::Metal_Sound:
            this->team[!teamindex]->set_boost(Statname::Sdef, -2);

        case Move::Cotton_Spore:
            this->team[!teamindex]->set_boost(Statname::Spe, -2);
        case Move::Scary_Face:
            this->team[!teamindex]->set_boost(Statname::Spe, -2);
        case Move::String_Shot:
            this->team[!teamindex]->set_boost(Statname::Spe, -1);

        case Move::Flash:
            this->team[!teamindex]->set_boost(Statname::Acc, -1);
        case Move::Kinesis:
            this->team[!teamindex]->set_boost(Statname::Acc, -1);
        case Move::Sand_Attack:
            this->team[!teamindex]->set_boost(Statname::Acc, -1);
        case Move::Smokescreen:
            this->team[!teamindex]->set_boost(Statname::Acc, -1);
        case Move::Sweet_Scent:
            this->team[!teamindex]->set_boost(Statname::Eva, -1);

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
        ///
        /// status moves
        ///

        ///
        /// healing moves
        ///
        case Move::Milk_Drink:
        case Move::Recover:
        case Move::Slack_Off:
        case Move::Soft_Boiled:
            this->team[teamindex]->mon_in_battle->increase_hp(
                static_cast<int>(this->team[teamindex]->mon_in_battle->get_stats().hp / 2.0));
            break;
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
            break;
        case Move::Rest:
            if(this->team[teamindex]->mon_in_battle->get_status() != Status::Sleep_inflicted &&
                this->team[teamindex]->mon_in_battle->get_status() != Status::Sleep_self){
                    this->team[teamindex]->mon_in_battle->set_status(Status::Sleep_self);
                    this->team[teamindex]->mon_in_battle->increase_hp(999);
                }
        case Move::Wish:
            this->team[teamindex]->wish = true;
            this->team[teamindex]->wish_recovery = static_cast<int>(this->team[teamindex]->mon_in_battle->get_stats().hp / 2.0);
        case Move::Ingrain:
            this->team[teamindex]->ingrain = true;
        case Move::Aromatherapy:
        case Move::Heal_Bell:
            for(int i = 0; i < 6; ++i){
                if(this->team[teamindex]->member[i].get_status() != Status::Fainted){
                    this->team[teamindex]->member[i].set_status(Status::Healthy);
                }
            }
        ///
        /// weather
        ///
        case Move::Hail:
            this->weather = Weather::Hail;
            this->weather_turns = 5;
        case Move::Rain_Dance:
            this->weather = Weather::Rain;
            this->weather_turns = 5;
        case Move::Sandstorm:
            this->weather = Weather::Sand;
            this->weather_turns = 5;
        case Move::Sunny_Day:
            this->weather = Weather::Sun;
            this->weather_turns = 5;
    }
}