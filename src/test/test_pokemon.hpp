#include "test.hpp"
#include "test_moves.hpp"

namespace Tests{

    typedef std::array<AttackMove, 4> mset;
    
    namespace EV{
        Stats hp_atk    = Stats(252, 252, 4, 0, 0, 0);
        Stats hp_def    = Stats(252, 0, 252, 0, 4, 0);
        Stats hp_satk   = Stats(252, 0, 0, 252, 4, 0);
        Stats hp_sdef   = Stats(252, 0, 4, 0, 252, 0);
        Stats hp_spe    = Stats(252, 0, 4, 0, 0, 252);
        Stats atk_def   = Stats(0, 252, 252, 0, 0, 0);
        Stats atk_satk  = Stats(0, 252, 0, 252, 0, 0);
        Stats atk_sdef  = Stats(0, 252, 0, 0, 252, 0);
        Stats atk_spe   = Stats(0, 252, 0, 0, 0, 252);
        Stats def_satk  = Stats(0, 0, 252, 252, 0, 0);
        Stats def_sdef  = Stats(0, 0, 252, 0, 252, 0);
        Stats def_spe   = Stats(0, 0, 252, 0, 0, 252);
        Stats satk_sdef = Stats(0, 0, 0, 252, 252, 0);
        Stats satk_spe  = Stats(0, 0, 0, 252, 0, 252);
        Stats sdef_spe  = Stats(0, 0, 0, 0, 252, 252);
    };

    namespace IV{
        Stats max       = Stats(31, 31, 31, 31, 31, 31); 
        // max atk
        Stats bug_a     = Stats(31, 31, 31, 31, 30, 30);
        // max speed
        Stats bug_s     = Stats(31, 30, 30, 31, 30, 31);
        Stats dark      = Stats(31, 31, 31, 31, 31, 31);
        Stats dragon    = Stats(31, 30, 31, 31, 31, 31);
        Stats electric  = Stats(31, 31, 31, 30, 31, 31);
        Stats fighting  = Stats(31, 31, 30, 30, 30, 30);
        Stats fire      = Stats(31, 30, 31, 30, 31, 30);
        // max atk
        Stats flying_a  = Stats(31, 31, 31, 30, 30, 30);
        // max speed
        Stats flying_s  = Stats(30, 30, 30, 30, 30, 31);
        Stats ghost     = Stats(31, 31, 30, 31, 30, 31);
        Stats grass     = Stats(31, 30, 31, 30, 31, 31);
        Stats ground    = Stats(31, 31, 31, 30, 30, 31);
        Stats ice       = Stats(31, 30, 30, 31, 31, 31);
        Stats poison    = Stats(31, 31, 30, 30, 30, 31);
        Stats psychic   = Stats(31, 30, 31, 31, 31, 30);
        Stats rock      = Stats(31, 31, 30, 31, 30, 30);
        Stats steel     = Stats(31, 31, 31, 31, 30, 31);
        Stats water     = Stats(31, 30, 30, 30, 31, 31);
    };

    namespace Aerodactyl{
        // movesets
        mset cb_       = { Moves::rock_slide, Moves::earthquake, Moves::double_edge, Moves::hidden_power };
        mset liechi_   = { Moves::substitute, Moves::rock_slide, Moves::earthquake, Moves::double_edge };

        // full set
        Pokemon* cb     = new Pokemon(Species::Aerodactyl, Nature::Jolly, Ability::Rock_Head, Item::Choiceband, EV::atk_spe, IV::bug_s, cb_);
        Pokemon* liechi = new Pokemon(Species::Aerodactyl, Nature::Jolly, Ability::Rock_Head, Item::Liechiberry, EV::atk_spe, IV::max, liechi_);
    };
    
    namespace Blissey{
        // movesets
        mset std_twave  = { Moves::seismic_toss, Moves::ice_beam, Moves::soft_boiled, Moves::thunder_wave };
        mset std_tox    = { Moves::seismic_toss, Moves::ice_beam, Moves::soft_boiled, Moves::toxic };
        mset counter_   = { Moves::seismic_toss, Moves::counter, Moves::soft_boiled, Moves::thunder_wave };

        // full set
        Pokemon* twave   = new Pokemon(Species::Blissey, Nature::Bold, Ability::Natural_Cure, Item::Leftovers, EV::def_satk, IV::max, std_twave);
        Pokemon* toxic   = new Pokemon(Species::Blissey, Nature::Bold, Ability::Natural_Cure, Item::Leftovers, EV::def_satk, IV::max, std_tox);
        Pokemon* counter = new Pokemon(Species::Blissey, Nature::Bold, Ability::Natural_Cure, Item::Leftovers, EV::hp_def, IV::max, counter_);
    };

    namespace Breloom{
        // movesets
        mset std_    = { Moves::spore, Moves::focus_punch, Moves::mach_punch, Moves::hidden_power };
        mset tf_     = { Moves::spore, Moves::focus_punch, Moves::sky_uppercut, Moves::mach_punch };

        // full set
        Pokemon* std   = new Pokemon(Species::Breloom, Nature::Jolly, Ability::Effect_Spore, Item::Leftovers, EV::atk_spe, IV::bug_s, std_);
        Pokemon* tf    = new Pokemon(Species::Breloom, Nature::Jolly, Ability::Effect_Spore, Item::Leftovers, EV::atk_spe, IV::max, tf_);
    };

    namespace Celebi{
        //movesets
        mset off_   = { Moves::calm_mind, Moves::psychic, Moves::giga_drain, Moves::hidden_power };
        mset lseed  = { Moves::leech_seed, Moves::psychic, Moves::hidden_power, Moves::recover };

        //full set
        Pokemon* off    = new Pokemon(Species::Celebi, Nature::Timid, Ability::Natural_Cure, Item::Leftovers, EV::satk_spe, IV::fire, off_);
        Pokemon* slseed = new Pokemon(Species::Celebi, Nature::Calm, Ability::Natural_Cure, Item::Leftovers, EV::hp_sdef, IV::grass, lseed);
        Pokemon* dlseed = new Pokemon(Species::Celebi, Nature::Bold, Ability::Natural_Cure, Item::Leftovers, EV::hp_def, IV::grass, lseed);
    };

    namespace Charizard{
        //movesets

        //full set
        
    };

    namespace Claydol{
        //movesets

        //full set
        
    };

    namespace Cloyster{
        //movesets

        //full set
        
    };

    namespace Dugtrio{
        //movesets

        //full set
        
    };

    namespace Flygon{
        //movesets

        //full set
        
    };

    namespace Forretress{
        //movesets

        //full set
        
    };

    namespace Gengar{
        //movesets

        //full set
        
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

        //full set
        
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

        //full set
        
    };

    namespace Tyranitar{
        //movesets

        //full set
        
    };

    namespace Zapdos{
        //movesets
        mset std_   = { Moves::thunderbolt, Moves::hidden_power, Moves::thunder_wave, Moves::baton_pass };
        mset rest_  = { Moves::thunderbolt, Moves::hidden_power, Moves::roar, Moves::rest };
        
        //full set
        Pokemon* modest = new Pokemon(Species::Zapdos, Nature::Modest, Ability::Pressure, Item::Leftovers, EV::satk_spe, IV::grass, std_);
        Pokemon* timid  = new Pokemon(Species::Zapdos, Nature::Timid, Ability::Pressure, Item::Leftovers, EV::satk_spe, IV::grass, std_);
        Pokemon* rest   = new Pokemon(Species::Zapdos, Nature::Careful, Ability::Pressure, Item::Leftovers, EV::hp_sdef, IV::grass, rest_);
    };
};