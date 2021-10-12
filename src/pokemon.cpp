#include "pokemon.hpp"

Pokemon::Pokemon(){

}

Pokemon::~Pokemon(){
    
}

Stats Pokemon::get_stats(){
    return this->stats;
}
///
/// relevant in battles
///
void Pokemon::set_status(Status p_status){
    this->status = p_status;
}

void Pokemon::set_revealed(bool p_revealed){
    this->revealed = revealed;
}

void Pokemon::remove_item(){
    this->item = Item::none;
}

void Pokemon::set_item(Item p_item){
    this->item = p_item;    
}

Item Pokemon::get_item(){
    return this->item;
}

bool Pokemon::get_revealed(){
    return this->revealed;
}

Status Pokemon::get_status(){
    return this->status;
}

Ability Pokemon::get_ability(){
    return this->ability;
}

Nature Pokemon::get_nature(){
    return this->nature;
}

Species Pokemon::get_species(){
    return this->species;
}

std::array<AttackMove, 4> Pokemon::get_moveset(){
    return this->moveset;
}

std::array<Type, 2> Pokemon::get_type(){
    return this->type;
}

int Pokemon::get_level(){
    return this->level;
}

Gender Pokemon::get_gender(){
    return this->gender;
}

int Pokemon::get_happiness(){
    return this->happiness;
}

int Pokemon::get_hiddenpower_power(){
    return this->hiddenpower_power;
}

Type Pokemon::get_hiddenpower_type(){
    return this->hiddenpower;
}
///
/// initilization relevant
///
void Pokemon::set_ability(Ability p_ability){
    this->ability = p_ability;
}

void Pokemon::set_basestats(Stats p_stats){
    this->basestats.hp = p_stats.hp;
    this->basestats.atk = p_stats.atk;
    this->basestats.def = p_stats.def;
    this->basestats.satk = p_stats.satk;
    this->basestats.sdef = p_stats.sdef;
    this->basestats.spe = p_stats.spe;
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

void Pokemon::set_gender(Gender p_gender){
    this->gender = p_gender;
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
    
    this->calc_hiddenpower_power();
    this->calc_hiddenpower_type();
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
    this->stats.hp += this->level + 10;
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
///
/// determinies the power of hidden power by summing up
/// differently weighted IV LSBs and normalizing between 30-70
///
void Pokemon::calc_hiddenpower_power(){
    int sum = 0;

    if(this->IVs.hp % 2 != 0){
        sum += 1;
    }

    if(this->IVs.atk % 2 != 0){
        sum += 2;
    }

    if(this->IVs.def % 2 != 0){
        sum += 4;
    }

    if(this->IVs.spe % 2 != 0){
        sum += 8;
    }

    if(this->IVs.satk % 2 != 0){
        sum += 16;
    }

    if(this->IVs.sdef % 2 != 0){
        sum += 32;
    }

    sum *= 40;
    sum = static_cast<int>(sum / 63);
    this->hiddenpower_power = sum + 30;
}
///
/// determines the type of hidden power by summing up 
/// differently weighted IV LSBs and normalizing between 
/// 0-15 to pick from a simple table
///
void Pokemon::calc_hiddenpower_type(){

    int sum = 0;

    if(this->IVs.hp % 2 != 0){
        sum += 1;
    }

    if(this->IVs.atk % 2 != 0){
        sum += 2;
    }

    if(this->IVs.def % 2 != 0){
        sum += 4;
    }

    if(this->IVs.spe % 2 != 0){
        sum += 8;
    }

    if(this->IVs.satk % 2 != 0){
        sum += 16;
    }

    if(this->IVs.sdef % 2 != 0){
        sum += 32;
    }
    
    sum *= 5;
    sum = static_cast<int>(sum / 21);

    switch (sum)
    {
    case 0: this->hiddenpower = Type::Fighting;
        break;
    case 1: this->hiddenpower = Type::Flying;
        break;
    case 2: this->hiddenpower = Type::Poison;
        break;
    case 3: this->hiddenpower = Type::Ground;
        break;
    case 4: this->hiddenpower = Type::Rock;
        break;
    case 5: this->hiddenpower = Type::Bug;
        break;
    case 6: this->hiddenpower = Type::Ghost;
        break;
    case 7: this->hiddenpower = Type::Steel;
        break;
    case 8: this->hiddenpower = Type::Fire;
        break;
    case 9: this->hiddenpower = Type::Water;
        break;
    case 10: this->hiddenpower = Type::Grass;
        break;
    case 11: this->hiddenpower = Type::Electric;
        break;
    case 12: this->hiddenpower = Type::Psychic;
        break;
    case 13: this->hiddenpower = Type::Ice;
        break;
    case 14: this->hiddenpower = Type::Dragon;
        break;
    case 15: this->hiddenpower = Type::Dark;
        break;
    default: std::cout << "ERROR HIDDEN POWER TYPE" << std::endl;
        break;
    }
}
