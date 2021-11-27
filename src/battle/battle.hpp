#include <string_view>

#include "effectiveness.hpp"
#include "team.hpp"
#include "rng.hpp"
#include "benchmark.hpp"
#include "weather.hpp"

class Battle{
public:
    Battle(Team &team1, Team &team2);
    ~Battle();
    std::string_view p1 = "p1";
    std::string_view p2 = "p2";
    std::array<Team*, 2> team;
    Weather weather = Weather::Clear;
    int weather_turns = 0;
    bool move_first;


    // battle.cpp
    int get_stat_boosted(const Statname stat, const Pokemon &pokemon, const int boost);
    bool compare_speed();
    void calc_first_attacker();

    // damage_calc.cpp
    int item_ability_mult(int damage, const AttackMove &movechoice, const Pokemon &atkmon, const Pokemon &defmon);
    int calculate_damage(const int patkteam);

    // turn.cpp
    bool check_fainted();
    void play_turn();
    void switch_in_checks();
    void weather_damage(const Weather weather, Pokemon &pokemon);
    void end_of_turn();

    // use_move.cpp
    void use_move(const int teamindex);
private:
};