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
}

void Test::check(std::string funcname, std::function<bool()> func){
    if(func()){
        std::cout << funcname << " test successful\n\n";
    }
    else{
        std::cout << funcname << " test NOT successful\n\n";
    }
}

bool Test::test_import(){

    std::cout << "== Import test ==\n";

    this->import_test = false;

    this->teams = import_team("sample");

    if(this->teams[0].member[0].get_species() != Species::Swampert){
        return false;
    }
    if(this->teams[12].member[0].get_species() != Species::Salamence){
        return false;
    }
    if(this->teams[27].member[0].get_species() != Species::Celebi){
        return false;
    }
    if(this->teams[0].member[0].get_item() != Item::Salacberry){
        return false;
    }
    if(this->teams[12].member[0].get_item() != Item::Leftovers){
        return false;
    }
    if(this->teams[27].member[0].get_item() != Item::Leftovers){
        return false;
    }
    if(this->teams[0].member[0].get_ability() != Ability::Torrent){
        return false;
    }
    if(this->teams[12].member[0].get_ability() != Ability::Intimidate){
        return false;
    }
    if(this->teams[27].member[0].get_ability() != Ability::Natural_Cure){
        return false;
    }
    if(this->teams[0].member[0].get_moveset()[0] != Move::Hydro_Pump){
        return false;
    }
    if(this->teams[12].member[0].get_moveset()[3] != Move::Brick_Break){
        return false;
    }
    if(this->teams[27].member[0].get_moveset()[2] != Move::Recover){
        return false;
    }
    this->import_test = true;
    return true;
}

bool Test::init_test_species(){

    std::cout << "species test ..." << "\n";
    if(this->teams[0].member[0].get_species() != Species::Swampert){
        return false;
    }
    if(this->teams[0].member[4].get_species() != Species::Aerodactyl){
        return false;
    }
    if(this->teams[0].member[5].get_species() != Species::no_pokemon){
        return false;
    }
    if(this->teams[5].member[0].get_species() != Species::Salamence){
        return false;
    }
    if(this->teams[5].member[2].get_species() != Species::Claydol){
        return false;
    }
    if(this->teams[5].member[5].get_species() != Species::Blissey){
        return false;
    }
    if(this->teams[27].member[0].get_species() != Species::Celebi){
        return false;
    }
    if(this->teams[27].member[3].get_species() != Species::Claydol){
        return false;
    }
    if(this->teams[27].member[5].get_species() != Species::Milotic){
        return false;
    }
    return true;
}

bool Test::init_test_stats(){

    std::cout << "stat test ..." << "\n";
    if( this->teams[0].member[0].get_stats().hp   != 341 ||
        this->teams[0].member[0].get_stats().atk  != 202 ||
        this->teams[0].member[0].get_stats().def  != 217 ||
        this->teams[0].member[0].get_stats().satk != 269 ||
        this->teams[0].member[0].get_stats().sdef != 216 ||
        this->teams[0].member[0].get_stats().spe  != 240 ){
            return false;
    }
    if( this->teams[0].member[4].get_stats().hp   != 301 ||
        this->teams[0].member[4].get_stats().atk  != 308 ||
        this->teams[0].member[4].get_stats().def  != 165 ||
        this->teams[0].member[4].get_stats().satk != 140 ||
        this->teams[0].member[4].get_stats().sdef != 186 ||
        this->teams[0].member[4].get_stats().spe  != 394 ){
            return false;
        }
    if( this->teams[16].member[0].get_stats().hp   != 301 ||
        this->teams[16].member[0].get_stats().atk  != 153 ||
        this->teams[16].member[0].get_stats().def  != 219 ||
        this->teams[16].member[0].get_stats().satk != 298 ||
        this->teams[16].member[0].get_stats().sdef != 250 ||
        this->teams[16].member[0].get_stats().spe  != 250 ){
            return false;
        }
    if( this->teams[16].member[4].get_stats().hp   != 356 ||
        this->teams[16].member[4].get_stats().atk  != 405 ||
        this->teams[16].member[4].get_stats().def  != 296 ||
        this->teams[16].member[4].get_stats().satk != 203 ||
        this->teams[16].member[4].get_stats().sdef != 216 ||
        this->teams[16].member[4].get_stats().spe  != 185 ){
            return false;
        }
    if( this->teams[27].member[0].get_stats().hp   != 404 ||
        this->teams[27].member[0].get_stats().atk  != 184 ||
        this->teams[27].member[0].get_stats().def  != 262 ||
        this->teams[27].member[0].get_stats().satk != 236 ||
        this->teams[27].member[0].get_stats().sdef != 236 ||
        this->teams[27].member[0].get_stats().spe  != 301 ){
            return false;
        }
    if( this->teams[27].member[5].get_stats().hp   != 391 ||
        this->teams[27].member[5].get_stats().atk  != 112 ||
        this->teams[27].member[5].get_stats().def  != 276 ||
        this->teams[27].member[5].get_stats().satk != 236 ||
        this->teams[27].member[5].get_stats().sdef != 286 ||
        this->teams[27].member[5].get_stats().spe  != 208 ){
            return false;
        }
    return true;
}

bool Test::init_test_moves(){

    std::cout << "move test ..." << "\n";
    if(this->teams[0].member[0].get_moveset()[0].base_pp != 8  ||
       this->teams[0].member[0].get_moveset()[0].get_pp() != 8 ||
       this->teams[0].member[0].get_moveset()[0].get_move() != Move::Hydro_Pump){
           return false;
       }
    if(this->teams[0].member[2].get_moveset()[3].base_pp != 8  ||
       this->teams[0].member[2].get_moveset()[3].get_pp() != 8 ||
       this->teams[0].member[2].get_moveset()[3].get_move() != Move::Explosion){

           return false;
       }
    if(this->teams[12].member[2].get_moveset()[1].base_pp != 32  ||
       this->teams[12].member[2].get_moveset()[1].get_pp() != 32 ||
       this->teams[12].member[2].get_moveset()[1].get_move() != Move::Dragon_Dance){
           return false;
       }
    if(this->teams[12].member[4].get_moveset()[2].base_pp != 24  ||
       this->teams[12].member[4].get_moveset()[2].get_pp() != 24 ||
       this->teams[12].member[4].get_moveset()[2].get_move() != Move::Crunch){
           return false;
       }
    if(this->teams[27].member[0].get_moveset()[0].base_pp != 16  ||
       this->teams[27].member[0].get_moveset()[0].get_pp() != 16 ||
       this->teams[27].member[0].get_moveset()[0].get_move() != Move::Substitute){
           return false;
       }
    if(this->teams[27].member[5].get_moveset()[0].base_pp != 16  ||
       this->teams[27].member[5].get_moveset()[0].get_pp() != 16 ||
       this->teams[27].member[5].get_moveset()[0].get_move() != Move::Ice_Beam){
           return false;
       }
    if(this->teams[27].member[0].get_moveset()[3].base_pp != 64  ||
       this->teams[27].member[0].get_moveset()[3].get_pp() != 64 ||
       this->teams[27].member[0].get_moveset()[3].get_move() != Move::Baton_Pass){
           return false;
       }
    if(this->teams[27].member[5].get_moveset()[3].base_pp != 32  ||
       this->teams[27].member[5].get_moveset()[3].get_pp() != 32 ||
       this->teams[27].member[5].get_moveset()[3].get_move() != Move::Recover){
           return false;
       }
    return true;
}

bool Test::init_test_hidden_power(){

    std::cout << "hidden power test ..." << "\n";
    if(this->teams[1].member[0].hiddenpower != Type::Bug ||
       this->teams[1].member[0].hiddenpower_power != 70){
           std::cout << to_string(this->teams[1].member[0].hiddenpower) << "\n";
           std::cout << this->teams[1].member[0].hiddenpower_power << "\n";
           return false;
       }
    if(this->teams[1].member[2].hiddenpower != Type::Grass ||
       this->teams[1].member[2].hiddenpower_power != 70){
           return false;
       }
    if(this->teams[2].member[1].hiddenpower != Type::Fighting ||
       this->teams[2].member[1].hiddenpower_power != 70){
           return false;
       }
    if(this->teams[3].member[1].hiddenpower != Type::Grass ||
       this->teams[3].member[1].hiddenpower_power != 70){
           return false;
       }
    if(this->teams[3].member[5].hiddenpower != Type::Bug ||
       this->teams[3].member[5].hiddenpower_power != 70){
           return false;
       }
    if(this->teams[20].member[3].hiddenpower != Type::Fire ||
       this->teams[20].member[3].hiddenpower_power != 70){
           return false;
       }
    if(this->teams[24].member[0].hiddenpower != Type::Grass ||
       this->teams[24].member[0].hiddenpower_power != 70){
           return false;
       }
    if(this->teams[24].member[1].hiddenpower != Type::Grass ||
       this->teams[24].member[1].hiddenpower_power != 70){
           return false;
       }
    if(this->teams[24].member[2].hiddenpower != Type::Bug ||
       this->teams[24].member[2].hiddenpower_power != 70){
           return false;
       }
    return true;
}

bool Test::test_team_init(){

    std::cout << "== team initilization test ==\n";

    if(this->import_test == true){
        for(auto&& team : this->teams){
            team.team_init();
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

    this->teams[0].member[0].moveset[0].reduce_pp(999);
    this->teams[0].member[0].moveset[1].reduce_pp(999);
    this->teams[0].get_move_options();
    for(auto&& option : this->teams[0].move_options){
        if(option.get_move() == Move::Hydro_Pump || option.get_move() == Move::Ice_Beam){
            return false;
        }
    }

    this->teams[1].member[2].reduce_hp(999);
    this->teams[1].member[4].reduce_hp(999);
    this->teams[1].get_move_options();
    for(auto&& option : this->teams[1].move_options){
        if(option.get_move() == Move::Switch2 ||
           option.get_move() == Move::Switch4){
               return false;
    }
    return true;
  }
}

bool Test::test_switch(){

    std::cout << "== switch test ==\n";

    if(this->team_init_test){
        if(this->teams[0].member[this->teams[0].active_pokemon].get_species() != Species::Swampert){
            return false;
        }
        if(this->teams[5].member[this->teams[5].active_pokemon].get_species() != Species::Salamence){
            return false;
        }
        if(this->teams[18].member[this->teams[18].active_pokemon].get_species() != Species::Tyranitar){
            return false;
        }
        if(this->teams[27].member[this->teams[27].active_pokemon].get_species() != Species::Celebi){
            return false;
        }

        this->teams[0].active_pokemon = 2;
        this->teams[5].active_pokemon = 4;
        this->teams[18].active_pokemon = 5;
        this->teams[27].active_pokemon = 0;

        if(this->teams[0].member[this->teams[0].active_pokemon].get_species() != Species::Metagross){
            return false;
        }
        if(this->teams[5].member[this->teams[5].active_pokemon].get_species() != Species::Jirachi){
            return false;
        }
        if(this->teams[18].member[this->teams[18].active_pokemon].get_species() != Species::Skarmory){
            return false;
        }
        if(this->teams[27].member[this->teams[27].active_pokemon].get_species() != Species::Celebi){
            return false;
        }
    }
    return true;
}

bool Test::test_substitute(){
    this->teams[0].member[0].create_substitute();
    if(this->teams[0].member[0].substitute_hp != 85){
        return false;
    }
    this->teams[0].member[0].reduce_hp(999);
    if(this->teams[0].member[0].get_status() == Status::Fainted ||
       this->teams[0].member[0].current_hp != 341){
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

    this->teams[0].movechoice = &this->teams[0].member[0].moveset[0];
    int damage = battle1.calculate_damage(this->teams[0], this->teams[1]);
    std::cout << "critical hits not considered damage calculation test\n";
    if(damage < 112 || damage > 132){
        return false;
    }

    this->teams[0].movechoice = &this->teams[0].member[0].moveset[1];
    damage = battle1.calculate_damage(this->teams[0], this->teams[1]);
    if(damage < 238 || damage > 280){
        return false;
    }

    return true;
}

bool Test::test_crit(){
    Battle battle(this->teams[21], this->teams[26]);
    this->battle = battle;
    return true;
}

bool Test::test_ability(){
    Battle battle(this->teams[26], this->teams[21]);
    this->battle = battle;
    this->battle.team[0]->active_pokemon = 4;
    this->battle.team[1]->active_pokemon = 3;
    
    this->battle.team[0]->movechoice = &this->battle.team[0]->member[4].moveset[1];
    if(this->battle.ability_multiplier(*this->battle.team[0], *this->battle.team[1]) != 0.0f){
        std::cout << "ability multiplier error \n";
        return false;
    }
    return true;
}

bool Test::test_item(){
    Battle battle(this->teams[0], this->teams[21]);
    this->battle = battle;
    this->battle.team[0]->active_pokemon = 4;
    this->battle.team[0]->movechoice = &this->battle.team[0]->member[4].moveset[1];

    if(this->battle.item_multiplier(*this->battle.team[0]) != 1.5f){
        std::cout << "item multiplier error \n";
        return false;
    }
    return true;
}

bool Test::test_weather(){
    Battle battle(this->teams[1], this->teams[4]);
    this->battle = battle;
    this->battle.team[0]->active_pokemon = 2;
    this->battle.team[1]->active_pokemon = 1;

    this->battle.team[0]->movechoice = &this->battle.team[0]->member[2].moveset[0];
    this->battle.team[1]->movechoice = &this->battle.team[1]->member[1].moveset[0];

    this->battle.weather = Weather::Sun;

    if(!(this-weather_compare(*this->battle.team[1], 0.5f)) ||
       !(this->weather_compare(*this->battle.team[0], 2.0f))){
           return false;
       }

    this->battle.weather = Weather::Rain;

    if(!(this-weather_compare(*this->battle.team[0], 0.5f)) ||
       !(this->weather_compare(*this->battle.team[1], 2.0f))){
           return false;
       }

    return true;
}

bool Test::weather_compare(const Team &_team, const float &value){
    const float result = this->battle.weather_multiplier(_team);
    if(result != value){
        std::cout << "weather multiplier error \n";
        return false;
    }
    return true;
}