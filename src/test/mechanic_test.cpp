#include "mechanic_test.hpp"

bool Tests::test_all_mechanic()
{
    std::cout << "\n== Mechanic Test ==\n";
    if(!check(speed_test))  { return false; }

    return true;
}

bool Tests::speed_test()
{
    auto reset = [](Battle& battle){
        battle.team[0].active()->set_status(Status::Healthy);
        battle.team[1].active()->set_status(Status::Healthy);
        battle.team[0].set_boost_flat(Statname::Spe, 0);
        battle.team[1].set_boost_flat(Statname::Spe, 0);
        battle.team[0].active_pokemon = 0;
        battle.team[1].active_pokemon = 0;
    };

    std::cout << "Testing Speed...\t";
    Battle tbattle({ Alph::ABCe, Alph::DFG });

    // Aerodactyl vs Dugtrio
    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(0);
    tbattle.team[1].movechoice = &tbattle.team[1].active()->get_moveset()->at(0);
    tbattle.calc_first_attacker();
    if(tbattle.move_first == true)
    {
        std::cout << "Error Speed Aerodactyl vs Dugtrio\n";
        return false;
    }
    reset(tbattle);

    // Aerodactyl vs +1 speed Dugtrio
    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(0);
    tbattle.team[1].movechoice = &tbattle.team[1].active()->get_moveset()->at(0);
    tbattle.team[1].set_boost(Statname::Spe, 1);
    tbattle.calc_first_attacker();
    if(tbattle.move_first == false)
    {
        std::cout << "Error Speed Aerodactyl vs Dugtrio\n";
        return false;
    }
    reset(tbattle);

    // paralyzed Aerodactyl vs Dugtrio
    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(0);
    tbattle.team[1].movechoice = &tbattle.team[1].active()->get_moveset()->at(0);
    tbattle.team[0].active()->set_status(Status::Paralysis);
    tbattle.calc_first_attacker();
    if(tbattle.move_first == false)
    {
        std::cout << "Error Speed paralyzed Aerodactyl vs Dugtrio\n";
        return false;
    }
    reset(tbattle);

    // paralyzed Aerodactyl vs  paralyzed Dugtrio
    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(0);
    tbattle.team[1].movechoice = &tbattle.team[1].active()->get_moveset()->at(0);
    tbattle.team[0].active()->set_status(Status::Paralysis);
    tbattle.team[1].active()->set_status(Status::Paralysis);
    tbattle.calc_first_attacker();
    if(tbattle.move_first == true)
    {
        std::cout << tbattle.team[1].get_boost(Statname::Spe) << std::endl;
        std::cout << "Error Speed paralyzed Aerodactyl vs paralyzed Dugtrio\n";
        return false;
    }
    reset(tbattle);
    
    // Blissey vs Dugtrio
    tbattle.team[0].active_pokemon = 3;

    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(0);
    tbattle.team[1].movechoice = &tbattle.team[1].active()->get_moveset()->at(0);
    tbattle.calc_first_attacker();
    if(tbattle.move_first == false)
    {
        std::cout << "Error Speed Blissey vs Dugtrio\n";
        return false;
    }
    reset(tbattle);

    // Blissey vs paralyzed Dugtrio
    tbattle.team[0].active_pokemon = 3;

    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(0);
    tbattle.team[1].movechoice = &tbattle.team[1].active()->get_moveset()->at(0);
    tbattle.team[1].active()->set_status(Status::Paralysis);
    tbattle.calc_first_attacker();
    if(tbattle.move_first == true)
    {
        std::cout << "Error Speed Blissey vs paralyzed Dugtrio\n";
        return false;
    }
    reset(tbattle);

    // Blissey Counter vs Dugtrio
    tbattle.team[0].active_pokemon = 3;

    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(0);
    tbattle.team[1].movechoice = &tbattle.team[1].active()->get_moveset()->at(1);
    tbattle.calc_first_attacker();
    if(tbattle.move_first == false)
    {
        std::cout << "Error Speed Blissey Counter vs Dugtrio\n";
        return false;
    }
    reset(tbattle);

    // Blissey Counter vs Dugtrio
    tbattle.team[0].active_pokemon = 3;
    
    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(0);
    tbattle.team[1].movechoice = &tbattle.team[1].active()->get_moveset()->at(1);
    tbattle.team[1].active()->set_status(Status::Paralysis);
    tbattle.calc_first_attacker();
    if(tbattle.move_first == false)
    {
        std::cout << "Error Speed Blissey Counter vs paralyzed Dugtrio\n";
        return false;
    }
    reset(tbattle);

    std::cout << "success\n";
    return true;
}