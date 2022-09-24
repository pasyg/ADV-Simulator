#include <algorithm>
#include <array> 
#include <string_view>

#include "battle.hpp"
#include "team_test.hpp"
#include "test.hpp"

namespace Tests
{
    bool test_all_move();
    void refresh(Pokemon& poki);
    bool test_damage();
    bool test_crit();
    bool test_accuracy();
    bool test_status();
    bool test_healing();
    bool test_misc();
}