#pragma once

#include <array>
#include <iostream>

#include "data/abilities.hpp"
#include "attackmove.hpp"
#include "base_stats.hpp"
#include "gender.hpp"
#include "item.hpp"
#include "natures.hpp"
#include "species.hpp"
#include "statnames.hpp"
#include "status.hpp"


class Pokemon{
public:
    Pokemon();
    ~Pokemon();
    void init();
    void stat_init();
    Stats get_stats() const;
    ///
    /// relevant in battles
    ///
    int get_current_hp();
    void remove_item();
    void reduce_hp(const int p_damage);
    void increase_hp(const int p_heal);

    void set_status(const Status p_status);
    void set_revealed(const bool p_revealed);
    void set_item(const Item p_item);
    
    int get_stat(const Statname stat) const;
    Item get_item() const;
    bool get_item_damage_boost() const;
    bool get_revealed() const;
    Status get_status() const;
    Ability get_ability() const;
    Nature get_nature() const;
    Species get_species() const;
    std::array<AttackMove, 4> get_moveset() const;
    std::array<Type, 2> get_type() const;
    int get_level() const;
    Gender get_gender() const;
    int get_happiness() const;
    int get_hiddenpower_power() const;
    Type get_hiddenpower_type() const;
    ///
    /// always intilization relevant
    ///
    void set_evs(const Stats stats);
    void set_ivs(const Stats stats);
    void set_ability(const Ability p_ability);
    void set_basestats(const Stats p_stats);
    void set_nature(const Nature p_nature);
    void set_species(const Species p_species);
    void set_moveset(const std::array<AttackMove, 4> p_moveset);
    void set_type(const std::array<Type, 2> p_type);
    void set_item_damage_boost(const bool dmgboost);
    ///
    /// sometimes intilization relevant
    ///
    void set_level(const int p_level);
    void set_gender(const Gender p_gender);
    void set_happiness(const int p_happiness);
    void set_hiddenpower(const Type p_type, const int p_power);

private:
    int current_hp = 0;
    ///
    /// given by import
    ///
    Species species;
    Gender gender;
    Item item;
    bool item_damage_boost;
    Ability ability;
    int level = 100;
    int happiness = 255;
    Stats EVs = {0,0,0,0,0,0};
    Nature nature;
    Stats IVs = {31,31,31,31,31,31};
    ///
    /// implied / initialized
    ///
    Stats basestats;
    Status status = Status::healthy;
    std::array<AttackMove, 4> moveset;
    std::array<Type, 2> type = {Type::Typeless, Type::Typeless};
    bool revealed = false;
    ///
    /// calculated
    ///
    Stats stats;
    Type hiddenpower;
    int hiddenpower_power = 70;
    ///
    /// private methods
    ///
    void calc_hp();
    void calc_atk();
    void calc_def();
    void calc_satk();
    void calc_sdef();
    void calc_spe();
    void calc_hiddenpower_power();
    void calc_hiddenpower_type();
    int pos_nature(const int stat);
    int neg_nature(const int stat);
};