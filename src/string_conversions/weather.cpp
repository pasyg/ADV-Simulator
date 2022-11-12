#include "string_conversions/weather.hpp"

std::string_view to_string(Weather const name){
    switch(name){
        case Weather::Clear:    return "Clear";
        case Weather::Hail:     return "Hail";
        case Weather::Rain:     return "Rain";
        case Weather::Sand:     return "Sandstorm";
        case Weather::Sun:      return "Sun";
        default:                return "ERROR weather";
    }
}

template<>
auto from_string(std::string_view const str) -> Weather{
   static const std::unordered_map<std::string_view, Weather> map{
       { "Clear", Weather::Clear },
       { "Hail", Weather::Hail },
       { "Rain", Weather::Rain },
       { "Sand", Weather::Sand },
       { "Sun", Weather::Sun },
   };
   
   return map.at(str);
}