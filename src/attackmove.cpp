#include "attackmove.hpp"

AttackMove::AttackMove(){

}

AttackMove::~AttackMove(){

}

void AttackMove::set_STAB(bool STAB){
    this->is_STAB = STAB;
}

bool AttackMove::get_STAB(){
    return this->is_STAB;
}

void AttackMove::set_revealed(bool revealed){
    this->revealed = revealed;
}

bool AttackMove::get_revealed(){
    return this->revealed;
}

void AttackMove::set_pp(int pp){
    this->pp = pp;
}

int AttackMove::get_pp(){
    return this->pp;
}

void AttackMove::set_type(Type type){
    this->type = type;
}

Type AttackMove::get_type(){
    return this->type;
}

void AttackMove::reduce_pp(int x = 1){
    this->pp -= x;
}

int AttackMove::get_priority(){
    return 0;
}

void AttackMove::set_priority(int prio){
    this->priority = prio;    
}

int AttackMove::get_power(){
    return movepower(this->move);
}