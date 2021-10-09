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

#define log(x) std::cout << (x) << std::endl;

int main(int argc, char** argv[]) {

    Pokemon Tyranitar, Abra, Alakazam, Gengar;

    std::array<Type, 2> tartype = {Type::Rock, Type::Dark};
    Stats tarev = {252,252,0,0,4,0};
    Stats tarstats;

    Tyranitar.set_ability(Ability::Sand_Stream);
    Tyranitar.set_type(tartype);
    Tyranitar.set_species(Species::Tyranitar);
    Tyranitar.set_basestats(base_stats(Tyranitar.get_species()));
    Tyranitar.set_nature(Nature::adamant);
    
    Tyranitar.stat_init();

    tarstats = Tyranitar.get_stats();
    log(tarstats.hp);
    log(tarstats.atk);
    log(tarstats.def);
    log(tarstats.satk);
    log(tarstats.sdef);
    log(tarstats.spe);

    log(Tyranitar.get_hiddenpower_power());

    


  return 0;
}