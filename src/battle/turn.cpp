#include "battle.hpp"

bool Battle::play_turn(){
    auto switch_faint = [&](Team &team, Team &oppteam){ 
        if(team.active()->get_current_hp() <= 0){
            team.get_move_options();
            team.decide_move();
            this->use_move(team, oppteam);
        }
    };

    // calculates which moves either side can use
    this->team[0].get_move_options();
    this->team[1].get_move_options();

    if(this->team[0].move_options.size() == 0 || this->team[1].move_options.size() == 0) {
        unsigned char lolol = 2; 
    }
    
    // decides what move will be selected for either side
    this->team[0].decide_move();
    this->team[1].decide_move();

    // false: this->team[this->move_first] moves first, true: this->team[!(this->move_first)] moves first
    this->calc_first_attacker();

    // move for the faster mon
    if(can_move(this->move_first)){
        use_move(this->team[this->move_first], this->team[!(this->move_first)]);
    }
    else{
        if(game_end(0)){ return false; }
    }

    if(check_fainted()){
        if(game_end(0)){ return false; }
        if(game_end(1)){ return false; }
        switch_faint(this->team[0], this->team[1]);
        switch_faint(this->team[1], this->team[0]);
        if(!this->end_of_turn()) { return false; }
    }
    else{
        if(can_move(!(this->move_first))){
            use_move(this->team[!(this->move_first)], this->team[this->move_first]);
            if(check_fainted()){
                if(game_end(0)){ return false; }
                if(game_end(1)){ return false; }
                switch_faint(this->team[0], this->team[1]);
                switch_faint(this->team[1], this->team[0]);
            }
        } else{ if(game_end(0)){ return false; } }
        if(!this->end_of_turn()) { return false; }
    }
    return true;
}


// checks if the pokemon is able to use a move
bool Battle::can_move(const bool teamindex){
    switch (this->team[teamindex].active()->get_status())
    {
        case Status::Freeze:
            return false;
        case Status::Sleep_inflicted:
        case Status::Sleep_self:
            if(this->team[teamindex].movechoice->get_move() != Move::Sleep_Talk){
                return false;
            }else{
                break;
            }
        case Status::Paralysis:
            if(get_random(1,100) < 26){
                return false;
            }
        default: 
            break;
    }
    if(this->team[teamindex].truant == true){
        return false;
    }
    if(this->team[teamindex].confusion > 0){
        if(get_random(1,2) == 1){
            this->team[teamindex].movechoice->set_move(Move::Hit_Self);
            this->team[teamindex].active()->reduce_hp(calculate_damage(this->team[teamindex], this->team[!teamindex]));
            return false;
        }
    }
    return true;
}

// checks turn state after a move and returns false if the second mon can move
// and true if the turn will be ended
bool Battle::check_fainted(){
    if(this->team[0].active()->get_current_hp() <= 0){
        return true;
    }
    if(this->team[1].active()->get_current_hp() <= 0){
        return true;
    }
    return false;
}
// NOT FULLY IMPLEMENTED!!!
bool Battle::end_of_turn(){

    this->move_first = this->compare_speed();

    // wish recovers 50% of the original users max HP to the pokemon that receives it
    if(this->team[this->move_first].wish == 1){
        this->team[this->move_first].active()->increase_hp(this->team[this->move_first].wish_recovery);
        this->team[this->move_first].wish = false;
    }
    if(this->team[!(this->move_first)].wish == 1){
        this->team[!(this->move_first)].active()->increase_hp(this->team[!(this->move_first)].wish_recovery);
        this->team[!(this->move_first)].wish = false;
    }
    // weather damage
    switch(this->weather){
        case Weather::Clear:
        case Weather::Rain:
        case Weather::Sun:
            break;
        case Weather::Hail:
            this->weather_damage(Weather::Hail, *this->team[this->move_first].active());
            if(game_end(this->move_first)){ return false; }
            this->weather_damage(Weather::Hail, *this->team[!(this->move_first)].active());
            if(game_end(!(this->move_first))){ return false; }
            break;
        case Weather::Sand:
            this->weather_damage(Weather::Sand, *this->team[this->move_first].active());
            if(game_end(this->move_first)){ return false; }
            this->weather_damage(Weather::Sand, *this->team[!(this->move_first)].active());
            if(game_end(!(this->move_first))){ return false; }
            break;
    }
    // weather turncounter gets decremented by 1 at the end of every turn
    weather_turns--;

    // reset weather if it runs out
    if(weather_turns == 0){
        this->weather = Weather::Clear;
    }
    ///
    ///
    /// pokemon faint
    ///
    ///
    this->move_first = this->compare_speed();
    for(int i = 0; i<2; ++i){
        // ingrain heals the currently active pokemon for 1/16th at the end of every turn
        if(this->team[this->move_first].ingrain == true){
            this->team[this->move_first].active()->increase_hp(static_cast<int>(this->team[this->move_first].active()->get_stats().hp / 16.0));
        }
        
        // rain dish
        if(this->weather == Weather::Rain){
            if(this->team[this->move_first].active()->get_ability() == Ability::Rain_Dish){
                this->team[this->move_first].active()->increase_hp(static_cast<int>(this->team[this->move_first].active()->get_stats().hp / 16.0));
            }
        }
        // speed boost
        if(this->team[this->move_first].active()->get_ability() == Ability::Speed_Boost){
            this->team[this->move_first].set_boost(Statname::Spe, 1);
        }
        // truant
        if(this->team[this->move_first].active()->get_ability() == Ability::Truant){
            this->team[this->move_first].truant = !this->team[this->move_first].truant;
        }
        // shed skin
        if(this->team[this->move_first].active()->get_ability() == Ability::Shed_Skin){
            if(get_random(0,2) > 0){
                this->team[this->move_first].active()->set_status(Status::Healthy, false);
            }
        }
        // leftovers
        if(this->team[this->move_first].active()->get_item() == Item::Leftovers){
            this->team[this->move_first].active()->increase_hp(static_cast<int>(this->team[this->move_first].active()->get_stats().hp / 16.0));
        }
        // berry and herbs
        this->team[this->move_first].use_hp_berry();
        this->team[this->move_first].use_pinch_berry();
        // leech seed, opponent regenerates the amount of hp the affected pokemon loses
        if(this->team[this->move_first].leechseed == true){
            int dmg = static_cast<int>(this->team[this->move_first].active()->get_stats().hp / 8.0);
            this->team[this->move_first].active()->reduce_hp(dmg);
            if(game_end(this->move_first)){ return false; }
            this->team[!(this->move_first)].active()->increase_hp(dmg);
        }
        // poison, fixed damage of 1/8th
        if(this->team[this->move_first].active()->get_status() == Status::Poison){
            this->team[this->move_first].active()->reduce_hp(static_cast<int>(this->team[this->move_first].active()->get_stats().hp / 8.0));
            if(game_end(this->move_first)){ return false; }
        }
        // toxic, pokemon takes an escalating amount of damage, 
        // increases by 1/16th every consecutive turn on the field
        if(this->team[this->move_first].active()->get_status() == Status::Toxic_poison){
            this->team[this->move_first].active()->reduce_hp(static_cast<int>(this->team[this->move_first].turns_on_the_field * (this->team[this->move_first].active()->get_stats().hp / 8.0)));
            if(game_end(this->move_first)){ return false; }
        }
        // burn
        if(this->team[this->move_first].active()->get_status() == Status::Burn){
            this->team[this->move_first].active()->reduce_hp(static_cast<int>(this->team[this->move_first].active()->get_stats().hp / 8.0));
            if(game_end(this->move_first)){ return false; }
        }
        // nightmare
        // curse
        if(this->team[this->move_first].curse == true){
            this->team[this->move_first].active()->reduce_hp(static_cast<int>(this->team[this->move_first].active()->get_stats().hp / 4.0));
            if(game_end(this->move_first)){ return false; }
        }
        // multi turn attacks ??????
        // uproar
        if(this->team[this->move_first].uproar > 0){
            if(this->team[this->move_first].active()->get_status() == Status::Sleep_inflicted || this->team[this->move_first].active()->get_status() == Status::Sleep_self){
                this->team[this->move_first].active()->set_status(Status::Healthy, false);
            }
            if(this->team[!(this->move_first)].active()->get_status() == Status::Sleep_inflicted || this->team[!(this->move_first)].active()->get_status() == Status::Sleep_self){
                this->team[!(this->move_first)].active()->set_status(Status::Healthy, false);
            }
        }
        // outrage/petaldance/thrash, user gets confused and end of the move counter (2-3 turns)
        if(this->team[this->move_first].selflock > 0){
            --this->team[this->move_first].selflock;
            if(this->team[this->move_first].selflock == 0){
                this->team[this->move_first].set_confusion();
            }
        }
        // decrement disable

        // encore
        --this->team[this->move_first].encore;
        // taunt / lock-on / mindreader
        -- this->team[this->move_first].taunt;
        -- this->team[this->move_first].lockon;
        // yawn
        if(this->team[this->move_first].yawn == 1){
            if(this->team[this->move_first].active()->get_status() == Status::Healthy){
                this->team[this->move_first].active()->set_status(Status::Sleep_inflicted, false);
            }
        }
        this->team[this->move_first].flinch = false;
        // future sight / doom desire
        // perish song
        // 
        // game decided after both fsight/DD AND perishsong
        // not inbetween
        this->move_first = !this->move_first;
    }
    return true;
}

void Battle::switch_in_checks(){

}

void Battle::weather_damage(const Weather weather, Pokemon &pokemon){

    if(weather == Weather::Sand){
        switch(pokemon.get_type()[0]){
            case Type::Ground:
            case Type::Rock:
            case Type::Steel:
                return;
            default:
                break;
        }
        switch(pokemon.get_type()[1]){
            case Type::Ground:
            case Type::Rock:
            case Type::Steel:
                return;
            default:
                pokemon.reduce_hp(static_cast<int>(pokemon.get_stats().hp / 16.0));
        }
    }

    if(weather == Weather::Hail){
        switch(pokemon.get_type()[0]){
            case Type::Ice:
                return;
            default:
                break;
        }
        switch(pokemon.get_type()[1]){
            case Type::Ice:
                return;
            default:
                pokemon.reduce_hp(static_cast<int>(pokemon.get_stats().hp / 16.0));
        }
    }
}