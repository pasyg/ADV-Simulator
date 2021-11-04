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

Nature nature_from_string(std::string_view const str){ 

    static std::unordered_map<std::string_view, Nature> map{ 
        
        { "Adamant", Nature::adamant },
        { "Bashful", Nature::bashful },
        { "Bold", Nature::bold },
        { "Brave", Nature::brave },
        { "Calm", Nature::calm },
        { "Careful", Nature::careful },
        { "Docile", Nature::docile },
        { "Gentle", Nature::gentle },
        { "Hardy", Nature::hardy },
        { "Hasty", Nature::hasty },
        { "Impish", Nature::impish },
        { "Jolly", Nature::jolly },
        { "Lax", Nature::lax },
        { "Lonely", Nature::lonely },
        { "Mild", Nature::mild },
        { "Modest", Nature::modest },
        { "Naive", Nature::naive },
        { "Naughty", Nature::naughty },
        { "Quiet", Nature::quiet },
        { "Quirky", Nature::quirky },
        { "Rash", Nature::rash },
        { "Relaxed", Nature::relaxed },
        { "Sassy", Nature::sassy },
        { "Serious", Nature::serious },
        { "Timid", Nature::timid }
    };

    return map[str];
}