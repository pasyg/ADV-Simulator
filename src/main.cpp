#include <iostream>

#include "define.hpp"

#include "benchmark.hpp"

#include "tools/import.hpp"

#include "data/base_stats.hpp"
#include "pokemon.hpp"

#include "string_conversions/gender.hpp"

int main(int argc, char** argv[]) {
  
#ifdef BENCHMARK
  Timer timer;
#endif

  std::vector<Team> test;
  // file must consist of packed teams (packed showdown format) and be line by line
  test = import_team("sample");

  for(int i = 0; i < test.size(); ++i){
    std::cout << test[i].member[0].get_name() << std::endl;
  }

#ifdef _DEBUG
  // for(int i = 0; i < 6; ++i){
  //   debug_log(test.member[i].get_name() << "@" << to_string(test.member[i].get_item()));
  //   debug_log("Level: " << test.member[i].get_level());
  //   debug_log("Gender: " << to_string(test.member[i].get_gender()));
  //   debug_log("Ability: " << to_string(test.member[i].get_ability()));
  //   debug_log("Nature: " << to_string(test.member[i].get_nature()));
  //   debug_log("hp evs: " << test.member[i].get_evs().hp);
  //   debug_log("atk evs: " << test.member[i].get_evs().atk);
  //   debug_log("def evs: " << test.member[i].get_evs().def);
  //   debug_log("satk evs: " << test.member[i].get_evs().satk);
  //   debug_log("sdef evs: " << test.member[i].get_evs().sdef);
  //   debug_log("spe evs: " << test.member[i].get_evs().spe) << std::endl;
  //   debug_log("hp ivs: " << test.member[i].get_ivs().hp);
  //   debug_log("atk ivs: " << test.member[i].get_ivs().atk);
  //   debug_log("def ivs: " << test.member[i].get_ivs().def);
  //   debug_log("satk ivs: " << test.member[i].get_ivs().satk);
  //   debug_log("sdef ivs: " << test.member[i].get_ivs().sdef);
  //   debug_log("spe ivs: " << test.member[i].get_ivs().spe) << std::endl;
  //   debug_log("Move 1: " << to_string(test.member[i].get_moveset()[0].get_move()));
  //   debug_log("Move 2: " << to_string(test.member[i].get_moveset()[1].get_move()));
  //   debug_log("Move 3: " << to_string(test.member[i].get_moveset()[2].get_move()));
  //   debug_log("Move 4: " << to_string(test.member[i].get_moveset()[3].get_move()))<<std::endl<<std::endl;
  // }
#endif

  return 0;
}