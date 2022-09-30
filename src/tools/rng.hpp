#pragma once

#include <random>
#include <array>

int get_random (int a, int b);

class prng
{
    std::mt19937::result_type seed;
    std::mt19937 engine;
    std::uniform_real_distribution<double> uniform_;
    
public:

    prng ();
    prng (std::mt19937::result_type seed);

    // Same device and seed, but 'restarted'
    // Default copy keeps progress
    prng copy();
    std::mt19937::result_type get_seed ();
    double uniform ();
    int random_int (int n);

    // samples an index from a probability distribution
    int sample_pdf (double* input, int k);

    template <typename T, size_t N>
    int sample_pdf (std::array<T, N> input, int k)
    {
        double p = uniform();
        for (int i = 0; i < k; ++i)
        {
            p -= input[i];
            if (p <= 0)
            {
                return i;
            }
        }
        return 0;
    }
};