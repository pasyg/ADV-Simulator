#include "battle.hpp"


int Battle::item_ability_mult(int damage, const AttackMove &movechoice, const Pokemon &atkmon, const Pokemon &defmon){
    
    const Type movetype = movechoice.get_type();
    const Item item = atkmon.get_item();

    // specific for Shedinja, not compatible with illegal combination
    if(defmon.get_ability() == Ability::Wonder_Guard){
        switch(movetype){
            case Type::Fire:
            case Type::Flying:
            case Type::Rock:
            case Type::Ghost:
            case Type::Dark:
                return 0;
            default:
                return damage * 2;
        }
    }

    if(atkmon.get_item_damage_boost()){
        if(movechoice.get_category() == Category::Physical){

            if((item == Item::Blackbelt) && (movetype == Type::Fighting)){
                return static_cast<int>(damage * 1.1);
            }
            if((item == Item::Sharpbeak) && (movetype == Type::Flying)){
                return static_cast<int>(damage * 1.1);
            }
            if((item == Item::Metalcoat) && (movetype == Type::Steel)){
                return static_cast<int>(damage * 1.1);
            }
            if((item == Item::Poisonbarb) && (movetype == Type::Poison)){
                return static_cast<int>(damage * 1.1);
            }
            if((item == Item::Softsand) && (movetype == Type::Ground)){
                return static_cast<int>(damage * 1.1);
            }
            if((item == Item::Silkscarf) && (movetype == Type::Normal)){
                return static_cast<int>(damage * 1.1);
            }
            if((item == Item::Spelltag) && (movetype == Type::Ghost)){
                return static_cast<int>(damage * 1.1);
            }
            if((item == Item::Hardstone) && (movetype == Type::Rock)){
                return static_cast<int>(damage * 1.1);
            }
            if((item == Item::Silverpowder) && (movetype == Type::Bug)){
                return static_cast<int>(damage * 1.1);
            }
    }
    if(movechoice.get_category() == Category::Special){
        if((item == Item::Blackglasses) && (movetype == Type::Dark)){
            return static_cast<int>(damage * 1.1);
        }
        if((item == Item::Charcoal) && (movetype == Type::Fire)){
            return static_cast<int>(damage * 1.1);
        }
        if((item == Item::Magnet) && (movetype == Type::Electric)){
            return static_cast<int>(damage * 1.1);
        }
        if((item == Item::Dragonfang) && (movetype == Type::Dragon)){
            return static_cast<int>(damage * 1.1);
        }
        if((item == Item::Miracleseed) && (movetype == Type::Grass)){
            return static_cast<int>(damage * 1.1);
        }
        if((item == Item::Mysticwater) && (movetype == Type::Water)){
            return static_cast<int>(damage * 1.1);
        }
        if((item == Item::Seaincense) && (movetype == Type::Water)){
            return static_cast<int>(damage * 1.05);
        }
        if((item == Item::Nevermeltice) && (movetype == Type::Ice)){
            return static_cast<int>(damage * 1.1);
        }
        if((item == Item::Twistedspoon) && (movetype == Type::Psychic)){
            return static_cast<int>(damage * 1.1);
        }
        if(defmon.get_ability() == Ability::Thick_Fat){
            if((movetype == Type::Fire) || 
                (movetype == Type::Ice)){
                    return static_cast<int>(damage / 2.0);
                }
            }
        }
    }
    return damage;
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
        atkteam = this->team[0];
        defteam = this->team[1];
    }
    else{
        atkteam = this->team[1];
        defteam = this->team[0];
    }

    if(atkteam->movechoice->get_category() == Category::Status){
    #ifdef _DEBUG
        debug_log("ERROR CATEGORY DAMAGE CALC battle.cpp");
    #endif
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
    if(atkteam->movechoice->get_category() == Category::Physical){
        attack = Statname::Atk;
        defense = Statname::Def;
        
        // Initialize attack value with boost
        atk_stat = get_stat_boosted(attack, *atkmon, atkteam->get_boost(attack));
        def_stat = get_stat_boosted(defense, *defmon, defteam->get_boost(defense));
        
        // attack boost abilities / items
        if(atkmon->get_item() == Item::Choiceband){
            atk_stat = static_cast<int>(atk_stat * 1.5);
        }
        if((atkmon->get_ability() == Ability::Huge_Power) || 
           (atkmon->get_ability() == Ability::Pure_Power)){
            atk_stat *= 2;
        }
        else if(atkmon->get_ability() == Ability::Guts){
            if(atkmon->get_status() != Status::Healthy){
                atk_stat *= 2;
            }
        }
        else if(atkmon->get_item() == Item::Thickclub){
            if((atkmon->get_species() == Species::Marowak) || 
               (atkmon->get_species() == Species::Cubone)){
                atk_stat *= 2;
            }
        }
        if(atkmon->get_status() == Status::Burn){
            if(atkmon->get_ability() != Ability::Guts){
                burn = 2;
            }
        }
    }
    else if(atkteam->movechoice->get_category() == Category::Special){
        attack = Statname::Satk;
        defense = Statname::Sdef;
        // Initialize attack value with boost
        atk_stat = get_stat_boosted(attack, *atkmon, atkteam->get_boost(attack));
        def_stat = get_stat_boosted(defense, *defmon, defteam->get_boost(defense));
    }
    else{
        return 0;
    }

    // basic damage formula from: https://bulbapedia.bulbagarden.net/wiki/Damage
    damage = 2 * atkmon->get_level();
    damage = static_cast<int>(damage / 5.0);
    damage += 2;
    damage *= atkteam->movechoice->get_power();

    // Critical Hit / Ignore positive defensive boost
    if(get_random(0,15) == 0){
        if(defteam->defboost >= 0){
            damage = static_cast<int>((damage * get_stat_boosted(attack, *atkmon, atkteam->get_boost(attack)
                                       / static_cast<float>(def_stat * 50.0))));
            damage *= 2;
        }
        else{
            damage = static_cast<int>((damage * get_stat_boosted(attack, *atkmon, atkteam->get_boost(attack) 
                                      / static_cast<float>(get_stat_boosted(defense, *defmon, defteam->get_boost(defense)) * 50.0))));
            damage *= 2;
        }
    }
    // No Critical Hit
    else{
    damage = static_cast<int>(damage * get_stat_boosted(attack, *atkmon, atkteam->get_boost(attack)) 
                              / static_cast<float>((get_stat_boosted(defense, *defmon, defteam->get_boost(defense)) * 50.0)));
    }

    damage += 2;

    // same type attack bonus
    if(atkteam->movechoice->get_stab()){
        damage = static_cast<int>(damage * 1.5);
    }

    ///
    /// WEATHER / TYPE EFFECTIVENESS
    ///

    // Weather effects
    if(this->weather == Weather::Rain){
        if(atkteam->movechoice->get_type() == Type::Water){
            damage = static_cast<int>(damage * 1.5);
        }
        if(atkteam->movechoice->get_type() == Type::Fire){
            damage = static_cast<int>(damage / 2.0);
        }
    }
    if(this->weather == Weather::Sun){
        if(atkteam->movechoice->get_type() == Type::Fire){
            damage = static_cast<int>(damage * 1.5);
        }
        if(atkteam->movechoice->get_type() == Type::Water){
            damage = static_cast<int>(damage / 2.0);
        }
    }

    // Item effects
    // outsource / earlier termination
    
    damage = static_cast<int>((effectiveness(atkteam->movechoice->get_type(), defmon->get_type()[0]) *
                                effectiveness(atkteam->movechoice->get_type(), defmon->get_type()[1]))
                                * damage);

    // Damage Roll
    damage = static_cast<int>((get_random(85,100) * damage) / 100.0);

    return damage;
}