#pragma once

#include "test_pokemon.hpp"

namespace Tests
{
    typedef std::array<Pokemon, 6> team;

    namespace TSS
    {
        static constexpr team aero_  = { Skarmory::std, Blissey::twave, Tyranitar::cb, Swampert::std, Gengar::std, Aerodactyl::cb };
        static constexpr team sbt_   = { Skarmory::std, Blissey::twave, Tyranitar::cb, Zapdos::modest, Celebi::dlseed, Claydol::std };

        static constexpr Team aero  = Team(aero_);
        static constexpr Team sbt   = Team(sbt_);
    };

    namespace SpecOff
    {
        static constexpr team cm_ = { Suicune::off, Dugtrio::std, Jirachi::super, Celebi::off, Swampert::std, Tyranitar::dd };

        static constexpr Team cm  = Team(cm_);
    };

    namespace Physoff
    {
        static constexpr team std_ = { Zapdos::modest, Metagross::spec, Swampert::std, Tyranitar::dd, Magneton::mag, Snorlax::off };

        static constexpr Team std  = Team(std_);
    };

    namespace Alph
    {
        static constexpr team ABCe_ { Aerodactyl::cb, Aerodactyl::liechi, Blissey::twave, Blissey::counter, Breloom::std, Celebi::dlseed };
        static constexpr team C_    { Charizard::std, Charizard::beatup, Claydol::std, Claydol::ref, Cloyster::spin, Cloyster::std };
        static constexpr team DFG_  { Dugtrio::std, Flygon::cb, Flygon::def, Forretress::std, Gengar::std, Gengar::off };
        static constexpr team GHJ_  { Gyarados::std, Gyarados::rest, Heracross::sd, Heracross::cb, Jirachi::asta, Jirachi::super };
        static constexpr team JM_   { Jolteon::std, Magneton::mag, Magneton::salac, Metagross::phys, Metagross::spec, Milotic::op };
        static constexpr team MS_   { Moltres::std, Salamence::mix, Salamence::cb, Skarmory::std, Snorlax::curse, Snorlax::off };
        static constexpr team S_    { Starmie::off, Starmie::def, Suicune::off, Suicune::huso, Swampert::std, Swampert::off };
        static constexpr team TZ_   { Tyranitar::cb, Tyranitar::dd, Tyranitar::suit, Zapdos::modest, Zapdos::timid, Zapdos::rest };

        static constexpr Team ABCe  = Team(ABCe_);
        static constexpr Team C     = Team(C_);
        static constexpr Team DFG   = Team(DFG_);
        static constexpr Team GHJ   = Team(GHJ_);
        static constexpr Team JM    = Team(JM_);
        static constexpr Team MS    = Team(MS_);
        static constexpr Team S     = Team(S_);
        static constexpr Team TZ    = Team(TZ_);
    }
};