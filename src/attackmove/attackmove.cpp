#include "attackmove.hpp"

AttackMove::AttackMove(){

}

AttackMove::~AttackMove(){

}

void AttackMove::set_move(Move move){
    this->move = move;
}

Move AttackMove::get_move(){
    return this->move;
}

void AttackMove::set_STAB(const bool STAB){
    this->is_STAB = STAB;
}

bool AttackMove::get_STAB() const{
    return this->is_STAB;
}

void AttackMove::set_revealed(const bool revealed){
    this->revealed = revealed;
}

bool AttackMove::get_revealed() const{
    return this->revealed;
}

void AttackMove::set_pp(const int pp){
    this->pp = pp;
}

int AttackMove::get_pp() const{
    return this->pp;
}

void AttackMove::set_type(const Type type){
    this->type = type;
}

Type AttackMove::get_type() const{
    return this->type;
}

void AttackMove::reduce_pp(const int x = 1){
    this->pp -= x;
}

int AttackMove::get_priority() const{
    return 0;
}

void AttackMove::set_priority(const int prio){
    this->priority = prio;    
}

void AttackMove::set_disabled(const bool disable){
    this->disabled = disable;
}

void AttackMove::set_category(const Category category){
    this->category = category;
}

Category AttackMove::get_category() const{
    return this->category;
}

int AttackMove::get_power() const{
    return movepower(this->move);
}

bool AttackMove::get_disabled() const{
    return this->disabled;
}