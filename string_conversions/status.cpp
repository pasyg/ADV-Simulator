#include "string_conversions/status.hpp"

std::string_view to_string(Status const status){
    switch(status){
        case Status::healthy: return "healthy";
        case Status::fainted: return "fainted";
        case Status::paralysis: return "paralysis";
        case Status::freeze: return "freeze";
        case Status::sleep_self: return "sleep self";
        case Status::sleep_inflicted: return "sleep inflicted";
        case Status::confusion: return "confusion";
        case Status::burn: return "burn";
        case Status::poison: return "poison";
        case Status::toxic_poison: return "toxic poison";
        default: return "ERROR status";
    }
}

Status from_string(std::string_view str){
}