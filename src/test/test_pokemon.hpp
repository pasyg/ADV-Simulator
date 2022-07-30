#pragma once

#include "test_moves.hpp"

namespace Tests{

    typedef std::array<AttackMove, 4> mset;
    
    namespace EV{
        static const Stats hp_atk    = Stats(252, 252, 4, 0, 0, 0);
        static const Stats hp_def    = Stats(252, 0, 252, 0, 4, 0);
        static const Stats hp_satk   = Stats(252, 0, 0, 252, 4, 0);
        static const Stats hp_sdef   = Stats(252, 0, 4, 0, 252, 0);
        static const Stats hp_spe    = Stats(252, 0, 4, 0, 0, 252);
        static const Stats atk_def   = Stats(0, 252, 252, 0, 0, 0);
        static const Stats atk_satk  = Stats(0, 252, 0, 252, 0, 0);
        static const Stats atk_sdef  = Stats(0, 252, 0, 0, 252, 0);
        static const Stats atk_spe   = Stats(0, 252, 0, 0, 0, 252);
        static const Stats def_satk  = Stats(0, 0, 252, 252, 0, 0);
        static const Stats def_sdef  = Stats(0, 0, 252, 0, 252, 0);
        static const Stats def_spe   = Stats(0, 0, 252, 0, 0, 252);
        static const Stats satk_sdef = Stats(0, 0, 0, 252, 252, 0);
        static const Stats satk_spe  = Stats(0, 0, 0, 252, 0, 252);
        static const Stats sdef_spe  = Stats(0, 0, 0, 0, 252, 252);
    };

    namespace IV{
        static const Stats max       = Stats(31, 31, 31, 31, 31, 31); 
        // max atk
        static const Stats bug_a     = Stats(31, 31, 31, 31, 30, 30);
        // max speed
        static const Stats bug_s     = Stats(31, 30, 30, 31, 30, 31);
        static const Stats dark      = Stats(31, 31, 31, 31, 31, 31);
        static const Stats dragon    = Stats(31, 30, 31, 31, 31, 31);
        static const Stats electric  = Stats(31, 31, 31, 30, 31, 31);
        static const Stats fighting  = Stats(31, 31, 30, 30, 30, 30);
        static const Stats fire      = Stats(31, 30, 31, 30, 31, 30);
        // max atk
        static const Stats flying_a  = Stats(31, 31, 31, 30, 30, 30);
        // max speed
        static const Stats flying_s  = Stats(30, 30, 30, 30, 30, 31);
        static const Stats ghost     = Stats(31, 31, 30, 31, 30, 31);
        static const Stats grass     = Stats(31, 30, 31, 30, 31, 31);
        static const Stats ground    = Stats(31, 31, 31, 30, 30, 31);
        static const Stats ice       = Stats(31, 30, 30, 31, 31, 31);
        static const Stats poison    = Stats(31, 31, 30, 30, 30, 31);
        static const Stats psychic   = Stats(31, 30, 31, 31, 31, 30);
        static const Stats rock      = Stats(31, 31, 30, 31, 30, 30);
        static const Stats steel     = Stats(31, 31, 31, 31, 30, 31);
        static const Stats water     = Stats(31, 30, 30, 30, 31, 31);
    };

    namespace Aerodactyl{
        // movesets
        static const mset cb_       = { Moves::rock_slide, Moves::earthquake, Moves::double_edge, Moves::hidden_power };
        static const mset liechi_   = { Moves::substitute, Moves::rock_slide, Moves::earthquake, Moves::double_edge };

        // full set
        static const Pokemon* cb     = new Pokemon(Species::Aerodactyl, Nature::Jolly, Ability::Rock_Head, Item::Choiceband, EV::atk_spe, IV::bug_s, cb_);
        static const Pokemon* liechi = new Pokemon(Species::Aerodactyl, Nature::Jolly, Ability::Rock_Head, Item::Liechiberry, EV::atk_spe, IV::max, liechi_);
    };
    
    namespace Blissey{
        // movesets
        static const mset std_twave  = { Moves::seismic_toss, Moves::ice_beam, Moves::soft_boiled, Moves::thunder_wave };
        static const mset std_tox    = { Moves::seismic_toss, Moves::ice_beam, Moves::soft_boiled, Moves::toxic };
        static const mset counter_   = { Moves::seismic_toss, Moves::counter, Moves::soft_boiled, Moves::thunder_wave };

        // full set
        static const Pokemon* twave   = new Pokemon(Species::Blissey, Nature::Bold, Ability::Natural_Cure, Item::Leftovers, EV::def_satk, IV::max, std_twave);
        static const Pokemon* toxic   = new Pokemon(Species::Blissey, Nature::Bold, Ability::Natural_Cure, Item::Leftovers, EV::def_satk, IV::max, std_tox);
        static const Pokemon* counter = new Pokemon(Species::Blissey, Nature::Bold, Ability::Natural_Cure, Item::Leftovers, EV::hp_def, IV::max, counter_);
    };

    namespace Breloom{
        // movesets
        static const mset std_    = { Moves::spore, Moves::focus_punch, Moves::mach_punch, Moves::hidden_power };
        static const mset tf_     = { Moves::spore, Moves::focus_punch, Moves::sky_uppercut, Moves::mach_punch };

        // full set
        static const Pokemon* std   = new Pokemon(Species::Breloom, Nature::Jolly, Ability::Effect_Spore, Item::Leftovers, EV::atk_spe, IV::bug_s, std_);
        static const Pokemon* tf    = new Pokemon(Species::Breloom, Nature::Jolly, Ability::Effect_Spore, Item::Leftovers, EV::atk_spe, IV::max, tf_);
    };

    namespace Celebi{
        //movesets
        static const mset off_   = { Moves::calm_mind, Moves::psychic, Moves::giga_drain, Moves::hidden_power };
        static const mset lseed  = { Moves::leech_seed, Moves::psychic, Moves::hidden_power, Moves::recover };

        //full set
        static const Pokemon* off    = new Pokemon(Species::Celebi, Nature::Timid, Ability::Natural_Cure, Item::Leftovers, EV::satk_spe, IV::fire, off_);
        static const Pokemon* slseed = new Pokemon(Species::Celebi, Nature::Calm, Ability::Natural_Cure, Item::Leftovers, EV::hp_sdef, IV::grass, lseed);
        static const Pokemon* dlseed = new Pokemon(Species::Celebi, Nature::Bold, Ability::Natural_Cure, Item::Leftovers, EV::hp_def, IV::grass, lseed);
    };

    namespace Charizard{
        //movesets
        static const mset std_ = { Moves::fire_blast, Moves::hidden_power, Moves::focus_punch, Moves::substitute };
        static const mset bup_ = { Moves::fire_blast, Moves::hidden_power, Moves::focus_punch, Moves::beat_up };

        //full set
        static const Pokemon* std = new Pokemon(Species::Charizard, Nature::Hasty, Ability::Blaze, Item::Leftovers, EV::satk_spe, IV::grass, std_);
        static const Pokemon* beatup = new Pokemon(Species::Charizard, Nature::Hasty, Ability::Blaze, Item::Leftovers, EV::satk_spe, IV::grass, bup_);
    };

    namespace Claydol{
        //movesets
        static const mset std_ = { Moves::earthquake, Moves::psychic, Moves::rapid_spin, Moves::explosion };
        static const mset ref_  = { Moves::earthquake, Moves::psychic, Moves::rapid_spin, Moves::refresh };
        
        //full set
        static const Pokemon* std = new Pokemon(Species::Claydol, Nature::Adamant, Ability::Levitate, Item::Leftovers, EV::hp_atk, IV::max, std_);
        static const Pokemon* ref = new Pokemon(Species::Claydol, Nature::Adamant, Ability::Levitate, Item::Leftovers, EV::hp_atk, IV::max, ref_);        
    };

    namespace Cloyster{
        //movesets
        static const mset spin_ = { Moves::spikes, Moves::explosion, Moves::rapid_spin, Moves::ice_beam };
        static const mset std_  = { Moves::spikes, Moves::explosion, Moves::surf, Moves::ice_beam };

        //full set
        static const Pokemon* spin = new Pokemon(Species::Cloyster, Nature::Timid, Ability::Shell_Armor, Item::Leftovers, EV::hp_spe, IV::max, spin_);
        static const Pokemon* std  = new Pokemon(Species::Cloyster, Nature::Timid, Ability::Shell_Armor, Item::Leftovers, EV::hp_spe, IV::max, std_);
    };

    namespace Dugtrio{
        //movesets
        static const mset std_ = { Moves::earthquake, Moves::rock_slide, Moves::hidden_power, Moves::beat_up };

        //full set
        static const Pokemon* std = new Pokemon(Species::Dugtrio, Nature::Jolly, Ability::Arena_Trap, Item::Choiceband, EV::atk_spe, IV::bug_s, std_);
    };

    namespace Flygon{
        //movesets
        static const mset cb_ = { Moves::earthquake, Moves::rock_slide, Moves::hidden_power, Moves::gust };

        //full set
        static const Pokemon* cb = new Pokemon(Species::Flygon, Nature::Jolly, Ability::Levitate, Item::Choiceband, EV::atk_spe, IV::bug_s, cb_);
    };

    namespace Forretress{
        //movesets
        static const mset std_ = { Moves::spikes, Moves::earthquake, Moves::explosion, Moves::rapid_spin };

        //full set
        static const Pokemon* std = new Pokemon(Species::Forretress, Nature::Calm, Ability::Sturdy, Item::Leftovers, EV::hp_sdef, IV::max, std_);
    };

    namespace Gengar{
        //movesets
        static const mset std_ = { Moves::will_o_wisp, Moves::thunderbolt, Moves::ice_punch, Moves::explosion };

        //full set
        static const Pokemon* std = new Pokemon(Species::Gengar, Nature::Timid, Ability::Levitate, Item::Leftovers, EV::hp_spe, IV::max, std_);
    };

    namespace Gyarados{
        //movesets

        //full set
        
    };

    namespace Heracross{
        //movesets

        //full set
        
    };

    namespace Jirachi{
        //movesets

        //full set
        
    };

    namespace Jolteon{
        //movesets

        //full set
        
    };
    
    namespace Magneton{
        //movesets

        //full set
        
    };

    namespace Metagross{
        //movesets

        //full set
        
    };

    namespace Milotic{
        //movesets

        //full set
        
    };

    namespace Moltres{
        //movesets

        //full set
        
    };

    namespace Salamence{
        //movesets

        //full set
        
    };

    namespace Skarmory{
        //movesets
        static const mset std_ = { Moves::spikes, Moves::toxic, Moves::whirlwind, Moves::protect };

        //full set
        static const Pokemon* std = new Pokemon(Species::Skarmory, Nature::Careful, Ability::Keen_Eye, Item::Leftovers, EV::hp_sdef, IV::max, std_);
    };

    namespace Snorlax{
        //movesets

        //full set
        
    };

    namespace Starmie{
        //movesets

        //full set
        
    };

    namespace Suicune{
        //movesets

        //full set
        
    };

    namespace Swampert{
        //movesets
        static const mset std_ = { Moves::hydro_pump, Moves::earthquake, Moves::ice_beam, Moves::protect };
        static const mset off_ = { Moves::hydro_pump, Moves::earthquake, Moves::ice_beam, Moves::focus_punch };

        //full set
        static const Pokemon* std = new Pokemon(Species::Swampert, Nature::Relaxed, Ability::Torrent, Item::Leftovers, EV::hp_def, IV::max, std_);
        static const Pokemon* off = new Pokemon(Species::Swampert, Nature::Rash, Ability::Torrent, Item::Leftovers, EV::satk_spe, IV::max, off_);
        
    };

    namespace Tyranitar{
        //movesets
        static const mset cb_ = { Moves::rock_slide, Moves::earthquake, Moves::hidden_power, Moves::focus_punch };
        static const mset dd_ = { Moves::dragon_dance, Moves::rock_slide, Moves::earthquake, Moves::double_edge };

        //full set
        static const Pokemon* cb = new Pokemon(Species::Tyranitar, Nature::Adamant, Ability::Sand_Stream, Item::Choiceband, EV::atk_spe, IV::bug_s, cb_);
        
    };

    namespace Zapdos{
        //movesets
        static const mset std_   = { Moves::thunderbolt, Moves::hidden_power, Moves::thunder_wave, Moves::baton_pass };
        static const mset rest_  = { Moves::thunderbolt, Moves::hidden_power, Moves::roar, Moves::rest };
        
        //full set
        static const Pokemon* modest = new Pokemon(Species::Zapdos, Nature::Modest, Ability::Pressure, Item::Leftovers, EV::satk_spe, IV::grass, std_);
        static const Pokemon* timid  = new Pokemon(Species::Zapdos, Nature::Timid, Ability::Pressure, Item::Leftovers, EV::satk_spe, IV::grass, std_);
        static const Pokemon* rest   = new Pokemon(Species::Zapdos, Nature::Careful, Ability::Pressure, Item::Leftovers, EV::hp_sdef, IV::grass, rest_);
    };
};