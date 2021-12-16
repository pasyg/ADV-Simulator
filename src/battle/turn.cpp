#include "battle.hpp"

bool Battle::play_turn(){
    // calculates which moves either side can use
    this->team[0]->get_move_options();
    this->team[1]->get_move_options();
    
    // decides what move will be selected for either side
    this->team[0]->decide_move();
    this->team[1]->decide_move();

    // false: team1 moves first, true: team2 moves first
    this->calc_first_attacker();

    // move for the faster mon
    if(can_move(move_first)){
        use_move(move_first);
    }
    if(this->team[move_first]->mon_in_battle->get_current_hp() <= 0){
        if(game_end(move_first)){
            this->winner = !move_first;
            return true;
        }

    }
    if(this->team[!move_first]->mon_in_battle->get_current_hp() <= 0){
        if(game_end(!move_first)){
            this->winner = move_first;
            return true;
        }
    }

    // slower mon moves if the turn hasnt been stopped yet
    if(check_fainted()){
        if(can_move(!move_first)){
            use_move(!move_first);
        }
    }
}

bool Battle::game_end(int teamindex){
    for(int i = 0; i < 6; ++i){
        if(this->team[teamindex]->member[i].get_current_hp() > 0){
            return false;
        }
    }
    return true;
}
// checks if the pokemon is able to use a move
bool Battle::can_move(const bool teamindex){
    switch (this->team[teamindex]->mon_in_battle->get_status())
    {
        case Status::Freeze:
            return false;
        case Status::Sleep_inflicted:
        case Status::Sleep_self:
            if(this->team[teamindex]->movechoice->get_move() != Move::Sleep_Talk){
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
    if(this->team[teamindex]->truant == true){
        return false;
    }
    if(this->team[teamindex]->confusion > 0){
        if(get_random(1,2) == 1){
            this->team[teamindex]->movechoice->set_move(Move::Hit_Self);
            this->team[teamindex]->mon_in_battle->reduce_hp(calculate_damage(teamindex));
            return false;
        }
    }
    return true;
}

// checks turn state after a move and returns true if the second mon can move
// and false if the turn will be ended
bool Battle::check_fainted(){
    if(this->team[0]->member[this->team[0]->active_pokemon].get_current_hp() <= 0){
        return false;
    }
    if(this->team[1]->member[this->team[1]->active_pokemon].get_current_hp() <= 0){
        return false;
    }
    return true;
}

void Battle::end_of_turn(){
    Team* team1 = this->team[this->move_first];
    Team* team2 = this->team[!(this->move_first)];

    Pokemon* pokemon1 = &this->team[this->move_first]->member[this->team[this->move_first]->active_pokemon];
    Pokemon* pokemon2 = &this->team[!(this->move_first)]->member[this->team[!(this->move_first)]->active_pokemon];

    this->move_first = this->compare_speed();
    // wish recovers 50% of the original users max HP to the pokemon that receives it
    if(team1->wish == 1){
        pokemon1->increase_hp(team1->wish_recovery);
        team1->wish = false;
    }
    if(team2->wish == 1){
        pokemon2->increase_hp(team2->wish_recovery);
        team2->wish = false;
    }
    // weather damage
    switch(this->weather){
        case Weather::Clear:
        case Weather::Rain:
        case Weather::Sun:
            break;
        case Weather::Hail:
            this->weather_damage(Weather::Hail, *pokemon1);
            this->weather_damage(Weather::Hail, *pokemon2);
            break;
        case Weather::Sand:
            this->weather_damage(Weather::Sand, *pokemon1);
            this->weather_damage(Weather::Sand, *pokemon2);
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
        if(team1->ingrain == true){
            pokemon1->increase_hp(static_cast<int>(pokemon1->get_stats().hp / 16.0));
        }
        
        // rain dish
        if(this->weather == Weather::Rain){
            if(pokemon1->get_ability() == Ability::Rain_Dish){
                pokemon1->increase_hp(static_cast<int>(pokemon1->get_stats().hp / 16.0));
            }
        }
        // speed boost
        if(pokemon1->get_ability() == Ability::Speed_Boost){
            team1->set_boost(Statname::Spe, 1);
        }
        // truant
        if(pokemon1->get_ability() == Ability::Truant){
            team1->truant = !team1->truant;
        }
        // shed skin
        if(pokemon1->get_ability() == Ability::Shed_Skin){
            if(get_random(0,2) > 0){
                pokemon1->set_status(Status::Healthy, false);
            }
        }
        // leftovers
        if(pokemon1->get_item() == Item::Leftovers){
            pokemon1->increase_hp(static_cast<int>(pokemon1->get_stats().hp / 16.0));
        }
        // berry and herbs
        team1->use_hp_berry();
        team1->use_pinch_berry();
        // leech seed, opponent regenerates the amount of hp the affected pokemon loses
        if(team1->leechseed == true){
            pokemon1->reduce_hp(static_cast<int>(pokemon1->get_stats().hp / 8.0));
            pokemon2->increase_hp(static_cast<int>(pokemon1->get_stats().hp / 8.0));
        }
        // poison, fixed damage of 1/8th
        if(pokemon1->get_status() == Status::Poison){
            pokemon1->reduce_hp(static_cast<int>(pokemon1->get_stats().hp / 8.0));
        }
        // toxic, pokemon takes an escalating amount of damage, 
        // increases by 1/16th every consecutive turn on the field
        if(pokemon1->get_status() == Status::Toxic_poison){
            pokemon1->reduce_hp(static_cast<int>(team1->turns_on_the_field * (pokemon1->get_stats().hp / 8.0)));
        }
        // burn
        if(pokemon1->get_status() == Status::Burn){
            pokemon1->reduce_hp(static_cast<int>(pokemon1->get_stats().hp / 8.0));
        }
        // nightmare
        // curse
        if(team1->curse == true){
            pokemon1->reduce_hp(static_cast<int>(pokemon1->get_stats().hp / 4.0));
        }
        // multi turn attacks ??????
        // uproar
        if(team1->uproar > 0){
            if(pokemon1->get_status() == Status::Sleep_inflicted || pokemon1->get_status() == Status::Sleep_self){
                pokemon1->set_status(Status::Healthy, false);
            }
            if(pokemon2->get_status() == Status::Sleep_inflicted || pokemon2->get_status() == Status::Sleep_self){
                pokemon2->set_status(Status::Healthy, false);
            }
        }
        // outrage/petaldance/thrash, user gets confused and end of the move counter (2-3 turns)
        if(team1->selflock > 0){
            --team1->selflock;
            if(team1->selflock == 0){
                team1->set_confusion();
            }
        }
        // decrement disable

        // encore
        --team1->encore;
        // taunt / lock-on / mindreader
        -- team1->taunt;
        -- team1->lockon;
        // yawn
        if(team1->yawn == 1){
            if(pokemon1->get_status() == Status::Healthy){
                pokemon1->set_status(Status::Sleep_inflicted, false);
            }
        }
        team1->flinch = false;
        // future sight / doom desire
        // perish song
        // 
        // game decided after both fsight/DD AND perishsong
        // not inbetween
        this->move_first = !this->move_first;
    }
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