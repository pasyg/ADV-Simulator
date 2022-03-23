#pragma once

#include <functional>
#include <vector>

template<typename T, typename Function>
bool multi_or(std::vector<T> const &vec, Function func){
    for(auto&& elem : vec){
        if(func(elem)){
            return true;
        }
    }
    return false;
}

template<typename T, typename Function>
bool multi_and(std::vector<T> const &vec, Function func){
    for(auto&& elem : vec){
        if(!func(elem)){
            return false;
        }
    }
    return true;
}