#include "battle.hpp"


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
    double other = 1;

    // choose correct attacking and defending side
    if(patkteam == 0){
        atkteam = this->team[0];
        defteam = this->team[1];
    }
    else{
        atkteam = this->team[1];
        defteam = this->team[0];
    }

    atkmon = &atkteam->member[atkteam->active_pokemon];
    defmon = &defteam->member[defteam->active_pokemon];
    
    // just for shedinja
    if(defmon->get_ability() == Ability::Wonder_Guard){
        switch(atkteam->movechoice->get_type()){
        case Type::Dark:
        case Type::Fire:
        case Type::Flying:
        case Type::Ghost:
        case Type::Rock:
            return 1;
        default:
            return 0;
        }
    }

    // type immunity, item type boost, weather boost
    switch(atkteam->movechoice->get_type()){
        case Type::Bug:
            if(atkmon->get_item() == Item::Silverpowder){
                other *= 1.1;
            }
            break;
        case Type::Dark:
            if(atkmon->get_item() == Item::Blackglasses){
                other *= 1.1;
            }
            break;
        case Type::Dragon:
            if(atkmon->get_item() == Item::Dragonfang){
                other *= 1.1;
            }
            break;
        case Type::Electric:
            if(defmon->get_ability() == Ability::Volt_Absorb){
                return 0;
            }
            if(atkmon->get_item() == Item::Magnet){
                other *= 1.1;
            }
            break;
        case Type::Fighting:
            if(atkmon->get_item() == Item::Blackbelt){
                other *= 1.1;
            }
            break;
        case Type::Fire:
            if(defmon->get_ability() == Ability::Flash_Fire){
                return 0;
            }
            if(atkmon->get_item() == Item::Charcoal){
                other *= 1.1;
            }
            if(this->weather == Weather::Sun){
                other *= 1.5;
            }
            if(this->weather == Weather::Rain){
                other /= 2.0;
            }
            break;
        case Type::Flying:
            if(atkmon->get_item() == Item::Sharpbeak){
                other *= 1.1;
            }
            break;
        case Type::Ghost:
            if(atkmon->get_item() == Item::Spelltag){
                other *= 1.1;
            }
            break;
        case Type::Grass:
            if(atkmon->get_item() == Item::Miracleseed){
                other *= 1.1;
            }
            break;
        case Type::Ground:
            if(defmon->get_ability() == Ability::Levitate){
                return 0;
            }
            if(atkmon->get_item() == Item::Softsand){
                other *= 1.1;
            }
            break;
        case Type::Ice:
            if(atkmon->get_item() == Item::Nevermeltice){
                other *= 1.1;
            }
            break;
        case Type::Normal:
            if(atkmon->get_item() == Item::Silkscarf){
                other *= 1.1;
            }
            break;
        case Type::Poison:
            if(atkmon->get_item() == Item::Poisonbarb){
                other *= 1.1;
            }
            break;
        case Type::Psychic:
            if(atkmon->get_item() == Item::Twistedspoon){
                other *= 1.1;
            }
            break;
        case Type::Rock:
            if(atkmon->get_item() == Item::Hardstone){
                other *= 1.1;
            }
            break;
        case Type::Steel:
            if(atkmon->get_item() == Item::Metalcoat){
                other *= 1.1;
            }
            break;
        case Type::Water:
            if(defmon->get_ability() == Ability::Water_Absorb){
                return 0;
            }
            if(atkmon->get_item() == Item::Mysticwater){
                other *= 1.1;
            }
            else if(atkmon->get_item() == Item::Seaincense){
                other *= 1.05;
            }
            if(this->weather == Weather::Rain){
                other *= 1.5;
            }
            if(this->weather == Weather::Sun){
                other /= 2.0;
            }
            break;
    }
    
    other *= effectiveness(atkteam->movechoice->get_type(), defmon->get_type()[0]);
    other *= effectiveness(atkteam->movechoice->get_type(), defmon->get_type()[1]);

    switch(atkteam->movechoice->get_type()){
        case Type::Bug:
        case Type::Fighting:
        case Type::Flying:
        case Type::Ghost:
        case Type::Ground:
        case Type::Normal:
        case Type::Poison:
        case Type::Rock:
        case Type::Steel:
            attack = Statname::Atk;
            defense = Statname::Def;

            // Initialize attack value with boost
            atk_stat = get_stat_boosted(attack, *atkmon, atkteam->get_boost(attack));
            def_stat = get_stat_boosted(defense, *defmon, defteam->get_boost(defense));
            // attack boost abilities / items
            switch (atkmon->get_item()){
                case Item::Choiceband:
                    atk_stat = static_cast<int>(atk_stat * 1.5);
                    break;
                //case Item::Deepseascale:
                //case Item::Deepseatooth:
                //case Item::Lightball:
                //case Item::Luckypunch:
                //case Item::Metalpowder:
                //case Item::Souldew:
                //case Item::Stick:
                case Item::Thickclub:
                    if(atkmon->get_species() == Species::Marowak){
                        atk_stat *= 2;
                    }
                    break;
                    if(atkmon->get_species() == Species::Cubone){
                        atk_stat *= 2;
                    }
                default: break;
                }
        default:
            attack = Statname::Satk;
            defense = Statname::Sdef;
            // Initialize attack value with boost
            atk_stat = get_stat_boosted(attack, *atkmon, atkteam->get_boost(attack));
            def_stat = get_stat_boosted(defense, *defmon, defteam->get_boost(defense));

    }
    // Check for physical / special
    if(0){
        if((atkmon->get_ability() == Ability::Huge_Power) || 
           (atkmon->get_ability() == Ability::Pure_Power)){
            atk_stat *= 2;
        }
        else if(atkmon->get_ability() == Ability::Guts){
            if(atkmon->get_status() != Status::Healthy){
                atk_stat *= 2;
            }
        }
        if(atkmon->get_status() == Status::Burn){
            if(atkmon->get_ability() != Ability::Guts){
                burn = 2;
            }
        }
    }

    // basic damage formula from: https://bulbapedia.bulbagarden.net/wiki/Damage
    damage = 2 * atkmon->get_level();
    damage = static_cast<int>(damage / 5.0);
    damage += 2;
    damage *= atkteam->movechoice->get_power();

    // Critical Hit / Ignore positive defensive boost
    if(get_random(0,15) == 0){
        if(defteam->defboost >= 0){
            damage = static_cast<int>(damage * get_stat_boosted(attack, *atkmon, atkteam->get_boost(attack)
                                       / static_cast<float>(def_stat * 50.0)));
            damage *= 2;
        }
        else{
            damage = static_cast<int>(damage * get_stat_boosted(attack, *atkmon, atkteam->get_boost(attack) 
                                      / static_cast<float>(get_stat_boosted(defense, *defmon, defteam->get_boost(defense)) * 50.0)));
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

    // Damage Roll
    damage = static_cast<int>((get_random(85,100) * damage) / 100.0);

    return damage;
}