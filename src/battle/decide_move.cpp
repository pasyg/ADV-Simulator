#include "battle.hpp"


// place to implement decision making
void Battle::decide_move(Team &team){
    team.prev_movechoice = team.movechoice;
    team.movechoice = team.move_options[get_random(0, static_cast<int>(team.move_options.size()) - 1)];
}