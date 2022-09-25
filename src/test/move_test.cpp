#include "move_test.hpp"

bool Tests::test_all_move()
{
    if(!check(test_damage))  { return false; }
    if(!check(test_crit))    { return false; }
    if(!check(test_accuracy)){ return false; }
    if(!check(test_status))  { return false; }
    if(!check(test_healing)) { return false; }
    if(!check(test_misc))    { return false; }

    return true;
}

void Tests::refresh(Pokemon& poki)
{
    poki.set_status(Status::Healthy);
    poki.increase_hp(999);
    for(auto&& move : poki.moveset)
    {
        move.set_pp(99);
    }
}
bool Tests::test_damage()
{
    std::cout << "Testing damage...";
    // possible damage values to compare to
    std::array<int, 32> rolls;

    // actual damage calculated
    int damage = 0;

    // function to determine if damage is in expected rolls
    auto in_rolls = [&damage](int roll){ return damage == roll; };
    
    // test battle to generate damage calcs
    Battle tbattle = Battle({ Alph::ABCe, Alph::C });

    // set a movechoice -> calculate damage -> check if in rolls -> repeat with other move
    for(int i = 0; i < 1000000; ++i)
    {
        // x4 effective
        // reset battle state
        refresh(*tbattle.team[0].active());
        refresh(*tbattle.team[1].active());
        // choose Blissey as active Pokemon
        tbattle.team[0].active_pokemon = 0;
        // choose Claydol as active Pokemon
        tbattle.team[1].active_pokemon = 0;
        // Choose Rock Slide
        tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(0);
        // Choice Band Aero Rock Slide vs Charizard
        damage = tbattle.calculate_damage(tbattle.team[0], tbattle.team[1]);
        rolls  = {  870,  880,  890,  901,  911,  921,  931,  942,  952,  962,  972,  983,  993, 1003, 1013, 1024,
                   1744, 1764, 1785, 1805, 1826, 1846, 1867, 1887, 1908, 1928, 1949, 1969, 1990, 2010, 2031, 2052 };
        // check if damage is in possible rolls
        if(std::none_of(rolls.begin(), rolls.end(), in_rolls))
        {
            std::cout << *tbattle.team[0].active() << std::endl;
            std::cout << *tbattle.team[1].active() << std::endl;
            std::cout << damage << std::endl;
            std::cout << "Error Aero RSlide vs Charizard\n";
            return false;
        }

        // x2 effective
        // reset battle state
        refresh(*tbattle.team[0].active());
        refresh(*tbattle.team[1].active());
        // choose Blissey as active Pokemon
        tbattle.team[0].active_pokemon = 2;
        // choose Claydol as active Pokemon
        tbattle.team[1].active_pokemon = 2;
        // choose Ice Beam
        tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(1);
        // Blissey Ice Beam vs Claydol
        damage = tbattle.calculate_damage(tbattle.team[0], tbattle.team[1]);
        rolls  = { 136, 137, 139, 140, 142, 144, 145, 147, 148, 150, 152, 153, 155, 156, 158, 160,
                   272, 275, 278, 281, 284, 288, 291, 294, 297, 300, 304, 307, 310, 313, 316, 320 };
        // check if damage is in possible rolls
        if(std::none_of(rolls.begin(), rolls.end(), in_rolls))
        {
            std::cout << *tbattle.team[0].active() << std::endl;
            std::cout << *tbattle.team[1].active() << std::endl;
            std::cout << damage << std::endl;
            std::cout << "Error Blissey IceBeam vs Claydol\n";
            return false;
        }

        // neutral damage
        // reset battle state
        refresh(*tbattle.team[0].active());
        refresh(*tbattle.team[1].active());
        // choose Earthquake
        tbattle.team[1].movechoice = &tbattle.team[1].active()->get_moveset()->at(0);
        // Claydol Earthquake vs Blissey
        damage = tbattle.calculate_damage(tbattle.team[1], tbattle.team[0]);
        rolls  = { 237, 239, 242, 245, 248, 251, 253, 256, 259, 262, 265, 267, 270, 273, 276, 279,
                   474, 479, 485, 491, 496, 502, 507, 513, 518, 524, 530, 535, 541, 546, 552, 558 };        
        // check if damage is in possible rolls
        if(std::none_of(rolls.begin(), rolls.end(), in_rolls))
        {
            std::cout << *tbattle.team[0].active() << std::endl;
            std::cout << *tbattle.team[1].active() << std::endl;
            std::cout << damage << std::endl;
            std::cout << "Error Claydol Earthquake vs Blissey\n";
            return false;
        }

        // x2 resistance
        // reset battle state
        refresh(*tbattle.team[0].active());
        refresh(*tbattle.team[1].active());
        // choose Aerodactyl as active Pokemon
        tbattle.team[0].active_pokemon = 0;
        // choose Charizard as active Pokemon
        tbattle.team[1].active_pokemon = 0;
        // choose Fire Blast
        tbattle.team[1].movechoice = &tbattle.team[1].active()->get_moveset()->at(0);
        // Charizard Fire Blast vs Aerodactyl
        damage = tbattle.calculate_damage(tbattle.team[1], tbattle.team[0]);
        rolls  = { 110, 111, 113, 114, 115, 117, 118, 119, 120, 122, 123, 124, 126, 127, 128, 130,
                   221, 224, 227, 229, 232, 234, 237, 240, 242, 245, 247, 250, 253, 255, 258, 261 };
        if(std::none_of(rolls.begin(), rolls.end(), in_rolls))
        {
            std::cout << *tbattle.team[0].active() << std::endl;
            std::cout << *tbattle.team[1].active() << std::endl;
            std::cout << damage << std::endl;
            std::cout << "Error Charizard Fire Blast vs Aero\n";
            return false;
        }

        // x4 resistance
        // reset battle state
        refresh(*tbattle.team[0].active());
        refresh(*tbattle.team[1].active());
        // choose Blissey as active Pokemon
        tbattle.team[0].active_pokemon = 2;
        // choose Cloyster as active Pokemon
        tbattle.team[1].active_pokemon = 5;
        // choose Ice Beam
        tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(1);
        // Blissey Ice Beam vs Cloyster
        damage = tbattle.calculate_damage(tbattle.team[0], tbattle.team[1]);
        rolls  = { 36, 36, 37, 37, 38, 38, 39, 39, 39, 40, 40, 41, 41, 42, 42, 43,
                   36, 36, 37, 37, 38, 38, 39, 39, 39, 40, 40, 41, 41, 42, 42, 43 };
        if(std::none_of(rolls.begin(), rolls.end(), in_rolls))
        {
            std::cout << *tbattle.team[0].active() << std::endl;
            std::cout << *tbattle.team[1].active() << std::endl;
            std::cout << damage << std::endl;
            std::cout << "Error Blissey Ice Beam vs Cloyster\n";
        }
    }
    
    std::cout << " success\n";
    return true;
}
bool Tests::test_crit()
{    
    std::cout << "Testing crit...";
    // possible damage values to compare to
    std::array<int, 16> rolls;

    // actual damage calculated
    int damage = 0;

    // function to determine if damage is in expected rolls
    auto in_rolls = [&damage](int roll){ return damage == roll; };
    
    // test battle to generate damage calcs
    Battle tbattle = Battle({ Alph::ABCe, Alph::C });

    constexpr int LOOP_N = 100000;
    // set a movechoice -> calculate damage -> check if in rolls -> repeat with other move
    // x4 effective
    // choose Blissey as active Pokemon
    tbattle.team[0].active_pokemon = 0;
    // choose Claydol as active Pokemon
    tbattle.team[1].active_pokemon = 0;
    // Choose Rock Slide
    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(0);
    rolls  = { 1744, 1764, 1785, 1805, 1826, 1846, 1867, 1887, 1908, 1928, 1949, 1969, 1990, 2010, 2031, 2052 };
    for(int i = 0; i <= LOOP_N; ++i)
    {
        // reset battle state
        refresh(*tbattle.team[0].active());
        refresh(*tbattle.team[1].active());
        // Choice Band Aero Rock Slide vs Charizard
        damage = tbattle.calculate_damage(tbattle.team[0], tbattle.team[1]);
        // check if damage is in possible rolls
        // if roll in damage -> return true (break)
        if(std::any_of(rolls.begin(), rolls.end(), in_rolls))
        {
            break;
        }
        else
        {
            if(i == LOOP_N-1)
            {
                return false;
            }
        }
    }
    // x2 effective
    // choose Blissey as active Pokemon
    tbattle.team[0].active_pokemon = 2;
    // choose Claydol as active Pokemon
    tbattle.team[1].active_pokemon = 2;
    // choose Ice Beam
    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(1);
    rolls  = { 272, 275, 278, 281, 284, 288, 291, 294, 297, 300, 304, 307, 310, 313, 316, 320 };
    for(int i = 0; i < LOOP_N; ++i)
    {
        // reset battle state
        refresh(*tbattle.team[0].active());
        refresh(*tbattle.team[1].active());
        // Blissey Ice Beam vs Claydol
        damage = tbattle.calculate_damage(tbattle.team[0], tbattle.team[1]);
        // check if damage is in possible rolls
        if(std::any_of(rolls.begin(), rolls.end(), in_rolls))
        {
            break;
        }
        else
        {
            if(i == LOOP_N-1)
            {
                return false;
            }
        }
    }
    // neutral damage
    // choose Earthquake
    tbattle.team[1].movechoice = &tbattle.team[1].active()->get_moveset()->at(0);
    rolls  = { 474, 479, 485, 491, 496, 502, 507, 513, 518, 524, 530, 535, 541, 546, 552, 558 };
    for(int i = 0; i < LOOP_N; ++i)
    {
        // reset battle state
        refresh(*tbattle.team[0].active());
        refresh(*tbattle.team[1].active());
        // Claydol Earthquake vs Blissey
        damage = tbattle.calculate_damage(tbattle.team[1], tbattle.team[0]);
        // check if damage is in possible rolls
        if(std::any_of(rolls.begin(), rolls.end(), in_rolls))
        {
            break;
        }
        else
        {
            if(i == LOOP_N-1)
            {
                return false;
            }
        }
    }
    // x2 resistance
    // choose Aerodactyl as active Pokemon
    tbattle.team[0].active_pokemon = 0;
    // choose Charizard as active Pokemon
    tbattle.team[1].active_pokemon = 0;
    // choose Fire Blast
    tbattle.team[1].movechoice = &tbattle.team[1].active()->get_moveset()->at(0);
    rolls  = { 221, 224, 227, 229, 232, 234, 237, 240, 242, 245, 247, 250, 253, 255, 258, 261 };
    for(int i = 0; i < LOOP_N; ++i)
    {
        // reset battle state
        refresh(*tbattle.team[0].active());
        refresh(*tbattle.team[1].active());
        // Charizard Fire Blast vs Aerodactyl
        damage = tbattle.calculate_damage(tbattle.team[1], tbattle.team[0]);
        // check if damage is in possible rolls
        if(std::any_of(rolls.begin(), rolls.end(), in_rolls))
        {
            break;
        }
        else
        {
            if(i == (LOOP_N-1))
            {
                return false;
            }
        }
    }
    // x4 resistance
    // choose Blissey as active Pokemon
    tbattle.team[0].active_pokemon = 2;
    // choose Cloyster as active Pokemon
    tbattle.team[1].active_pokemon = 5;
    // choose Ice Beam
    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(1);
    rolls  = { 36, 36, 37, 37, 38, 38, 39, 39, 39, 40, 40, 41, 41, 42, 42, 43 };
    for(int i = 0; i < LOOP_N; ++i)
    {
        // reset battle state
        refresh(*tbattle.team[0].active());
        refresh(*tbattle.team[1].active());
        // Blissey Ice Beam vs Cloyster
        damage = tbattle.calculate_damage(tbattle.team[0], tbattle.team[1]);
        // check if damage is in possible rolls
        if(std::any_of(rolls.begin(), rolls.end(), in_rolls))
        {
            break;
        }
        else
        {
            if(i == LOOP_N-1)
            {
                return false;
            }
        }
    }
    std::cout << " success\n";
    return true;
}
bool Tests::test_accuracy()
{
    std::cout << "Testing accuracy...";

    // test battle to generate damage calcs
    Battle tbattle = Battle({ Alph::ABCe, Alph::C });

    constexpr int LOOP_N = 100000;

    // Choose Rock Slide
    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(0);

    // max hp value to see if damage was dealt
    int max_hp = tbattle.team[1].member[0].get_current_hp();

    for(int i = 0; i <= LOOP_N; ++i)
    {
        // reset battle state
        refresh(*tbattle.team[0].active());
        refresh(*tbattle.team[1].active());

        // use Rock Slide Aero vs Charizard
        tbattle.use_move(tbattle.team[0], tbattle.team[1]);

        // check if damage was dealt
        if(tbattle.team[1].member[0].get_current_hp() == max_hp)

        {
            break;
        }
        else
        {
            if(i == LOOP_N-1)
            {
                return false;
            }
        }
    }

    // max hp value to see if damage was dealt
    max_hp = tbattle.team[0].member[0].get_current_hp();

    // choose Fire Blast
    tbattle.team[1].movechoice = &tbattle.team[1].active()->get_moveset()->at(0);

    for(int i = 0; i < LOOP_N; ++i)
    {
        // reset battle state
        refresh(*tbattle.team[0].active());
        refresh(*tbattle.team[1].active());
        // use Fire Blast Charizard vs Aero
        tbattle.use_move(tbattle.team[1], tbattle.team[0]);
        // check if damage was dealt
        if(tbattle.team[0].member[0].get_current_hp() == max_hp)
        {
            break;
        }
        else
        {
            if(i == (LOOP_N-1))
            {
                return false;
            }
        }
    }
    std::cout << " success\n";
    return true;
}
bool Tests::test_status()
{    
    std::cout << "Testing status...";
    // test battle to generate damage calcs
    Battle tbattle = Battle({ Alph::ABCe, Alph::C });
    
    constexpr int LOOP_N = 100000;
    
    // choose Fire Blast
    tbattle.team[1].movechoice = &tbattle.team[1].active()->get_moveset()->at(0);

    for(int i = 0; i < LOOP_N; ++i)
    {
        // reset battle state
        refresh(*tbattle.team[0].active());
        refresh(*tbattle.team[1].active());
        // use Fire Blast Charizard vs Aero
        tbattle.use_move(tbattle.team[1], tbattle.team[0]);
        // check if damage was dealt
        if(tbattle.team[0].member[0].get_status() == Status::Burn)
        {
            break;
        }
        else
        {
            if(i == (LOOP_N-1))
            {
                return false;
            }
        }
    }

    // Choose Blissey
    tbattle.team[0].active_pokemon = 2;

    // Choose Thunder Wave
    tbattle.team[0].movechoice = &tbattle.team[0].active()->get_moveset()->at(3);
    if(tbattle.team[1].active()->get_status() != Status::Paralysis)
    {
        return false;
    }
    std::cout << "success" << std::endl;
    return true;
}
bool Tests::test_healing()
{
    
    return true;
}
bool Tests::test_misc()
{
    return true;
}