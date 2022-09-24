#include "test.hpp"
#include "import_test.hpp"
#include "move_test.hpp"
#include "team_test.hpp"

std::string create_filepath()
{
    auto time = std::chrono::steady_clock::now();
    int lTime = static_cast<int>(time.time_since_epoch().count());

    return ("replays/" + std::to_string(lTime) + ".html");
}

int main(int argc, char* argv[])
{
    Tests::test_import_init();
    Tests::test_all_move();

    int played_games = 100;

    if(argc > 1)
    {
        played_games = std::stoi(argv[1]);
    }

    std::cout << "\nStart gaming!\n";
    std::vector<Team> teams = import_team("brr");

    int fract = played_games / 10;
    int w1 = 0, w2 = 0, tie = 0, tie_cap = 0;
/*
    {
        Timer timer;

        for(int i = 0; i < played_games; ++i)
        {
            if(i == fract)    { std::cout << "10%\n"; }
            if(i == fract * 2){ std::cout << "20%\n"; }
            if(i == fract * 3){ std::cout << "30%\n"; }
            if(i == fract * 4){ std::cout << "40%\n"; }
            if(i == fract * 5){ std::cout << "50%\n"; }
            if(i == fract * 6){ std::cout << "60%\n"; }
            if(i == fract * 7){ std::cout << "70%\n"; }
            if(i == fract * 8){ std::cout << "80%\n"; }
            if(i == fract * 9){ std::cout << "90%\n"; }

            //Battle battle({ teams[5], teams[23] });
            Battle battle({ Tests::TSS::aero, Tests::SpecOff::cm });

            int winner = battle.play_battle();

            switch(winner)
            {
                case 0:
                    ++tie_cap;
                    break;
                case 1:
                    ++w1;
                    break;
                case 2:
                    ++w2;
                    break;
                case 3:
                    ++tie;
                    break;
                default:
                    std::cout << winner << "\n";
                    std::cout << "Sumtin Wong\n";
                    break;
            }
        }
        std::cout << "Turn cap: " << constants::turn_cap << "\n";
        std::cout << "\nTeam 1 wins: " << w1;
        std::cout << "\nTeam 2 wins: " << w2;
        std::cout << "\nTies: " << tie;
        std::cout << "\nTies by turncap: " << tie_cap;
        std::cout << "\n" << played_games << " games played in:\n";
    }*/
    
    return 0;
}