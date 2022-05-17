#include "string_conversions/nature.hpp"

std::string_view to_string(Nature const name){ 
    switch(name){ 
        case Nature::Adamant:   return "adamant";
        case Nature::Bashful:   return "bashful";
        case Nature::Bold:      return "bold";
        case Nature::Brave:     return "brave";
        case Nature::Calm:      return "calm";
        case Nature::Careful:   return "careful";
        case Nature::Docile:    return "docile";
        case Nature::Gentle:    return "gentle";
        case Nature::Hardy:     return "hardy";
        case Nature::Hasty:     return "hasty";
        case Nature::Impish:    return "impish";
        case Nature::Jolly:     return "jolly";
        case Nature::Lax:       return "lax";
        case Nature::Lonely:    return "lonely";
        case Nature::Mild:      return "mild";
        case Nature::Modest:    return "modest";
        case Nature::Naive:     return "naive";
        case Nature::Naughty:   return "naughty";
        case Nature::Quiet:     return "quiet";
        case Nature::Quirky:    return "quirky";
        case Nature::Rash:      return "rash";
        case Nature::Relaxed:   return "relaxed";
        case Nature::Sassy:     return "sassy";
        case Nature::Serious:   return "serious";
        case Nature::Timid:     return "timid";
        default:                return "ERROR natures";
    }
}

template<>
auto from_string(std::string_view const str) -> Nature{
    static const std::unordered_map<std::string_view, Nature> map{ 
        {  "", Nature::Bashful  },
        { "Adamant", Nature::Adamant },
        { "Bashful", Nature::Bashful },
        { "Bold", Nature::Bold },
        { "Brave", Nature::Brave },
        { "Calm", Nature::Calm },
        { "Careful", Nature::Careful },
        { "Docile", Nature::Docile },
        { "Gentle", Nature::Gentle },
        { "Hardy", Nature::Hardy },
        { "Hasty", Nature::Hasty },
        { "Impish", Nature::Impish },
        { "Jolly", Nature::Jolly },
        { "Lax", Nature::Lax },
        { "Lonely", Nature::Lonely },
        { "Mild", Nature::Mild },
        { "Modest", Nature::Modest },
        { "Naive", Nature::Naive },
        { "Naughty", Nature::Naughty },
        { "Quiet", Nature::Quiet },
        { "Quirky", Nature::Quirky },
        { "Rash", Nature::Rash },
        { "Relaxed", Nature::Relaxed },
        { "Sassy", Nature::Sassy },
        { "Serious", Nature::Serious },
        { "Timid", Nature::Timid }
    };

    return map.at(str);
}