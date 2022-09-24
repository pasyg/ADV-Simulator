#include "test.hpp"

bool est::test_moves(){
    std::cout << "== move test ==\n";
    
    std::cout << "damage moves check\n";
    if(!this->test_attacking_moves()){ return false; }
    
    std::cout << "crit check\n";
    if(!this->test_crit()){ return false; }
    
    std::cout << "accuracy check\n";
    if(!this->test_accuracy_moves()){ return false; }
    
    std::cout << "side effects check\n";
    if(!this->test_sideeffects_moves()){ return false; }
    
    std::cout << "healing moves check\n";
    if(!this->test_healing_moves()){ return false; }
    
    std::cout << "status moves check\n";
    if(!this->test_status_moves()){ return false; }
    
    std::cout << "misc moves check\n";
    if(!this->test_misc_moves()){ return false; }

    return true;
}

bool Test::test_attacking_moves(){
    Battle battle({ this->teams[0], this->teams[1] });

    // skarmory attacks breloom with drill peck
    battle.team[0].movechoice = &battle.team[0].member[1].moveset[1];
    battle.use_move(battle.team[0], battle.team[1]);
    if(battle.team[0].member[1].moveset[1].get_pp() >= battle.team[0].member[1].moveset[1].base_pp){
        return false;
    }
    if(battle.team[1].member[0].current_hp >= battle.team[1].member[0].get_stats().hp){
        return false;
    }
    return true;
}

bool Test::test_crit(){
    Battle battle({ this->teams[21], this->teams[26] }); 
    
    return true;
}

bool Test::test_accuracy_moves(){
    auto is_miss = [&](Team t1, Team t2){
        for(int i = 0; i < 300; ++i){
            battle.use_move(t1, t2);
            if(t2.active()->current_hp == t2.active()->stats.hp){
                return true;
            }
            t2.active()->set_current_hp(t2.active()->stats.hp);
        }
        return false;
    };

    this->teams[0].movechoice = &member(0, 0)->moveset[0];
    if(!is_miss(teams[0], teams[1])){
        return false;
    }
    return true;
}

bool Test::test_sideeffects_moves(){
    Battle battle({ this->teams[0], this->teams[1] });

    // swampert attacks tyranitar with ice beam
    battle.team[0].movechoice = &battle.team[0].member[0].moveset[1];
    battle.team[0].active_pokemon = 0;
    battle.team[1].active_pokemon = 1;
    battle.use_move(battle.team[0], battle.team[1]);

    auto is_status = [&](Team t1, Team t2, Status status){
        for(int i = 0; i < 300; ++i){
            battle.use_move(t1, t2);
            if(t2.active()->get_status() == status){  return true; };
            t1.movechoice->set_pp(10);
            t2.active()->set_status(Status::Healthy);
            t2.active()->increase_hp(std::numeric_limits<int>::max());
        }
        return false;
    };

    if(!is_status(battle.team[0], battle.team[1], Status::Freeze)){
        return false;
    }
    
    return true;
}

bool Test::test_healing_moves(){
    return true;
}

bool Test::test_status_moves(){
    Battle battle({ this->teams[1], this->teams[2] }); 

    battle.team[0].active_pokemon = 0;
    battle.team[1].active_pokemon = 0;

    battle.team[0].movechoice = &battle.team[0].member[0].moveset[0];
    battle.team[1].movechoice = &battle.team[1].member[0].moveset[3];

    battle.use_move(battle.team[1], battle.team[0]);
    battle.use_move(battle.team[0], battle.team[1]);

    if(battle.team[0].member[0].get_status() != Status::Paralysis)       { return false; }
    if(battle.team[1].member[0].get_status() != Status::Sleep_inflicted) { return false; }

    return true;
}

bool Test::test_misc_moves(){
    return true;
}