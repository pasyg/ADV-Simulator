#include <iostream>

#include "base_stats.hpp"
#include "pokemon.hpp"

#define OHKO_CLAUSE

#ifdef BENCHMARK
#include <chrono>
class Timer{
    public:
    Timer(){
        StartTimepoint = std::chrono::steady_clock::now();
    }
    ~Timer(){
        Stop();
    }
    void Stop(){
        auto endTimepoint = std::chrono::steady_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::nanoseconds>(StartTimepoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::nanoseconds>(endTimepoint).time_since_epoch().count();

        auto duration = end - start;
        double us = duration * 0.001;
        double ms = us * 0.001;
        std::cout << duration << " ns" << std::endl;
        std::cout << us << " us" << std::endl;
        std::cout << ms << " ms" << std::endl;
    }
    private:
    std::chrono::time_point<std::chrono::steady_clock> StartTimepoint;
};
#endif

int main(int argc, char** argv[]) {

    Pokemon Abra;

    BaseStats abra_stats = base_stats(Species::Abra); 

    std::cout << abra_stats.hp << std::endl;
    std::cout << abra_stats.atk << std::endl;
    std::cout << abra_stats.def << std::endl;
    std::cout << abra_stats.satk << std::endl;
    std::cout << abra_stats.sdef << std::endl;
    std::cout << abra_stats.spd << std::endl;


  return 0;
}