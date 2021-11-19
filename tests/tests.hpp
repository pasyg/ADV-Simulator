#pragma once
#include <fstream>
#include <vector>

#include "tools/import.hpp"

#include "data/base_stats.hpp"
#include "string_conversions/gender.hpp"

void init_test(std::vector<Team> &test);

void battle_test(Team &team1, Team &team2);