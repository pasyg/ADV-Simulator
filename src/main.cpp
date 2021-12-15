#include <fstream>
#include <iostream>
#include <thread>

#include "define.hpp"

#include "src/tools/benchmark.hpp"

#include "tests.hpp"


int main(int argc, char* argv[]) {

  // import team sample for tests
  std::vector<Team> test;
  // file must consist of packed teams (packed showdown format) and be line by line
  test = import_team("sample");

  battle_test(test[0], test[1]);

  std::thread t_1(battle_test, test[0], test[1]);
  std::thread t_2(battle_test, test[2], test[3]);
  std::thread t_3(battle_test, test[4], test[5]);
  std::thread t_4(battle_test, test[6], test[7]);
  std::thread t_5(battle_test, test[8], test[9]);
  std::thread t_6(battle_test, test[10], test[11]);
  std::thread t_7(battle_test, test[12], test[13]);
  std::thread t_8(battle_test, test[14], test[15]);

  t_1.join();
  t_2.join();
  t_3.join();
  t_4.join();
  t_5.join();
  t_6.join();
  t_7.join();
  t_8.join();

  return 0;
}