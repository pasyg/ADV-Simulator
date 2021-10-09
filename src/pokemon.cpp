#include "pokemon.hpp"

Pokemon::Pokemon(){

}

Pokemon::~Pokemon(){
    
}

///
/// battle relevant
///

void set_status(Status p_status){
    this->status = p_status;
}

void set_revealed(bool p_revealed){
    this->revealed = revealed;
}

///
/// intilization relevant
///
void Pokemon::set_ability(Ability p_ability){
    this->ability = p_ability;
}

void Pokemon::set_nature(Nature p_nature){
    this->nature = p_nature;
}

void Pokemon::set_species(Species p_species){
    this->species = p_species;
}

void Pokemon::set_moveset(std::array<AttackMove, 4> p_moveset){
    this->moveset = p_moveset;
}

void Pokemon::set_type(std::array<Type, 2> p_type){
    this->type = p_type;
}

void Pokemon::set_level(int p_level){
    this->level = p_level;
}

void Pokemon::set_happiness(int p_happiness){
    this->happiness = p_happiness;
}

void Pokemon::set_hiddenpower(Type p_type, int p_power){
    this->hiddenpower = p_type;
    this->hiddenpower_power = p_power;
}

///
/// calculates the pokemon objects stats from
/// base stats / EVs / IVs / nature
///
/// static_cast<int> is used to avoid compiler warnings 
/// for truncating the float values, like in the game
///

void Pokemon::stat_init(){
    this->calc_hp();
    this->calc_atk();
    this->calc_def();
    this->calc_satk();
    this->calc_sdef();
    this->calc_spe();

    switch (this->nature)
    {
    case Nature::adamant:
    this->stats.atk = static_cast<int>(this->stats.atk * 1.1f);
    this->stats.satk = static_cast<int>(this->stats.satk * 0.9f);
        break;
    case Nature::bold:
    this->stats.def = static_cast<int>(this->stats.def * 1.1f);
    this->stats.atk = static_cast<int>(this->stats.atk * 0.9f);
        break;
    case Nature::brave:
    this->stats.atk = static_cast<int>(this->stats.atk * 1.1f);
    this->stats.spe = static_cast<int>(this->stats.spe * 0.9f);
        break;
    case Nature::calm:
    this->stats.sdef = static_cast<int>(this->stats.sdef * 1.1f);
    this->stats.atk = static_cast<int>(this->stats.atk * 0.9f);
        break;
    case Nature::careful:
    this->stats.sdef = static_cast<int>(this->stats.sdef * 1.1f);
    this->stats.satk = static_cast<int>(this->stats.satk * 0.9f);
        break;
    case Nature::gentle:
    this->stats.sdef = static_cast<int>(this->stats.sdef * 1.1f);
    this->stats.def = static_cast<int>(this->stats.def * 0.9f);
        break;
    case Nature::hasty:
    this->stats.spe = static_cast<int>(this->stats.spe * 1.1f);
    this->stats.def = static_cast<int>(this->stats.def * 0.9f);
        break;
    case Nature::impish:
    this->stats.def = static_cast<int>(this->stats.def * 1.1f);
    this->stats.satk = static_cast<int>(this->stats.satk * 0.9f);
        break;
    case Nature::jolly:
    this->stats.spe = static_cast<int>(this->stats.spe * 1.1f);
    this->stats.satk = static_cast<int>(this->stats.satk * 0.9f);
        break;
    case Nature::lax:
    this->stats.def = static_cast<int>(this->stats.def * 1.1f);
    this->stats.sdef = static_cast<int>(this->stats.sdef * 0.9f);
        break;
    case Nature::lonely:
    this->stats.atk = static_cast<int>(this->stats.atk * 1.1f);
    this->stats.def = static_cast<int>(this->stats.def * 0.9f);
        break;
    case Nature::mild:
    this->stats.satk = static_cast<int>(this->stats.satk * 1.1f);
    this->stats.def = static_cast<int>(this->stats.def * 0.9f);
        break;
    case Nature::modest:
    this->stats.satk = static_cast<int>(this->stats.satk * 1.1f);
    this->stats.atk = static_cast<int>(this->stats.atk * 0.9f);
        break;
    case Nature::naive:
    this->stats.spe = static_cast<int>(this->stats.spe * 1.1f);
    this->stats.sdef = static_cast<int>(this->stats.sdef * 0.9f);
        break;
    case Nature::naughty:
    this->stats.atk = static_cast<int>(this->stats.atk * 1.1f);
    this->stats.sdef = static_cast<int>(this->stats.sdef * 0.9f);
        break;
    case Nature::quiet:
    this->stats.satk = static_cast<int>(this->stats.satk * 1.1f);
    this->stats.spe = static_cast<int>(this->stats.spe * 0.9f);
        break;
    case Nature::rash:
    this->stats.satk = static_cast<int>(this->stats.satk * 1.1f);
    this->stats.sdef = static_cast<int>(this->stats.sdef * 0.9f);
        break;
    case Nature::relaxed:
    this->stats.def = static_cast<int>(this->stats.def * 1.1f);
    this->stats.spe = static_cast<int>(this->stats.spe * 0.9f);
        break;
    case Nature::sassy:
    this->stats.sdef = static_cast<int>(this->stats.sdef * 1.1f);
    this->stats.spe = static_cast<int>(this->stats.spe * 0.9f);
        break;
    case Nature::timid:
    this->stats.spe = static_cast<int>(this->stats.spe * 1.1f);
    this->stats.atk = static_cast<int>(this->stats.atk * 0.9f);
        break;
    
    default:
        break;
    }
}

Stats Pokemon::get_stats(){
    return this->stats;
}

///
/// stat calculations for initilization
///

void Pokemon::calc_hp(){
    this->stats.hp = 2 * this->basestats.hp;
    this->stats.hp += this->IVs.hp;
    this->stats.hp += (this->EVs.hp / 4);
    this->stats.hp *= this->level;
    this->stats.hp /= 100;
    this->stats.hp += this->stats.hp + 10;
}

void Pokemon::calc_atk(){
    this->stats.atk = 2 * this->basestats.atk;
    this->stats.atk += this->IVs.atk;
    this->stats.atk += (this->EVs.atk / 4);
    this->stats.atk *= this->level;
    this->stats.atk /= 100;
    this->stats.atk += 5;
}

void Pokemon::calc_def(){
    this->stats.def = 2 * this->basestats.def;
    this->stats.def += this->IVs.def;
    this->stats.def += (this->EVs.def / 4);
    this->stats.def *= this->level;
    this->stats.def /= 100;
    this->stats.def += 5;
}

void Pokemon::calc_satk(){
    this->stats.satk = 2 * this->basestats.satk;
    this->stats.satk += this->IVs.satk;
    this->stats.satk += (this->EVs.satk / 4);
    this->stats.satk *= this->level;
    this->stats.satk /= 100;
    this->stats.satk += 5;
}

void Pokemon::calc_sdef(){
    this->stats.sdef = 2 * this->basestats.sdef;
    this->stats.sdef += this->IVs.sdef;
    this->stats.sdef += (this->EVs.sdef / 4);
    this->stats.sdef *= this->level;
    this->stats.sdef /= 100;
    this->stats.sdef += 5;
}

void Pokemon::calc_spe(){
    this->stats.spe = 2 * this->basestats.spe;
    this->stats.spe += this->IVs.spe;
    this->stats.spe += (this->EVs.spe / 4);
    this->stats.spe *= this->level;
    this->stats.spe /= 100;
    this->stats.spe += 5;
}