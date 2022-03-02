#include "test.hpp"

Test::Test(){}

Test::~Test(){}

void Test::test_all(){
    check("import", std::bind(&Test::test_import, this));
    check("team init", std::bind(&Test::test_team_init, this));
    check("move options", std::bind(&Test::test_move_options, this));
}

void Test::check(std::string funcname, std::function<bool()> func){
    if(func()){
        std::cout << funcname << " test successful" << "\n";
    }
    else{
        std::cout << funcname << " test NOT successful" << "\n";
    }
}

bool Test::test_import(){
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
    if( this->teams[0].member[0].get_stats().hp !=   341   ||
        this->teams[0].member[0].get_stats().atk !=  202   ||
        this->teams[0].member[0].get_stats().def !=  217   ||
        this->teams[0].member[0].get_stats().satk != 269   ||
        this->teams[0].member[0].get_stats().sdef != 216   ||
        this->teams[0].member[0].get_stats().spe !=  240 ){
            return false;
    }
    if( this->teams[0].member[4].get_stats().hp !=   301   ||
        this->teams[0].member[4].get_stats().atk !=  308  ||
        this->teams[0].member[4].get_stats().def !=  165  ||
        this->teams[0].member[4].get_stats().satk != 140 ||
        this->teams[0].member[4].get_stats().sdef != 186 ||
        this->teams[0].member[4].get_stats().spe !=  394 ){
            return false;
        }
    if( this->teams[16].member[0].get_stats().hp !=   301   ||
        this->teams[16].member[0].get_stats().atk !=  153  ||
        this->teams[16].member[0].get_stats().def !=  219  ||
        this->teams[16].member[0].get_stats().satk != 298 ||
        this->teams[16].member[0].get_stats().sdef != 250 ||
        this->teams[16].member[0].get_stats().spe !=  250 ){
            return false;
        }
    if( this->teams[16].member[4].get_stats().hp !=   356   ||
        this->teams[16].member[4].get_stats().atk !=  405  ||
        this->teams[16].member[4].get_stats().def !=  296  ||
        this->teams[16].member[4].get_stats().satk != 203 ||
        this->teams[16].member[4].get_stats().sdef != 216 ||
        this->teams[16].member[4].get_stats().spe !=  185 ){
            return false;
        }
    if( this->teams[27].member[0].get_stats().hp !=   404   ||
        this->teams[27].member[0].get_stats().atk !=  184  ||
        this->teams[27].member[0].get_stats().def !=  262  ||
        this->teams[27].member[0].get_stats().satk != 236 ||
        this->teams[27].member[0].get_stats().sdef != 236 ||
        this->teams[27].member[0].get_stats().spe !=  301 ){
            return false;
        }
    if( this->teams[27].member[5].get_stats().hp !=   391   ||
        this->teams[27].member[5].get_stats().atk !=  112  ||
        this->teams[27].member[5].get_stats().def !=  276  ||
        this->teams[27].member[5].get_stats().satk != 236 ||
        this->teams[27].member[5].get_stats().sdef != 286 ||
        this->teams[27].member[5].get_stats().spe !=  208 ){
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
    if(this->import_test == true){
        for(auto&& team : this->teams){
            team.team_init();
        }
        if(this->init_test_species() &&
           this->init_test_stats() &&
           this->init_test_moves() &&
           this->init_test_hidden_power()){ 
               return true; 
            }
        else{
            return false;
        }
    }
    else{
        std::cout << "(ERROR import)" << "\n";
        return false;
    }
}

bool Test::test_move_options(){
    this->teams[0].member[0].get_moveset()[0].reduce_pp(9999);
    this->teams[0].member[0].get_moveset()[1].reduce_pp(9999);
    this->teams[0].get_move_options();
    this->teams[0].decide_move();
    for(int i = 0; i < 200; ++i){
        if(this->teams[0].movechoice->get_move() == Move::Hydro_Pump ||
           this->teams[0].movechoice->get_move() == Move::Ice_Beam){
               return false;
           }
        }
    this->teams[1].member[2].reduce_hp(999);
    this->teams[1].member[4].reduce_hp(999);
    this->teams[1].get_move_options();
    this->teams[1].decide_move();
    for(int i = 0; i < 200; ++i){
        if(this->teams[1].movechoice->get_move() == Move::Switch2 ||
           this->teams[1].movechoice->get_move() == Move::Switch4){
               return false;
           }
        }
    return true;
}
