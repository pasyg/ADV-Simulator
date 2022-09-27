#include "attackmove.hpp"
#include "constants.hpp"
#include "iostream"

AttackMove::AttackMove()
{
}

void AttackMove::init()
{
    this->base_pp   = static_cast<int>(move_pp(this->move) * (constants::pp_up * 0.2 + 1));
    this->pp        = this->base_pp;
    this->power     = move_power(this->move);
    this->type      = move_type(this->move);
    this->priority  = move_prio(this->move);
    this->revealed  = false;
    this->disabled  = false;

    switch(this->type)
    {
        case Type::Bug:
        case Type::Fighting:
        case Type::Flying:
        case Type::Ghost:
        case Type::Ground:
        case Type::Hidden_Power:
        case Type::Normal:
        case Type::Poison:
        case Type::Rock:
        case Type::Steel:
        case Type::Typeless:
            this->category = MoveCategory::Physical;
            break;
        default:
            this->category = MoveCategory::Special;
    }
}

void AttackMove::set_power(const int power)
{
    this->power = power;
}

void AttackMove::set_move(const Move move)
{
    this->move = move;
}

Move AttackMove::get_move()
{
    return this->move;
}

void AttackMove::set_stab(const bool stab)
{
    this->is_stab = stab;
}

bool AttackMove::get_stab() const
{
    return this->is_stab;
}

void AttackMove::set_revealed(const bool revealed)
{
    this->revealed = revealed;
}

bool AttackMove::get_revealed() const
{
    return this->revealed;
}

void AttackMove::set_pp(const int pp)
{
    this->pp = pp;
}

int AttackMove::get_pp() const
{
    return this->pp;
}

void AttackMove::set_type(const Type type)
{
    this->type = type;
}

Type AttackMove::get_type() const
{
    return this->type;
}

void AttackMove::reduce_pp(const int x = 1)
{
    this->pp -= x;
    if(this->pp < 0)
    {
        this->pp = 0;
    }
}

int AttackMove::get_priority() const
{
    return 0;
}

void AttackMove::set_priority(const int prio)
{
    this->priority = prio;    
}

void AttackMove::set_disabled(const bool disable)
{
    this->disabled = disable;
}

int AttackMove::get_power() const
{
    return move_power(this->move);
}

bool AttackMove::get_disabled() const
{
    return this->disabled;
}

bool AttackMove::operator== (const Move _move)
{
    return this->move == _move;
}
bool AttackMove::operator!= (const Move _move)
{
    return this->move != _move;
}
bool AttackMove::operator== (const Type _type)
{
    return this->type == _type;
}
bool AttackMove::operator!= (const Type _type)
{
    return this->type != _type;
}