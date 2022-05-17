#include "team.hpp"
#include "rng.hpp"

Team::Team() : teamsize(0){

}

Team::~Team(){

}
/////////////////////////////////////////////////////
void Team::print_team(){
    for(auto&& pokemon : this->member){
        std::cout << "Name: " << pokemon.get_name() << "\n";
        std::cout << "HP: " << pokemon.get_current_hp() << "/" << pokemon.get_stat(Statname::HP) << "\n";
        std::cout << "Atk: " << pokemon.get_stat(Statname::Atk) << "\t\t"
                  << "Def: " << pokemon.get_stat(Statname::Def) <<  "\t"
                  << "SAtk: " << pokemon.get_stat(Statname::Satk) << "\t"
                  << "SDef: " << pokemon.get_stat(Statname::Sdef) << "\t"
                  << "Spe: " << pokemon.get_stat(Statname::Spe) << "\n";
        for(auto move : *(pokemon.get_moveset())){
            std::cout << "Move: " << to_string(move.get_move());
            std::cout << " " << move.get_pp() 
                      << "/" << move.base_pp << "\n";
        }
    }
}

void Team::init(){
    // switch move options
    for(int i = 0; i < 6; ++i){
        this->switches[i].set_priority(6);
        switch(i){
        case 0:
            this->switches[i].set_move(Move::Switch0);
            break;
        case 1:
            this->switches[i].set_move(Move::Switch1);
            break;
        case 2:
            this->switches[i].set_move(Move::Switch2);
            break;
        case 3:
            this->switches[i].set_move(Move::Switch3);
            break;
        case 4:
            this->switches[i].set_move(Move::Switch4);
            break;
        case 5:
            this->switches[i].set_move(Move::Switch5);
            break;
        default:
        #ifdef _DEBUG
            debug_log("ERROR TEAM INIT SWITCHES");
        #endif
            break;
        }
    }
    // initialize each pokemon
    for(auto&& pokemon : this->member){
        if(pokemon.get_species() != Species::None){
            pokemon.init();
            this->teamsize++;
        }
    }
    
    this->active_pokemon = 0;
    this->protect = false;
    this->protect_acc = 100;
    this->flinch = false;
    this->focuspunch = false;
    this->magiccoat = false;
    this->endure = false;
    this->grudge = false;
    this->lastdamage = 0;

    this->wish = false;
    this->wish_recovery = 0;
    this->spikes = 0;

    this->atkboost = 0;
    this->defboost = 0;
    this->satkboost = 0;
    this->sdefboost = 0;
    this->speboost = 0;
    this->accboost = 0;
    this->evaboost = 0;

    this->reflect = 0;
    this->lightscreen = 0;
    this->perishsong = 0;

    this->trapped = false;
    this->move_locked = false;
    this->taunt = false;
    this->confusion = false;
    this->ingrain = false;
    this->yawn = false;
    this->infatuated = false;
    this->curse = false;
    this->leechseed = false;
    this->block = false;
    this->targetable = true;
    this->charge = false;
    this->foresight = false;
    this->lockon = false;
    this->mist = false;
}

int Team::get_boost(Statname stat){
    switch(stat){
        case Statname::Atk:
            return this->atkboost;
        case Statname::Def:
            return this->defboost;
        case Statname::Satk:
            return this->satkboost;
        case Statname::Sdef:
            return this->sdefboost;
        case Statname::Spe:
            return this->speboost;
        case Statname::Acc:
            return this->accboost;
        case Statname::Eva:
            return this->evaboost;
        default:
        #ifdef _DEBUG
            std::cout << "ERROR GET_BOOST team.cpp" << std::endl;
        #endif
            return 0;
    }
}

void Team::set_boost(Statname stat, int boost){
    switch(stat){
        case Statname::Acc:
            this->accboost += boost;
            if(this->accboost > 6){
                this->accboost = 6;
            }
            if(this->accboost < -6){
                this->accboost = -6;
            }
            return;
        case Statname::Atk:
            this->atkboost += boost;
            if(this->atkboost > 6){
                this->atkboost = 6;
            }
            if(this->atkboost < -6){
                this->atkboost = -6;
            }
            return;
        case Statname::Def:
            this->defboost += boost;
            if(this->defboost > 6){
                this->defboost = 6;
            }
            if(this->defboost < -6){
                this->defboost = -6;
            }
            return;
        case Statname::Eva:
            this->evaboost += boost;
            if(this->evaboost > 6){
                this->evaboost = 6;
            }
            if(this->evaboost < -6){
                this->evaboost = -6;
            }
            return;
        case Statname::Satk:
            this->satkboost += boost;
            if(this->satkboost > 6){
                this->satkboost = 6;
            }
            if(this->satkboost < -6){
                this->satkboost = -6;
            }
            return;
        case Statname::Sdef:
            this->sdefboost += boost;
            if(this->sdefboost > 6){
                this->sdefboost = 6;
            }
            if(this->sdefboost < -6){
                this->sdefboost = -6;
            }
            return;
        case Statname::Spe:
            this->speboost += boost;
            if(this->speboost > 6){
                this->speboost = 6;
            }
            if(this->speboost < -6){
                this->speboost = -6;
            }
            return;
    }
}

void Team::use_pinch_berry(){
    if(this->active()->get_current_hp() < 
        (this->active()->get_stats().hp / 4.0)){
        switch(this->active()->get_item()){
            case Item::Liechiberry:
                this->set_boost(Statname::Atk, 1);
                this->active()->remove_item();
                return;
            case Item::Ganlonberry:
                this->set_boost(Statname::Def, 1);
                this->active()->remove_item();
                return;
            case Item::Petayaberry:
                this->set_boost(Statname::Satk, 1);
                this->active()->remove_item();
                return;
            case Item::Apicotberry:
                this->set_boost(Statname::Sdef, 1);
                this->active()->remove_item();
                return;
            case Item::Salacberry:
                this->set_boost(Statname::Spe, 1);
                this->active()->remove_item();
                return;
        }
    }
}

void Team::set_confusion(){
    if(this->active()->get_ability() == Ability::Own_Tempo){ return; }
    if(this->confusion < 1){
        this->confusion = get_random(2,5);
    }
}

void Team::use_hp_berry(){
    auto berry_heal = [&](){
            this->active()->increase_hp(static_cast<int>(this->active()->get_stats().hp / 8.0));
        };

    if(this->active()->get_current_hp() < 
        (this->active()->get_stats().hp / 2.0)){
        switch(this->active()->get_item()){
            case Item::Aguavberry:
                switch(this->active()->get_nature()){
                    case Nature::Naughty:
                    case Nature::Rash:
                    case Nature::Naive:
                    case Nature::Lax:
                        this->set_confusion();
                }
                berry_heal();
                break;
            case Item::Figyberry:
                switch(this->active()->get_nature()){
                    case Nature::Modest:
                    case Nature::Timid:
                    case Nature::Calm:
                    case Nature::Bold:
                        this->set_confusion();
                }
                berry_heal();
                break;
            case Item::Iapapaberry:
                switch(this->active()->get_nature()){
                    case Nature::Lonely:
                    case Nature::Mild:
                    case Nature::Gentle:
                    case Nature::Hasty:
                        this->set_confusion();
                }
                berry_heal();
                break;
            case Item::Magoberry:
                switch(this->active()->get_nature()){
                    case Nature::Brave:
                    case Nature::Quiet:
                    case Nature::Sassy:
                    case Nature::Relaxed:
                        this->set_confusion();
                }
                berry_heal();
                break;
            case Item::Wikiberry:
                switch(this->active()->get_nature()){
                    case Nature::Adamant:
                    case Nature::Jolly:
                    case Nature::Careful:
                    case Nature::Impish:
                        this->set_confusion();
                }
                break;
            case Item::Oranberry:
                this->active()->increase_hp(10);
                break;
            case Item::Sitrusberry:
                this->active()->increase_hp(30);
                break;
        }
    }
}

Pokemon* Team::active(){
    return &this->member[this->active_pokemon];
}

void Team::get_move_options(){
    const std::array<AttackMove, 4> *moves = this->active()->get_moveset();
    // Struggle will be chosen if pokemon can use no other move (not switches)
    static AttackMove struggle(Move::Struggle, 9999);

    // free the vector from previous options
    this->move_options.clear();

    if(this->active()->get_current_hp() > 0){
        // if pokemon is locked into a move, add it
        if(this->move_locked){
            if(this->locked_move->get_pp() > 0){
                this->move_options.push_back(this->locked_move);        
            }
        }
        // add all moves that are not disabled and have more than 0 PP
        else{
            for(auto&& move : *this->active()->get_moveset()){
                if(move.get_pp() > 0 && !move.get_disabled()){
                    this->move_options.push_back(&move);
                }
            }
        }
        // pokemon has to struggle if no other move can be chosen
        if(this->move_options.size() == 0){
            this->move_options.push_back(&struggle);
        }
        // if trapped, pokemon can't switch
        if(this->trapped){
            return;
        }
    }
    // add non fainted pokemon as switch options
    for(int i = 0; i<6; ++i){
        // don't switch to self
        if(i == this->active_pokemon){
            continue;
        }
        else{
            if(this->member[i].get_status() != Status::Fainted){
                this->move_options.push_back(&this->switches[i]);
            }
        }
    }
}