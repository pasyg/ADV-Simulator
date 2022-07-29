#include "test.hpp"
#include "test_moves.hpp"

// Pokemon(Species species, Nature nature, Ability ability, Item item, Stats evs, Stats ivs, std::array<Moves, 4> moves);

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
        mset cb_moves = { Moves::rock_slide, Moves::earthquake, Moves::double_edge, Moves::hidden_power };
        mset liechi_moves = { Moves::substitute, Moves::rock_slide, Moves::earthquake, Moves::double_edge };

        // full set
        Pokemon* cb = new Pokemon(Species::Aerodactyl, Nature::Jolly, Ability::Rock_Head, Item::Choiceband, EV::atk_spe, IV::bug_s, cb_moves);
        Pokemon* liechi = new Pokemon(Species::Aerodactyl, Nature::Jolly, Ability::Rock_Head, Item::Liechiberry, EV::atk_spe, IV::max, liechi_moves);
    };
    
    namespace Blissey{
        // movesets
        mset std_twave = { Moves::seismic_toss, Moves::ice_beam, Moves::soft_boiled, Moves::thunder_wave };
        mset std_tox = { Moves::seismic_toss, Moves::ice_beam, Moves::soft_boiled, Moves::toxic };
        mset counter_ = { Moves::seismic_toss, Moves::counter, Moves::soft_boiled, Moves::thunder_wave };

        // full set
        Pokemon* twave   = new Pokemon(Species::Blissey, Nature::Bold, Ability::Natural_Cure, Item::Leftovers, EV::def_satk, IV::max, std_twave);
        Pokemon* toxic   = new Pokemon(Species::Blissey, Nature::Bold, Ability::Natural_Cure, Item::Leftovers, EV::def_satk, IV::max, std_tox);
        Pokemon* counter = new Pokemon(Species::Blissey, Nature::Bold, Ability::Natural_Cure, Item::Leftovers, EV::hp_def, IV::max, counter_);
    };

    namespace Breloom{

    };

    namespace Celebi{

    };

    namespace Charizard{

    };

    namespace Claydol{

    };

    namespace Cloyster{

    };

    namespace Dugtrio{

    };

    namespace Flygon{

    };

    namespace Forretress{

    };

    namespace Gengar{

    };

    namespace Gyarados{

    };

    namespace Heracross{

    };

    namespace Jirachi{

    };

    namespace Jolteon{

    };
    
    namespace Magneton{

    };

    namespace Metagross{
        
    };

    namespace Milotic{

    };

    namespace Moltres{

    };

    namespace Salamence{

    };

    namespace Skarmory{

    };

    namespace Snorlax{

    };

    namespace Starmie{

    };

    namespace Suicune{

    };

    namespace Swampert{

    };

    namespace Tyranitar{

    };

    namespace Zapdos{

    };
};