#pragma once

#include <cstdint>

#include "moves.hpp"
#include "type.hpp"
// add movename
class AttackMove{
    
public:
    AttackMove();
    ~AttackMove();
    void set_STAB(bool STAB);
    bool get_STAB();
    void set_revealed(bool revealed);
    bool get_revealed();
    void set_pp(int pp);
    int get_pp();
    void set_type(Type type);
    Type get_type();
    void reduce_pp(int x);

private:
    bool revealed = false;
    bool damage = false;
    bool secondary = false;
    #ifndef OHKO_CLAUSE
    bool ohko = false;
    #endif
    bool is_STAB = false;
    Move move;
    uint8_t pp = 0;
    Type type;
};