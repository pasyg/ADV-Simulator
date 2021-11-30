#include "tests.hpp"
#include "benchmark.hpp"

void battle_test(Team &team1, Team &team2){
    
    {
        Timer timer;
        for(int i = 0; i< 100000; ++i){ 
            
            Battle battle(team1, team2);
            
            for(int j = 0; j < 100; ++j){
                battle.team[0]->get_move_options();
                battle.team[0]->decide_move();
                battle.calculate_damage(0);
                battle.end_of_turn();
            }
        }
    }
}