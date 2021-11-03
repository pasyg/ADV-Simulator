#include "string_conversions/item.hpp"

std::string to_string(Item item){
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
    if(str == "none"){
        return Item::none;
    }
    else if(str == "ChoiceBand"){
        return Item::choiceband;
    }
    else if(str == "Leftovers"){
        return Item::leftovers;
    }
    else if(str == "LumBerry"){
        return Item::lumberry;
    }
    else if(str == "SalacBerry"){
        return Item::salacberry;
    }
    else if(str == "ApicotBerry"){
        return Item::apicotberry;
    }
    else if(str == "BlackBelt"){
        return Item::blackbelt;
    }
    else if(str == "BlackGlasses"){
        return Item::blackglasses;
    }
    else if(str == "BrightPowder"){
        return Item::brightpowder;
    }
    else if(str == "Charcoal"){
        return Item::charcoal;
    }
    else if(str == "ChestoBerry"){
        return Item::chestoberry;
    }
    else if(str == "DragonFang"){
        return Item::dragonfang;
    }
    else if(str == "GanlonBerry"){
        return Item::ganlonberry;
    }
    else if(str == "GrepaBerry"){
        return Item::grepaberry;
    }
    else if(str == "HardStone"){
        return Item::hardstone;
    }
    else if(str == "KelpsyBerry"){
        return Item::kelpsyberry;
    }
    else if(str == "KingsRock"){
        return Item::kingsrock;
    }
    else if(str == "LansatBerry"){
        return Item::lansatberry;
    }
    else if(str == "LaxIncense"){
        return Item::laxincense;
    }
    else if(str == "LeppaBerry"){
        return Item::leppaberry;
    }
    else if(str == "LiechiBerry"){
        return Item::liechiberry;
    }
    else if(str == "Magnet"){
        return Item::magnet;
    }
    else if(str == "Mail"){
        return Item::mail;
    }
    else if(str == "MetalCoat"){
        return Item::metalcoat;
    }
    else if(str == "MiracleSeed"){
        return Item::miracleseed;
    }
    else if(str == "MysticWater"){
        return Item::mysticwater;
    }
    else if(str == "NeverMeltIce"){
        return Item::nevermeltice;
    }
    else if(str == "PetayaBerry"){
        return Item::petayaberry;
    }
    else if(str == "PoisonBarb"){
        return Item::poisonbarb;
    }
    else if(str == "QuickClaw"){
        return Item::quickclaw;
    }
    else if(str == "ScopeLens"){
        return Item::scopelens;
    }
    else if(str == "SeaIncense"){
        return Item::seaincense;
    }
    else if(str == "SharpBeak"){
        return Item::sharpbeak;
    }
    else if(str == "ShellBell"){
        return Item::shellbell;
    }
    else if(str == "SilkScarf"){
        return Item::silkscarf;
    }
    else if(str == "SilverPowder"){
        return Item::silverpowder;
    }
    else if(str == "SoftSand"){
        return Item::softsand;
    }
    else if(str == "SpellTag"){
        return Item::spelltag;
    }
    else if(str == "StarfBerry"){
        return Item::starfberry;
    }
    else if(str == "TwistedSpoon"){
        return Item::twistedspoon;
    }
    else if(str == "WhiteHerb"){
        return Item::whiteherb;
    }
    else if(str == "DeepSeaScale"){
        return Item::deepseascale;
    }
    else if(str == "DeepSeaTooth"){
        return Item::deepseatooth;
    }
    else if(str == "LightBall"){
        return Item::lightball;
    }
    else if(str == "LuckyPunch"){
        return Item::luckypunch;
    }
    else if(str == "MetalPowder"){
        return Item::metalpowder;
    }
    else if(str == "SoulDew"){
        return Item::souldew;
    }
    else if(str == "Stick"){
        return Item::stick;
    }
    else if(str == "ThickClub"){
        return Item::thickclub;
    }
    else if(str == "AguavBerry"){
        return Item::aguavberry;
    }
    else if(str == "AspearBerry"){
        return Item::aspearberry;
    }
    else if(str == "CheriBerry"){
        return Item::cheriberry;
    }
    else if(str == "FigyBerry"){
        return Item::figyberry;
    }
    else if(str == "FocusBand"){
        return Item::focusband;
    }
    else if(str == "IapapaBerry"){
        return Item::iapapaberry;
    }
    else if(str == "MachoBrace"){
        return Item::machobrace;
    }
    else if(str == "MagoBerry"){
        return Item::magoberry;
    }
    else if(str == "MentalBerry"){
        return Item::mentalberry;
    }
    else if(str == "OranBerry"){
        return Item::oranberry;
    }
    else if(str == "PechaBerry"){
        return Item::pechaberry;
    }
    else if(str == "PersimBerry"){
        return Item::persimberry;
    }
    else if(str == "RawstBerry"){
        return Item::rawstberry;
    }
    else if(str == "SitrusBerry"){
        return Item::sitrusberry;
    }
    else{
        return Item::wikiberry;
    }
}