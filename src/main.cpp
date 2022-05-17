#pragma once

#include "test.hpp"

constexpr int played_games = 10;

std::string create_filepath(){
    auto time = std::chrono::steady_clock::now();
    int lTime = time.time_since_epoch().count();

    std::string path = "replays/" + std::to_string(lTime) + ".html";
    return path;
}

int main(int argc, char* argv[]) {

  // Test all_test;
  // all_test.test_all();

  int w1 = 0, w2 = 0, tie = 0;

  std::cout << "Start gaming!\n";

  std::vector<Team> teams = import_team("brr");
  {
    Timer timer;
    for(int i = 0; i < played_games; ++i){
      if(i == played_games / 10){ std::cout << "10%\n"; }
      if(i == played_games / 5){ std::cout << "20%\n"; }
      if(i == played_games / 2){ std::cout << "50%\n"; }

      Battle battle(teams[5], teams[23], create_filepath());

      int winner = battle.play_battle();
      // log stuff in battle.cpp
      switch(winner){
        case 0: 
          ++w1;
          battle.logger << "|win|Player 1";
          break;
        case 1:
          ++w2;
          battle.logger << "|win|Player 2";
          break;
        case 2:
          ++tie;
          battle.logger << "|tie|";
          break;
      }
    }
  std::cout << "Turn cap: " << constants::turn_cap << "\n";
  std::cout << played_games << " games played in:\n";
  std::cout << "\nTeam 1 wins: " << w1;
  std::cout << "\nTeam 2 wins: " << w2;
  std::cout << "\nTies: " << tie << "\n";

  return 0;
  } 
}