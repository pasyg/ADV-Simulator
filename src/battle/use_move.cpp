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
            if(this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Ghost &&
               this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Ghost){
                this->team[!teamindex]->member[this->team[!teamindex]->active_pokemon].reduce_hp(
                    this->team[!teamindex]->member[this->team[!teamindex]->active_pokemon].get_current_hp() / 2);
            }
            return;
        case Move::Seismic_Toss:
            if(this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Ghost &&
               this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Ghost){
                this->team[!teamindex]->member[this->team[!teamindex]->active_pokemon].reduce_hp(100);
            }
            return;
        case Move::Night_Shade:
            if(this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Normal &&
               this->team[!teamindex]->mon_in_battle->get_type()[0] != Type::Normal){
                this->team[!teamindex]->member[this->team[!teamindex]->active_pokemon].reduce_hp(100);
            }	
            return;
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
            return;
        ///
        /// secondary effect damage moves
        ///
        case Move::Absorb:
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
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Air_Cutter:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Ancient_Power:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Arm_Thrust:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Astonish:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Aurora_Beam:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Bite:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Blast_Burn:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Blaze_Kick:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Blizzard:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Body_Slam:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Bone_Club:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Bubble:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Bubble_Beam:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Confusion:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Constrict:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Crunch:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Crush_Claw:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Dizzy_Punch:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Double_Edge:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Dragon_Breath:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Dream_Eater:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Dynamic_Punch:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Ember:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Explosion:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Extrasensory:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Facade:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::False_Swipe:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Feint_Attack:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Fire_Blast:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Fire_Punch:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Flamethrower:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Frenzy_Plant:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Giga_Drain:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Headbutt:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Heat_Wave:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::High_Jump_Kick:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Hydro_Cannon:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Hyper_Beam:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Ice_Beam:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Ice_Punch:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Icy_Wind:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Iron_Tail:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Knock_Off:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Leaf_Blade:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Leech_Life:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Lick:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Magical_Leaf:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Magnitude:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Mega_Drain:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Metal_Claw:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Meteor_Mash:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Nature_Power:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Needle_Arm:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Octazooka:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Overheat:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Poison_Fang:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Poison_Tail:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Powder_Snow:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Psychic:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Pursuit:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Rapid_Spin:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Razor_Leaf:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Rock_Slide:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Rock_Smash:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Rock_Tomb:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Sacred_Fire:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Secret_Power:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Self_Destruct:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Shadow_Ball:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Shadow_Punch:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Signal_Beam:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Silver_Wind:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Sludge:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Sludge_Bomb:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Smog:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Spark:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Steel_Wing:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Struggle:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Submission:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Superpower:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Take_Down:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Thief:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Thunder:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Thunder_Punch:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Thunder_Shock:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Thunderbolt:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Tri_Attack:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Twister:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Volt_Tackle:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Water_Pulse:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
        case Move::Zap_Cannon:
            this->team[!teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return;
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
            this->team[!teamindex]->set_boost(Statname::Sdef, -2);
            return;
        case Move::Metal_Sound:
            this->team[!teamindex]->set_boost(Statname::Sdef, -2);
            return;

        case Move::Cotton_Spore:
            this->team[!teamindex]->set_boost(Statname::Spe, -2);
            return;
        case Move::Scary_Face:
            this->team[!teamindex]->set_boost(Statname::Spe, -2);
            return;
        case Move::String_Shot:
            this->team[!teamindex]->set_boost(Statname::Spe, -1);
            return;

        case Move::Flash:
            this->team[!teamindex]->set_boost(Statname::Acc, -1);
            return;
        case Move::Kinesis:
            this->team[!teamindex]->set_boost(Statname::Acc, -1);
            return;
        case Move::Sand_Attack:
            this->team[!teamindex]->set_boost(Statname::Acc, -1);
            return;
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
        case Move::Hypnosis:
            if(this->team[!teamindex]->mon_in_battle->get_status() != Status::Healthy){
                this->team[!teamindex]->mon_in_battle->set_status(Status::Sleep_inflicted);
            }
            return;
        case Move::Lovely_Kiss:
            if(this->team[!teamindex]->mon_in_battle->get_status() != Status::Healthy){
                this->team[!teamindex]->mon_in_battle->set_status(Status::Sleep_inflicted);
            }
            return;
        case Move::Poison_Powder:
            if(this->team[!teamindex]->mon_in_battle->get_status() != Status::Healthy){
                this->team[!teamindex]->mon_in_battle->set_status(Status::Poison);
            }
            return;
        case Move::Sing:
            if(this->team[!teamindex]->mon_in_battle->get_status() != Status::Healthy){
                this->team[!teamindex]->mon_in_battle->set_status(Status::Sleep_inflicted);
            }
            return;
        case Move::Sleep_Powder:
            if(this->team[!teamindex]->mon_in_battle->get_status() != Status::Healthy){
                this->team[!teamindex]->mon_in_battle->set_status(Status::Sleep_inflicted);
            }
            return;
        case Move::Spore:
            if(this->team[!teamindex]->mon_in_battle->get_status() != Status::Healthy){
                this->team[!teamindex]->mon_in_battle->set_status(Status::Sleep_inflicted);
            }
            return;
        case Move::Stun_Spore:
            if(this->team[!teamindex]->mon_in_battle->get_status() != Status::Healthy){
                this->team[!teamindex]->mon_in_battle->set_status(Status::Paralysis);
            }
            return;
        case Move::Thunder_Wave:
            if(this->team[!teamindex]->mon_in_battle->get_status() != Status::Healthy){
                this->team[!teamindex]->mon_in_battle->set_status(Status::Paralysis);
            }
            return;
        case Move::Toxic:
            if(this->team[!teamindex]->mon_in_battle->get_status() != Status::Healthy){
                this->team[!teamindex]->mon_in_battle->set_status(Status::Toxic_poison);
            }
            return;
        case Move::Will_O_Wisp:
            if(this->team[!teamindex]->mon_in_battle->get_status() != Status::Healthy){
                this->team[!teamindex]->mon_in_battle->set_status(Status::Burn);
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
    }
}