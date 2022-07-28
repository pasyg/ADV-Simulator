#include "test.hpp"
#include "test_moves.hpp"

// Pokemon(Species species, Nature nature, Ability ability, Item item, Stats evs, Stats ivs, std::array<Moves, 4> moves);

namespace Tests{

    Stats max_ivs = Stats(31, 31, 31, 31, 31, 31); 
    Stats evs_atk_spe = Stats(0, 252, 4, 0, 0, 252);
    Stats evs_satk_spe = Stats(0, 0, 4, 252, 0, 252);
    Stats ivs_hp_bug = Stats(31, 30, 30, 31, 30, 31);

    namespace Aerodactyl{
        std::array<AttackMove, 4> cb_moves = { Moves::rock_slide, Moves::earthquake, Moves::double_edge, Moves::hidden_power };
        Pokemon* cb = new Pokemon(Species::Aerodactyl, Nature::Jolly, Ability::Rock_Head, Item::Choiceband, evs_atk_spe, ivs_hp_bug, cb_moves);
    };
    
    namespace Blissey{
        std::array<AttackMove, 4> std_twave = { Moves::seismic_toss, Moves::ice_beam, Moves::soft_boiled, Moves::thunder_wave };
        std::array<AttackMove, 4> std_tox = { Moves::seismic_toss, Moves::ice_beam, Moves::soft_boiled, Moves::toxic };
        std::array<AttackMove, 4> counter_ = { Moves::seismic_toss, Moves::counter, Moves::soft_boiled, Moves::thunder_wave };
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
}