#include "attackmove.hpp"

AttackMove::AttackMove(){

}

AttackMove::~AttackMove(){

}

void AttackMove::init(){
    this->pp =  move_pp(this->move);
    this->power = move_power(this->move);
    this->type = move_type(this->move);
    this->priority = move_prio(this->move);
    this->revealed = false;
    //this->secondary =
    this->disabled = false;
    // implement
    #ifndef OHKO_CLAUSE
    this->ohko = false;
    #endif
}

void AttackMove::set_power(const int power){
    this->power = power;
}

void AttackMove::set_move(const Move move){
    this->move = move;
}

Move AttackMove::get_move(){
    return this->move;
}

void AttackMove::set_stab(const bool stab){
    this->is_stab = stab;
}

bool AttackMove::get_stab() const{
    return this->is_stab;
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

int AttackMove::get_power() const{
    return move_power(this->move);
}

bool AttackMove::get_disabled() const{
    return this->disabled;
}