#include "battle.hpp"


int Battle::calculate_damage(Team &atkteam, Team &defteam){
    int damage = 0;

    return 0;
}

int Battle::apply_boost(Statname stat, Pokemon &pokemon, int boost){
    switch(stat){
        case Statname::atk:
        case Statname::def:
        case Statname::satk:
        case Statname::sdef:
        case Statname::spe:
            if(boost > 0){
                return static_cast<int>(pokemon.get_stat(stat) * (2 + boost) / 2);
            }
            if(boost < 0){
                return static_cast<int>(2 / (2 - pokemon.get_stat(stat)));
            }
        case Statname::acc:
        case Statname::eva:
            return 0;
    }
}

///
/// compares the speed of two active pokemon and returns 0 (false), if team1 is faster, returns 1 (true) if team2 is faster
///
bool Battle::compare_speed(){
    int speed1 = this->team1.member[this->team1.active_pokemon].get_stat(Statname::spe); 
    int speed2 = this->team2.member[this->team2.active_pokemon].get_stat(Statname::spe);

    //this->team1.speboost

    if(team1.member[this->team1.active_pokemon].get_status() == Status::paralysis){
        static_cast<int>(speed1) /= 4;
    }
    if(team2.member[this->team2.active_pokemon].get_status() == Status::paralysis){
        static_cast<int>(speed2) /= 4;
    }
    return true;
}
///
/// checks which pokemon moves first, returns 0 (false) for first move for team 1, 1 (true) for first move for team 2
///
bool Battle::move_first(){
    if(this->team1.movechoice == Move::Switch){
        if(this->team2.movechoice != Move::Switch){
            return false;
        }
        else if(this->team2.movechoice == Move::Switch){

        }
    }
}