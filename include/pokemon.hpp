#pragma once

#include <array>

#include "abilities.hpp"
#include "natures.hpp"
#include "attackmove.hpp"
#include "species.hpp"
#include "status.hpp"

///
/// structure structs for easy handling with IVs, EVs,
/// base stats and real stats and easy function returns
/// 

struct Stats{
    int hp;
    int atk;
    int def;
    int satk;
    int sdef;
    int spe;
};

class Pokemon{
public:
    Pokemon();
    ~Pokemon();
    Stats stats;
    void stat_init();
    Stats get_stats();
    
    /// relevant in battles
   
    void set_status(Status p_status);
    void set_revealed(bool p_revealed);

    /// always intilization relevant
   
    void set_ability(Ability p_ability);
    void set_nature(Nature p_nature);
    void set_species(Species p_species);
    void set_moveset(std::array<AttackMove, 4> p_moveset);
    void set_type(std::array<Type, 2> p_type);
    
    /// sometimes intilization relevant
    
    void set_level(int p_level);
    void set_happiness(int p_happiness);
    void set_hiddenpower(Type p_type, int p_power);

private:
    int level = 100;
    int happiness = 255;
    Stats basestats;
    Stats IVs;
    Stats EVs;
    Type hiddenpower;
    int hiddenpower_power = 70;
    Ability ability;
    Nature nature;
    Species species;
    Status status = Status::healthy;
    std::array<AttackMove, 4> moveset;
    std::array<Type, 2> type;
    bool revealed = false;
    void calc_hp();
    void calc_atk();
    void calc_def();
    void calc_satk();
    void calc_sdef();
    void calc_spe();
};