#pragma once

#include <algorithm>
#include <array>
#include <limits>
#include <memory>
#include <vector>

#include "define.hpp"
#include "string_conversions/moves.hpp"

#include "pokemon.hpp"

class Team{
public:
    Team();
    Team(std::array<Pokemon, 6> pokemon);
    ~Team();
    int teamsize;
    std::string team;
    int get_boost(Statname stat);
    void get_move_options(std::array<Move, 3> impmoves);
    bool taunt_move(const Move move);
    void set_boost(Statname stat, int boost);
    void set_confusion();
    void swap(int slot);
    void init();

    void use_hp_berry();
    void use_pinch_berry();
    // if a pokemon is below 25% health, some berries will activate
    // at the end of turn
    AttackMove* movechoice;
    AttackMove* prev_movechoice;
    AttackMove* disabled_move;
    std::array<AttackMove, 6> switches;
    std::vector<AttackMove*> move_options;
/// TRANSFORM / BIDE / METRONOME / MIRRORMOVE
    std::array<Pokemon, 6> member;
    int active_pokemon = 0;     // index of currently active pokemon
    Pokemon* active();

    friend std::ostream& operator<<(std::ostream& out, Team& team);
    ///
    /// one turn
    ///
    std::array<Move, 3> imprison_moves;
    bool imprison = false;
    bool meanlook = false;
    bool charged = false; // charge moves (solarbeam, fly,...)
    bool endure = false;
    bool flinch = false;
    bool focuspunch = false;
    bool grudge = false;
    bool magiccoat = false;
    bool protect = false;
    bool torment = false;
    bool truant = false;
    int safeguard = 0;
    int wrap = 0;
    int lastdamage = 0;
    int protect_acc = 100;
    int delayed_damage = 0;
    int delayed_damage_turns = 0;
    bool special_calc = false;
    int special_damage_calc = 0;
    ///
    /// static
    ///
    bool sleep_inflict = false;
    int spikes = 0;
    int wish = 0;
    int wish_recovery = 0;
    ///
    /// reset on switch
    ///
    int atkboost = 0;
    int defboost = 0;
    int satkboost = 0;
    int sdefboost = 0;
    int speboost = 0;
    int accboost = 0;
    int evaboost = 0; // evasion
    bool flash_fire = false;
    
    int confusion = 0;
    int encore = 0;
    int lightscreen = 0;
    int lockon = 0;
    int perishsong = 0;
    int recharge = 0;
    int reflect = 0;
    int selflock = 0; // outrage, petaldance, thrash
    int taunt = 0;
    int turns_on_the_field = 0;
    int uproar = 0;
    int yawn = false;  

    AttackMove* locked_move;
    bool move_locked = false;
    bool block = false;
    bool charge = false;
    bool curse = false;
    bool foresight = false;
    bool infatuated = false;
    bool ingrain = false;
    bool leechseed = false;
    bool mist = false;
    bool targetable = true; // bounce, dig, etc.
    bool trapped = false;
};