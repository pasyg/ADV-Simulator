#include "test.hpp"

constexpr int played_games = 100000;

std::string create_filepath(){
    auto time = std::chrono::steady_clock::now();
    int lTime = time.time_since_epoch().count();

    std::string path = "replays/" + std::to_string(lTime) + ".html";
    return path;
}

int main(int argc, char* argv[]) {

  Test test;
  test.test_all();

  int w1 = 0, w2 = 0, tie = 0, tie_cap = 0;

  std::cout << "\nStart gaming!\n";
  
  std::vector<Team> teams = import_team("brr");

  {
    Timer timer;
    int fract = played_games / 10;
    for(int i = 0; i < played_games; ++i){
      if(i == played_games){ std::cout << "10%\n"; }
      if(i == played_games * 2){ std::cout << "20%\n"; }
      if(i == played_games * 3){ std::cout << "30%\n"; }
      if(i == played_games * 4){ std::cout << "40%\n"; }
      if(i == played_games * 5){ std::cout << "50%\n"; }
      if(i == played_games * 6){ std::cout << "60%\n"; }
      if(i == played_games * 7){ std::cout << "70%\n"; }
      if(i == played_games * 8){ std::cout << "80%\n"; }
      if(i == played_games * 9){ std::cout << "90%\n"; }

      Battle battle(teams[5], teams[23]);

      int winner = battle.play_battle();
      // log stuff in battle.cpp
      switch(winner){
        case 0: 
          ++tie_cap;
          //battle.logger << "|win|Player 1";
          break;
        case 1:
          ++w1;
          //battle.logger << "|win|Player 2";
          break;
        case 2:
          ++w2;
          //battle.logger << "|tie|";
          break;
        case 3: 
          ++tie;
      }
    }
  std::cout << "Turn cap: " << constants::turn_cap << "\n";
  std::cout << "\nTeam 1 wins: " << w1;
  std::cout << "\nTeam 2 wins: " << w2;
  std::cout << "\nTies: " << tie << "\n";
  std::cout << "\nTies by turncap: " << tie_cap << "\n";
  std::cout << played_games << " games played in:\n";

  return 0;
 } 
}