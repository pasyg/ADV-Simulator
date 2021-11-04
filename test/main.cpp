#include <iostream>

#include "define.hpp"

#include "benchmark.hpp"

#include "tools/import.hpp"

#include "data/base_stats.hpp"
#include "pokemon.hpp"

#include "string_conversions/gender.hpp"


int main(int argc, char** argv[]) {
  
  Timer timer;

  Team test;
  test = importteam("sample");

  for(int i = 0; i < 6; ++i){
    std::cout << test.member[i].get_name() << std::endl;
    std::cout << test.member[i].
  }

  return 0;
}