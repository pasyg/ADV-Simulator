#pragma once

#include <fstream>
#include <limits>
#include <string>
#include <vector>

#include "test_pokemon.hpp"

#include "battle.hpp"

#include "tools/benchmark.hpp"
#include "tools/import.hpp"

#include "data/base_stats.hpp"
#include "../string_conversions/ability.hpp"
#include "../string_conversions/gender.hpp"
#include "../string_conversions/item.hpp"
#include "../string_conversions/moves.hpp"
#include "../string_conversions/nature.hpp"
#include "../string_conversions/species.hpp"
#include "../string_conversions/status.hpp"
#include "../string_conversions/type.hpp"

class Test{
public:
    void test_works_ok();
    void test_works_ok_two();
    Test();
    ~Test();
    void test_all();
    template<typename Func>
    void check(std::string_view funcname, Func func){
        if(func()){
            std::cout << funcname << " test successful\n\n";
        }
        else{
            std::cout << funcname << " test NOT successful\n\n";
        }
    }
    bool test_import();
    bool test_team_init();
    bool test_move_options();
    bool test_calc();
    Pokemon* member(int team, int slot);
private:
    std::vector<Team> teams;
    Battle battle;
    bool import_test;
    bool team_init_test;
    void reset();
    
    // init test
    bool init_test_species();
    bool init_test_stats();
    bool init_test_moves();
    bool init_test_hidden_power();

    // various mechanics tests1
    bool test_switch();
    bool test_substitute();
    bool test_ability();
    bool test_item();
    bool test_weather();
    
    // moves test
    bool test_moves();
    bool test_use_move();
    bool test_crit();
    bool test_accuracy_moves();
    bool test_attacking_moves();
    bool test_sideeffects_moves();
    bool test_healing_moves();
    bool test_status_moves();
    bool test_misc_moves();
    bool weather_compare(const Team &_team, const float &value, Weather weather);
};