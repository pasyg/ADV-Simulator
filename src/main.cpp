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
  
  //Battle tbattle(test[2], test[3]);

  test[2].team_init();
  test[2].print_team();

  // Pokemon Tyranitar;
  // Stats IVs = { 31, 30, 30, 31, 30, 31 };
  // Stats EVs = { 248, 252, 0, 0, 8, 0};
  // std::array<Move, 4> moveset = { Move::Dragon_Dance, 
  //                                 Move::Rock_Slide,
  //                                 Move::Earthquake,
  //                                 Move::Hidden_Power };


  // Tyranitar.set_ivs(IVs);
  // Tyranitar.set_evs(EVs);
  // Tyranitar.set_moveset(moveset);
  // Tyranitar.set_nature(Nature::Adamant);
  // Tyranitar.set_item(Item::Leftovers);
  // Tyranitar.calc_atk();

  return 0;
}