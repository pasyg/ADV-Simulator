#include "battle.hpp"
#include "rng.hpp"


int Battle::item_ability_mult(const int damage, const Pokemon &atkmon, const Pokemon &defmon){
    return 0;
}
int Battle::calculate_damage(const int patkteam){
    // Air Lock not implemented
    // Crits (shellarmor, scopelens, etc.)
    Team* atkteam;
    Team* defteam;

    Pokemon* atkmon;
    Pokemon* defmon;

    Statname attack;
    Statname defense;

    int atk_stat = 0;
    int def_stat = 0;

    int damage = 0;
    int burn = 1;

    // choose correct attacking and defending side
    if(patkteam == 0){
        atkteam = &this->team1;
        defteam = &this->team2;
    }
    else{
        atkteam = &this->team2;
        defteam = &this->team1;
    }

    if(atkteam->movechoice->get_category() == Category::status){
        std::cout << "ERROR CATEGORY DAMAGE CALC battle.cpp" << std::endl;
        return 0;
    }

    atkmon = &atkteam->member[atkteam->active_pokemon];
    defmon = &defteam->member[defteam->active_pokemon];

    //check for neutralizing abilities
    if((defmon->get_ability() == Ability::Volt_Absorb) && (atkteam->movechoice->get_type() == Type::Electric)){
        return 0;
    }
    if((defmon->get_ability() == Ability::Water_Absorb) && (atkteam->movechoice->get_type() == Type::Water)){
        return 0;
    }
    if((defmon->get_ability() == Ability::Flash_Fire) && (atkteam->movechoice->get_type() == Type::Fire)){
        return 0;
    }
    if((defmon->get_ability() == Ability::Levitate) && (atkteam->movechoice->get_type() == Type::Ground)){
        return 0;
    }

    // Check for physical / special
    if(atkteam->movechoice->get_category() == Category::physical){
        attack = Statname::atk;
        defense = Statname::def;
        
        // Initialize attack value with boost
        atk_stat = get_stat_boost(attack, *
        atkmon, atkteam->get_boost(attack));
        
        // attack boost abilities / items
        if(atkmon->get_item() == Item::choiceband){
            atk_stat = static_cast<int>(atk_stat * 1.5);
        }
        if((atkmon->get_ability() == Ability::Huge_Power) || 
           (atkmon->get_ability() == Ability::Pure_Power)){
            atk_stat *= 2;
        }
        else if(atkmon->get_ability() == Ability::Guts){
            if(atkmon->get_status() != Status::healthy){
                atk_stat *= 2;
            }
        }
        else if(atkmon->get_item() == Item::thickclub){
            if((atkmon->get_species() == Species::Marowak) || 
               (atkmon->get_species() == Species::Cubone)){
                atk_stat *= 2;
            }
        }
        if(atkmon->get_status() == Status::burn){
            if(atkmon->get_ability() != Ability::Guts){
                burn = 2;
            }
        }
    }
    else if(atkteam->movechoice->get_category() == Category::special){
        attack = Statname::satk;
        defense = Statname::sdef;
        // Initialize attack value with boost
        atk_stat = get_stat_boost(attack, *atkmon, atkteam->get_boost(attack));
    }
    else{
        return 0;
    }

    // basic damage formula from: https://bulbapedia.bulbagarden.net/wiki/Damage
    damage = 2 * atkmon->get_level();
    damage = static_cast<int>(damage / 5);
    damage += 2;
    damage *= atkteam->movechoice->get_power();
    damage *= 1;

    // Critical Hit / Ignore positive defensive boost
    if(get_random(0,15) > 0){
        if(defteam->defboost >= 0){
            damage = static_cast<int>(damage / def_stat);
            damage *= 2;
        }
        else{
            damage = static_cast<int>(damage / ((get_stat_boost(defense, *defmon, defteam->get_boost(defense)) * 50)));
            damage *= 2;
        }
    }
    // No Critical Hit
    else{
    damage = static_cast<int>(damage / ((get_stat_boost(defense, *defmon, defteam->get_boost(defense)) * 50)));
    }

    damage += 2;

    // STAB
    if(atkteam->movechoice->get_STAB()){
        damage = static_cast<int>(damage * 1.5);
    }

    ///
    /// WEATHER / TYPE EFFECTIVENESS
    ///

    // Weather effects
    if(this->weather == Weather::rain){
        if(atkteam->movechoice->get_type() == Type::Water){
            damage = static_cast<int>(damage * 1.5);
        }
        if(atkteam->movechoice->get_type() == Type::Fire){
            damage = static_cast<int>(damage / 2);
        }
    }
    if(this->weather == Weather::sun){
        if(atkteam->movechoice->get_type() == Type::Fire){
            damage = static_cast<int>(damage * 1.5);
        }
        if(atkteam->movechoice->get_type() == Type::Water){
            damage = static_cast<int>(damage / 2);
        }
    }

    // Item effects
    // outsource / earlier termination
    if(atkteam->movechoice->get_category() == Category::physical){
        if((atkmon->get_item() == Item::blackbelt) && (atkteam->movechoice->get_type() == Type::Fighting)){
            damage = static_cast<int>(damage * 1.1);
        }
        if((atkmon->get_item() == Item::sharpbeak) && (atkteam->movechoice->get_type() == Type::Flying)){
            damage = static_cast<int>(damage * 1.1);
        }
        if((atkmon->get_item() == Item::metalcoat) && (atkteam->movechoice->get_type() == Type::Steel)){
            damage = static_cast<int>(damage * 1.1);
        }
        if((atkmon->get_item() == Item::poisonbarb) && (atkteam->movechoice->get_type() == Type::Poison)){
            damage = static_cast<int>(damage * 1.1);
        }
        if((atkmon->get_item() == Item::softsand) && (atkteam->movechoice->get_type() == Type::Ground)){
            damage = static_cast<int>(damage * 1.1);
        }
        if((atkmon->get_item() == Item::silkscarf) && (atkteam->movechoice->get_type() == Type::Normal)){
            damage = static_cast<int>(damage * 1.1);
        }
        if((atkmon->get_item() == Item::spelltag) && (atkteam->movechoice->get_type() == Type::Ghost)){
            damage = static_cast<int>(damage * 1.1);
        }
        if((atkmon->get_item() == Item::hardstone) && (atkteam->movechoice->get_type() == Type::Rock)){
            damage = static_cast<int>(damage * 1.1);
        }
        if((atkmon->get_item() == Item::silverpowder) && (atkteam->movechoice->get_type() == Type::Bug)){
            damage = static_cast<int>(damage * 1.1);
        }
    }
    if(atkteam->movechoice->get_category() == Category::special){
        if((atkmon->get_item() == Item::blackglasses) && (atkteam->movechoice->get_type() == Type::Dark)){
            damage = static_cast<int>(damage * 1.1);
        }
        if((atkmon->get_item() == Item::charcoal) && (atkteam->movechoice->get_type() == Type::Fire)){
            damage = static_cast<int>(damage * 1.1);
        }
        if((atkmon->get_item() == Item::magnet) && (atkteam->movechoice->get_type() == Type::Electric)){
            damage = static_cast<int>(damage * 1.1);
        }
        if((atkmon->get_item() == Item::dragonfang) && (atkteam->movechoice->get_type() == Type::Dragon)){
            damage = static_cast<int>(damage * 1.1);
        }
        if((atkmon->get_item() == Item::miracleseed) && (atkteam->movechoice->get_type() == Type::Grass)){
            damage = static_cast<int>(damage * 1.1);
        }
        if((atkmon->get_item() == Item::mysticwater) && (atkteam->movechoice->get_type() == Type::Water)){
            damage = static_cast<int>(damage * 1.1);
        }
        if((atkmon->get_item() == Item::seaincense) && (atkteam->movechoice->get_type() == Type::Water)){
            damage = static_cast<int>(damage * 1.05);
        }
        if((atkmon->get_item() == Item::nevermeltice) && (atkteam->movechoice->get_type() == Type::Ice)){
            damage = static_cast<int>(damage * 1.1);
        }
        if((atkmon->get_item() == Item::twistedspoon) && (atkteam->movechoice->get_type() == Type::Psychic)){
            damage = static_cast<int>(damage * 1.1);
        }
        if(defmon->get_ability() == Ability::Thick_Fat){
            if((atkteam->movechoice->get_type() == Type::Fire) || 
                (atkteam->movechoice->get_type() == Type::Ice)){
                    damage = static_cast<int>(damage / 2);
                }
        }
    }

    damage *= static_cast<int>((effectiveness(atkteam->movechoice->get_type(), defmon->get_type()[0]) *
                                effectiveness(atkteam->movechoice->get_type(), defmon->get_type()[1])));

    // Damage Roll
    damage *= static_cast<int>((get_random(85,100) / 100) * damage);

    return damage;
}

int Battle::get_stat_boost(const Statname stat, const Pokemon &pokemon, const int boost){
    switch(stat){
        case Statname::atk:
        case Statname::def:
        case Statname::satk:
        case Statname::sdef:
        case Statname::spe:
            if(boost > 0){
                return static_cast<int>(pokemon.get_stat(stat) * (2 + boost) / 2);
            }
            if(boost < 0){
                return static_cast<int>(pokemon.get_stat(stat) * 2 / (2 + boost));
            }
        case Statname::acc:
        case Statname::eva:
            if(boost > 0){
                return static_cast<int>((3 + boost) / 3);
            }
            if(boost < 0){
                return static_cast<int>(3 / (3 + boost));
            }
            else{
                return 1;
            }
        default:
            return 0;
    }
}

///
/// compares the speed of two active pokemon and returns 0 (false), if team1 is faster, returns 1 (true) if team2 is faster
///
bool Battle::compare_speed(){

    Pokemon* mon1 = &this->team1.member[this->team1.active_pokemon];
    Pokemon* mon2 = &this->team1.member[this->team1.active_pokemon];

    int speed1 = get_stat_boost(Statname::spe, *mon1, this->team1.speboost);
    int speed2 = get_stat_boost(Statname::spe, *mon2, this->team2.speboost);

    //this->team1.speboost

    if(mon1->get_status() == Status::paralysis){
        static_cast<int>(speed1) /= 4;
    }
    if(mon2->get_status() == Status::paralysis){
        static_cast<int>(speed2) /= 4;
    }
    if(speed1 > speed2){
        return false;
    }
    if(speed1 < speed2){
        return true;
    }
    else{
        return get_random(0,1);
    }
}
///
/// checks which pokemon moves first, returns 0 (false) for first move for team 1, 1 (true) for first move for team 2
///
bool Battle::move_first(){
    if(moveprio(this->team1.movechoice->get_move()) > moveprio(team2.movechoice->get_move())){
        return false;
    }
    else if(moveprio(this->team1.movechoice->get_move()) < moveprio(team2.movechoice->get_move())){
        return true;
    }
    else{
        return compare_speed();
    }
}