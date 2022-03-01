#include "test.hpp"

int main(int argc, char* argv[]) {

  Test all_test;
  all_test.test_all();

  // import team sample for tests
  std::vector<Team> test;
  // file must consist of packed teams (packed showdown format) and be line by line
  test = import_team("sample");
  //Battle tbattle(test[2], test[3]);
  for(auto&& team : test){
    team.team_init();
  }
  test[2].member[0].moveset[0].reduce_pp(555);
  for(auto&& mon : test[2].member){
    if(mon.species != Species::Starmie){
      mon.reduce_hp(999);
    }
  }
  for(int i = 0; i<100; ++i){
    test[2].get_move_options();
    test[2].decide_move();
    //std::cout << "Movechoice: " << to_string(test[2].movechoice->get_move()) << "\n";
  }
  // Pokemon Tyranitar;
  // Stats IVs = { 31, 30, 30, 31, 30, 31 };
  // Stats EVs = { 248, 252, 0, 0, 8, 0 };
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