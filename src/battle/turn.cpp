#include "battle.hpp"


bool Battle::play_turn()
{
    // set trapped if trapped
    // reset trapped if not
    auto is_trapped = [&](Team &team, Team &oppteam)
    {
        if(oppteam.active()->get_ability() == Ability::Magnet_Pull && *team.active() == Type::Steel)
        {
            team.trapped = true;
        }
        else{
            team.trapped = false;
        }
        if((oppteam.active()->get_ability() == Ability::Arena_Trap 
           && (*team.active() != Type::Flying
           && team.active()->get_ability() != Ability::Levitate))
           || (*team.active() == Type::Steel && oppteam.active()->get_ability() == Ability::Magnet_Pull)
           || oppteam.meanlook)
        {
            team.trapped = true;
        }
        else
        {
            team.trapped = false;
        }
    };
    if(game_end(this->team[0], this->team[1]))
    {
        return false;
    }
    // check if any active mon is trapped
    is_trapped(this->team[0], this->team[1]);
    is_trapped(this->team[1], this->team[0]);

    // calculate which moves each side can use
    this->team[0].get_move_options(this->team[1].imprison_moves);
    this->team[1].get_move_options(this->team[0].imprison_moves);
    
    // decide what move will be selected for each side
    this->decide_move(this->team[0]);
    this->decide_move(this->team[1]);

    // false: this->team[this->move_first] moves first, true: this->team[!(this->move_first)] moves first
    this->calc_first_attacker();

    // faster mon uses its move first
    if(can_move(this->team[this->move_first]))
    {
        use_move(this->team[this->move_first], this->team[!(this->move_first)]);
    }
    else
    {
        if(game_end(this->team[0], this->team[1]))
        {
            return false; 
        }
    }

    // check if turn ends if one of the active pokemon dies
    if(check_fainted())
    {
        if(game_end(this->team[0], this->team[1]))
        { 
            return false; 
        }
        switch_faint(this->team[0], this->team[1]);
        if(game_end(this->team[0], this->team[1]))
        { 
            return false; 
        }
        switch_faint(this->team[1], this->team[0]);
        if(!this->end_of_turn()) { return false; }
    }

    // slower pokemon uses move now, check if any pokemon died and has to be swapped out
    else
    {
        if(can_move(this->team[!(this->move_first)]))
        {
            use_move(this->team[!(this->move_first)], this->team[this->move_first]);
            if(check_fainted())
            {
                if(game_end(this->team[0], this->team[1]))
                {
                    return false; 
                }
                bool t1 = switch_faint(this->team[0], this->team[1]);
                bool t2 = switch_faint(this->team[1], this->team[0]);
                if(t1 && t2)
                {
                    this->abilities_simultaneous(); 
                }
            }
        } 
        else
        { 
            if(game_end(this->team[0], this->team[1]))
            { 
                return false; 
            }
        }
        if(!this->end_of_turn()) { return false; }
    }
    // if nothing fainted, go to next turn
    return true;
}


// check if fainted pokemon is fainted,
// initiate the forced switchout if so
bool Battle::switch_faint(Team &team, Team &oppteam)
{ 
    if(game_end(team, oppteam)) { return false; }
    if(team.active()->get_current_hp() <= 0)
    {
        faint_log(team);
        team.get_move_options(oppteam.imprison_moves);
        this->decide_move(team);
        this->use_move(team, oppteam);
    }
    return true;
};

// checks if the pokemon is able to use a move
// true: move will be used, false: move will be canceled
bool Battle::can_move(Team &team)
{
    // status preventing move action
    switch (team.active()->get_status())
    {
        case Status::Freeze:
            if(this->transition.randomChance(1, 5))
            {
                team.active()->set_status(Status::Healthy);
                break;
            }
            cant_move_log(team, "frz");
            return false;
        case Status::Sleep_inflicted:
        case Status::Sleep_self:
            if(team.active()->get_ability() == Ability::Early_Bird)
            {
                team.active()->sleep_turns -= 2;
            }
            else{
                team.active()->sleep_turns -= 1;
            }
            if(team.active()->sleep_turns < 1)
            {
                team.active()->set_status(Status::Healthy);
                break;
            }
            if(team.movechoice->get_move() != Move::Sleep_Talk)
            {
                cant_move_log(team, "slp");
                return false;
            }else{
                break;
            }
        case Status::Paralysis:
            if(this->transition.randomChance(1, 4))
            {
                cant_move_log(team, "par");
                return false;
            }
        default: 
            break;
    }
    // truant: user can only move every other turn
    if(team.truant == true){ return false; }
    // infatuation
    if(team.infatuated)
    {
        if(this->transition.randomChance(1, 2)){ return false; }
    }
    // confusion selfhit
    if(team.confusion > 0)
    {
        if(this->transition.randomChance(1, 2))
        {
            team.movechoice->set_move(Move::Hit_Self);
            team.active()->reduce_hp_direct(calculate_damage(team, team));
            return false;
        }
    }
    return true;
}

// checks turn state after a move and returns false if the second mon can move
// and true if the turn will be ended
bool Battle::check_fainted()
{
    if(this->team[0].active()->get_status() == Status::Fainted)
    {
        return true;
    }
    if(this->team[1].active()->get_status() == Status::Fainted)
    {
        return true;
    }
    return false;
}
// NOT FULLY IMPLEMENTED!!!
bool Battle::end_of_turn()
{
    bool first = this->compare_speed();
    bool second = !first;

    // wish recovers 50% of the original users max HP to the pokemon that receives it
    if(this->team[first].wish == 1)
    {
        this->team[first].active()->increase_hp(this->team[first].wish_recovery);    
        // replay log
        this->heal_log(this->team[first], *this->team[first].active(), "move: Wish| [wisher] whatever");
        this->team[first].wish = false;
    }
    if(this->team[second].wish == 1)
    {
        this->team[second].active()->increase_hp(this->team[second].wish_recovery);
        // replay log
        this->heal_log(this->team[second], *this->team[second].active(), "move: Wish| [wisher] whatever");
        this->team[second].wish = false;
    }
    // weather turncounter gets decremented by 1 at the end of every turn
    weather_turns--;

    // reset weather if it runs out
    if(weather_turns == 0)
    {
        this->weather = Weather::Clear;
        // replay log
        this->weather_end();
    }
    else
    {
        // replay log
        this->weather_upkeep();
    }
    // weather damage
    switch(this->weather)
    {
        case Weather::Clear:
        case Weather::Rain:
        case Weather::Sun:
            break;
        case Weather::Hail:
            this->weather_damage(Weather::Hail, *this->team[first].active(), first);
            if(switch_faint(this->team[0], this->team[1]))
            {
                return false; 
            }
            this->weather_damage(Weather::Hail, *this->team[second].active(), second);
            if(switch_faint(this->team[0], this->team[1]))
            {
                return false; 
            }
            break;
        case Weather::Sand:
            this->weather_damage(Weather::Sand, *this->team[first].active(), first);
                if(switch_faint(this->team[0], this->team[1]))
                {
                    return false; 
                }
            this->weather_damage(Weather::Sand, *this->team[second].active(), second);
            if(switch_faint(this->team[0], this->team[1]))
            {
                return false; 
            }
            break;
    }
    // end of turn effects
    // after weather damage, the faster mon will run through all these effects first
    // then the other mon
    first = this->compare_speed();
    second = !first;

    for(int i = 0; i<2; ++i)
    {
        // ingrain heals the currently active pokemon for 1/16th at the end of every turn
        if(this->team[first].ingrain == true)
        {
            this->team[first].active()->increase_hp(static_cast<int>(this->team[first].active()->get_stats().hp / 16.0));
            // replay log
            this->heal_log(this->team[first], *this->team[first].active(), "move: Ingrain\n");
        }

        // rain dish
        if(this->weather == Weather::Rain)
        {
            if(this->team[first].active()->get_ability() == Ability::Rain_Dish)
            {
                this->team[first].active()->increase_hp(static_cast<int>(this->team[first].active()->get_stats().hp / 16.0));
                this->heal_log(this->team[first], *this->team[first].active(), "ability: Rain Dish\n");
            }
        }

        // speed boost, boost speed by 1
        if(this->team[first].active()->get_ability() == Ability::Speed_Boost)
        {
            this->team[first].set_boost(Statname::Spe, 1);
        }

        // truant
        if(this->team[first].active()->get_ability() == Ability::Truant)
        {
            this->team[first].truant = !this->team[first].truant;
        }

        // shed skin, 1/3 chance of removing status condition
        if(this->team[first].active()->get_ability() == Ability::Shed_Skin)
        {
            if(this->transition.randomChance(1, 3))
            {
                this->team[first].active()->set_status(Status::Healthy);
            }
        }

        // leftovers healing
        if(this->team[first].active()->get_item() == Item::Leftovers && 
           this->team[first].active()->current_hp < this->team[first].active()->get_stats().hp)
        {
            this->team[first].active()->increase_hp(static_cast<int>(this->team[first].active()->get_stats().hp / 16.0));
            this->heal_log(this->team[first], *this->team[first].active(), "item: Leftovers\n");
        }

        // berry and herbs
        this->team[first].use_hp_berry();
        this->team[first].use_pinch_berry();

        // leech seed, opponent regenerates the amount of hp the affected pokemon loses
        if(this->team[first].leechseed == true)
        {
            int dmg = static_cast<int>(this->team[first].active()->get_stats().hp / 8.0);
            this->team[first].active()->reduce_hp_direct(dmg);
            if(game_end(this->team[0], this->team[1]))
            { 
                return false; 
            }
            if(this->team[first].active()->get_ability() == Ability::Liquid_Ooze)
            {
                this->team[second].active()->increase_hp(dmg);     
            }
            else
            {
                this->team[second].active()->increase_hp(dmg);
            }
        }

        // poison, fixed damage of 1/8th
        if(this->team[first].active()->get_status() == Status::Poison)
        {
            this->team[first].active()->reduce_hp_direct(static_cast<int>(this->team[first].active()->get_stats().hp / 8.0));
            if(game_end(this->team[0], this->team[1]))
            {
                return false; 
            }
        }

        // toxic, pokemon takes an escalating amount of damage, 
        // increases by 1/16th every consecutive turn on the field
        if(this->team[first].active()->get_status() == Status::Toxic_poison)
        {
            this->team[first].active()->reduce_hp_direct(static_cast<int>(this->team[first].turns_on_the_field * (this->team[first].active()->get_stats().hp / 8.0)));
            if(game_end(this->team[0], this->team[1]))
            { 
                return false; 
            }
        }

        // burn, fixed 1/8th max hp damage
        if(this->team[first].active()->get_status() == Status::Burn)
        {
            this->team[first].active()->reduce_hp_direct(static_cast<int>(this->team[first].active()->get_stats().hp / 8.0));
            if(game_end(this->team[0], this->team[1]))
            { 
                return false; 
            }
        }
        // nightmare

        // curse
        if(this->team[first].curse == true)
        {
            this->team[first].active()->reduce_hp_direct(static_cast<int>(this->team[first].active()->get_stats().hp / 4.0));
            if(game_end(this->team[0], this->team[1]))
            { 
                return false; 
            }
        }
        // multi turn attacks ??????

        // uproar
        if(this->team[first].uproar > 0)
        {
            if(this->team[first].active()->get_status() == Status::Sleep_inflicted || this->team[first].active()->get_status() == Status::Sleep_self)
            {
                this->team[first].active()->set_status(Status::Healthy);
            }
            if(this->team[second].active()->get_status() == Status::Sleep_inflicted || this->team[second].active()->get_status() == Status::Sleep_self)
            {
                this->team[second].active()->set_status(Status::Healthy);
            }
        }

        // outrage/petaldance/thrash, user gets confused and end of the move counter (2-3 turns)
        if(this->team[first].selflock > 0)
        {
            --this->team[first].selflock;
            if(this->team[first].selflock == 0)
            {
                this->team[first].set_confusion();
            }
        }
        // decrement disable

        // encore
        --this->team[first].encore;

        // taunt / lock-on / mindreader
        -- this->team[first].safeguard;
        -- this->team[first].taunt;
        -- this->team[first].lockon;
        -- this->team[first].wrap;
        if(this->team[first].wrap <= 0){ this->team[first].trapped = false; }
        
        // yawn
        if(this->team[first].yawn == 1)
        {
            if(this->team[first].active()->get_status() == Status::Healthy)
            {
                this->team[first].active()->set_status(Status::Sleep_inflicted);
            }
        }
        // game decided after both fsight/DD AND perishsong
        // not inbetween
        first = !first;
        second = !second;
    }
    for(int i = 0; i<2; ++i)
    {
        this->team[first].flinch = false;
        // future sight / doom desire
        -- this->team[first].delayed_damage_turns;
        if(this->team[first].delayed_damage_turns == 0)
        {
            team[second].active()->reduce_hp_attack(team[first].delayed_damage);
        }
        // perish song
        -- team[first].perishsong;
        if(team[first].perishsong == 0)
        {
            team[first].active()->kill();
        }
    }
    return true;
}

void Battle::switch_in_checks()
{
// ???
}

void Battle::weather_damage(const Weather weather, Pokemon &pokemon, int team)
{
    if(weather == Weather::Sand)
    {
        switch(pokemon.get_type()[0])
        {
            case Type::Ground:
            case Type::Rock:
            case Type::Steel:
                return;
            default:
                break;
        }
        switch(pokemon.get_type()[1])
        {
            case Type::Ground:
            case Type::Rock:
            case Type::Steel:
                return;
            default:
                pokemon.reduce_hp_direct(static_cast<int>(pokemon.get_stats().hp / 16.0));
                // replay log
                this->damage_log(this->team[team], *this->team[team].active(), "Sandstorm\n");
        }
    }

    if(weather == Weather::Hail)
    {
        switch(pokemon.get_type()[0])
        {
            case Type::Ice:
                return;
            default:
                break;
        }
        switch(pokemon.get_type()[1])
        {
            case Type::Ice:
                return;
            default:
                pokemon.reduce_hp_direct(static_cast<int>(pokemon.get_stats().hp / 16.0));
                // replay log
                this->damage_log(this->team[team], *this->team[team].active(), "Hail\n");
        }
    }
}