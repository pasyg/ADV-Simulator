#pragma once

#include "test_moves.hpp"

namespace Tests
{
    typedef std::array<AttackMove, 4> mset;
    namespace EV
    {
        static constexpr Stats hp_atk    = Stats(252, 252, 0, 0, 0, 0);
        static constexpr Stats hp_def    = Stats(252, 0, 252, 0, 0, 0);
        static constexpr Stats hp_satk   = Stats(252, 0, 0, 252, 0, 0);
        static constexpr Stats hp_sdef   = Stats(252, 0, 0, 0, 252, 0);
        static constexpr Stats hp_spe    = Stats(252, 0, 0, 0, 0, 252);
        static constexpr Stats atk_def   = Stats(0, 252, 252, 0, 0, 0);
        static constexpr Stats atk_satk  = Stats(0, 252, 0, 252, 0, 0);
        static constexpr Stats atk_sdef  = Stats(0, 252, 0, 0, 252, 0);
        static constexpr Stats atk_spe   = Stats(0, 252, 0, 0, 0, 252);
        static constexpr Stats def_satk  = Stats(0, 0, 252, 252, 0, 0);
        static constexpr Stats def_sdef  = Stats(0, 0, 252, 0, 252, 0);
        static constexpr Stats def_spe   = Stats(0, 0, 252, 0, 0, 252);
        static constexpr Stats satk_sdef = Stats(0, 0, 0, 252, 252, 0);
        static constexpr Stats satk_spe  = Stats(0, 0, 0, 252, 0, 252);
        static constexpr Stats sdef_spe  = Stats(0, 0, 0, 0, 252, 252);
    };

    namespace IV
    {
        static constexpr Stats max       = Stats(31, 31, 31, 31, 31, 31); 
        // max atk
        static constexpr Stats bug_a     = Stats(31, 31, 31, 31, 30, 30);
        // max speed
        static constexpr Stats bug_s     = Stats(31, 30, 30, 31, 30, 31);
        static constexpr Stats dark      = Stats(31, 31, 31, 31, 31, 31);
        static constexpr Stats dragon    = Stats(31, 30, 31, 31, 31, 31);
        static constexpr Stats electric  = Stats(31, 31, 31, 30, 31, 31);
        static constexpr Stats fighting  = Stats(31, 31, 30, 30, 30, 30);
        static constexpr Stats fire      = Stats(31, 30, 31, 30, 31, 30);
        // max atk
        static constexpr Stats flying_a  = Stats(31, 31, 31, 30, 30, 30);
        // max speed
        static constexpr Stats flying_s  = Stats(30, 30, 30, 30, 30, 31);
        static constexpr Stats ghost     = Stats(31, 31, 30, 31, 30, 31);
        static constexpr Stats grass     = Stats(31, 30, 31, 30, 31, 31);
        static constexpr Stats ground    = Stats(31, 31, 31, 30, 30, 31);
        static constexpr Stats ice       = Stats(31, 30, 30, 31, 31, 31);
        static constexpr Stats poison    = Stats(31, 31, 30, 30, 30, 31);
        static constexpr Stats psychic   = Stats(31, 30, 31, 31, 31, 30);
        static constexpr Stats rock      = Stats(31, 31, 30, 31, 30, 30);
        static constexpr Stats steel     = Stats(31, 31, 31, 31, 30, 31);
        static constexpr Stats water     = Stats(31, 30, 30, 30, 31, 31);
    };

    static constexpr Pokemon none  = Pokemon(Species::None, Nature::Jolly, Ability::Air_Lock, Item::None, EV::hp_atk, IV::max, { Move::None, Move::None, Move::None, Move::None });

    namespace Aerodactyl
    {
        // movesets
        static constexpr mset cb_      { Moves::rock_slide, Moves::earthquake, Moves::double_edge, Moves::hidden_power };
        static constexpr mset liechi_  { Moves::substitute, Moves::rock_slide, Moves::earthquake, Moves::double_edge };
        // full set
        static constexpr Pokemon cb     = Pokemon(Species::Aerodactyl, Nature::Jolly, Ability::Rock_Head, Item::Choiceband, EV::atk_spe, IV::bug_s, cb_);
        static constexpr Pokemon liechi = Pokemon(Species::Aerodactyl, Nature::Jolly, Ability::Rock_Head, Item::Liechiberry, EV::atk_spe, IV::max, liechi_);
    };
    
    namespace Blissey
    {
        // movesets
        static constexpr mset std_twave  { Moves::snatch, Moves::ice_beam, Moves::soft_boiled, Moves::thunder_wave };
        static constexpr mset std_tox    { Moves::seismic_toss, Moves::ice_beam, Moves::soft_boiled, Moves::toxic };
        static constexpr mset counter_   { Moves::seismic_toss, Moves::counter, Moves::soft_boiled, Moves::thunder_wave };
        // full set
        static constexpr Pokemon twave   = Pokemon(Species::Blissey, Nature::Modest, Ability::Natural_Cure, Item::Leftovers, EV::def_satk, IV::max, std_twave);
        static constexpr Pokemon toxic   = Pokemon(Species::Blissey, Nature::Bold, Ability::Natural_Cure, Item::Leftovers, EV::def_satk, IV::max, std_tox);
        static constexpr Pokemon counter = Pokemon(Species::Blissey, Nature::Bold, Ability::Natural_Cure, Item::Leftovers, EV::hp_def, IV::max, counter_);
    };

    namespace Breloom
    {
        // movesets
        static constexpr mset std_    { Moves::spore, Moves::focus_punch, Moves::mach_punch, Moves::hidden_power };
        static constexpr mset tf_     { Moves::spore, Moves::focus_punch, Moves::sky_uppercut, Moves::mach_punch };
        // full set
        static constexpr Pokemon std  = Pokemon(Species::Breloom, Nature::Jolly, Ability::Effect_Spore, Item::Leftovers, EV::atk_spe, IV::bug_s, std_);
        static constexpr Pokemon tf   = Pokemon(Species::Breloom, Nature::Jolly, Ability::Effect_Spore, Item::Leftovers, EV::atk_spe, IV::max, tf_);
    };

    namespace Celebi
    {
        //movesets
        static constexpr mset off_   { Moves::calm_mind, Moves::psychic, Moves::giga_drain, Moves::hidden_power };
        static constexpr mset lseed  { Moves::leech_seed, Moves::psychic, Moves::hidden_power, Moves::recover };
        //full set
        static constexpr Pokemon off    = Pokemon(Species::Celebi, Nature::Timid, Ability::Natural_Cure, Item::Leftovers, EV::satk_spe, IV::fire, off_);
        static constexpr Pokemon slseed = Pokemon(Species::Celebi, Nature::Calm, Ability::Natural_Cure, Item::Leftovers, EV::hp_sdef, IV::grass, lseed);
        static constexpr Pokemon dlseed = Pokemon(Species::Celebi, Nature::Bold, Ability::Natural_Cure, Item::Leftovers, EV::hp_def, IV::grass, lseed);
    };

    namespace Charizard
    {
        //movesets
        static constexpr mset std_ { Moves::fire_blast, Moves::hidden_power, Moves::focus_punch, Moves::substitute };
        static constexpr mset bup_ { Moves::fire_blast, Moves::hidden_power, Moves::focus_punch, Moves::beat_up };
        //full set
        static constexpr Pokemon std    = Pokemon(Species::Charizard, Nature::Hasty, Ability::Blaze, Item::Leftovers, EV::satk_spe, IV::grass, std_);
        static constexpr Pokemon beatup = Pokemon(Species::Charizard, Nature::Hasty, Ability::Blaze, Item::Leftovers, EV::satk_spe, IV::grass, bup_);
    };

    namespace Claydol
    {
        //movesets
        static constexpr mset std_ { Moves::earthquake, Moves::psychic, Moves::rapid_spin, Moves::explosion };
        static constexpr mset ref_ { Moves::earthquake, Moves::psychic, Moves::rapid_spin, Moves::refresh };
        //full set
        static constexpr Pokemon std = Pokemon(Species::Claydol, Nature::Adamant, Ability::Levitate, Item::Leftovers, EV::hp_atk, IV::max, std_);
        static constexpr Pokemon ref = Pokemon(Species::Claydol, Nature::Adamant, Ability::Levitate, Item::Leftovers, EV::hp_atk, IV::max, ref_);        
    };

    namespace Cloyster
    {
        //movesets
        static constexpr mset spin_ { Moves::spikes, Moves::explosion, Moves::rapid_spin, Moves::ice_beam };
        static constexpr mset std_  { Moves::spikes, Moves::explosion, Moves::surf, Moves::ice_beam };
        //full set
        static constexpr Pokemon spin = Pokemon(Species::Cloyster, Nature::Timid, Ability::Shell_Armor, Item::Leftovers, EV::hp_spe, IV::max, spin_);
        static constexpr Pokemon std  = Pokemon(Species::Cloyster, Nature::Timid, Ability::Shell_Armor, Item::Leftovers, EV::hp_spe, IV::max, std_);
    };

    namespace Dugtrio
    {
        //movesets
        static constexpr mset std_ { Moves::earthquake, Moves::rock_slide, Moves::hidden_power, Moves::beat_up };
        //full set
        static constexpr Pokemon std = Pokemon(Species::Dugtrio, Nature::Jolly, Ability::Arena_Trap, Item::Choiceband, EV::atk_spe, IV::bug_s, std_);
    };

    namespace Flygon
    {
        //movesets
        static constexpr mset cb_  { Moves::earthquake, Moves::rock_slide, Moves::hidden_power, Moves::gust };
        static constexpr mset def_ { Moves::earthquake, Moves::rock_slide, Moves::toxic, Moves::protect };
        //full set
        static constexpr Pokemon cb  = Pokemon(Species::Flygon, Nature::Jolly, Ability::Levitate, Item::Choiceband, EV::atk_spe, IV::bug_s, cb_);
        static constexpr Pokemon def = Pokemon(Species::Flygon, Nature::Impish, Ability::Levitate, Item::Leftovers, EV::hp_def, IV::max, def_);
    };

    namespace Forretress
    {
        //movesets
        static constexpr mset std_ { Moves::spikes, Moves::earthquake, Moves::explosion, Moves::rapid_spin };
        //full set
        static constexpr Pokemon std = Pokemon(Species::Forretress, Nature::Calm, Ability::Sturdy, Item::Leftovers, EV::hp_sdef, IV::max, std_);
    };

    namespace Gengar
    {
        //movesets
        static constexpr mset std_ { Moves::will_o_wisp, Moves::thunderbolt, Moves::ice_punch, Moves::explosion };
        static constexpr mset off_ { Moves::thunderbolt, Moves::ice_punch, Moves::hidden_power, Moves::explosion };
        //full set
        static constexpr Pokemon std = Pokemon(Species::Gengar, Nature::Timid, Ability::Levitate, Item::Leftovers, EV::hp_spe, IV::max, std_);
        static constexpr Pokemon off = Pokemon(Species::Gengar, Nature::Modest, Ability::Levitate, Item::Leftovers, EV::satk_spe, IV::grass, off_);
    };

    namespace Gyarados
    {
        //movesets
        static constexpr mset std_  { Moves::dragon_dance, Moves::hidden_power, Moves::earthquake, Moves::taunt };
        static constexpr mset rest_ { Moves::dragon_dance, Moves::hidden_power, Moves::earthquake, Moves::rest  };
        //full set
        static constexpr Pokemon std  = Pokemon(Species::Gyarados, Nature::Jolly, Ability::Intimidate, Item::Leftovers, EV::atk_spe, IV::rock, std_);
        static constexpr Pokemon rest = Pokemon(Species::Gyarados, Nature::Adamant, Ability::Intimidate, Item::Leftovers, EV::hp_sdef, IV::flying_a, rest_);
    };

    namespace Heracross
    {
        //movesets
        static constexpr mset sd_ { Moves::swords_dance, Moves::megahorn, Moves::rock_slide, Moves::brick_break };
        static constexpr mset cb_ { Moves::megahorn, Moves::focus_punch, Moves::rock_slide, Moves::sleep_talk };
        //full set
        static constexpr Pokemon sd = Pokemon(Species::Heracross, Nature::Jolly, Ability::Guts, Item::Leftovers, EV::atk_spe, IV::max, sd_);
        static constexpr Pokemon cb = Pokemon(Species::Heracross, Nature::Adamant, Ability::Swarm, Item::Choiceband, EV::atk_spe, IV::max, cb_);
    };

    namespace Jirachi
    {
        //movesets
        static constexpr mset asta_ { Moves::toxic, Moves::fire_punch, Moves::wish, Moves::protect };
        static constexpr mset super_ { Moves::calm_mind, Moves::psychic, Moves::fire_punch, Moves::hidden_power };
        //full set
        static constexpr Pokemon asta  = Pokemon(Species::Jirachi, Nature::Calm, Ability::Serene_Grace, Item::Leftovers, EV::hp_sdef, IV::max, asta_);
        static constexpr Pokemon super = Pokemon(Species::Jirachi, Nature::Timid, Ability::Serene_Grace, Item::Leftovers, EV::satk_spe, IV::grass, super_);
        
    };

    namespace Jolteon
    {
        //movesets
        static constexpr mset std_ { Moves::baton_pass, Moves::thunderbolt, Moves::hidden_power, Moves::roar };
        //full set
        static constexpr Pokemon std = Pokemon(Species::Jolteon, Nature::Timid, Ability::Volt_Absorb, Item::Leftovers, EV::satk_spe, IV::grass, std_);
    };
    
    namespace Magneton
    {
        //movesets
        static constexpr mset mag_   { Moves::thunderbolt, Moves::hidden_power, Moves::toxic, Moves::protect };
        static constexpr mset salac_ { Moves::thunderbolt, Moves::hidden_power, Moves::endure, Moves::thunder_wave };
        //full set
        static constexpr Pokemon mag   = Pokemon(Species::Magneton, Nature::Modest, Ability::Magnet_Pull, Item::Magnet, EV::satk_spe, IV::fire, mag_);
        static constexpr Pokemon salac = Pokemon(Species::Magneton, Nature::Timid, Ability::Magnet_Pull, Item::Salacberry, EV::satk_spe, IV::grass, salac_);
    };

    namespace Metagross
    {
        //movesets
        static constexpr mset phys_ { Moves::meteor_mash, Moves::earthquake, Moves::rock_slide, Moves::explosion };
        static constexpr mset spec_ { Moves::psychic, Moves::hidden_power, Moves::meteor_mash, Moves::explosion  };
        //full set
        static constexpr Pokemon phys = Pokemon(Species::Metagross, Nature::Adamant, Ability::Clear_Body, Item::Leftovers, EV::hp_atk, IV::max, phys_);
        static constexpr Pokemon spec = Pokemon(Species::Metagross, Nature::Modest, Ability::Clear_Body, Item::Leftovers, EV::satk_spe, IV::fire, spec_);
    };

    namespace Milotic
    {
        //movesets
        static constexpr mset op_ { Moves::surf, Moves::toxic, Moves::recover, Moves::refresh };
        //full set
        static constexpr Pokemon op = Pokemon(Species::Milotic, Nature::Bold, Ability::Marvel_Scale, Item::Leftovers, EV::hp_def, IV::max, op_);
    };

    namespace Moltres
    {
        //movesets
        static constexpr mset std_ { Moves::flamethrower, Moves::will_o_wisp, Moves::hidden_power, Moves::roar };
        //full set
        static constexpr Pokemon std = Pokemon(Species::Moltres, Nature::Modest, Ability::Pressure, Item::Leftovers, EV::satk_spe, IV::grass, std_);
    };

    namespace Salamence
    {
        //movesets
        static constexpr mset mix_ { Moves::dragon_claw, Moves::fire_blast, Moves::hidden_power, Moves::brick_break };
        static constexpr mset cb_  { Moves::hidden_power, Moves::earthquake, Moves::rock_slide, Moves::brick_break  };
        //full set
        static constexpr Pokemon mix = Pokemon(Species::Salamence, Nature::Naughty, Ability::Intimidate, Item::Leftovers, EV::satk_spe, IV::grass, mix_);
        static constexpr Pokemon cb  = Pokemon(Species::Salamence, Nature::Adamant, Ability::Intimidate, Item::Leftovers, EV::atk_spe, IV::flying_a, cb_);
    };

    namespace Skarmory
    {
        //movesets
        static constexpr mset std_ { Moves::spikes, Moves::toxic, Moves::whirlwind, Moves::protect };
        //full set
        static constexpr Pokemon std = Pokemon(Species::Skarmory, Nature::Careful, Ability::Keen_Eye, Item::Leftovers, EV::hp_sdef, IV::max, std_);
    };

    namespace Snorlax
    {
        //movesets
        static constexpr mset curse_ { Moves::curse, Moves::rest, Moves::body_slam, Moves::shadow_ball };
        static constexpr mset off_   { Moves::return_, Moves::shadow_ball, Moves::focus_punch, Moves::self_destruct };
        //full set
        static constexpr Pokemon curse = Pokemon(Species::Snorlax, Nature::Adamant, Ability::Immunity, Item::Leftovers, EV::atk_sdef, IV::max, curse_);
        static constexpr Pokemon off   = Pokemon(Species::Snorlax, Nature::Adamant, Ability::Immunity, Item::Leftovers, EV::atk_sdef, IV::max, off_);
    };

    namespace Starmie
    {
        //movesets
        static constexpr mset off_ { Moves::hydro_pump, Moves::ice_beam, Moves::thunderbolt, Moves::rapid_spin };
        static constexpr mset def_ { Moves::surf, Moves::thunder_wave, Moves::rapid_spin, Moves::recover };
        //full set
        static constexpr Pokemon off = Pokemon(Species::Starmie, Nature::Timid, Ability::Natural_Cure, Item::Leftovers, EV::satk_spe, IV::max, off_);
        static constexpr Pokemon def = Pokemon(Species::Starmie, Nature::Timid, Ability::Natural_Cure, Item::Leftovers, EV::hp_spe, IV::max, def_);
    };

    namespace Suicune
    {
        //movesets
        static constexpr mset off_  { Moves::calm_mind, Moves::hydro_pump, Moves::ice_beam, Moves::hidden_power };
        static constexpr mset huso_ { Moves::calm_mind, Moves::surf, Moves::rest, Moves::sleep_talk };
        //full set
        static constexpr Pokemon off  = Pokemon(Species::Suicune, Nature::Modest, Ability::Pressure, Item::Leftovers, EV::satk_spe, IV::electric, off_);
        static constexpr Pokemon huso = Pokemon(Species::Suicune, Nature::Bold, Ability::Pressure, Item::Leftovers, EV::hp_def, IV::max, huso_);
    };

    namespace Swampert
    {
        //movesets
        static constexpr mset std_ { Moves::hydro_pump, Moves::earthquake, Moves::ice_beam, Moves::protect };
        static constexpr mset off_ { Moves::hydro_pump, Moves::earthquake, Moves::ice_beam, Moves::focus_punch };
        //full set
        static constexpr Pokemon std = Pokemon(Species::Swampert, Nature::Relaxed, Ability::Torrent, Item::Leftovers, EV::hp_def, IV::max, std_);
        static constexpr Pokemon off = Pokemon(Species::Swampert, Nature::Rash, Ability::Torrent, Item::Leftovers, EV::satk_spe, IV::max, off_);
        
    };

    namespace Tyranitar
    {
        //movesets
        static constexpr mset cb_   { Moves::rock_slide, Moves::earthquake, Moves::hidden_power, Moves::focus_punch };
        static constexpr mset dd_   { Moves::dragon_dance, Moves::rock_slide, Moves::earthquake, Moves::double_edge };
        static constexpr mset suit_ { Moves::crunch, Moves::pursuit, Moves::fire_blast, Moves::roar };
        //full set
        static constexpr Pokemon cb   = Pokemon(Species::Tyranitar, Nature::Adamant, Ability::Sand_Stream, Item::Choiceband, EV::atk_spe, IV::bug_s, cb_);
        static constexpr Pokemon dd   = Pokemon(Species::Tyranitar, Nature::Jolly, Ability::Sand_Stream, Item::Lumberry, EV::atk_spe, IV::max, dd_);
        static constexpr Pokemon suit = Pokemon(Species::Tyranitar, Nature::Modest, Ability::Sand_Stream, Item::Leftovers, EV::hp_satk, IV::max, suit_);
    };

    namespace Zapdos
    {
        //movesets
        static constexpr mset std_   { Moves::thunderbolt, Moves::hidden_power, Moves::thunder_wave, Moves::baton_pass };
        static constexpr mset rest_  { Moves::thunderbolt, Moves::hidden_power, Moves::roar, Moves::rest };
        //full set
        static constexpr Pokemon modest = Pokemon(Species::Zapdos, Nature::Modest, Ability::Pressure, Item::Leftovers, EV::satk_spe, IV::grass, std_);
        static constexpr Pokemon timid  = Pokemon(Species::Zapdos, Nature::Timid, Ability::Pressure, Item::Leftovers, EV::satk_spe, IV::grass, std_);
        static constexpr Pokemon rest   = Pokemon(Species::Zapdos, Nature::Careful, Ability::Pressure, Item::Leftovers, EV::hp_sdef, IV::grass, rest_);
    };
};