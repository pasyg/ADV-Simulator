#include "attackmove.hpp"
#include "constants.hpp"
#include "iostream"

AttackMove::AttackMove(){

}

AttackMove::~AttackMove(){

}

void AttackMove::init(){
    this->base_pp = static_cast<int>(move_pp(this->move) * (constants::pp_up * 0.2 + 1));
    this->pp = this->base_pp;
    this->power = move_power(this->move);
    this->type = move_type(this->move);
    this->priority = move_prio(this->move);
    this->revealed = false;
    //this->secondary =
    this->disabled = false;
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
    std::cout << this->pp << "\n";
    this->pp -= x;
    std::cout << this->pp << "\n";
    if(this->pp < 0){
        this->pp = 0;
    }
    std::cout << this->pp << "\n";
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

bool AttackMove::operator== (const Move _move){
    if(this->move == _move){
        return true;
    }
    return false;
}
bool AttackMove::operator!= (const Move _move){
    if(this->move != _move){
        return true;
    }
    return false;
}
bool AttackMove::operator== (const Type _type){
    if(this->type == _type){
        return true;
    }
    return false;
}
bool AttackMove::operator!= (const Type _type){
    if(this->type != _type){
        return true;
    }
    return false;
}