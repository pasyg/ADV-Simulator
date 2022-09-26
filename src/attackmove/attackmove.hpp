#pragma once

#include <cstdint>

#include "data/movecategory.hpp"
#include "data/moves.hpp"
#include "data/type.hpp"

class AttackMove
{
public:
    AttackMove();
    constexpr AttackMove(Move move) : 
        move(move)
        {
        };
    
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

    Move get_move();
    Type get_type() const;
    int get_power() const;
    int get_pp() const;
    int get_priority() const;
    bool get_disabled() const;
    bool get_revealed() const;
    bool get_stab() const;

    bool operator== (const Move _move);
    bool operator!= (const Move _move);
    bool operator== (const Type _type);
    bool operator!= (const Type _type);

//private:
    using MC = MoveCategory;
    Move move;
    Type type       = Type::Typeless;
    MC category     = MC::Physical;
    int base_pp     = 0;
    int power       = 0;
    int pp          = 0;
    int priority    = 0;
    bool damage     = false;
    bool disabled   = false;
    bool is_stab    = false;
    bool revealed   = false;
    bool secondary  = false;
};