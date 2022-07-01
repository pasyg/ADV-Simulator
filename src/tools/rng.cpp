#include "rng.hpp"

int get_random(int a = 0, int b = 100){
    
    static auto engine = std::mt19937(std::random_device()());
    auto distribution = std::uniform_int_distribution<>(a, b);
    auto const random_number = distribution(engine);

    return random_number;
}