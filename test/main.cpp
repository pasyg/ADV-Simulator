#include <iostream>

#include "define.hpp"

#include "benchmark.hpp"

#include "data/base_stats.hpp"
#include "pokemon.hpp"

#include "string_conversions/gender.hpp"


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

    debug_log(Tyranitar.get_stats().hp);
    debug_log(Tyranitar.get_stats().atk);
    debug_log(Tyranitar.get_stats().def);
    debug_log(Tyranitar.get_stats().satk);
    debug_log(Tyranitar.get_stats().sdef);
    debug_log(Tyranitar.get_stats().spe);

    debug_log(Tyranitar.get_hiddenpower_power());

    debug_log(to_string(Tyranitar.get_gender()));
    
  return 0;
}