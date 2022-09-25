#pragma once

#include <fstream>
#include <limits>
#include <string>
#include <vector>

#include "test_moves.hpp"
#include "test_pokemon.hpp"

#include "benchmark.hpp"

namespace Tests
{
    template<typename Func>
    bool check(Func func)
    {
        if(func())
        {
            return true;
        }
        else
        {
            std::cout << "failed" << std::endl;
            return false;
        }
    }
}