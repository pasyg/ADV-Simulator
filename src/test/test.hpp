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
    bool check(std::string_view funcname, Func func)
    {
        if(func())
        {
            std::cout << funcname << " test successful\n\n";
            return true;
        }
        else
        {
            std::cout << funcname << " test NOT successful\n\n";
            return false;
        }
    }
}