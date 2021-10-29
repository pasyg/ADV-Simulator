#include <array>

#include "pokemon.hpp"

class Team{
public:
    void swap(int slot);
    Move movechoice;
    std::array<Move, 9> move_options;
/// TRANSFORM / BIDE / DOOMDESIRE / FUTURE SIGHT / IMPRISON / METRONOME / MIRRORMOVE
    std::array<Pokemon, 6> member;
    int active_pokemon = 0;  // index of currently active pokemon 
    ///
    /// one turn
    ///
    bool protect = false;
    int protect_acc = 0;
    bool flinch = false;
    bool focuspunch = false;
    bool magiccoat = false;
    bool endure = false;
    bool grudge = false;
    int lastdamage = 0;
    ///
    /// static
    ///
    bool wish = false;
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
    bool taunt = false;
    bool confusion = false;
    bool ingrain = false;
    bool yawn = false;
    bool infatuated = false;
    bool curse = false;
    bool disable = false;
    bool encore = false;
    Move encore_move = Move::None;
    bool leechseed = false;
    bool selflock = false;
    Move selflock_move = Move::None;
    bool choicelock = false;
    Move choicelock_move = Move::None;
    bool block = false;
    bool targetable = true; // bounce, dig, etc.
    bool charge = false;
    bool foresight = false;
    bool lockon = false;
    bool mist = false;
};