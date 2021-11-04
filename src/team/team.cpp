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
        case Statname::Atk:
            return this->atkboost;
        case Statname::Def:
            return this->defboost;
        case Statname::Satk:
            return this->satkboost;
        case Statname::Sdef:
            return this->sdefboost;
        case Statname::Spe:
            return this->speboost;
        case Statname::Acc:
            return this->accboost;
        case Statname::Eva:
            return this->evaboost;
        default:
            std::cout << "ERROR GET_BOOST team.cpp" << std::endl;
            return 0;
    }
}

void Team::get_move_options(){
    const Pokemon activemon = this->member[this->active_pokemon];
    const std::array<AttackMove, 4> moves = activemon.get_moveset();
    
    // free the vector from previous options
    this->move_options.clear();
    
    if(this->move_locked){
        this->move_options.push_back(this->locked_move);
    }
    else{
        for(int i = 0; i<4; ++i){
            if(moves[i].get_pp() > 0 && !moves[i].get_disabled()){
                this->move_options.push_back(moves[i]);
            }
        }
    }
    if(this->trapped){
        return;
    }
    for(int i = 0; i<6; ++i){
        if(i == this->active_pokemon){
            continue;
        }
        else{
            if(this->member[i].get_status() != Status::Fainted){
                this->move_options.push_back(this->switches[i]);
            }
        }
    }
}

// can be rewritten for however one wants to make move decisions
void Team::decide_move(){

}