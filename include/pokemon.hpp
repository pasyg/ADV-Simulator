#pragma once

#include <array>

#include "abilities.hpp"
#include "natures.hpp"
#include "attackmove.hpp"
#include "species.hpp"
#include "status.hpp"

struct Stats{
    int hp;
    int atk;
    int def;
    int satk;
    int sdef;
    int spe;
};

class Pokemon{
public:
    Pokemon();
    ~Pokemon();

private:
    int level = 100;
    int happiness = 255;
    Stats basestats;
    Stats IVs;
    Stats EVs;
    Type hiddenpower;
    int hiddenpower_power = 70;
    Ability ability;
    Nature nature;
    Species species;
    Status status = Status::healthy;
    std::array<AttackMove, 4> move;
    std::array<Type, 2> type;
    bool revealed = false;
};