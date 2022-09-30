#pragma once

#include <vector>
#include <string>

#include "rng.hpp"

class Transition 
{
public:
    prng device;

    bool randomChance (int numerator, int denominator)
    {
        if (numerator >= denominator)
        {
            return true;
        }
        const int x = this->device.random_int(denominator);
        this->q *= denominator;
        if (x <= numerator)
        {
            this->p *= numerator;
            return true;
        } 
        else
        {
            this->p *= (denominator - numerator);
            return false;
        }
    }

    // Random integer sampled uniformly from [0, a)
    int random(int a)
    {
        this->q *= a;
        return this->device.random_int(a);
    }

    int random(int a, int b)
    {
        this->q *= b-a;
        return a + this->device.random_int(b - a);
    }

    void reset ()
    {
        this->p = 1;
        this->q = 1;
        log_string.clear();
    }

private:
    int p = 1;
    int q = 1;
    std::vector<std::string> log_string;

};