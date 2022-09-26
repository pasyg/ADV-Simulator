#include "rng.hpp"


// TODO Remove this. Only needed by non battle objects.
int get_random(int a = 0, int b = 100){
    
    static auto engine = std::mt19937(std::random_device()());
    auto distribution = std::uniform_int_distribution<>(a, b);
    auto const random_number = distribution(engine);

    return random_number;
}

prng::prng () :
seed(std::random_device{}()), engine(std::mt19937 {seed}) {}
prng::prng (std::mt19937::result_type seed) : 
seed(seed), engine(std::mt19937 {seed}) {}

// Same device and seed, but 'restarted'
// Default copy keeps progress
prng prng :: copy () {
    return prng(seed);
}

std::mt19937::result_type prng :: get_seed () {
    return seed;
}

double prng :: uniform () {
    return uniform_(engine);
}

int prng :: random_int (int n) {
    return int (this->uniform() * n);
}

// samples an index from a probability distribution
int prng :: sample_pdf (double* input, int k) {
    double p = this->uniform();
    for (int i = 0; i < k; ++i) {
        p -= input[i];
        if (p <= 0) {
            return i;
        }
    }
    return 0;
}