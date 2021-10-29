#include "team.hpp"
#include "weather.hpp"

class Battle{
public:

private:
    std::string p1 = "p1";
    std::string p2 = "p2";
    Team team1;
    Team team2;
    Weather weather;

    int calculate_damage(Team &atkteam, Team &defteam);
    bool move_first();
    bool compare_speed();
    int apply_boost(Statname stat, Pokemon &pokemon, int boost);
    
};
