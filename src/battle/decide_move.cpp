#include "battle.hpp"


// place to implement decision making
void Battle::decide_move(Team &team)
{
    static int choice = 0;
    if(team.move_options.size() == 0)
    {
        std::string in;
        std::cout << team;
        std::cin >> in;
    }
    
    team.prev_movechoice = team.movechoice;
    team.movechoice = team.move_options[this->transition.random(team.move_options.size())];
    //team.movechoice = team.move_options[++choice % team.move_options.size()];
}