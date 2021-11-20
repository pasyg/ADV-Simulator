#include "battle.hpp"

Battle::Battle(Team &team1, Team &team2){
    this->team[0] = &team1;
    this->team[1] = &team2;

    this->team[0]->team_init();
    this->team[1]->team_init();

    this->weather = Weather::Clear;
    this->weather_turns = 0;
}

Battle::~Battle(){

}

int Battle::get_stat_boosted(const Statname stat, const Pokemon &pokemon, const int boost){
    switch(stat){
        case Statname::Atk:
        case Statname::Def:
        case Statname::Satk:
        case Statname::Sdef:
        case Statname::Spe:
            if(boost > 0){
                return static_cast<int>(pokemon.get_stat(stat) * (2 + boost) / 2.0);
            }
            else if(boost < 0){
                return static_cast<int>(pokemon.get_stat(stat) * 2 / static_cast<float>(2 + boost));
            }
            else{
                return pokemon.get_stat(stat);
            }
        case Statname::Acc:
        case Statname::Eva:
            if(boost > 0){
                return static_cast<int>((3 + boost) / 3.0);
            }
            if(boost < 0){
                return static_cast<int>(3 / static_cast<float>(3 + boost));
            }
            else{
                return 1;
            }
        default:
            return 0;
    }
}

///
/// compares the speed of two active pokemon and returns 0 (false), if team1 moves first, returns 1 (true) if team2 moves first
///
bool Battle::compare_speed(){

    int speed1 = get_stat_boosted(Statname::Spe, this->team[0]->member[this->team[0]->active_pokemon], this->team[0]->speboost);
    int speed2 = get_stat_boosted(Statname::Spe, this->team[1]->member[this->team[1]->active_pokemon], this->team[1]->speboost);


    if(this->active_1->get_status() == Status::Paralysis){
        speed1 = static_cast<int>(speed1 / 4.0);
    }
    if(this->active_2->get_status() == Status::Paralysis){
        speed2 = static_cast<int>(speed2 / 4.0);
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
void Battle::calc_first_attacker(){

    int prio1 = move_prio(this->team[0]->movechoice->get_move());
    int prio2 = move_prio(this->team[1]->movechoice->get_move());

    // quickclaw holders have a 20% chance to move first in their priority bracket
    // in singles formats this equates to moving up one priority bracket
    if(this->active_1->get_item() == Item::Quickclaw){
        if(get_random(1,10) < 3){
            prio1 += 1;
        }
    }    

    if(this->active_2->get_item() == Item::Quickclaw){
        if(get_random(1,10) < 3){
            prio2 += 1;
        }
    }

    if(prio1 > prio2){
        this->move_first = false;
    }
    else if(prio1 < prio2){
        this->move_first = true;
    }
    else{
        this->move_first = compare_speed();
    }
}
