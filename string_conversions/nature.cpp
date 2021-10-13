#include "string_conversions/nature.hpp"

std::string_view to_string(Nature const name){
    switch(name){
        case Nature::adamant: return "adamant";
        case Nature::bashful: return "bashful";
        case Nature::bold: return "bold";
        case Nature::brave: return "brave";
        case Nature::calm: return "calm";
        case Nature::careful: return "careful";
        case Nature::docile: return "docile";
        case Nature::gentle: return "gentle";
        case Nature::hardy: return "hardy";
        case Nature::hasty: return "hasty";
        case Nature::impish: return "impish";
        case Nature::jolly: return "jolly";
        case Nature::lax: return "lax";
        case Nature::lonely: return "lonely";
        case Nature::mild: return "mild";
        case Nature::modest: return "modest";
        case Nature::naive: return "naive";
        case Nature::naughty: return "naughty";
        case Nature::quiet: return "quiet";
        case Nature::quirky: return "quirky";
        case Nature::rash: return "rash";
        case Nature::relaxed: return "relaxed";
        case Nature::sassy: return "sassy";
        case Nature::serious: return "serious";
        case Nature::timid: return "timid";
        default: return "ERROR natures";
    }
}

Nature from_string(std::string_view str){
    if(str == "adamant"){
        return Nature::adamant;
    }
    else if(str == "bashful"){
        return Nature::bashful;
    }
    else if(str == "bold"){
        return Nature::bold;
    }
    else if(str == "brave"){
        return Nature::brave;
    }
    else if(str == "calm"){
        return Nature::calm;
    }
    else if(str == "careful"){
        return Nature::careful;
    }
    else if(str == "docile"){
        return Nature::docile;
    }
    else if(str == "gentle"){
        return Nature::gentle;
    }
    else if(str == "hardy"){
        return Nature::hardy;
    }
    else if(str == "hasty"){
        return Nature::hasty;
    }
    else if(str == "impish"){
        return Nature::impish;
    }
    else if(str == "jolly"){
        return Nature::jolly;
    }
    else if(str == "lax"){
        return Nature::lax;
    }
    else if(str == "lonely"){
        return Nature::lonely;
    }
    else if(str == "mild"){
        return Nature::mild;
    }
    else if(str == "modest"){
        return Nature::modest;
    }
    else if(str == "naive"){
        return Nature::naive;
    }
    else if(str == "naughty"){
        return Nature::naughty;
    }
    else if(str == "quiet"){
        return Nature::quiet;
    }
    else if(str == "quirky"){
        return Nature::quirky;
    }
    else if(str == "rash"){
        return Nature::rash;
    }
    else if(str == "relaxed"){
        return Nature::relaxed;
    }
    else if(str == "sassy"){
        return Nature::sassy;
    }
    else if(str == "serious"){
        return Nature::serious;
    }
    else{
        return Nature::timid;
    }
}