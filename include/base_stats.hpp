#pragma once

#include "species.hpp"

struct BaseStats{
    int hp;
    int atk;
    int def;
    int satk;
    int sdef;
    int spd;
};

BaseStats base_stats(Species species);