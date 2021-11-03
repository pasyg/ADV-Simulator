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

Nature nature_from_string(std::string_view str){
    if(str == "Adamant"){
        return Nature::adamant;
    }
    else if(str == "Bashful"){
        return Nature::bashful;
    }
    else if(str == "Bold"){
        return Nature::bold;
    }
    else if(str == "Brave"){
        return Nature::brave;
    }
    else if(str == "Calm"){
        return Nature::calm;
    }
    else if(str == "Careful"){
        return Nature::careful;
    }
    else if(str == "Docile"){
        return Nature::docile;
    }
    else if(str == "Gentle"){
        return Nature::gentle;
    }
    else if(str == "Hardy"){
        return Nature::hardy;
    }
    else if(str == "Hasty"){
        return Nature::hasty;
    }
    else if(str == "Impish"){
        return Nature::impish;
    }
    else if(str == "Jolly"){
        return Nature::jolly;
    }
    else if(str == "Lax"){
        return Nature::lax;
    }
    else if(str == "Lonely"){
        return Nature::lonely;
    }
    else if(str == "Mild"){
        return Nature::mild;
    }
    else if(str == "Modest"){
        return Nature::modest;
    }
    else if(str == "Naive"){
        return Nature::naive;
    }
    else if(str == "Naughty"){
        return Nature::naughty;
    }
    else if(str == "Quiet"){
        return Nature::quiet;
    }
    else if(str == "Quirky"){
        return Nature::quirky;
    }
    else if(str == "Rash"){
        return Nature::rash;
    }
    else if(str == "Relaxed"){
        return Nature::relaxed;
    }
    else if(str == "Sassy"){
        return Nature::sassy;
    }
    else if(str == "Serious"){
        return Nature::serious;
    }
    else{
        return Nature::timid;
    }
}