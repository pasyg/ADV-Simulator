#pragma once

#include "species.hpp"

///
/// stat structs for easy handling with IVs, EVs,
/// base stats and real stats and easy function returns
/// 

struct Stats
{
    int hp;
    int atk;
    int def;
    int satk;
    int sdef;
    int spe;
    Stats(){};
    constexpr Stats(int t_hp, int t_atk, int t_def, int t_satk, int t_sdef, int t_spe) :
	    hp(t_hp), atk(t_atk), def(t_def), satk(t_satk), sdef(t_sdef), spe(t_spe){};
};

Stats base_stats(Species species);