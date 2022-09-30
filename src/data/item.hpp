#pragma once

#include <cstdint>

enum class Item : std::uint8_t
{
    None,
    Knocked,
    Leftovers,
    // pinch berries
    Apicotberry,
    Chestoberry,
    Ganlonberry,
    Lansatberry,
    Leppaberry,
    Liechiberry,
    Petayaberry,
    Salacberry,
    Starfberry,
    // status berries
    Aspearberry,
    Cheriberry,
    Lumberry,
    Pechaberry,
    Persimberry,
    Rawstberry,
    // hp berries
    Aguavberry,
    Figyberry,
    Iapapaberry,
    Magoberry,
    Oranberry,
    Sitrusberry,
    Wikiberry,
    // type damage boost
    Blackbelt,
    Blackglasses,
    Charcoal,
    Dragonfang,
    Hardstone,
    Magnet,
    Metalcoat,
    Miracleseed,
    Mysticwater,
    Nevermeltice,
    Poisonbarb,
    Seaincense,
    Sharpbeak,
    Silkscarf,
    Softsand,
    Spelltag,
    Twistedspoon,

    Brightpowder,
    Choiceband,
    Deepseascale,
    Deepseatooth,
    Focusband,
    Kingsrock,
    Laxincense,
    Lightball,
    Luckypunch,
    Machobrace,
    Mail,
    Mentalherb,
    Metalpowder,
    Quickclaw,
    Scopelens,
    Shellbell,
    Silverpowder,
    Souldew,
    Stick,
    Thickclub,
    Whiteherb
};

bool const damage_boosting(const Item item);