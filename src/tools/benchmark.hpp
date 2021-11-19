///
/// simple timer for benchmark testing
/// use by creating Timer object within a defined scope
/// will be destructed and shows needed time by itself
///
#pragma once

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

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(StartTimepoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

        auto duration = end - start;
        double us = duration;
        double ms = us * 0.001;
        double s = ms * 0.001;
        std::cout << duration << " us" << std::endl;
        std::cout << ms << " ms" << std::endl;
        std::cout << s << " s" << std::endl;
    }
    private:
    std::chrono::time_point<std::chrono::steady_clock> StartTimepoint;
};
#endif