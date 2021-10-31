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

Status status_from_string(std::string_view str){
    if(str == "healthy"){
        return Status::healthy;
    }
    else if(str == "fainted"){
        return Status::fainted;
    }
    else if(str == "paralysis"){
        return Status::paralysis;
    }
    else if(str == "freeze"){
        return Status::freeze;
    }
    else if(str == "sleep_self"){
        return Status::sleep_self;
    }
    else if(str == "sleep_inflicted"){
        return Status::sleep_inflicted;
    }
    else if(str == "confusion"){
        return Status::confusion;
    }
    else if(str == "burn"){
        return Status::burn;
    }
    else if(str == "poison"){
        return Status::poison;
    }
    else if(str == "toxic_poison"){
        return Status::toxic_poison;
    }
    else{
        return Status::confusion;
    }
}