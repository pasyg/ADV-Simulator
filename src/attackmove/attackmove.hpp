#pragma once

#include <cstdint>

#include "data/category.hpp"
#include "data/moves.hpp"
#include "data/type.hpp"
// add movename
class AttackMove{
    
public:
    AttackMove();
    ~AttackMove();

    void set_STAB(const bool STAB);
    void set_revealed(const bool revealed);
    void set_pp(const int pp);
    void set_type(const Type type);
    void reduce_pp(const int x);
    void set_priority(const int prio);
    void set_move(const Move move);
    void set_category(const Category category);

    int get_power() const;
    bool get_STAB() const;
    bool get_revealed() const;
    int get_pp() const;
    Type get_type() const;
    int get_priority() const;
    Move get_move() const;
    Category get_category() const;


private:
    int priority;
    bool revealed = false;
    bool damage = false;
    bool secondary = false;
    #ifndef OHKO_CLAUSE
    bool ohko = false;
    #endif
    bool is_STAB = false;
    Move move;
    int pp = 0;
    Type type;
    Category category;
};