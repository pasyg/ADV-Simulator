#include "test.hpp"

int main(int argc, char* argv[]) {

  Test all_test;
  //all_test.test_all();

  std::vector<Team> teams = import_team("brr");
  {
    Timer timer;
    for(int i = 0; i<100000; ++i){

      Battle battle(teams[5], teams[23]);
      int winner = battle.play_battle();
      switch(winner){
        case 0: 
          std::cout << "Team 1 wins!" << std::endl;
          break;
        case 1:
          std::cout << "Team 2 wins!" << std::endl;
          break;
        case 2:
          std::cout << "TIIIIEEEE!!!!" << std::endl;
          break;
      }
    //battle.team[0].print_team();
    // std::cout << "==========\n";
    // battle.team[1].print_team();
    // if(winner == false){
    //   std::cout << "team 1 wins\n";
    // }
    // else{
    //   std::cout << "team 2 wins\n";
    }
  }
  return 0;
}