#pragma once

#include "test_pokemon.hpp"

namespace Tests{
    typedef std::array<Pokemon, 6> team;

    namespace TSS{
        static const team aero_  = { *Tests::Skarmory::std, *Tests::Blissey::twave, *Tests::Tyranitar::cb, *Tests::Swampert::std, *Tests::Gengar::std, *Tests::Aerodactyl::cb };
        static const team sbt_   = { *Tests::Skarmory::std, *Tests::Blissey::twave, *Tests::Tyranitar::cb, *Tests::none, *Tests::none, *Tests::none };

        static const Team* aero  = new Team(aero_);
        static const Team* sbt   = new Team(sbt_);
    };

    namespace SpecOff{

    };

    namespace Physoff{

    };

};