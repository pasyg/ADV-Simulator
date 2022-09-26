#include "import_test.hpp"

bool Tests::test_import_init()
{
    std::vector<Team> teams { import_team("sample") };

    std::cout << " == Import Test ==\n";

    if(teams[0].member[0].get_species() != Species::Swampert)
    {
        return false;
    }
    if(teams[12].member[0].get_species() != Species::Salamence)
    {
        return false;
    }
    if(teams[27].member[0].get_species() != Species::Celebi)
    {
        return false;
    }
    if(teams[0].member[0].get_item() != Item::Salacberry)
    {
        return false;
    }
    if(teams[12].member[0].get_item() != Item::Leftovers)
    {
        return false;
    }
    if(teams[27].member[0].get_item() != Item::Leftovers)
    {
        return false;
    }
    if(teams[0].member[0].get_ability() != Ability::Torrent)
    {
        return false;
    }
    if(teams[12].member[0].get_ability() != Ability::Intimidate)
    {
        return false;
    }
    if(teams[27].member[0].get_ability() != Ability::Natural_Cure)
    {
        return false;
    }
    if(teams[0].member[0].get_moveset()->at(0) != Move::Hydro_Pump)
    {
        return false;
    }
    if(teams[12].member[0].get_moveset()->at(3) != Move::Brick_Break)
    {
        return false;
    }
    if(teams[27].member[0].get_moveset()->at(2) != Move::Recover)
    {
        return false;
    }

    std::cout << "Testing stats...\t";
    // init test for import
    for(auto&& team : teams)
    {
        team.init();
    }

    if(teams[0].member[0].get_stats().hp    != 341 ||
       teams[0].member[0].get_stats().atk   != 202 ||
       teams[0].member[0].get_stats().def   != 217 ||
       teams[0].member[0].get_stats().satk  != 269 ||
       teams[0].member[0].get_stats().sdef  != 216 ||
       teams[0].member[0].get_stats().spe   != 240)
    {
        return false;
    }
    if(teams[0].member[4].get_stats().hp    != 301 ||
       teams[0].member[4].get_stats().atk   != 308 ||
       teams[0].member[4].get_stats().def   != 165 ||
       teams[0].member[4].get_stats().satk  != 140 ||
       teams[0].member[4].get_stats().sdef  != 186 ||
       teams[0].member[4].get_stats().spe   != 394)
    {
        return false;
    }
    if(teams[16].member[0].get_stats().hp    != 301 ||
       teams[16].member[0].get_stats().atk   != 153 ||
       teams[16].member[0].get_stats().def   != 219 ||
       teams[16].member[0].get_stats().satk  != 298 ||
       teams[16].member[0].get_stats().sdef  != 250 ||
       teams[16].member[0].get_stats().spe   != 250)
    {
        return false;
    }
    if(teams[16].member[4].get_stats().hp    != 356 ||
       teams[16].member[4].get_stats().atk   != 405 ||
       teams[16].member[4].get_stats().def   != 296 ||
       teams[16].member[4].get_stats().satk  != 203 ||
       teams[16].member[4].get_stats().sdef  != 216 ||
       teams[16].member[4].get_stats().spe   != 185)
    {
        return false;
    }
    if(teams[27].member[4].get_stats().hp    != 404 ||
       teams[27].member[4].get_stats().atk   != 184 ||
       teams[27].member[4].get_stats().def   != 312 ||
       teams[27].member[4].get_stats().satk  != 236 ||
       teams[27].member[4].get_stats().sdef  != 236 ||
       teams[27].member[4].get_stats().spe   != 252)
    {
        return false;
    }
    if(teams[27].member[5].get_stats().hp    != 391 ||
       teams[27].member[5].get_stats().atk   != 112 ||
       teams[27].member[5].get_stats().def   != 276 ||
       teams[27].member[5].get_stats().satk  != 236 ||
       teams[27].member[5].get_stats().sdef  != 286 ||
       teams[27].member[5].get_stats().spe   != 208)
    {
        return false;
    }
    std::cout << "success\nTesting moves...\t";
    
    if(teams[0].member[0].get_moveset()->at(0).base_pp    != 8 ||
       teams[0].member[0].get_moveset()->at(0).get_pp()   != 8 ||
       teams[0].member[0].get_moveset()->at(0).get_move() != Move::Hydro_Pump)
    {
        return false;
    }
    if(teams[0].member[2].get_moveset()->at(3).base_pp    != 8 ||
       teams[0].member[2].get_moveset()->at(3).get_pp()   != 8 ||
       teams[0].member[2].get_moveset()->at(3).get_move() != Move::Explosion)
    {
        return false;
    }
    if(teams[12].member[2].get_moveset()->at(1).base_pp    != 32 ||
       teams[12].member[2].get_moveset()->at(1).get_pp()   != 32 ||
       teams[12].member[2].get_moveset()->at(1).get_move() != Move::Dragon_Dance)
    {
        return false;
    }
    if(teams[12].member[4].get_moveset()->at(2).base_pp    != 24 ||
       teams[12].member[4].get_moveset()->at(2).get_pp()   != 24 ||
       teams[12].member[4].get_moveset()->at(2).get_move() != Move::Crunch)
    {
        return false;
    }
    if(teams[27].member[0].get_moveset()->at(0).base_pp    != 16 ||
       teams[27].member[0].get_moveset()->at(0).get_pp()   != 16 ||
       teams[27].member[0].get_moveset()->at(0).get_move() != Move::Substitute)
    {
        return false;
    }
    if(teams[27].member[5].get_moveset()->at(0).base_pp    != 16 ||
       teams[27].member[5].get_moveset()->at(0).get_pp()   != 16 ||
       teams[27].member[5].get_moveset()->at(0).get_move() != Move::Ice_Beam)
    {
        return false;
    }
    if(teams[27].member[0].get_moveset()->at(3).base_pp    != 64 ||
       teams[27].member[0].get_moveset()->at(3).get_pp()   != 64 ||
       teams[27].member[0].get_moveset()->at(3).get_move() != Move::Baton_Pass)
    {
        return false;
    }
    if(teams[27].member[5].get_moveset()->at(3).base_pp    != 32 ||
       teams[27].member[5].get_moveset()->at(3).get_pp()   != 32 ||
       teams[27].member[5].get_moveset()->at(3).get_move() != Move::Recover)
    {
        return false;
    }
    
    std::cout << "success\nTesting hidden power...\t";

    if(teams[1].member[0].hiddenpower != Type::Bug ||
       teams[1].member[0].hiddenpower_power != 70)
    {
        return false;
    }
    if(teams[1].member[2].hiddenpower != Type::Grass ||
       teams[1].member[2].hiddenpower_power != 70)
    {
        return false;
    }
    if(teams[2].member[1].hiddenpower != Type::Fighting ||
       teams[2].member[1].hiddenpower_power != 70)
    {
        return false;
    }
    if(teams[3].member[1].hiddenpower != Type::Grass ||
       teams[3].member[1].hiddenpower_power != 70)
    {
        return false;
    }
    if(teams[3].member[5].hiddenpower != Type::Bug ||
       teams[3].member[5].hiddenpower_power != 70)
    {
        return false;
    }
    if(teams[20].member[3].hiddenpower != Type::Fire ||
       teams[20].member[3].hiddenpower_power != 70)
    {
        return false;
    }
    if(teams[24].member[0].hiddenpower != Type::Grass ||
       teams[24].member[0].hiddenpower_power != 70)
    {
        return false;
    }
    if(teams[24].member[1].hiddenpower != Type::Grass ||
       teams[24].member[1].hiddenpower_power != 70)
    {
        return false;
    }
    if(teams[24].member[2].hiddenpower != Type::Bug ||
       teams[24].member[2].hiddenpower_power != 70)
    {
        return false;
    }

    std::cout << "success\n";

    return true;
}