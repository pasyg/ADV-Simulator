#pragma once
#include <fstream>
#include <string>

#include "string_conversions/string_conversions.hpp"

#include "rng.hpp"
#include "battle.hpp"

struct Strstats{
    std::string hp;
    std::string atk;
    std::string def;
    std::string satk;
    std::string sdef;
    std::string spe;
};

void set_moves(std::string &moves, Pokemon &pokemon);
void set_evs(std::string &evs, Pokemon &pokemon);
void set_ivs(std::string &ivs, Pokemon &pokemon);
std::vector<Team> import_team(std::string_view path);