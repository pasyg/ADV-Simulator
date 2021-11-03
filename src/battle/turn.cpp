#include "battle.hpp"

void Battle::play_turn(){
    // calculates which moves either side can use
    this->team[0].get_move_options();
    this->team[1].get_move_options();
    
    // decides what move will be selected for either side
    this->team[0].decide_move();
    this->team[1].decide_move();    

    // false, team1 moves first, true, team2 moves first
    bool move_first = this->move_first();

    
}