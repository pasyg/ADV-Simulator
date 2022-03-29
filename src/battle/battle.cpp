#include "battle.hpp"

Battle::Battle(Team team1, Team team2) 
    : logger("replays/test.txt")
{
    this->team[0] = team1;
    this->team[1] = team2;
    this->team[0].team_init();
    this->team[1].team_init();

    this->weather = Weather::Clear;
    this->weather_turns = 0;
}

Battle::Battle() 
    : logger("replays/test.txt") {

}

Battle::~Battle(){

}

int Battle::play_battle(){
    for(int i = 1; i < constants::turn_cap; ++i){
        // loop playing turns as long as no winner has been declared,
        // or turn limit (i) hasn't been reached
        if(this->play_turn()){
            continue;
        }
        // if the game is over, return winner or tie
        else{
            bool t_1 = game_end(0);
            bool t_2 = game_end(1);
            if(t_1 && !t_2){ return 0; }
            else{ 
                return t_1 ? 2 : 1; 
            }
        }
    }
    return 2;
}
// loop through team to check if game has to end
bool Battle::game_end(int teamindex){
    for(auto&& member : this->team[teamindex].member){
        if(member.get_status() != Status::Fainted){
            return false;
        }
    }
    return true;
}

int Battle::get_stat_boosted(int statvalue, const Statname &stat,  const int &boost){
    switch(stat){
        case Statname::Atk:
        case Statname::Def:
        case Statname::Satk:
        case Statname::Sdef:
        case Statname::Spe:
            if(boost > 0){
                return static_cast<int>(statvalue * (2 + boost) / 2.0);
            }
            else if(boost < 0){
                return static_cast<int>(statvalue * 2 / static_cast<float>(2 + boost));
            }
            else{
                return statvalue;
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
/// checks which pokemon moves first, returns 0 (false) for first move for team 1, 1 (true) for first move for team 2
///
void Battle::calc_first_attacker(){

    int prio1 = move_prio(this->team[0].movechoice->get_move());
    int prio2 = move_prio(this->team[1].movechoice->get_move());

    // quickclaw holders have a 20% chance to move first in their priority bracket
    // in singles formats this is equivalent to moving up one priority bracket
    if(this->team[0].active()->get_item() == Item::Quickclaw){
        if(get_random(1,10) < 3){
            prio1 += 1;
        }
    }    
    if(this->team[1].active()->get_item() == Item::Quickclaw){
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
///
/// compares the speed of two active pokemon and returns 0 (false), if team1 moves first, returns 1 (true) if team2 moves first
///
bool Battle::compare_speed(){

    int speed1 = get_stat_boosted(this->team[0].active()->get_stats().spe, 
                                  Statname::Spe, this->team[0].speboost);
    int speed2 = get_stat_boosted(this->team[1].active()->get_stats().spe, 
                                  Statname::Spe, this->team[1].speboost);

    if(this->team[0].active()->get_status() == Status::Paralysis){
        speed1 = static_cast<int>(speed1 / 4.0);
    }
    if(this->team[1].active()->get_status() == Status::Paralysis){
        speed2 = static_cast<int>(speed2 / 4.0);
    }
    switch(this->weather){
        case Weather::Sun:
            if(this->team[0].active()->get_ability() == Ability::Chlorophyll) { speed1 *= 2; }
            if(this->team[1].active()->get_ability() == Ability::Chlorophyll) { speed2 *= 2; }
            break;
        case Weather::Rain:
            if(this->team[0].active()->get_ability() == Ability::Swift_Swim) { speed1 *= 2; }
            if(this->team[1].active()->get_ability() == Ability::Swift_Swim) { speed2 *= 2; }
            break;
        default:
            break;
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