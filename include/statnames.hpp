#include <cstdint>

enum class Statname : std::uint8_t{
    atk,    //attack
    def,    //defense
    satk,   //special attack
    sdef,   //special defense
    spe,    //speed
    acc,    //accuracy
    eva     //evasion
};