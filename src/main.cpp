#include "test.hpp"

int main(int argc, char* argv[]) {

  Test all_test;
  all_test.test_all();

  std::vector<Team> teams = import_team("brr");
  Battle battle(teams[1], teams[10]);
  battle.play_battle();
  battle.team[0].print_team();
  std::cout << "==========\n";
  battle.team[1].print_team();
  return 0;
}