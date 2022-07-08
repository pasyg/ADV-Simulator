#include "battle.hpp"


// place to implement decision making
void Battle::decide_move(Team &team){
    team.prev_movechoice = team.movechoice;
    team.movechoice = team.move_options[this->transition.random(static_cast<int>(team.move_options.size()))];
}