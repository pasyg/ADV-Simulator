#pragma once

#include <fstream>
#include <string_view>

#include "effectiveness.hpp"
#include "team.hpp"
#include "rng.hpp"
#include "benchmark.hpp"
#include "weather.hpp"

class Battle{
public:
    Battle(Team team1, Team team2);
    Battle();
    ~Battle();
    std::ofstream logger;
    std::string_view p1 = "p1";
    std::string_view p2 = "p2";
    std::array<Team, 2> team = {};
    Weather weather = Weather::Clear;
    int weather_turns = 0;
    bool move_first = true;
    bool winner = false; // false: team 1, true: team 2

    //decide_move.cpp
    void decide_move(Team &team);

    // battle.cpp
    int play_battle();
    int get_stat_boosted(int statvalue, const Statname &stat,  const int &boost);
    bool compare_speed();
    void calc_first_attacker();

    // damage_calc.cpp
    int calculate_damage(const Team &atkteam, Team &defteam);
    bool is_crit(const Team &atkteam, const Team &defteam);
    float ability_multiplier(const Team &atkteam, Team &defteam);
    int crit_multiplier(const Team &atkteam, const Team &defteam);
    float effectiveness_multiplier(const Team &atkteam, const Team &defteam);
    float item_multiplier(const Team &atkteam);
    float weather_multiplier(const Team &atkteam, Weather weather);

    // turn.cpp
    bool play_turn();
    bool game_end(const Team &team);
    bool can_move(Team &team);
    bool check_fainted();
    void switch_in_checks();
    void weather_damage(const Weather weather, Pokemon &pokemon);
    bool end_of_turn();

    // use_move.cpp
    void use_move(Team &atkteam, Team &defteam);
    bool is_sound_move(Move move);
    bool is_contact_move(Move move);
};