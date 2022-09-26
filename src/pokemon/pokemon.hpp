#pragma once

#include <array>
#include <iostream>

#include "abilities.hpp"
#include "attackmove.hpp"
#include "base_stats.hpp"
#include "gender.hpp"
#include "item.hpp"
#include "natures.hpp"
#include "species.hpp"
#include "statnames.hpp"
#include "status.hpp"
#include "rng.hpp"

#include "string_conversions.hpp"

class Pokemon{
public:
    Pokemon()
    {
    };
    constexpr Pokemon(Species species, Nature nature, Ability ability, Item item, Stats evs, Stats ivs, std::array<AttackMove, 4> moves) :
        species(species), 
        nature(nature), 
        ability(ability), 
        item(item), 
        EVs(evs), 
        IVs(ivs),
        moveset(moves)
        {
        };
    Ability former_ability = Ability::Air_Lock;
    void set_former_ability(Ability fability);
    // in this class, because of reduce_hp(), reset on switch
    // pass over to incoming on baton pass
    bool substitute = false;
    int substitute_hp = 0;
    void set_sub(bool sub);
    void set_sub_hp(int subhp);
    void create_substitute();

    void kill();
    int hp_percentage();
    void init();
    void stat_init();
    Stats get_stats() const;
    ///
    /// relevant in battles
    ///
    int get_current_hp();
    void set_current_hp(int hp);
    void remove_item();
    void reduce_hp_direct(const int damage);
    void reduce_hp_attack(const int damage);
    void increase_hp(const int heal);

    void set_status(const Status p_status);
    void set_revealed(const bool p_revealed);
    void set_item(const Item p_item);
    
    Stats get_evs() const;
    Stats get_ivs() const;
    int get_stat(const Statname stat) const;
    Item get_item() const;
    bool get_item_damage_boost() const;
    bool get_revealed() const;
    Status get_status() const;
    Ability get_ability() const;
    Nature get_nature() const;
    Species get_species() const;
    std::array<AttackMove, 4>* get_moveset();
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

    // operator overloads
    bool operator== (const Type _type);
    bool operator!= (const Type _type);
    friend std::ostream& operator<<(std::ostream& out, Pokemon& pokemon);
//private:
    int current_hp      = 0;
    ///
    /// given by import
    ///
    Species species;
    Ability ability;
    Nature nature;
    Item item;
    Gender gender       = Gender::Genderless;
    Item previous_item  = Item::None;
    bool knocked_off    = false;
    int level           = 100;
    int happiness       = 255;
    Stats EVs           = { 0, 0, 0, 0, 0, 0 };
    Stats IVs           = { 31, 31, 31, 31, 31, 31 };
    Status status       = Status::Healthy;
    int sleep_turns     = 0;
    ///
    /// implied / initialized
    ///
    std::array<AttackMove, 4> moveset;
    std::array<Type, 2> type        = { Type::Typeless, Type::Typeless };
    std::array<Type, 2> former_type = { Type::Typeless, Type::Typeless };
    bool revealed = false;
    ///
    /// calculated
    ///
    Stats basestats       = { 0, 0, 0, 0, 0, 0 };
    Stats stats           = { 0, 0, 0, 0, 0, 0 };
    Type hiddenpower      = Type::Normal;
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