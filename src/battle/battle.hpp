#include "effectiveness.hpp"
#include "team/team.hpp"

#include "weather.hpp"

class Battle{
public:

private:
    std::string p1 = "p1";
    std::string p2 = "p2";
    Team team1;
    Team team2;
    Weather weather;

    int calculate_damage(const int patkteam);
    bool move_first();
    bool compare_speed();
    int get_stat_boost(const Statname stat, const Pokemon &pokemon, const int boost);
    int item_ability_mult(const int damage, const Pokemon &atkmon, const Pokemon &defmon);
};
