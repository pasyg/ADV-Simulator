#include "tests.hpp"
#include "benchmark.hpp"

void battle_test(Team &team1, Team &team2){
    
    {
        Timer timer;
        Battle battle(team1, team2);
    }
    // battle.team[0] = &team1;
    // battle.team[1] = &team2;

    // battle.team[0]->active_pokemon = 2;
    // battle.team[0]->get_move_options();
    // battle.team[0]->decide_move();
    // std::cout << to_string(battle.team[0]->movechoice->get_move()) << std::endl;
    // battle.team[0]->decide_move();
    // std::cout << to_string(battle.team[0]->movechoice->get_move()) << std::endl;
    // battle.team[0]->decide_move();
    // std::cout << to_string(battle.team[0]->movechoice->get_move()) << std::endl;
    // battle.team[0]->decide_move();
    // std::cout << to_string(battle.team[0]->movechoice->get_move()) << std::endl;
    // battle.team[0]->decide_move();
    // std::cout << to_string(battle.team[0]->movechoice->get_move()) << std::endl;
    // battle.team[0]->decide_move();
    // std::cout << to_string(battle.team[0]->movechoice->get_move()) << std::endl;
    // battle.team[0]->decide_move();
    // std::cout << to_string(battle.team[0]->movechoice->get_move()) << std::endl;
}