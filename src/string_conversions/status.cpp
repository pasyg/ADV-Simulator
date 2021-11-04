#include "string_conversions/status.hpp"

std::string_view to_string(Status const status){
    switch(status){
        case Status::healthy:           return "healthy";
        case Status::fainted:           return "fainted";
        case Status::paralysis:         return "paralysis";
        case Status::freeze:            return "freeze";
        case Status::sleep_self:        return "sleep self";
        case Status::sleep_inflicted:   return "sleep inflicted";
        case Status::confusion:         return "confusion";
        case Status::burn:              return "burn";
        case Status::poison:            return "poison";
        case Status::toxic_poison:      return "toxic poison";
        default:                        return "ERROR status";
    }
}

Status status_from_string(std::string_view const str){

    static std::unordered_map<std::string_view, Status> map{
        
        { "healthy", Status::healthy },
        { "fainted", Status::fainted },
        { "paralysis", Status::paralysis },
        { "freeze", Status::freeze },
        { "sleepself", Status::sleep_self },
        { "sleepinflict", Status::sleep_inflicted },
        { "confusion", Status::confusion },
        { "burn", Status::burn },
        { "poison", Status::poison },
        { "toxicpoison", Status::toxic_poison },
    };

    return map[str];
}