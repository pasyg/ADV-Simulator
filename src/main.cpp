#include <fstream>
#include <iostream>

#include "define.hpp"

#include "src/tools/benchmark.hpp"

#include "tools/import.hpp"

#include "data/base_stats.hpp"
#include "pokemon.hpp"

#include "string_conversions/gender.hpp"


int main(int argc, char** argv[]) {
  
#ifdef BENCHMARK
  Timer timer;
#endif
  std::ofstream file("../output.txt");
  std::vector<Team> test;
  // file must consist of packed teams (packed showdown format) and be line by line
  test = import_team("sample");

  // for(int i = 0; i < test.size(); ++i){
  //   std::cout << test[i].member[0].get_name() << std::endl;
  // }

//#ifdef _DEBUG
  for(int j = 0; j < test.size(); ++j){
    for(int i = 0; i < 6; ++i){
      file << test[j].member[i].get_name() << "@" << to_string(test[j].member[i].get_item()) << std::endl;
      file << "Level: " << test[j].member[i].get_level() << std::endl;
      file << "Gender: " << to_string(test[j].member[i].get_gender()) << std::endl;
      file << "Ability: " << to_string(test[j].member[i].get_ability()) << std::endl;
      file << "Nature: " << to_string(test[j].member[i].get_nature()) << std::endl;
      file << "hp evs: " << test[j].member[i].get_evs().hp << std::endl;
      file << "atk evs: " << test[j].member[i].get_evs().atk << std::endl;
      file << "def evs: " << test[j].member[i].get_evs().def << std::endl;
      file << "satk evs: " << test[j].member[i].get_evs().satk << std::endl;
      file << "sdef evs: " << test[j].member[i].get_evs().sdef << std::endl;
      file << "spe evs: " << test[j].member[i].get_evs().spe << std::endl;
      file << "hp ivs: " << test[j].member[i].get_ivs().hp << std::endl;
      file << "atk ivs: " << test[j].member[i].get_ivs().atk << std::endl;
      file << "def ivs: " << test[j].member[i].get_ivs().def << std::endl;
      file << "satk ivs: " << test[j].member[i].get_ivs().satk << std::endl;
      file << "sdef ivs: " << test[j].member[i].get_ivs().sdef << std::endl;
      file << "spe ivs: " << test[j].member[i].get_ivs().spe << std::endl;
      file << "Move 1: " << to_string(test[j].member[i].get_moveset()[0].get_move())<<std::endl;
      file << "Move 2: " << to_string(test[j].member[i].get_moveset()[1].get_move())<<std::endl;
      file << "Move 3: " << to_string(test[j].member[i].get_moveset()[2].get_move())<<std::endl;
      file << "Move 4: " << to_string(test[j].member[i].get_moveset()[3].get_move())<<std::endl<<std::endl;
    }
  }
//#endif
  return 0;
}