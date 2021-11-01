#include "battle.hpp"


int Battle::get_stat_boost(const Statname stat, const Pokemon &pokemon, const int boost){
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
                return static_cast<int>(pokemon.get_stat(stat) * 2 / (2 + boost));
            }
        case Statname::acc:
        case Statname::eva:
            if(boost > 0){
                return static_cast<int>((3 + boost) / 3);
            }
            if(boost < 0){
                return static_cast<int>(3 / (3 + boost));
            }
            else{
                return 1;
            }
        default:
            return 0;
    }
}

///
/// compares the speed of two active pokemon and returns 0 (false), if team1 is faster, returns 1 (true) if team2 is faster
///
bool Battle::compare_speed(){

    Pokemon* mon1 = &this->team1.member[this->team1.active_pokemon];
    Pokemon* mon2 = &this->team1.member[this->team1.active_pokemon];

    int speed1 = get_stat_boost(Statname::spe, *mon1, this->team1.speboost);
    int speed2 = get_stat_boost(Statname::spe, *mon2, this->team2.speboost);

    //this->team1.speboost

    if(mon1->get_status() == Status::paralysis){
        static_cast<int>(speed1) /= 4;
    }
    if(mon2->get_status() == Status::paralysis){
        static_cast<int>(speed2) /= 4;
    }
    if(speed1 > speed2){
        return false;
    }
    if(speed1 < speed2){
        return true;
    }
    else{
        return get_random(0,1);
    }
}
///
/// checks which pokemon moves first, returns 0 (false) for first move for team 1, 1 (true) for first move for team 2
///
bool Battle::move_first(){

    int prio1 = moveprio(this->team1.movechoice->get_move());
    int prio2 = moveprio(this->team2.movechoice->get_move());

    // quickclaw holders have a 20% chance to move first in their priority bracket
    // in singles formats this equates to moving up one priority bracket
    if(this->team1.member[this->team1.active_pokemon].get_item() == Item::quickclaw){
        if(get_random(1,10) < 3){
            prio1 += 1;
        }
    }    

    if(this->team2.member[this->team2.active_pokemon].get_item() == Item::quickclaw){
        if(get_random(1,10) < 3){
            prio2 += 1;
        }
    }

    if(prio1 > prio2){
        return false;
    }
    else if(prio1 < prio2){
        return true;
    }
    else{
        return compare_speed();
    }
}