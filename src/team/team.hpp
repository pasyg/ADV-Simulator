#include <array>
#include <vector>

#include "define.hpp"

#include "pokemon.hpp"

class Team{
public:
    Team();
    ~Team();
    void swap(int slot);
    void team_init();
    void get_move_options();
    void decide_move();
    int get_boost(Statname stat);
    void set_boost(Statname stat, int boost);
    void set_confusion();
    // if a pokemon is below 25% health, some berries will activate
    // at the end of turn
    void use_pinch_berry();
    void use_hp_berry();
    AttackMove* movechoice;
    std::array<AttackMove, 6> switches;
    std::vector<AttackMove> move_options;
/// TRANSFORM / BIDE / DOOMDESIRE / FUTURE SIGHT / IMPRISON / METRONOME / MIRRORMOVE
    std::array<Pokemon, 6> member;
    int active_pokemon = 0;     // index of currently active pokemon 
    ///
    /// one turn
    ///
    bool protect = false;
    int protect_acc = 100;
    bool flinch = false;
    bool focuspunch = false;
    bool magiccoat = false;
    bool endure = false;
    bool grudge = false;
    bool truant = false;
    int lastdamage = 0;
    ///
    /// static
    ///
    bool wish = false;
    int wish_recovery = 0;
    int spikes = 0;
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
    
    int reflect = 0;
    int lightscreen = 0;
    int perishsong = 0;
    int confusion = 0;
    
    bool trapped = false;
    bool move_locked = false;
    AttackMove locked_move;
    bool taunt = false;
    bool ingrain = false;
    bool yawn = false;
    bool infatuated = false;
    bool curse = false;
    bool leechseed = false;
    bool block = false;
    bool targetable = true; // bounce, dig, etc.
    bool charge = false;
    bool foresight = false;
    bool lockon = false;
    bool mist = false;
};