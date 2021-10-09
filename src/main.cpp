#include <iostream>

#include "benchmark.hpp"

#include "base_stats.hpp"
#include "pokemon.hpp"

#define OHKO_CLAUSE

#define log(x) std::cout << (x) << std::endl;

int main(int argc, char** argv[]) {

    Pokemon Tyranitar, Abra, Alakazam, Gengar;

    std::array<Type, 2> tartype = {Type::Rock, Type::Dark};
    Stats tarev = {252,252,0,0,4,0};
    Stats tarstats;

    Tyranitar.set_ability(Ability::Sand_Stream);
    Tyranitar.set_type(tartype);
    Tyranitar.set_species(Species::Tyranitar);
    Tyranitar.set_basestats(base_stats(Tyranitar.get_species()));
    Tyranitar.set_nature(Nature::adamant);
    
    Tyranitar.stat_init();

    tarstats = Tyranitar.get_stats();
    log(tarstats.hp);
    log(tarstats.atk);
    log(tarstats.def);
    log(tarstats.satk);
    log(tarstats.sdef);
    log(tarstats.spe);

    log(Tyranitar.get_hiddenpower_power());

    
  return 0;
}