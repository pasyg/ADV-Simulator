#pragma once

#include <array>
#include <iostream>

#include "abilities.hpp"
#include "attackmove.hpp"
#include "base_stats.hpp"
#include "natures.hpp"
#include "species.hpp"
#include "status.hpp"


class Pokemon{
public:
    Pokemon();
    ~Pokemon();
    Stats stats;
    void stat_init();
    Stats get_stats();
    
    ///
    /// relevant in battles
    ///

    void set_status(Status p_status);
    void set_revealed(bool p_revealed);

    Status get_status();
    bool get_revealed();
    Ability get_ability();
    Nature get_nature();
    Species get_species();
    std::array<AttackMove, 4> get_moveset();
    std::array<Type, 2> get_type();
    int get_level();
    int get_happiness();
    int get_hiddenpower_power();
    Type get_hiddenpower_type();

    ///
    /// always intilization relevant
    ///

    void set_ability(Ability p_ability);
    void set_basestats(Stats p_stats);
    void set_nature(Nature p_nature);
    void set_species(Species p_species);
    void set_moveset(std::array<AttackMove, 4> p_moveset);
    void set_type(std::array<Type, 2> p_type);
    
    ///
    /// sometimes intilization relevant
    ///
    
    void set_level(int p_level);
    void set_happiness(int p_happiness);
    void set_hiddenpower(Type p_type, int p_power);

private:
    int level = 100;
    int happiness = 255;
    Stats basestats;
    Stats IVs = {31,31,31,31,31,31};
    Stats EVs = {0,0,0,0,0,0};
    Type hiddenpower;
    int hiddenpower_power = 70;
    Ability ability;
    Nature nature;
    Species species;
    Status status = Status::healthy;
    std::array<AttackMove, 4> moveset;
    std::array<Type, 2> type = {Type::Typeless, Type::Typeless};
    bool revealed = false;
    void calc_hp();
    void calc_atk();
    void calc_def();
    void calc_satk();
    void calc_sdef();
    void calc_spe();
    void calc_hiddenpower_power();
    void calc_hiddenpower_type();
};