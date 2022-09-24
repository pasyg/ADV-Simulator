#include "battle.hpp"


int Battle::calculate_damage(Team &atkteam, Team &defteam)
{
    int damage        = 0;
    int atk_stat      = 0;
    int def_stat      = 0;
    bool burn         = false;
    bool screen       = false;
    bool ff           = false;
    bool critical_hit = is_crit(atkteam, defteam);

    switch(atkteam.movechoice->category)
    {
        case MoveCategory::Physical:
            if(atkteam.active()->get_status() == Status::Burn) { burn = true; }
            if(defteam.reflect > 0) { screen = true; }
            atk_stat = atkteam.member[atkteam.active_pokemon].get_stats().atk;
            if(!(critical_hit && atkteam.atkboost < 0))
            {
                atk_stat = get_stat_boosted(atkteam.member[atkteam.active_pokemon].get_stats().atk, Statname::Atk, atkteam.atkboost);
            }
            def_stat = defteam.member[defteam.active_pokemon].get_stats().def;
            if(!(critical_hit && defteam.defboost > 0))
            {
                def_stat = get_stat_boosted(defteam.member[defteam.active_pokemon].get_stats().def, Statname::Def, defteam.defboost);
            }
            break;
        case MoveCategory::Special:
            if(defteam.lightscreen > 0) { screen = true; }
            atk_stat = atkteam.member[atkteam.active_pokemon].get_stats().satk;
            if(!(critical_hit && atkteam.satkboost < 0))
            {
                atk_stat = get_stat_boosted(atkteam.member[atkteam.active_pokemon].get_stats().satk, Statname::Satk, atkteam.satkboost);
            }
            if(atkteam.movechoice->get_type() == Type::Fire && atkteam.flash_fire)
            {
                ff = true;
            }
            def_stat = defteam.member[defteam.active_pokemon].get_stats().sdef;
            if(!(critical_hit && defteam.sdefboost > 0))
            {
                def_stat = get_stat_boosted(defteam.member[defteam.active_pokemon].get_stats().sdef, Statname::Sdef, defteam.sdefboost);
            }
            break;
    }
    atk_stat = static_cast<int>(atk_stat * ability_multiplier(atkteam, defteam));
    int power = 0;
    // special damages like eruption, flail...
    if(atkteam.special_calc)
    {
        power = atkteam.special_damage_calc;
        atkteam.special_calc = false;
    }
    else
    {
        power = move_power(atkteam.movechoice->get_move());
    }

    damage = 2 * (atkteam.member[atkteam.active_pokemon].get_level());
    damage /= 5;
    damage += 2;
    damage *= power;
    damage = static_cast<int>(static_cast<float>(damage) * static_cast<float>(atk_stat) / static_cast<float>(def_stat));
    damage = static_cast<int>(static_cast<float>(damage) / 50.0f);
    if(burn)  { damage = static_cast<int>(damage / 2.0f); }
    if(screen){ damage = static_cast<int>(damage / 2.0f); }
    if(ff)    { damage = static_cast<int>(damage * 1.5f); }
    damage = static_cast<int>(static_cast<float>(damage) * this->weather_multiplier(atkteam, this->weather));
    damage += 2;
    damage = static_cast<int>(static_cast<float>(damage) * this->item_multiplier(atkteam));
    if(critical_hit)
    {
        damage *= 2;
    }
    if(atkteam.movechoice->get_stab())
    {
        damage = static_cast<int>(static_cast<float>(damage) * 1.5f);
    }
    damage = static_cast<int>(static_cast<float>(damage) * effectiveness_multiplier(atkteam, defteam));
    // Need to implement custom damage rolls
    damage = static_cast<int>(static_cast<float>(damage) * static_cast<float>(85 + this->transition.random(16)) / 100.0f);

    if(critical_hit)
    {
        defteam.active()->reduce_hp_attack(damage);
        crit_log(defteam);
        atk_damage_log(defteam);
    }
    else
    {
        defteam.active()->reduce_hp_attack(damage);
        atk_damage_log(defteam);
    }
    return damage;
}

bool Battle::is_crit(const Team &atkteam, Team &defteam)
{
    if(defteam.active()->get_ability() == Ability::Shell_Armor ||
       defteam.active()->get_ability() == Ability::Battle_Armor)
    {
        return false;
    }
    switch(crit_multiplier(atkteam, defteam))
    {
        case 0:
            return this->transition.randomChance(1, 16);
            break;
        case 1:
            return this->transition.randomChance(1, 8);
            break;
        case 2:
            return this->transition.randomChance(1, 4);
            break;
        case 3:
            return this->transition.randomChance(1, 3);
            break;
        case 4:
            return this->transition.randomChance(1, 2);
            break;
        default:
            return false;
    }
    return false;
}

float Battle::ability_multiplier(const Team &atkteam, Team &defteam)
{
    float atk_multiplier = 1;
    float def_multiplier = 1;

    auto pinch_ability = [&](Type type)
                        { 
                            if(*atkteam.movechoice == type &&
                            (atkteam.member[atkteam.active_pokemon].current_hp <
                            static_cast<int>(atkteam.member[atkteam.active_pokemon].get_stats().hp / 3.0)))
                            {
                                atk_multiplier = 1.5;
                            }
                        };
    auto ability_heal = [](Team &team)
                        {
                            team.active()->increase_hp(static_cast<int>(team.active()->get_stats().hp / 3.0));
                        };

    switch(atkteam.member[atkteam.active_pokemon].get_ability())
    {
        case Ability::Blaze:
            pinch_ability(Type::Fire);
               break;
        case Ability::Overgrow:
            pinch_ability(Type::Grass);
            break;
        case Ability::Torrent:
            pinch_ability(Type::Water);
            break;
        case Ability::Swarm:
            pinch_ability(Type::Bug);
            break;
        case Ability::Pure_Power:
        case Ability::Huge_Power:
            if(atkteam.movechoice->category == MoveCategory::Physical)
            {
                atk_multiplier = 2.0;
            }
            break;
        case Ability::Guts:
            if(atkteam.movechoice->category == MoveCategory::Physical &&
                atkteam.member[atkteam.active_pokemon].get_status() != Status::Healthy)
                {
                    atk_multiplier = 1.5;
                }
            break;
        case Ability::Hustle:
            if(atkteam.movechoice->category == MoveCategory::Physical)
            {
                atk_multiplier = 1.5;
            }
            break;
    }
    switch(defteam.member[defteam.active_pokemon].get_ability())
    {
        case Ability::Flash_Fire:
            if(*atkteam.movechoice == Type::Fire)
            {
                def_multiplier = 0;
            }
            break;
        case Ability::Levitate:
            if(*atkteam.movechoice == Type::Ground)
            {
                def_multiplier = 0;
            }
            break;
        case Ability::Marvel_Scale:
            if(defteam.member[defteam.active_pokemon].get_status() != Status::Healthy)
            {
                if(atkteam.movechoice->category == MoveCategory::Physical)
                {
                    def_multiplier = 1.5;
                }
            }
            break;
        case Ability::Thick_Fat:
            if(*atkteam.movechoice == Type::Fire ||
               *atkteam.movechoice == Type::Ice)
                {
                   def_multiplier = 2;
                }
            break;
        case Ability::Volt_Absorb:
            if(*atkteam.movechoice == Type::Electric)
            {
                def_multiplier = 0;
                ability_heal(defteam);
            }
            break;
        case Ability::Water_Absorb:
            if(*atkteam.movechoice == Type::Water)
            {
                def_multiplier = 0;
                ability_heal(defteam);
                
            }
            break;
        case Ability::Wonder_Guard:
            switch(atkteam.movechoice->get_type())
            {
                case Type::Dark:
                case Type::Fire:
                case Type::Flying:
                case Type::Ghost:
                case Type::Rock:
                    return 1.0f;
                default:
                    def_multiplier = 0;
            }
            break;
    }
    if(def_multiplier == 0)
    {
        return 0;
    }
    else
    {
        return atk_multiplier / def_multiplier;
    }
}

int Battle::crit_multiplier(const Team &atkteam, const Team &defteam)
{
    int crit_multiplier = 0;

    switch (defteam.member[defteam.active_pokemon].get_ability())
    {
        case Ability::Battle_Armor:
        case Ability::Shell_Armor:
            return 0;
        default:
            break;
    }

    switch(atkteam.movechoice->get_move())
    {
        case Move::Future_Sight:
        case Move::Doom_Desire:
        case Move::Spit_Up:
            return 0;
        case Move::Aeroblast:
        case Move::Air_Cutter:
        case Move::Attack_Order:
        case Move::Blaze_Kick:
        case Move::Crabhammer:
        case Move::Cross_Chop:
        case Move::Cross_Poison:
        case Move::Drill_Run:
        case Move::Karate_Chop:
        case Move::Leaf_Blade:
        case Move::Night_Slash:
        case Move::Poison_Tail:
        case Move::Psycho_Cut:
        case Move::Razor_Leaf:
        case Move::Razor_Wind:
        case Move::Shadow_Claw:
        case Move::Sky_Attack:
        case Move::Slash:
        case Move::Spacial_Rend:
        case Move::Stone_Edge:
            crit_multiplier += 1;
            break;
        default:
            break;
    }

    switch(atkteam.member[atkteam.active_pokemon].get_item())
    {
        case Item::Luckypunch:
            if(atkteam.member[atkteam.active_pokemon].get_species() == Species::Chansey)
            {
                crit_multiplier += 1;
            }
            break;
        case Item::Stick:
            if(atkteam.member[atkteam.active_pokemon].get_species() == Species::Farfetchd)
            {
                crit_multiplier += 1;
            }
            break;
        case Item::Scopelens:
            crit_multiplier += 1;
            break;
        default:
            break;
    }

    return crit_multiplier;
}

float Battle::effectiveness_multiplier(const Team &atkteam, const Team &defteam)
{

    return effectiveness(atkteam.movechoice->get_type(), defteam.member[defteam.active_pokemon].get_type()[0]) *
           effectiveness(atkteam.movechoice->get_type(), defteam.member[defteam.active_pokemon].get_type()[1]);
}

float Battle::item_multiplier(const Team &atkteam)
{
    switch(atkteam.member[atkteam.active_pokemon].get_item())
    {
        case Item::Blackbelt:
            if(*atkteam.movechoice == Type::Fighting)
            {
                return 1.1f;
            }
        case Item::Blackglasses:
            if(*atkteam.movechoice == Type::Dark)
            {
                return 1.1f;
            }
        case Item::Charcoal:
            if(*atkteam.movechoice == Type::Fire)
            {
                return 1.1f;
            }
        case Item::Choiceband:
            if(atkteam.movechoice->category == MoveCategory::Physical)
            {
                return 1.5f;
            }
        case Item::Deepseatooth:
            if(atkteam.member[atkteam.active_pokemon].get_species() == Species::Clamperl &&
               atkteam.movechoice->category == MoveCategory::Special)
            {
                return 2.0f;
            }
        case Item::Dragonfang:
            if(*atkteam.movechoice == Type::Dragon)
            {
                return 1.1f;
            }
        case Item::Hardstone:
            if(*atkteam.movechoice == Type::Rock)
            {
                return 1.1f;
            }
        case Item::Lightball:
            if(atkteam.movechoice->category == MoveCategory::Special &&
               atkteam.member[atkteam.active_pokemon].get_species() == Species::Pikachu)
                {
                   return 2.0f;
                }
        case Item::Magnet:
            if(*atkteam.movechoice == Type::Electric)
            {
                return 1.1f;
            }
        case Item::Metalcoat:
            if(*atkteam.movechoice == Type::Steel)
            {
                return 1.1f;
            }
        case Item::Miracleseed:
            if(*atkteam.movechoice == Type::Grass)
            {
                return 1.1f;
            }
        case Item::Mysticwater:
            if(*atkteam.movechoice == Type::Water)
            {
                return 1.1f;
            }
        case Item::Nevermeltice:
            if(*atkteam.movechoice == Type::Ice)
            {
                return 1.1f;
            }
        case Item::Poisonbarb:
            if(*atkteam.movechoice == Type::Poison)
            {
                return 1.1f;
            }
        case Item::Silkscarf:
            if(*atkteam.movechoice == Type::Normal)
            {
                return 1.1f;
            }
        case Item::Softsand:
            if(*atkteam.movechoice == Type::Ground)
            {
                return 1.1f;
            }
        case Item::Spelltag:
            if(*atkteam.movechoice == Type::Ghost)
            {       
                return 1.1f;
            }
        case Item::Thickclub:
            if(atkteam.movechoice->category == MoveCategory::Physical &&
              (atkteam.member[atkteam.active_pokemon].get_species() == Species::Cubone ||
               atkteam.member[atkteam.active_pokemon].get_species() == Species::Marowak))
                {
                   return 2.0f;
                }
        case Item::Twistedspoon:
            if(*atkteam.movechoice == Type::Psychic)
            {
                return 1.1f;
            }
            else
            {
                return 1.0f;
            }
        default: return 1.0f;
    }
}

float Battle::weather_multiplier(const Team &atkteam, Weather weather)
{
    switch(weather)
    {
        case Weather::Sun:
            if(*atkteam.movechoice == Type::Fire) { return 2.0; }
            if(*atkteam.movechoice == Type::Water) { return 0.5; }
        case Weather::Rain:        
            if(*atkteam.movechoice == Type::Fire) { return 0.5; }
            if(*atkteam.movechoice == Type::Water) { return 2; }
        default: return 1;
    }
}