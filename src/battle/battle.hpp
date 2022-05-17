#pragma once

#include <fstream>

#include "string_conversions/string_conversions.hpp"

#include "effectiveness.hpp"
#include "team.hpp"
#include "rng.hpp"
#include "benchmark.hpp"
#include "weather.hpp"

class Battle{
public:
    Battle(Team team1, Team team2, const std::string &filepath);
    Battle(Team team1, Team team2);
    Battle();
    ~Battle();
    std::ofstream logger;
    std::string_view p1 = "p1a";
    std::string_view p2 = "p2a";
    std::array<Team, 2> team = {};
    Weather weather = Weather::Clear;
    int weather_turns = 0;
    bool move_first = true;
    bool winner = false; // false: team 1, true: team 2

    //decide_move.cpp
    void decide_move(Team &team);

    // battle.cpp
    void init(Team &team1, Team &team2);
    void abilities_simultaneous();
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
    void weather_damage(const Weather weather, Pokemon &pokemon, int team);
    bool end_of_turn();

    // use_move.cpp
    void use_move(Team &atkteam, Team &defteam);
    bool is_sound_move(Move move);
    bool is_contact_move(Move move);

    // log.cpp
    void cant_move_log(Team &team, std::string_view reason);
    void damage_log(Team &team, Pokemon &target, std::string_view from);
    void atk_damage_log(Team &team);
    void faint_log(Team &team);
    void heal_log(Team &team, Pokemon &target, std::string_view from);
    void move_log(Team &atkteam, Team &defteam);
    void miss_log(bool team);
    void crit_log(Team &team);
    void switch_log(Team &team);
    void weather_start(Team &team, Weather weather, std::string_view from);
    void weather_upkeep();
    void weather_end();
    void miss_log();
    void confusion_log();
    void substitute_log(Team &team);
    void infatuation_log();
    void truant_log();
    void boost_log();
    void curestatus_log();
    void effective_log();
};