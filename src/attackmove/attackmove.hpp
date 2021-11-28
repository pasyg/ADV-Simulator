#pragma once

#include <cstdint>

#include "data/moves.hpp"
#include "data/type.hpp"

class AttackMove{
    
public:
    AttackMove();
    ~AttackMove();

    void init();

    void set_power(const int power);
    void set_stab(const bool STAB);
    void set_revealed(const bool revealed);
    void set_pp(const int pp);
    void set_type(const Type type);
    void reduce_pp(const int x);
    void set_priority(const int prio);
    void set_disabled(const bool disable);
    void set_move(const Move move);

    int get_power() const;
    bool get_stab() const;
    bool get_revealed() const;
    int get_pp() const;
    Type get_type() const;
    int get_priority() const;
    bool get_disabled() const;
    Move get_move();


private:
    Move move;
    int pp = 0;
    int power;
    Type type;
    int priority;
    bool revealed = false;
    bool damage = false;
    bool secondary = false;
    bool disabled = false;
    #ifndef OHKO_CLAUSE
    bool ohko = false;
    #endif
    bool is_stab = false;
};