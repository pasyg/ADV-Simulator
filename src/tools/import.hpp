#pragma once
#include <fstream>
#include <string>

#include "string_conversions/ability.hpp"
#include "string_conversions/gender.hpp"
#include "string_conversions/item.hpp"
#include "string_conversions/moves.hpp"
#include "string_conversions/nature.hpp"
#include "string_conversions/species.hpp"
#include "string_conversions/status.hpp"
#include "string_conversions/type.hpp"

#include "rng.hpp"
#include "team.hpp"

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
std::vector<Team> importteam(std::string const path);