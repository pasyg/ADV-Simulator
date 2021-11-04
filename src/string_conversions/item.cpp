#include "string_conversions/item.hpp"

std::string to_string(Item const item){
    switch(item){
        case Item::none: return "none";
        case Item::choiceband: return "Leftovers";
        case Item::leftovers: return "Leftovers";
        case Item::lumberry: return "Lum Berry";
        case Item::salacberry: return "Salac Berry";
        case Item::apicotberry: return "Apicot Berry";
        case Item::blackbelt: return "Black Belt";
        case Item::blackglasses: return "Black Glasses";
        case Item::brightpowder: return "Bright Powder";
        case Item::charcoal: return "Charcoal";
        case Item::chestoberry: return "Chesto Berry";
        case Item::dragonfang: return "Dragon Fang";
        case Item::ganlonberry: return "Ganlon Berry";
        case Item::grepaberry: return "Grepa Berry";
        case Item::hardstone: return "Hard Stone";
        case Item::kelpsyberry: return "Kelpsy Berry";
        case Item::kingsrock: return "Kings Rock";
        case Item::lansatberry: return "Lansat Berry";
        case Item::laxincense: return "Lax Incense";
        case Item::leppaberry: return "Leppa Berry";
        case Item::liechiberry: return "Liechi Berry";
        case Item::magnet: return "Magnet";
        case Item::mail: return "Mail";
        case Item::metalcoat: return "Metal Coat";
        case Item::miracleseed: return "Miracle Seed";
        case Item::mysticwater: return "Mystic Water";
        case Item::nevermeltice: return "Never Melt Ice";
        case Item::petayaberry: return "Petaya Berry";
        case Item::poisonbarb: return "Poison Barb";
        case Item::quickclaw: return "Quick Claw";
        case Item::scopelens: return "Scope Lens";
        case Item::seaincense: return "Sea Incense";
        case Item::sharpbeak: return "Sharp Beak";
        case Item::shellbell: return "Shell Bell";
        case Item::silkscarf: return "Silk Scarf";
        case Item::silverpowder: return "Silver Powder";
        case Item::softsand: return "Soft Sand";
        case Item::spelltag: return "Spell Tag";
        case Item::starfberry: return "Starf Berry";
        case Item::twistedspoon: return "Twisted Spoon";
        case Item::whiteherb: return "White Herb";
        case Item::deepseascale: return "Deep Sea Scale";
        case Item::deepseatooth: return "Deep Sea Tooth";
        case Item::lightball: return "Light Ball";
        case Item::luckypunch: return "Lucky Punch";
        case Item::metalpowder: return "Metal Powder";
        case Item::souldew: return "Soul Dew";
        case Item::stick: return "Stick";
        case Item::thickclub: return "Thick Club";
        case Item::aguavberry: return "Aguav Berry";
        case Item::aspearberry: return "Aspear Berry";
        case Item::cheriberry: return "Cheri Berry";
        case Item::figyberry: return "Figy Berry";
        case Item::focusband: return "Focus Band";
        case Item::iapapaberry: return "Iapapa Berry";
        case Item::machobrace: return "Macho Brace";
        case Item::magoberry: return "Mago Berry";
        case Item::rawstberry: return "Rawst Berry";
        case Item::mentalberry: return "Mental Berry";
        case Item::oranberry: return "Oran Berry";
        case Item::pechaberry: return "Pecha Berry";
        case Item::persimberry: return "Persim Berry";
        case Item::sitrusberry: return "Sitrus Berry";
        case Item::wikiberry: return "Wiki Berry";
        default: return "ERROR item";
    }
}

Item item_from_string(std::string_view str){ 
  
    static std::unordered_map<std::string_view, Item> map{ 
        
        { "", Item::none },
        { "Leftovers", Item::leftovers },
        { "LumBerry", Item::lumberry },
        { "SalacBerry", Item::salacberry },
        { "ChoiceBand", Item::choiceband },
        { "ThickClub", Item::thickclub },
        { "LightBall", Item::lightball },
        { "DeepSeaScale", Item::deepseascale },
        { "DeepSeaTooth", Item::deepseatooth },
        { "BlackBelt", Item::blackbelt },
        { "SharpBeak", Item::sharpbeak },
        { "MetalCoat", Item::metalcoat },
        { "PoisonBarb", Item::poisonbarb },
        { "SoftSand", Item::softsand },
        { "SilkScarf", Item::silkscarf },
        { "SpellTag", Item::spelltag },
        { "BlackGlasses", Item::blackglasses },
        { "Charcoal", Item::charcoal },
        { "Magnet", Item::magnet },
        { "DragonFang", Item::dragonfang },
        { "MiracleSeed", Item::miracleseed },
        { "MysticWater", Item::mysticwater },
        { "SeaIncense", Item::seaincense },
        { "NeverMeltIce", Item::nevermeltice },
        { "TwistedSpoon", Item::twistedspoon },
        { "ScopeLens", Item::scopelens },
        { "Stick", Item::stick },
        { "ApicotBerry", Item::apicotberry },
        { "BrightPowder", Item::brightpowder },
        { "ChestoBerry", Item::chestoberry },
        { "GanlonBerry", Item::ganlonberry },
        { "GrepaBerry", Item::grepaberry },
        { "HardStone", Item::hardstone },
        { "KelpsyBerry", Item::kelpsyberry },
        { "KingsRock", Item::kingsrock },
        { "LansatBerry", Item::lansatberry },
        { "LaxIncense", Item::laxincense },
        { "SoulDew", Item::souldew },
        { "LeppaBerry", Item::leppaberry },
        { "LiechiBerr", Item::liechiberry },
        { "Mail", Item::mail },
        { "PetayaBerry", Item::petayaberry },
        { "QuickClaw", Item::quickclaw },
        { "ShellBell", Item::shellbell },
        { "SilverPowder", Item::silverpowder },
        { "StarfBerry", Item::starfberry },
        { "WhiteHerb", Item::whiteherb },
        { "LuckyPunch", Item::luckypunch },
        { "MetalPowder", Item::metalpowder },
        { "AguavBerry", Item::aguavberry },
        { "AspearBerry", Item::aspearberry },
        { "CheriBerry", Item::cheriberry },
        { "FigyBerry", Item::figyberry },
        { "FocusBand", Item::focusband },
        { "IapapaBerry", Item::iapapaberry },
        { "MachoBrace", Item::machobrace },
        { "MagoBerry", Item::magoberry },
        { "MentalBerry", Item::mentalberry },
        { "OranBerry", Item::oranberry },
        { "PechaBerry", Item::pechaberry },
        { "PersimBerry", Item::persimberry },
        { "RawstBerry", Item::rawstberry },
        { "SitrusBerry", Item::sitrusberry },
        { "WikiBerry", Item::wikiberry },
    };

    return map[str];
}