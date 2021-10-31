#include "team.hpp"
#include "rng.hpp"

void Team::team_init(){
    for(int i = 0; i < 6; ++i){
        this->switches[i].set_priority(6);
        switch(i){
        case 0:
            this->switches[i].set_move(Move::Switch0);
        case 1:
            this->switches[i].set_move(Move::Switch1);
        case 2:
            this->switches[i].set_move(Move::Switch2);
        case 3:
            this->switches[i].set_move(Move::Switch3);
        case 4:
            this->switches[i].set_move(Move::Switch4);
        case 5:
            this->switches[i].set_move(Move::Switch5);
        default:
            std::cout << "ERROR TEAM INIT SWITCHES";
        }
    }

/*    for(int i = 0; i<6; ++i){
        if(this->member[i].get_species() != Species::no_pokemon){
            this->member[i].stat_init();
        }
    }*/
}


int Team::get_boost(Statname stat){
    switch(stat){
        case Statname::atk:
            return this->atkboost;
        case Statname::def:
            return this->defboost;
        case Statname::satk:
            return this->satkboost;
        case Statname::sdef:
            return this->sdefboost;
        case Statname::spe:
            return this->speboost;
        case Statname::acc:
            return this->accboost;
        case Statname::eva:
            return this->evaboost;
        default:
            std::cout << "ERROR GET_BOOST team.cpp" << std::endl;
            return 0;
    }
}

void Team::get_move_options(){
/*    for(int i = 0; i < 4; ++i){
        if(this->member[this->active_pokemon].get_moveset()[i].get_move() != Move::None){
            if(this->member[this->active_pokemon].get_moveset()[i].get_pp() > 0){
                this->move_options[i] = this->member[this->active_pokemon].get_moveset()[i];
            }
        }
    }*/
}