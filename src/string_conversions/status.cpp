#include "string_conversions/status.hpp"

std::string_view to_string(Status const status){
    switch(status){
        case Status::Healthy:           return "healthy";
        case Status::Fainted:           return "fainted";
        case Status::Paralysis:         return "paralysis";
        case Status::Freeze:            return "freeze";
        case Status::Sleep_self:        return "sleep self";
        case Status::Sleep_inflicted:   return "sleep inflicted";
        case Status::Confusion:         return "confusion";
        case Status::Burn:              return "burn";
        case Status::Poison:            return "poison";
        case Status::Toxic_poison:      return "toxic poison";
        default:                        return "ERROR status";
    }
}

template<>
auto from_string(std::string_view const str) -> Status{
    static const std::unordered_map<std::string_view, Status> map{
        { "healthy", Status::Healthy },
        { "fainted", Status::Fainted },
        { "paralysis", Status::Paralysis },
        { "freeze", Status::Freeze },
        { "sleepself", Status::Sleep_self },
        { "sleepinflict", Status::Sleep_inflicted },
        { "confusion", Status::Confusion },
        { "burn", Status::Burn },
        { "poison", Status::Poison },
        { "toxicpoison", Status::Toxic_poison },
    };

    return map.at(str);
}