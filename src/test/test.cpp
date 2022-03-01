#include "test.hpp"

Test::Test(){}

Test::~Test(){}

void Test::test_all(){
    check("import", std::bind(&Test::test_import, this));
    check("team init", std::bind(&Test::test_team_init, this));
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

bool Test::test_team_init(){
    if(this->import_test == true){
        for(auto&& team : this->teams){
            team.team_init();
        }
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
    else{
        std::cout << "(ERROR import)" << "\n";
        return false;
    }
}