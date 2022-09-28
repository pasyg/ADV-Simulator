#pragma once

#include <fstream>
#include <limits>

#include "string_conversions/string_conversions.hpp"

#include "effectiveness.hpp"
#include "team.hpp"
#include "rng.hpp"
#include "benchmark.hpp"
#include "weather.hpp"
#include "transition.hpp"

class Battle
{
public:
    using bTeams = std::array<Team, 2>;

    Battle(bTeams, const std::string &filepath);
    Battle(bTeams teams);
    Battle();
    ~Battle();
    std::ofstream logger;
    std::string_view p1 = "p1a";
    std::string_view p2 = "p2a";
    bTeams team         = {};
    Weather weather     = Weather::Clear;
    int weather_turns   = 0;
    bool uproar         = false;
    bool move_first     = true;
    bool winner         = false; // false: team 1, true: team 2

    Transition transition;

    // decide_move.cpp
    void decide_move(Team &team);

    // battle.cpp
    void init();
    void abilities_simultaneous();
    int play_battle();
    int get_stat_boosted(int statvalue, const Statname &stat, const int &boost);
    bool compare_speed();
    void calc_first_attacker();

    // damage_calc.cpp
    int calculate_damage(Team &atkteam, Team &defteam);
    float atk_multiplier(Ability ability, Type atk_type);
    bool is_crit(const Team &atkteam, Team &defteam);
    float ability_multiplier(const Team &atkteam, Team &defteam);
    int crit_multiplier(const Team &atkteam, const Team &defteam);
    float effectiveness_multiplier(const Team &atkteam, const Team &defteam);
    float item_multiplier(const Team &atkteam);
    float weather_multiplier(const Team &atkteam, Weather weather);

    // turn.cpp
    bool play_turn();
    int game_end(const Team &team1, const Team &team2);
    bool can_move(Team &team);
    bool check_fainted();
    void switch_in_checks();
    void weather_damage(const Weather weather, Pokemon &pokemon, int team);
    bool end_of_turn();

    // use_move.cpp
    void use_move(Team &atkteam, Team &defteam);
    bool is_sound_move(Move move);
    bool is_contact_move(Move move);
    void contact_move(Team &atkteam, Team &defteam);
    void opp_boost(Team &team, const Statname stat, const int boost, const int chance);
    void switch_in(Team &atkteam, Team &defteam, const int target);
    int calculate_accuracy(Team &atkteam, Team &defteam);
    int used_pp(Team &atkteam, Team &defteam);
    bool can_set_status(Team &team, Status status);
    void set_status(Team &atkteam, Team &defteam, Status status);
    bool is_snatchable(Move const move);

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