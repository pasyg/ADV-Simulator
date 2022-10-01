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
    //Tests::test_all();

    int played_games = 100;

    if(argc > 1)
    {
        played_games = std::stoi(argv[1]);
    }

    std::cout << "\nStart gaming!\n";
    std::vector<Team> teams = import_team("brr");
    std::array<Team, 2> teamsS { Tests::TSS::aero, Tests::SpecOff::cm };

    int fract = played_games / 10;
    int w1 = 0, w2 = 0, tie = 0, tie_cap = 0;

    {
        Timer timer;

        for(int i = 0; i < played_games; ++i)
        {
            constants::progress(i, played_games);
            //Battle battle(teamsS);
            //Battle battle({ teams[5], teams[23] });
            Battle battle({ Tests::Physoff::std, Tests::Alph::TZ });

           int winner = battle.play_battle();

            switch(winner)
            {
                case 0: ++tie_cap; break;
                case 1:      ++w1; break;
                case 2:      ++w2; break;
                case 3:     ++tie; break;
                default:
                    std::cout << winner << "\n";
                    std::cout << "Sumtin Wong\n";
                    break;
            }
        }
        constants::summary(w1, w2, tie, tie_cap, played_games);
    }
    
    return 0;
}