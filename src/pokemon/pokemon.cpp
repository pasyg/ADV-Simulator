#include "pokemon.hpp"

void Pokemon::kill()
{
    this->set_current_hp(0);
    this->status = Status::Fainted;
}

// full initilization to prepare for start of a battle
// puts team always in the same defined state
void Pokemon::init()
{
    // stat calculation and initilization
    PokemonType p_type  = pokemon_type(this->species);
    this->type[0]       = p_type.type1;
    this->type[1]       = p_type.type2;
    
    this->basestats     = base_stats(this->species);
    this->current_hp    = this->stats.hp;
    this->stat_init();

    // initialize each move
    for(auto&& move : this->moveset)
    {
        if(move.get_move() != Move::None)
        {
            move.init();
        }
    }

    // sets STAB trait for same type attacks
    // assigns the type and power of hidden power
    for(auto&& move : this->moveset)
    {    
        if(move.get_type() == Type::Hidden_Power)
        {
            move.set_type(this->hiddenpower);
            move.set_power(this->hiddenpower_power);
        }
        if(this->type[0] == move.get_type())
        {
            move.set_stab(true);
        }
        else if(this->type[0] == move.get_type())
        {        
                move.set_stab(true);
        }
    }
    this->status = Status::Healthy;
    this->revealed = false;
    this->former_ability = this->ability;
}

Stats Pokemon::get_stats() const
{
    return this->stats;
}

///
/// relevant in battles
///

int Pokemon::get_current_hp()
{
    return this->current_hp;    
}

void Pokemon::set_current_hp(int hp)
{
    this->current_hp = hp;
}

int Pokemon::hp_percentage()
{
    return (this->current_hp * 100) / this->stats.hp;
}

void Pokemon::set_status(const Status p_status)
{
    if(p_status == Status::Sleep_inflicted)
    {
        this->sleep_turns = get_random(2,5); // TODO
    }
    this->status = p_status;
}

void Pokemon::set_revealed(const bool p_revealed)
{
    this->revealed = revealed;
}

void Pokemon::remove_item()
{
    this->item = Item::None;
}

void Pokemon::set_item(const Item p_item)
{
    this->item = p_item;    
}

Stats Pokemon::get_evs() const
{
    return this->EVs;
}

Stats Pokemon::get_ivs() const
{
    return this->IVs;
}

int Pokemon::get_stat(const Statname stat) const
{
    switch(stat)
    {
        case Statname::HP:
            return this->stats.hp;
        case Statname::Atk:
            return this->stats.atk;
        case Statname::Def:
            return this->stats.def;
        case Statname::Satk:
            return this->stats.satk;
        case Statname::Sdef:
            return this->stats.sdef;
        case Statname::Spe:
            return this->stats.spe;
        default:
            std::cout << "ERROR GET_STAT pokemon.cpp" << std::endl;
            return 0;
    }
}

void Pokemon::set_former_ability(Ability fability)
{
    this->former_ability = fability;
}

void Pokemon::create_substitute()
{
    if(this->current_hp >= static_cast<int>(this->stats.hp / 4.0))
    {
        this->substitute = true;
        substitute_hp = static_cast<int>(this->stats.hp / 4.0);
    }
}
void Pokemon::reduce_hp_direct(const int damage)
{
    this->current_hp -= damage;
    
    if(this->current_hp <= 0)
    {
        this->kill();
    }
}

void Pokemon::reduce_hp_attack(const int damage)
{
    if(this->substitute)
    {
        this->substitute_hp -= damage;
        if(this->substitute_hp <= 0)
        {
            this->substitute = false;
            this->substitute_hp = 0;
        }
    }
    else
    {
        this->current_hp -= damage;
    }
    if(this->current_hp <= 0)
    {
        this->kill();
    }
}

void Pokemon::increase_hp(const int heal)
{
    this->current_hp += heal;

    if(this->current_hp >= this->stats.hp)
    {
        this->current_hp = this->stats.hp;
    }
}

Item Pokemon::get_item() const
{
    return this->item;
}

bool Pokemon::get_revealed() const
{
    return this->revealed;
}

Status Pokemon::get_status() const
{
    return this->status;
}

Ability Pokemon::get_ability() const
{
    return this->ability;
}

Nature Pokemon::get_nature() const
{
    return this->nature;
}

Species Pokemon::get_species() const
{
    return this->species;
}

std::array<AttackMove, 4>* Pokemon::get_moveset()
{
    return &this->moveset;
}

std::array<Type, 2> Pokemon::get_type() const
{
    return this->type;
}

int Pokemon::get_level() const
{
    return this->level;
}

Gender Pokemon::get_gender() const
{
    return this->gender;
}

int Pokemon::get_happiness() const
{
    return this->happiness;
}

int Pokemon::get_hiddenpower_power() const
{
    return this->hiddenpower_power;
}

Type Pokemon::get_hiddenpower_type() const
{
    return this->hiddenpower;
}

void Pokemon::set_sub(bool sub)
{
    this->substitute = sub;
}

void Pokemon::set_sub_hp(int subhp)
{
    this->substitute_hp = subhp;
}

///
/// initilization relevant
///
void Pokemon::set_evs(const Stats stats)
{
    this->EVs = stats;
}

void Pokemon::set_ivs(const Stats stats)
{
    this->IVs = stats;
}

void Pokemon::set_ability(const Ability p_ability)
{
    this->ability = p_ability;
}

void Pokemon::set_basestats(const Stats p_stats)
{
    this->basestats.hp = p_stats.hp;
    this->basestats.atk = p_stats.atk;
    this->basestats.def = p_stats.def;
    this->basestats.satk = p_stats.satk;
    this->basestats.sdef = p_stats.sdef;
    this->basestats.spe = p_stats.spe;
}

void Pokemon::set_nature(const Nature p_nature)
{
    this->nature = p_nature;
}

void Pokemon::set_species(const Species p_species)
{
    this->species = p_species;
}

void Pokemon::set_moveset(const std::array<AttackMove, 4> p_moveset)
{
    this->moveset = p_moveset;
}

void Pokemon::set_type(const std::array<Type, 2> p_type)
{
    this->type = p_type;
}

void Pokemon::set_level(const int p_level)
{
    this->level = p_level;
}

void Pokemon::set_gender(const Gender p_gender)
{
    this->gender = p_gender;
}

void Pokemon::set_happiness(const int p_happiness)
{
    this->happiness = p_happiness;
}

void Pokemon::set_hiddenpower(const Type p_type, const int p_power)
{
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

int Pokemon::pos_nature(const int stat)
{
    return static_cast<int>(stat * 1.1f);
}

int Pokemon::neg_nature(const int stat)
{
    return static_cast<int>(stat * 0.9f);
}

void Pokemon::stat_init()
{
    this->calc_hp();
    this->calc_atk();
    this->calc_def();
    this->calc_satk();
    this->calc_sdef();
    this->calc_spe();

    switch (this->nature)
    {
    case Nature::Adamant:
    this->stats.atk = pos_nature(this->stats.atk);
    this->stats.satk = neg_nature(this->stats.satk);
        break;
    case Nature::Bold:
    this->stats.def = pos_nature(this->stats.def);
    this->stats.atk = neg_nature(this->stats.atk);
        break;
    case Nature::Brave:
    this->stats.atk = pos_nature(this->stats.atk);
    this->stats.spe = neg_nature(this->stats.spe);
        break;
    case Nature::Calm:
    this->stats.sdef = pos_nature(this->stats.sdef);
    this->stats.atk = neg_nature(this->stats.atk);
        break;
    case Nature::Careful:
    this->stats.sdef = pos_nature(this->stats.sdef);
    this->stats.satk = neg_nature(this->stats.satk);
        break;
    case Nature::Gentle:
    this->stats.sdef = pos_nature(this->stats.sdef);
    this->stats.def = neg_nature(this->stats.def);
        break;
    case Nature::Hasty:
    this->stats.spe = pos_nature(this->stats.spe);
    this->stats.def = neg_nature(this->stats.def);
        break;
    case Nature::Impish:
    this->stats.def = pos_nature(this->stats.def);
    this->stats.satk = neg_nature(this->stats.satk);
        break;
    case Nature::Jolly:
    this->stats.spe = pos_nature(this->stats.spe);
    this->stats.satk = neg_nature(this->stats.satk);
        break;
    case Nature::Lax:
    this->stats.def = pos_nature(this->stats.def);
    this->stats.sdef = neg_nature(this->stats.sdef);
        break;
    case Nature::Lonely:
    this->stats.atk = pos_nature(this->stats.atk);
    this->stats.def = neg_nature(this->stats.def);
        break;
    case Nature::Mild:
    this->stats.satk = pos_nature(this->stats.satk);
    this->stats.def = neg_nature(this->stats.def);
        break;
    case Nature::Modest:
    this->stats.satk = pos_nature(this->stats.satk);
    this->stats.atk = neg_nature(this->stats.atk);
        break;
    case Nature::Naive:
    this->stats.spe = pos_nature(this->stats.spe);
    this->stats.sdef = neg_nature(this->stats.sdef);
        break;
    case Nature::Naughty:
    this->stats.atk = pos_nature(this->stats.atk);
    this->stats.sdef = neg_nature(this->stats.sdef);
        break;
    case Nature::Quiet:
    this->stats.satk = pos_nature(this->stats.satk);
    this->stats.spe = neg_nature(this->stats.spe);
        break;
    case Nature::Rash:
    this->stats.satk = pos_nature(this->stats.satk);
    this->stats.sdef = neg_nature(this->stats.sdef);
        break;
    case Nature::Relaxed:
    this->stats.def = pos_nature(this->stats.def);
    this->stats.spe = neg_nature(this->stats.spe);
        break;
    case Nature::Sassy:
    this->stats.sdef = pos_nature(this->stats.sdef);
    this->stats.spe = neg_nature(this->stats.spe);
        break;
    case Nature::Timid:
    this->stats.spe = pos_nature(this->stats.spe);
    this->stats.atk = neg_nature(this->stats.atk);
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

void Pokemon::calc_hp()
{
    this->stats.hp = 2 * this->basestats.hp;
    this->stats.hp += this->IVs.hp;
    this->stats.hp += static_cast<int>(this->EVs.hp / 4.0);
    this->stats.hp *= this->level;
    this->stats.hp = static_cast<int>(this->stats.hp/100.0);
    this->stats.hp += this->level + 10;
}

void Pokemon::calc_atk()
{
    this->stats.atk = 2 * this->basestats.atk;
    this->stats.atk += this->IVs.atk;
    this->stats.atk += static_cast<int>(this->EVs.atk / 4.0);
    this->stats.atk *= this->level;
    this->stats.atk = static_cast<int>(this->stats.atk/100.0);
    this->stats.atk += 5;
}

void Pokemon::calc_def()
{
    this->stats.def = 2 * this->basestats.def;
    this->stats.def += this->IVs.def;
    this->stats.def += static_cast<int>(this->EVs.def / 4.0);
    this->stats.def *= this->level;
    this->stats.def = static_cast<int>(this->stats.def/100.0);
    this->stats.def += 5;
}

void Pokemon::calc_satk()
{
    this->stats.satk = 2 * this->basestats.satk;
    this->stats.satk += this->IVs.satk;
    this->stats.satk += static_cast<int>(this->EVs.satk / 4.0);
    this->stats.satk *= this->level;
    this->stats.satk = static_cast<int>(this->stats.satk/100.0);
    this->stats.satk += 5;
}

void Pokemon::calc_sdef()
{
    this->stats.sdef = 2 * this->basestats.sdef;
    this->stats.sdef += this->IVs.sdef;
    this->stats.sdef += static_cast<int>(this->EVs.sdef / 4.0);
    this->stats.sdef *= this->level;
    this->stats.sdef = static_cast<int>(this->stats.sdef/100.0);
    this->stats.sdef += 5;
}

void Pokemon::calc_spe()
{
    this->stats.spe = 2 * this->basestats.spe;
    this->stats.spe += this->IVs.spe;
    this->stats.spe += static_cast<int>(this->EVs.spe / 4.0);
    this->stats.spe *= this->level;
    this->stats.spe = static_cast<int>(this->stats.spe/100.0);
    this->stats.spe += 5;
}

///
/// calculate power of hidden power according to:
/// https://bulbapedia.bulbagarden.net/wiki/Hidden_Power_(move)/Calculation#Damage
///

void Pokemon::calc_hiddenpower_power()
{
    int sum = 0;

    if(this->IVs.hp % 4 == 2 ||
       this->IVs.hp % 4 == 3)
    {
        sum += 1;
    }
    if(this->IVs.atk % 4 == 2 ||
       this->IVs.atk % 4 == 3)
    {
        sum += 2;
    }
    if(this->IVs.def % 4 == 2 ||
       this->IVs.def % 4 == 3)
    {
        sum += 4;
    }
    if(this->IVs.spe % 4 == 2 ||
       this->IVs.spe % 4 == 3)
    {
        sum += 8;
    }
    if(this->IVs.satk % 4 == 2 ||
       this->IVs.satk % 4 == 3)
    {
        sum += 16;
    }
    if(this->IVs.sdef % 4 == 2 ||
       this->IVs.sdef % 4 == 3)
    {
        sum += 32;
    }

    sum *= 40;
    sum = static_cast<int>(sum / 63.0);
    this->hiddenpower_power = sum + 30;
}

///
/// determines the type of hidden power by summing up 
/// differently weighted IV LSBs and normalizing between 
/// 0-15 to pick from a simple table
///

void Pokemon::calc_hiddenpower_type()
{
    int sum = 0;

    if(this->IVs.hp % 2 != 0)
    {
        sum += 1;
    }
    if(this->IVs.atk % 2 != 0)
    {
        sum += 2;
    }
    if(this->IVs.def % 2 != 0)
    {
        sum += 4;
    }
    if(this->IVs.spe % 2 != 0)
    {
        sum += 8;
    }
    if(this->IVs.satk % 2 != 0)
    {
        sum += 16;
    }
    if(this->IVs.sdef % 2 != 0)
    {
        sum += 32;
    }
    
    sum *= 5;
    sum = static_cast<int>(sum / 21.0);

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

bool Pokemon::operator== (const Type _type)
{
    if(this->type[0] == _type || this->type[1] == _type)
    {
        return true;
    }
    return false;
}

bool Pokemon::operator!= (const Type _type)
{
    if(this->type[0] != _type && this->type[1] != _type)
    {
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, Pokemon& pokemon)
{
    out << "Species: "  << to_string(pokemon.get_species()) << "\n";
    out << "HP: "       << pokemon.current_hp << "/" << pokemon.get_stats().hp << " " << pokemon.hp_percentage() << "%\n";
    out << "Status: "   << to_string(pokemon.get_status()) << "\n";
    out << "Ability: "  << to_string(pokemon.get_ability()) << "\n";
    out << "EVs: "      << pokemon.get_evs().hp << " / "
                        << pokemon.get_evs().atk << " / "
                        << pokemon.get_evs().def << " / "
                        << pokemon.get_evs().satk << " / "
                        << pokemon.get_evs().sdef << " / "
                        << pokemon.get_evs().spe << "\n";

    out << "IVs: "      << pokemon.get_ivs().hp << " / "
                        << pokemon.get_ivs().atk << " / "
                        << pokemon.get_ivs().def << " / "
                        << pokemon.get_ivs().satk << " / "
                        << pokemon.get_ivs().sdef << " / "
                        << pokemon.get_ivs().spe << "\n"; 
                         
    out << "Nature: "   << to_string(pokemon.get_nature()) << "\n";
    out << "Move 1: "   << to_string(pokemon.moveset[0].get_move()) << "   " << pokemon.moveset[0].get_pp() << "\n";
    out << "Move 2: "   << to_string(pokemon.moveset[1].get_move()) << "   " << pokemon.moveset[1].get_pp() << "\n";
    out << "Move 3: "   << to_string(pokemon.moveset[2].get_move()) << "   " << pokemon.moveset[2].get_pp() << "\n";
    out << "Move 4: "   << to_string(pokemon.moveset[3].get_move()) << "   " << pokemon.moveset[3].get_pp() << "\n\n";

    return out;
}