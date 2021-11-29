#include "tests.hpp"
#include "benchmark.hpp"

void battle_test(Team &team1, Team &team2){
    
    {
        Timer timer;
        Battle battle(team1, team2);

        battle.team[0]->movechoice = &battle.team[0]->member[battle.team[0]->active_pokemon].get_moveset()[0];

        for(int i = 0; i < 7000000; ++i){
            battle.calculate_damage(0);
        }
    }
}