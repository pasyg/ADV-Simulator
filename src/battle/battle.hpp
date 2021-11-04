#include <string_view>

#include "effectiveness.hpp"
#include "team.hpp"
#include "rng.hpp"

#include "weather.hpp"

class Battle{
public:

private:
    std::string_view p1 = "p1";
    std::string_view p2 = "p2";
    std::array<Team, 2> team;
    Weather weather;

    void use_move(const int team);
    int calculate_damage(const int patkteam);
    bool move_first();
    bool compare_speed();
    int get_stat_boosted(const Statname stat, const Pokemon &pokemon, const int boost);
    int item_ability_mult(int damage, const AttackMove &movechoice, const Pokemon &atkmon, const Pokemon &defmon);
    void play_turn();
};
