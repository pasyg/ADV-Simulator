#include "test.hpp"

Test::Test(){}

Test::~Test(){}

void Test::test_all(){
    Timer timer;
    check("import", std::bind(&Test::test_import, this));
    check("team init", std::bind(&Test::test_team_init, this));
    check("move options", std::bind(&Test::test_move_options, this));
    check("switch", std::bind(&Test::test_switch, this));
    check("substitute", std::bind(&Test::test_substitute, this));
    check("damage calculation", std::bind(&Test::test_calc, this));
    check("use move", std::bind(&Test::test_use_move, this));
}


Pokemon* Test::member(int team, int slot){
    return &this->teams[team].member[slot];
}

void Test::reset(){

    for(auto&& team : this->teams){
        team.init();
    }
}

bool Test::test_import(){

    std::cout << "== Import test ==\n";

    this->import_test = false;

    this->teams = import_team("sample");

    if(member(0, 0)->get_species() != Species::Swampert){
        return false;
    }
    if(member(12, 0)->get_species() != Species::Salamence){
        return false;
    }
    if(member(27, 0)->get_species() != Species::Celebi){
        return false;
    }
    if(member(0, 0)->get_item() != Item::Salacberry){
        return false;
    }
    if(member(12, 0)->get_item() != Item::Leftovers){
        return false;
    }
    if(member(27, 0)->get_item() != Item::Leftovers){
        return false;
    }
    if(member(0, 0)->get_ability() != Ability::Torrent){
        return false;
    }
    if(member(12, 0)->get_ability() != Ability::Intimidate){
        return false;
    }
    if(member(27, 0)->get_ability() != Ability::Natural_Cure){
        return false;
    }
    if(member(0, 0)->get_moveset()->at(0).get_move() != Move::Hydro_Pump){
        return false;
    }
    if(member(12, 0)->get_moveset()->at(3).get_move() != Move::Brick_Break){
        return false;
    }
    if(member(27, 0)->get_moveset()->at(2).get_move() != Move::Recover){
        return false;
    }
    this->import_test = true;
    return true;
}

bool Test::init_test_species(){

    std::cout << "species test ..." << "\n";
    if(member(0, 0)->get_species() != Species::Swampert){
        return false;
    }
    if(member(0, 4)->get_species() != Species::Aerodactyl){
        return false;
    }
    if(member(0, 5)->get_species() != Species::None){
        return false;
    }
    if(member(5, 0)->get_species() != Species::Salamence){
        return false;
    }
    if(member(5, 2)->get_species() != Species::Claydol){
        return false;
    }
    if(member(5, 5)->get_species() != Species::Blissey){
        return false;
    }
    if(member(27, 0)->get_species() != Species::Celebi){
        return false;
    }
    if(member(27, 3)->get_species() != Species::Claydol){
        return false;
    }
    if(member(27, 5)->get_species() != Species::Milotic){
        return false;
    }
    return true;
}

bool Test::init_test_stats(){

    std::cout << "stat test ..." << "\n";
    if( member(0, 0)->get_stats().hp   != 341 ||
        member(0, 0)->get_stats().atk  != 202 ||
        member(0, 0)->get_stats().def  != 217 ||
        member(0, 0)->get_stats().satk != 269 ||
        member(0, 0)->get_stats().sdef != 216 ||
        member(0, 0)->get_stats().spe  != 240 ){
            return false;
    }
    if( member(0, 4)->get_stats().hp   != 301 ||
        member(0, 4)->get_stats().atk  != 308 ||
        member(0, 4)->get_stats().def  != 165 ||
        member(0, 4)->get_stats().satk != 140 ||
        member(0, 4)->get_stats().sdef != 186 ||
        member(0, 4)->get_stats().spe  != 394 ){
            return false;
        }
    if( member(16, 0)->get_stats().hp   != 301 ||
        member(16, 0)->get_stats().atk  != 153 ||
        member(16, 0)->get_stats().def  != 219 ||
        member(16, 0)->get_stats().satk != 298 ||
        member(16, 0)->get_stats().sdef != 250 ||
        member(16, 0)->get_stats().spe  != 250 ){
            return false;
        }
    if( member(16, 4)->get_stats().hp   != 356 ||
        member(16, 4)->get_stats().atk  != 405 ||
        member(16, 4)->get_stats().def  != 296 ||
        member(16, 4)->get_stats().satk != 203 ||
        member(16, 4)->get_stats().sdef != 216 ||
        member(16, 4)->get_stats().spe  != 185 ){
            return false;
        }
    if( member(27, 4)->get_stats().hp   != 404 ||
        member(27, 4)->get_stats().atk  != 184 ||
        member(27, 4)->get_stats().def  != 312 ||
        member(27, 4)->get_stats().satk != 236 ||
        member(27, 4)->get_stats().sdef != 236 ||
        member(27, 4)->get_stats().spe  != 252 ){
            return false;
        }
    if( member(27, 5)->get_stats().hp   != 391 ||
        member(27, 5)->get_stats().atk  != 112 ||
        member(27, 5)->get_stats().def  != 276 ||
        member(27, 5)->get_stats().satk != 236 ||
        member(27, 5)->get_stats().sdef != 286 ||
        member(27, 5)->get_stats().spe  != 208 ){
            return false;
        }
    return true;
}

bool Test::init_test_moves(){

    std::cout << "move test ..." << "\n";
    if(member(0, 0)->get_moveset()->at(0).base_pp != 8  ||
       member(0, 0)->get_moveset()->at(0).get_pp() != 8 ||
       member(0, 0)->get_moveset()->at(0).get_move() != Move::Hydro_Pump){
           return false;
       }
    if(member(0, 2)->get_moveset()->at(3).base_pp != 8  ||
       member(0, 2)->get_moveset()->at(3).get_pp() != 8 ||
       member(0, 2)->get_moveset()->at(3).get_move() != Move::Explosion){

           return false;
       }
    if(member(12, 2)->get_moveset()->at(1).base_pp != 32  ||
       member(12, 2)->get_moveset()->at(1).get_pp() != 32 ||
       member(12, 2)->get_moveset()->at(1).get_move() != Move::Dragon_Dance){
           return false;
       }
    if(member(12, 4)->get_moveset()->at(2).base_pp != 24  ||
       member(12, 4)->get_moveset()->at(2).get_pp() != 24 ||
       member(12, 4)->get_moveset()->at(2).get_move() != Move::Crunch){
           return false;
       }
    if(member(27, 0)->get_moveset()->at(0).base_pp != 16  ||
       member(27, 0)->get_moveset()->at(0).get_pp() != 16 ||
       member(27, 0)->get_moveset()->at(0).get_move() != Move::Substitute){
           return false;
       }
    if(member(27, 5)->get_moveset()->at(0).base_pp != 16  ||
       member(27, 5)->get_moveset()->at(0).get_pp() != 16 ||
       member(27, 5)->get_moveset()->at(0).get_move() != Move::Ice_Beam){
           return false;
       }
    if(member(27, 0)->get_moveset()->at(3).base_pp != 64  ||
       member(27, 0)->get_moveset()->at(3).get_pp() != 64 ||
       member(27, 0)->get_moveset()->at(3).get_move() != Move::Baton_Pass){
           return false;
       }
    if(member(27, 5)->get_moveset()->at(3).base_pp != 32  ||
       member(27, 5)->get_moveset()->at(3).get_pp() != 32 ||
       member(27, 5)->get_moveset()->at(3).get_move() != Move::Recover){
           return false;
       }
    return true;
}

bool Test::init_test_hidden_power(){

    std::cout << "hidden power test ..." << "\n";
    if(member(1, 0)->hiddenpower != Type::Bug ||
       member(1, 0)->hiddenpower_power != 70){
           std::cout << to_string(member(1, 0)->hiddenpower) << "\n";
           std::cout << member(1, 0)->hiddenpower_power << "\n";
           return false;
       }
    if(member(1, 2)->hiddenpower != Type::Grass ||
       member(1, 2)->hiddenpower_power != 70){
           return false;
       }
    if(member(2, 1)->hiddenpower != Type::Fighting ||
       member(2, 1)->hiddenpower_power != 70){
           return false;
       }
    if(member(3, 1)->hiddenpower != Type::Grass ||
       member(3, 1)->hiddenpower_power != 70){
           return false;
       }
    if(member(3, 5)->hiddenpower != Type::Bug ||
       member(3, 5)->hiddenpower_power != 70){
           return false;
       }
    if(member(20, 3)->hiddenpower != Type::Fire ||
       member(20, 3)->hiddenpower_power != 70){
           return false;
       }
    if(member(24, 0)->hiddenpower != Type::Grass ||
       member(24, 0)->hiddenpower_power != 70){
           return false;
       }
    if(member(24, 1)->hiddenpower != Type::Grass ||
       member(24, 1)->hiddenpower_power != 70){
           return false;
       }
    if(member(24, 2)->hiddenpower != Type::Bug ||
       member(24, 2)->hiddenpower_power != 70){
           return false;
       }
    return true;
}

bool Test::test_team_init(){

    std::cout << "== team initilization test ==\n";

    if(this->import_test == true){
        for(auto&& team : this->teams){
            team.init();
        }
        if(!this->init_test_species()) return false;
        if(!this->init_test_stats()) return false;
        if(!this->init_test_moves()) return false;
        if(!this->init_test_hidden_power()) return false;
        return true;
    }
    else{
        std::cout << "(ERROR import)" << "\n";
        return false;
    }
}

bool Test::test_move_options(){

    std::cout << "== move options test ==\n";

    member(0, 0)->moveset[0].reduce_pp(std::numeric_limits<int>::max());
    member(0, 0)->moveset[1].reduce_pp(std::numeric_limits<int>::max());
    this->teams[0].get_move_options(this->teams[1].imprison_moves);
    for(auto&& option : this->teams[0].move_options){
        if(option->get_move() == Move::Hydro_Pump || option->get_move() == Move::Ice_Beam){
            return false;
        }
    }

    member(1, 2)->reduce_hp_direct(std::numeric_limits<int>::max());
    member(1, 4)->reduce_hp_direct(std::numeric_limits<int>::max());
    this->teams[1].get_move_options(this->teams[1].imprison_moves);
    for(auto&& option : this->teams[1].move_options){
        if(option->get_move() == Move::Switch2 ||
           option->get_move() == Move::Switch4){
               return false;
    }
  }
    for(auto&& pokemon : this->teams[1].member){
        if(pokemon.get_species() != Species::Breloom){
            pokemon.reduce_hp_direct(std::numeric_limits<int>::max());
        }
    }
    for(auto&& move : member(1, 0)->moveset){
        move.reduce_pp(std::numeric_limits<int>::max());
    }
    this->teams[1].get_move_options(this->teams[1].imprison_moves);
    if(this->teams[1].move_options[0]->get_move() != Move::Struggle){
        return false;
    }
  return true;
}

bool Test::test_switch(){

    std::cout << "== switch test ==\n";

    if(this->team_init_test){
        if(this->teams[0].active()->get_species() != Species::Swampert){
            return false;
        }
        if(this->teams[5].active()->get_species() != Species::Salamence){
            return false;
        }
        if(this->teams[18].active()->get_species() != Species::Tyranitar){
            return false;
        }
        if(this->teams[27].active()->get_species() != Species::Celebi){
            return false;
        }

        this->teams[0].active_pokemon = 2;
        this->teams[5].active_pokemon = 4;
        this->teams[18].active_pokemon = 5;
        this->teams[27].active_pokemon = 0;

        if(this->teams[0].active()->get_species() != Species::Metagross){
            return false;
        }
        if(this->teams[5].active()->get_species() != Species::Jirachi){
            return false;
        }
        if(this->teams[18].active()->get_species() != Species::Skarmory){
            return false;
        }
        if(this->teams[27].active()->get_species() != Species::Celebi){
            return false;
        }
    }
    return true;
}

bool Test::test_substitute(){
    member(0, 0)->create_substitute();
    if(member(0, 0)->substitute_hp != 85){
        return false;
    }
    member(0, 0)->reduce_hp_attack(std::numeric_limits<int>::max());
    if(member(0, 0)->get_status() == Status::Fainted ||
       member(0, 0)->current_hp != 341){
           return false;
       }
       return true;
}

bool Test::test_calc(){
    std::cout << "== Damage Calculator Test ==\n";
    std::cout << "test crits...\n";
    if(!this->test_crit()){
        return false;
    }
    std::cout << "test ability...\n";
    if(!this->test_ability()){
        return false;
    }
    std::cout << "test item...\n";
    if(!this->test_item()){
        return false;
    }
    std::cout << "test weather...\n";
    if(!this->test_weather()){
        return false;
    }
    Battle battle1(this->teams[0], this->teams[1]);
    // swampert hydro pump vs breloom
    this->teams[0].movechoice = &member(0, 0)->moveset[0];
    this->teams[0].active_pokemon = 0;
    this->teams[1].active_pokemon = 0;
    int damage = battle1.calculate_damage(this->teams[0], this->teams[1]);

    auto func = [&](int roll) -> bool{ return roll == damage; };
    
    std::vector<int> rolls = { 112, 113, 114, 116, 117, 118, 120, 121, 122, 124, 125, 126, 128, 129, 130, 132,
                               224, 227, 229, 232, 234, 237, 240, 242, 245, 248, 250, 253, 256, 258, 261, 264 };
    if(!multi_or(rolls, func)){
        return false;
    }

    // swampert ice beam vs breloom
    this->teams[0].movechoice = &member(0, 0)->moveset[1];
    damage = battle1.calculate_damage(this->teams[0], this->teams[1]);
    rolls = { 238, 240, 243, 246, 249, 252 ,254, 257, 260, 263, 266, 268, 271, 274, 277, 280,
              476, 481, 487, 492, 498, 504, 509, 515, 520, 526, 532, 537, 543, 548, 554, 560 };

    if(!multi_or(rolls, func)){
        return false;
    }

    return true;
}

bool Test::test_crit(){
    Battle battle(this->teams[21], this->teams[26]); 
    
    return true;
}

bool Test::test_ability(){
    Battle battle(this->teams[26], this->teams[21]);
    
    battle.team[0].active_pokemon = 4;
    battle.team[1].active_pokemon = 3;
    
    battle.team[0].movechoice = &battle.team[0].member[4].moveset[1];
    if(battle.ability_multiplier(battle.team[0], battle.team[1]) != 0.0f){
        std::cout << "ability multiplier error \n";
        return false;
    }
    return true;
}

bool Test::test_item(){
    Battle battle(this->teams[0], this->teams[21]);

    battle.team[0].active_pokemon = 4;
    battle.team[0].movechoice = &battle.team[0].member[4].moveset[1];

    if(battle.item_multiplier(battle.team[0]) != 1.5f){
        std::cout << "item multiplier error \n";
        return false;
    }
    return true;
}

bool Test::test_weather(){
    Battle battle(this->teams[1], this->teams[4]);

    battle.team[0].active_pokemon = 2;
    battle.team[1].active_pokemon = 1;

    battle.team[0].movechoice = &battle.team[0].member[2].moveset[0];
    battle.team[1].movechoice = &battle.team[1].member[1].moveset[0];

    battle.weather = Weather::Sun;

    if(!(this->weather_compare(battle.team[1], 0.5f, battle.weather)) ||
       !(this->weather_compare(battle.team[0], 2.0f, battle.weather))){
           return false;
       }

    battle.weather = Weather::Rain;

    if(!(this->weather_compare(battle.team[0], 0.5f, battle.weather)) ||
       !(this->weather_compare(battle.team[1], 2.0f, battle.weather))){
           return false;
       }

    return true;
}
/// Fehler in weather_multiplier (this) -> change to weather is parameter
bool Test::weather_compare(const Team &_team, const float &value, Weather weather){
    const float result = battle.weather_multiplier(_team, weather);
    if(result != value){
        std::cout << "weather multiplier error \n";
        return false;
    }
    return true;
}

bool Test::test_use_move(){
    std::cout << "== use move test ==\n";
    // attacking moves, no side effect   
    std::cout << "damage moves check...\n";
    reset();
    if(!test_attacking_moves()){
        return false;
    }
    // attacking moves, side effect
    std::cout << "side effects check...\n";
    reset();
    if(!test_sideeffects_moves()){
        return false;
    }
    // accuracy check
    std::cout << "accuracy check...\n";
    reset();
    if(!test_accuracy_moves()){
        return false;
    }
    // healing moves
    std::cout << "healing check...\n";
    reset();
    if(!test_healing_moves()){
        return false;
    }
    // status moves
    std::cout << "status check...\n";
    reset();
    if(!test_status_moves()){
        return false;
    }
    // random
    std::cout << "misc. check...\n";
    reset();
    if(!test_misc_moves()){
        return false;
    }
    return true;
}

bool Test::test_attacking_moves(){
    Battle battle(this->teams[0], this->teams[1]);

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

bool Test::test_sideeffects_moves(){
    Battle battle(this->teams[0], this->teams[1]);

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

bool Test::test_healing_moves(){
    return true;
}

bool Test::test_status_moves(){
    Battle battle(this->teams[1], this->teams[2]); 

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