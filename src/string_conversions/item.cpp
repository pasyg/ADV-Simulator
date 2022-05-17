#include "string_conversions/item.hpp"

std::string_view to_string(Item const item){
    switch(item){
        case Item::None:            return "none";
        case Item::Choiceband:      return "Leftovers";
        case Item::Leftovers:       return "Leftovers";
        case Item::Lumberry:        return "Lum Berry";
        case Item::Salacberry:      return "Salac Berry";
        case Item::Apicotberry:     return "Apicot Berry";
        case Item::Blackbelt:       return "Black Belt";
        case Item::Blackglasses:    return "Black Glasses";
        case Item::Brightpowder:    return "Bright Powder";
        case Item::Charcoal:        return "Charcoal";
        case Item::Chestoberry:     return "Chesto Berry";
        case Item::Dragonfang:      return "Dragon Fang";
        case Item::Ganlonberry:     return "Ganlon Berry";
        case Item::Hardstone:       return "Hard Stone";
        case Item::Kingsrock:       return "Kings Rock";
        case Item::Lansatberry:     return "Lansat Berry";
        case Item::Laxincense:      return "Lax Incense";
        case Item::Leppaberry:      return "Leppa Berry";
        case Item::Liechiberry:     return "Liechi Berry";
        case Item::Magnet:          return "Magnet";
        case Item::Mail:            return "Mail";
        case Item::Metalcoat:       return "Metal Coat";
        case Item::Miracleseed:     return "Miracle Seed";
        case Item::Mysticwater:     return "Mystic Water";
        case Item::Nevermeltice:    return "Never Melt Ice";
        case Item::Petayaberry:     return "Petaya Berry";
        case Item::Poisonbarb:      return "Poison Barb";
        case Item::Quickclaw:       return "Quick Claw";
        case Item::Scopelens:       return "Scope Lens";
        case Item::Seaincense:      return "Sea Incense";
        case Item::Sharpbeak:       return "Sharp Beak";
        case Item::Shellbell:       return "Shell Bell";
        case Item::Silkscarf:       return "Silk Scarf";
        case Item::Silverpowder:    return "Silver Powder";
        case Item::Softsand:        return "Soft Sand";
        case Item::Spelltag:        return "Spell Tag";
        case Item::Starfberry:      return "Starf Berry";
        case Item::Twistedspoon:    return "Twisted Spoon";
        case Item::Whiteherb:       return "White Herb";
        case Item::Deepseascale:    return "Deep Sea Scale";
        case Item::Deepseatooth:    return "Deep Sea Tooth";
        case Item::Lightball:       return "Light Ball";
        case Item::Luckypunch:      return "Lucky Punch";
        case Item::Metalpowder:     return "Metal Powder";
        case Item::Souldew:         return "Soul Dew";
        case Item::Stick:           return "Stick";
        case Item::Thickclub:       return "Thick Club";
        case Item::Aguavberry:      return "Aguav Berry";
        case Item::Aspearberry:     return "Aspear Berry";
        case Item::Cheriberry:      return "Cheri Berry";
        case Item::Figyberry:       return "Figy Berry";
        case Item::Focusband:       return "Focus Band";
        case Item::Iapapaberry:     return "Iapapa Berry";
        case Item::Machobrace:      return "Macho Brace";
        case Item::Magoberry:       return "Mago Berry";
        case Item::Rawstberry:      return "Rawst Berry";
        case Item::Mentalherb:     return "Mental Herb";
        case Item::Oranberry:       return "Oran Berry";
        case Item::Pechaberry:      return "Pecha Berry";
        case Item::Persimberry:     return "Persim Berry";
        case Item::Sitrusberry:     return "Sitrus Berry";
        case Item::Wikiberry:       return "Wiki Berry";
        default:                    return "ERROR item";
    }
}

template<>
auto from_string(std::string_view const str) -> Item{
    static const std::unordered_map<std::string_view, Item> map{ 
        { "", Item::None },
        { "Leftovers", Item::Leftovers },
        { "LumBerry", Item::Lumberry },
        { "SalacBerry", Item::Salacberry },
        { "ChoiceBand", Item::Choiceband },
        { "ThickClub", Item::Thickclub },
        { "LightBall", Item::Lightball },
        { "DeepSeaScale", Item::Deepseascale },
        { "DeepSeaTooth", Item::Deepseatooth },
        { "BlackBelt", Item::Blackbelt },
        { "SharpBeak", Item::Sharpbeak },
        { "MetalCoat", Item::Metalcoat },
        { "PoisonBarb", Item::Poisonbarb },
        { "SoftSand", Item::Softsand },
        { "SilkScarf", Item::Silkscarf },
        { "SpellTag", Item::Spelltag },
        { "BlackGlasses", Item::Blackglasses },
        { "Charcoal", Item::Charcoal },
        { "Magnet", Item::Magnet },
        { "DragonFang", Item::Dragonfang },
        { "MiracleSeed", Item::Miracleseed },
        { "MysticWater", Item::Mysticwater },
        { "SeaIncense", Item::Seaincense },
        { "NeverMeltIce", Item::Nevermeltice },
        { "TwistedSpoon", Item::Twistedspoon },
        { "ScopeLens", Item::Scopelens },
        { "Stick", Item::Stick },
        { "ApicotBerry", Item::Apicotberry },
        { "BrightPowder", Item::Brightpowder },
        { "ChestoBerry", Item::Chestoberry },
        { "GanlonBerry", Item::Ganlonberry },
        { "HardStone", Item::Hardstone },
        { "KingsRock", Item::Kingsrock },
        { "LansatBerry", Item::Lansatberry },
        { "LaxIncense", Item::Laxincense },
        { "SoulDew", Item::Souldew },
        { "LeppaBerry", Item::Leppaberry },
        { "LiechiBerry", Item::Liechiberry },
        { "Mail", Item::Mail },
        { "PetayaBerry", Item::Petayaberry },
        { "QuickClaw", Item::Quickclaw },
        { "ShellBell", Item::Shellbell },
        { "SilverPowder", Item::Silverpowder },
        { "StarfBerry", Item::Starfberry },
        { "WhiteHerb", Item::Whiteherb },
        { "LuckyPunch", Item::Luckypunch },
        { "MetalPowder", Item::Metalpowder },
        { "AguavBerry", Item::Aguavberry },
        { "AspearBerry", Item::Aspearberry },
        { "CheriBerry", Item::Cheriberry },
        { "FigyBerry", Item::Figyberry },
        { "FocusBand", Item::Focusband },
        { "IapapaBerry", Item::Iapapaberry },
        { "MachoBrace", Item::Machobrace },
        { "MagoBerry", Item::Magoberry },
        { "MentalHerb", Item::Mentalherb },
        { "OranBerry", Item::Oranberry },
        { "PechaBerry", Item::Pechaberry },
        { "PersimBerry", Item::Persimberry },
        { "RawstBerry", Item::Rawstberry },
        { "SitrusBerry", Item::Sitrusberry },
        { "WikiBerry", Item::Wikiberry },
    };

    return map.at(str);
}