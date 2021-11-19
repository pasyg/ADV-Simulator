#include "battle.hpp"

void Battle::use_move(const int teamindex){
    switch(this->team[teamindex]->movechoice->get_move()){
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
        default:
            break;
    }
}