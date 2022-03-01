#pragma once

#include <fstream>
#include <functional>
#include <string>
#include <vector>

#include "tools/import.hpp"

#include "data/base_stats.hpp"
#include "../string_conversions/ability.hpp"
#include "../string_conversions/gender.hpp"
#include "../string_conversions/item.hpp"
#include "../string_conversions/moves.hpp"
#include "../string_conversions/nature.hpp"
#include "../string_conversions/species.hpp"
#include "../string_conversions/status.hpp"
#include "../string_conversions/type.hpp"

class Test{
public:
    Test();
    ~Test();
    void test_all();
    void check(std::string functionname, std::function<bool()> function);
    bool test_import();
    bool test_team_init();
private:
    std::vector<Team> teams;
    bool import_test;
    bool team_init_test;
};