///
/// simple timer for benchmark testing
/// use by creating Timer object within a scope
/// will be destructed at the end of the scope
/// and shows needed time by itself
///
#pragma once

#include <chrono>

#include <iostream>

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
        double us = static_cast<double>(duration);
        double ms = us * 0.001;
        double s = ms * 0.001;
        std::cout << duration << " us\n";
        std::cout << ms << " ms\n";
        std::cout << s << " s" << std::endl;
    }
    private:
    std::chrono::time_point<std::chrono::steady_clock> StartTimepoint;
};