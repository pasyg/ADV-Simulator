#pragma once

#include "species.hpp"

///
/// stat structs for easy handling with IVs, EVs,
/// base stats and real stats and easy function returns
/// 

struct Stats{
    int hp;
    int atk;
    int def;
    int satk;
    int sdef;
    int spe;
};

Stats base_stats(Species species);