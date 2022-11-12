#pragma once

#include <array>
#include <iostream>

#include "attackmove.hpp"

namespace constants
{
    // battle stuff
    constexpr int turn_cap      = 100;
    constexpr int pp_up         = 3;
    constexpr bool ohko_clause  = true;
    constexpr std::array<Move, 6> switches { Move::Switch0, Move::Switch1, Move::Switch2, Move::Switch3, Move::Switch4, Move::Switch5 };
    constexpr std::array<AttackMove, 6> Aswitches { AttackMove(Move::Switch0), AttackMove(Move::Switch1), AttackMove(Move::Switch2), 
                                                    AttackMove(Move::Switch3), AttackMove(Move::Switch4), AttackMove(Move::Switch5) };
    constexpr std::array<Move, 3> dummy_imp_moves { Move::None, Move::None, Move::None };

    // Type effectiveness
    constexpr float no_effect           = 0;
    constexpr float not_very_effective  = 0.5;
    constexpr float regular             = 1.0;
    constexpr float super_effective     = 2.0;

    // misc
    constexpr int test_loop = 300;

    // replay logs
    namespace log
    {
        constexpr auto html_header          = "<!DOCTYPE html>\n<script type=\"text/plain\" class=\"battle-log-data\">|t:|1638527531\n|gametype|singles\n|player|p1|Player 1||\n|player|p2|Player 2||\n";
        constexpr auto generation           = "|gen|3\n|tier|[Gen 3] OU\n";
        constexpr auto sleep_clause         = "|rule|Sleep Clause Mod: Limit one foe put to sleep\n";
        constexpr auto prio_switch_clause   = "|rule|Switch Priority Clause Mod: Faster Pokémon switch first\n";
        constexpr auto species_clause       = "|rule|Species Clause: Limit one of each Pokémon\n";
        constexpr auto ohko_clause          = "|rule|OHKO Clause: OHKO moves are banned\n";
        constexpr auto evasion_clause       = "|rule|Evasion Moves Clause: Evasion moves are banned\n";
        constexpr auto endless_clause       = "|rule|Endless Battle Clause: Forcing endless battles is banned\n";
        constexpr auto hp_percentage_mod    = "|rule|HP Percentage Mod: HP is shown in percentages\n";
        constexpr auto baton_pass_clause    = "|rule|3 Baton Pass Clause: Limit three Baton Passers\n";
        constexpr auto start                = "\n|\n|start\n";
        constexpr auto html_end             = "</script>\n<script src=\"https://play.pokemonshowdown.com/js/replay-embed.js\"></script>";
    };
    inline void summary(int w1, int w2, int tie, int tie_cap, int played_games)
    {
        std::cout << "Turn cap: " << turn_cap << "\n";
        std::cout << "\nTeam 1 wins: " << w1;
        std::cout << "\nTeam 2 wins: " << w2;
        std::cout << "\nTies: " << tie;
        std::cout << "\nTies by turncap: " << tie_cap;
        std::cout << "\n" << played_games << " games played in:\n";
    }
    inline void progress(int i, int played_games)
    {
        static int fract = played_games / 10;
        if(i == fract)         { std::cout << "10%\n"; }
        else if(i == fract * 2){ std::cout << "20%\n"; }
        else if(i == fract * 3){ std::cout << "30%\n"; }
        else if(i == fract * 4){ std::cout << "40%\n"; }
        else if(i == fract * 5){ std::cout << "50%\n"; }
        else if(i == fract * 6){ std::cout << "60%\n"; }
        else if(i == fract * 7){ std::cout << "70%\n"; }
        else if(i == fract * 8){ std::cout << "80%\n"; }
        else if(i == fract * 9){ std::cout << "90%\n"; }
    }
}