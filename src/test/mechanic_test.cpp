#include "mechanic_test.hpp"

bool Tests::test_all_mechanic()
{
    std::cout << "\n== Mechanic Test ==\n";
    if (!check(speed_test))
    {
        return false;
    }
    if (!check(game_end))
    {
        return false;
    }

    return true;
}

bool Tests::speed_test()
{
    // switches AttackMove
    AttackMove switch_0 = constants::Aswitches[0];
    AttackMove switch_1 = constants::Aswitches[1];
    AttackMove switch_2 = constants::Aswitches[2];
    AttackMove switch_3 = constants::Aswitches[3];
    AttackMove switch_4 = constants::Aswitches[4];
    AttackMove switch_5 = constants::Aswitches[5];

    auto reset = [](Battle &battle)
    {
        battle.team[0].active()->set_status(Status::Healthy);
        battle.team[1].active()->set_status(Status::Healthy);
        battle.team[0].set_boost_flat(Statname::Spe, 0);
        battle.team[1].set_boost_flat(Statname::Spe, 0);
        battle.team[0].active_pokemon = 0;
        battle.team[1].active_pokemon = 0;
    };

    std::cout << "Testing move order...\t";
    Battle tbattle({Alph::ABCe, Alph::DFG});

    // Aerodactyl vs Dugtrio
    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(0);
    tbattle.team[1].movechoice = &tbattle.team[1].active()->get_moveset()->at(0);
    tbattle.calc_first_attacker();
    if (tbattle.move_first == true)
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
    if (tbattle.move_first == false)
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
    if (tbattle.move_first == false)
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
    if (tbattle.move_first == true)
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
    if (tbattle.move_first == false)
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
    if (tbattle.move_first == true)
    {
        std::cout << "Error Speed Blissey vs paralyzed Dugtrio\n";
        return false;
    }
    reset(tbattle);

    // Blissey Counter vs Dugtrio
    tbattle.team[0].active_pokemon = 3;

    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(1);
    tbattle.team[1].movechoice = &tbattle.team[1].active()->get_moveset()->at(0);
    tbattle.calc_first_attacker();
    if (tbattle.move_first == false)
    {
        std::cout << "Error Speed Blissey Counter vs Dugtrio\n";
        return false;
    }
    reset(tbattle);

    // Blissey Counter vs paralyzed Dugtrio
    tbattle.team[0].active_pokemon = 3;

    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(1);
    tbattle.team[1].movechoice = &tbattle.team[1].active()->get_moveset()->at(0);
    tbattle.team[1].active()->set_status(Status::Paralysis);
    tbattle.calc_first_attacker();
    if (tbattle.move_first == false)
    {
        std::cout << *tbattle.team[0].active() << "\n";
        std::cout << *tbattle.team[1].active() << "\n";
        std::cout << "Error Speed Blissey Counter vs paralyzed Dugtrio\n";
        return false;
    }
    reset(tbattle);

    // Aerodactyl switch vs Dugtrio
    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(0);
    tbattle.team[0].movechoice = &switch_2;
    tbattle.calc_first_attacker();
    if (tbattle.move_first == true)
    {
        std::cout << "Error Speed Aerodactyl switch vs Dugtrio\n";
        return false;
    }
    reset(tbattle);

    // Aerodactyl vs Dugtrio switch
    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(0);
    tbattle.team[1].movechoice = &switch_2;
    tbattle.calc_first_attacker();
    if (tbattle.move_first == false)
    {
        std::cout << "Error Speed Aerodactyl vs Dugtrio switch\n";
        return false;
    }
    reset(tbattle);

    // paralyzed Aerodactyl switch vs Dugtrio
    tbattle.team[0].movechoice = &switch_2;
    tbattle.team[1].movechoice = &tbattle.team[0].active()->get_moveset()->at(0);
    tbattle.team[0].active()->set_status(Status::Paralysis);
    tbattle.calc_first_attacker();
    if (tbattle.move_first == true)
    {
        std::cout << "Error Speed paraylzed Aerodactyl switch vs Dugtrio\n";
        return false;
    }
    reset(tbattle);

    std::cout << "success\n";
    return true;
}

bool Tests::game_end()
{
    std::cout << "Testing game end...\t";
    Battle tbattle({Alph::MS, Alph::ABCe});
    tbattle.init();

    for (int i = 0; i < 5; ++i)
    {
        tbattle.team[0].member[i].kill();
        tbattle.team[1].member[i].kill();
        if (tbattle.team[0].member[i].get_status() != Status::Fainted)
        {
            std::cout << "Error Test game_end, Status::Fainted\n";
            return false;
        }

        if (tbattle.team[1].member[i].get_status() != Status::Fainted)
        {
            std::cout << "Error Test game_end, Status::Fainted\n";
            return false;
        }

        if (tbattle.team[0].member[i].current_hp != 0)
        {
            std::cout << "Error Test game_end, HP\n";
            return false;
        }

        if (tbattle.team[1].member[i].current_hp != 0)
        {
            std::cout << "Error Test game_end, HP\n";
            return false;
        }
    }
    // Celebi and Snorlax
    tbattle.team[0].active_pokemon = 5;
    tbattle.team[1].active_pokemon = 5;

    tbattle.team[0].active()->set_current_hp(3);
    tbattle.team[1].active()->set_current_hp(3);

    // make Snorlax choose Self-Destruct
    tbattle.team[0].active()->moveset[0].set_pp(0);
    tbattle.team[0].active()->moveset[1].set_pp(0);
    tbattle.team[0].active()->moveset[2].set_pp(0);

    std::cout << *tbattle.team[0].active();
    std::cout << *tbattle.team[1].active();

    tbattle.team[0].get_move_options(constants::dummy_imp_moves);
    tbattle.team[1].get_move_options(constants::dummy_imp_moves);

    int game_result = tbattle.play_battle();
    if (game_result != 3)
    {
        std::cout << "Error Test game_end, Tie\n";
        std::cout << game_result << "\n";
        return false;
    }

    std::cout << "success\n";
    return true;
}