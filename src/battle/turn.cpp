#include "battle.hpp"

void Battle::play_turn(){
    // calculates which moves either side can use
    this->team[0].get_move_options();
    this->team[1].get_move_options();
    
    // decides what move will be selected for either side
    this->team[0].decide_move();
    this->team[1].decide_move();

    // false, team1 moves first, true, team2 moves first
    this->calc_first_attacker();

    // move for the faster mon
    use_move(move_first);
    
    if(check_fainted()){
    // slower mon moves if the turn hasnt been stopped yet
    use_move(!move_first);
    }
}

// checks turn state after a move and returns true if the second mon can move
// and false if the turn will be ended
bool Battle::check_fainted(){
    if(this->team[0].member[this->team[0].active_pokemon].get_current_hp() <= 0){
        return false;
    }
    if(this->team[1].member[this->team[1].active_pokemon].get_current_hp() <= 0){
        return false;
    }
    return true;
}

void Battle::end_of_turn(){
    Pokemon *pokemon1 = &this->team[this->move_first].member[this->team[this->move_first].active_pokemon];
    Pokemon *pokemon2 = &this->team[!(this->move_first)].member[this->team[!(this->move_first)].active_pokemon];

    // wish
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
    // pokemon faint
    // ingrain
    // rain dish
    // speed boost
    // truant
    // shed skin
    // leftovers
    // berry and herbs
    // leech seed
    // poison
    // toxic
    // burn
    // nightmare
    // curse
    // multi turn attacks
    // uproar
    // outrage/petaldance/thrash
    // decrement disable
    // encore
    // taunt / lock-on / mindreader
    // yawn
    // future sight / doom desire
    // perish song
    // 
    // game decided after both fsight/DD AND perishsong
    // not inbetween
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