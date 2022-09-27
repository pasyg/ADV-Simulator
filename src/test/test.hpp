#pragma once

#include <fstream>
#include <limits>
#include <string>
#include <vector>

#include "test_moves.hpp"
#include "test_pokemon.hpp"
#include "import_test.hpp"
#include "mechanic_test.hpp"
#include "move_test.hpp"

#include "benchmark.hpp"

namespace Tests
{
    void test_all();

    template<typename Func>
    bool check(Func func)
    {
        if(func())
        {
            return true;
        }
        else
        {
            std::cout << "failed\n";
            return false;
        }
    }
}