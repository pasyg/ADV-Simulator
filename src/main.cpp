#include <fstream>
#include <iostream>

#include "define.hpp"

#include "src/tools/benchmark.hpp"

#include "tests.hpp"


int main(int argc, char* argv[]) {

  // import team sample for tests
  std::vector<Team> test;
  // file must consist of packed teams (packed showdown format) and be line by line
  test = import_team("sample");

  battle_test(test[0], test[1]);


  return 0;
}