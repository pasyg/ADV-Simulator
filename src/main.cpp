#include <iostream>

#include "benchmark.hpp"

#include "base_stats.hpp"
#include "pokemon.hpp"

#include "string_conversions/gender.hpp"


#define OHKO_CLAUSE

#define log(x) std::cout << (x) << std::endl;

int main(int argc, char** argv[]) {

    Pokemon Tyranitar, Abra, Alakazam, Gengar;

    std::array<Type, 2> tartype = {Type::Rock, Type::Dark};
    Stats tarev = {252,252,0,0,4,0};

    Tyranitar.set_ability(Ability::Sand_Stream);
    Tyranitar.set_type(tartype);
    Tyranitar.set_species(Species::Tyranitar);
    Tyranitar.set_basestats(base_stats(Tyranitar.get_species()));
    Tyranitar.set_nature(Nature::adamant);
    Tyranitar.set_gender(Gender::male);
    
    Tyranitar.stat_init();

    log(Tyranitar.get_stats().hp);
    log(Tyranitar.get_stats().atk);
    log(Tyranitar.get_stats().def);
    log(Tyranitar.get_stats().satk);
    log(Tyranitar.get_stats().sdef);
    log(Tyranitar.get_stats().spe);

    log(Tyranitar.get_hiddenpower_power());

    log(to_string(Tyranitar.get_gender()));
    
  return 0;
}