#include "team.hpp"
#include "rng.hpp"

Team::Team() : teamsize(0)
{
}

/////////////////////////////////////////////////////
void Team::init()
{
    // initialize each pokemon
    for(auto&& pokemon : this->member)
    {
        if(pokemon.get_species() != Species::None)
        {
            pokemon.init();
            this->teamsize++;
        }
    }
    
    this->active_pokemon = 0;
    this->protect        = false;
    this->protect_acc    = 100;
    this->flinch         = false;
    this->focuspunch     = false;
    this->magiccoat      = false;
    this->endure         = false;
    this->grudge         = false;
    this->lastdamage     = 0;

    this->wish           = false;
    this->wish_recovery  = 0;
    this->spikes         = 0;

    this->atkboost       = 0;
    this->defboost       = 0;
    this->satkboost      = 0;
    this->sdefboost      = 0;
    this->speboost       = 0;
    this->accboost       = 0;
    this->evaboost       = 0;

    this->reflect        = 0;
    this->lightscreen    = 0;
    this->perishsong     = 0;

    this->trapped        = false;
    this->move_locked    = false;
    this->taunt          = false;
    this->confusion      = false;
    this->ingrain        = false;
    this->yawn           = false;
    this->infatuated     = false;
    this->curse          = false;
    this->leechseed      = false;
    this->block          = false;
    this->targetable     = true;
    this->charge         = false;
    this->foresight      = false;
    this->lockon         = false;
    this->mist           = false;
}

int Team::get_boost(Statname stat)
{
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

void Team::set_boost(Statname stat, int boost)
{
    if(this->active()->get_item() == Item::Whiteherb)
    {
        if(boost < 0){
            this->active()->set_item(Item::None);
            return;
        }
    }
    auto boundcheck = [](int boost){ 
                                        if(boost > 6){ return 6; }
                                        if(boost < -6){ return -6;}
                                        return boost;  
                                    };
    switch(stat)
    {
        case Statname::Acc:
            this->accboost  = boundcheck(this->accboost + boost);
            return;
        case Statname::Atk:
            this->atkboost  = boundcheck(this->atkboost + boost);
            return;
        case Statname::Def:
            this->defboost  = boundcheck(this->defboost + boost);
            return;
        case Statname::Eva:
            this->evaboost  = boundcheck(this->evaboost + boost);
            return;
        case Statname::Satk:
            this->satkboost = boundcheck(this->satkboost + boost);
            return;
        case Statname::Sdef:
            this->sdefboost = boundcheck(this->sdefboost + boost);
            return;
        case Statname::Spe:
            this->speboost  = boundcheck(this->speboost + boost);
            return;
    }
}

void Team::set_boost_flat(Statname stat, int boost)
{
    switch(stat)
    {
        case Statname::Atk:     this->atkboost  = boost; return;
        case Statname::Def:     this->defboost  = boost; return;
        case Statname::Satk:    this->satkboost = boost; return;
        case Statname::Sdef:    this->sdefboost = boost; return;
        case Statname::Spe:     this->speboost  = boost; return;
        case Statname::Acc:     this->accboost  = boost; return;
        case Statname::Eva:     this->evaboost  = boost; return;
        default: std::cout << "Error set_boost_flat\n";  return;
    }
}
void Team::use_pinch_berry()
{
    auto berry_boost = [&](Statname stat){
                                            this->set_boost(stat, 1);
                                            this->active()->remove_item();
                                         };

    if(this->active()->get_current_hp() < 
        (this->active()->get_stats().hp / 4.0))
    {
        switch(this->active()->get_item())
        {
            case Item::Liechiberry:
                berry_boost(Statname::Atk);
                return;
            case Item::Ganlonberry:
                berry_boost(Statname::Def);
                return;
            case Item::Petayaberry:
                berry_boost(Statname::Satk);
                return;
            case Item::Apicotberry:
                berry_boost(Statname::Sdef);
                return;
            case Item::Salacberry:
                berry_boost(Statname::Spe);
                return;
        }
    }
}

void Team::set_confusion(){
    if(this->active()->get_ability() == Ability::Own_Tempo){ return; }
    if(this->confusion < 1)
    {
        this->confusion = get_random(2,5); // TODO Needs major overhaul
    }
}

void Team::use_hp_berry(){
    auto berry_heal = [&]()
        {
            this->active()->increase_hp(static_cast<int>(this->active()->get_stats().hp / 8.0));
        };

    if(this->active()->get_current_hp() < 
        (this->active()->get_stats().hp / 2.0))
    {
        switch(this->active()->get_item())
        {
            case Item::Aguavberry:
                switch(this->active()->get_nature())
                {
                    case Nature::Naughty:
                    case Nature::Rash:
                    case Nature::Naive:
                    case Nature::Lax:
                        this->set_confusion();
                }
                berry_heal();
                break;
            case Item::Figyberry:
                switch(this->active()->get_nature())
                {
                    case Nature::Modest:
                    case Nature::Timid:
                    case Nature::Calm:
                    case Nature::Bold:
                        this->set_confusion();
                }
                berry_heal();
                break;
            case Item::Iapapaberry:
                switch(this->active()->get_nature())
                {
                    case Nature::Lonely:
                    case Nature::Mild:
                    case Nature::Gentle:
                    case Nature::Hasty:
                        this->set_confusion();
                }
                berry_heal();
                break;
            case Item::Magoberry:
                switch(this->active()->get_nature())
                {
                    case Nature::Brave:
                    case Nature::Quiet:
                    case Nature::Sassy:
                    case Nature::Relaxed:
                        this->set_confusion();
                }
                berry_heal();
                break;
            case Item::Wikiberry:
                switch(this->active()->get_nature())
                {
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

Pokemon* Team::active()
{
    return &this->member[this->active_pokemon];
}

std::ostream& operator<<(std::ostream& out, Team& team)
{
    out << "Size: " << team.teamsize << "\n";
    out << "Active Pokemon: " << to_string(team.active()->get_species()) << "\n";
    out << "Boosts: Atk: "  << team.get_boost(Statname::Atk)
                            << " Def: "  << team.get_boost(Statname::Def)
                            << " SAtk: " << team.get_boost(Statname::Satk)
                            << " SDef: " << team.get_boost(Statname::Sdef)
                            << " Spe: "  << team.get_boost(Statname::Spe)
                            << "\n";
    for(auto&& member : team.member)
    {
        if(member.get_species() != Species::None)
        {
            out << member;
        }
    }
    return out;
}

void Team::get_move_options(std::array<Move, 3> impmoves)
{
    const std::array<AttackMove, 4> *moves = this->active()->get_moveset();
    // Struggle will be chosen if pokemon can use no other move (not switches)
    static AttackMove struggle(Move::Struggle);
    struggle.set_pp(9999);
    
    // free the vector from previous options
    this->move_options.clear();

    if(this->active()->get_current_hp() > 0)
    {
        // if pokemon is locked into a move, add it
        if(this->move_locked)
        {
            // needs torment taunt etc. too
            if(this->locked_move->get_pp() > 0)
            {
                this->move_options.push_back(this->locked_move);        
            }
        }
        // add all moves that are not disabled and have more than 0 PP and not hindered by imprison, taunt or torment
        else
        {
            for(auto&& move : *this->active()->get_moveset())
            {
                // can't select move without pp
                if(move.get_pp() < 1)
                {
                    continue;
                }
                // can't select disabled moves
                if(move.get_disabled())
                {
                    continue;
                }
                // can't select certain moves when taunted
                if(taunt_move(move.get_move()) && this->taunt)
                {
                    continue;
                }
                // can't select same move twice in a row when tormented
                if(this->torment)
                {
                    if(this->prev_movechoice->get_move() == move.get_move())
                    {
                        continue;
                    }
                }
                // can't select moves shared with opponent when opponents imprison is active
                if(std::any_of(impmoves.begin(), impmoves.end(), 
                                [&move](Move impmove) -> bool { return move.get_move() == impmove; }))
                {
                        continue;
                }
                // add move to options
                this->move_options.push_back(&move);
            }
        }        
        // pokemon has to struggle if no other move can be chosen
        if(this->move_options.size() == 0)
        {
            this->move_options.push_back(&struggle);
        }    
        // if trapped, pokemon can't switch
        if(this->trapped)
        {
            return;
        }
    }
    // add non fainted pokemon as switch options
    for(int i = 0; i<6; ++i)
    {
        // don't switch to self
        if(i == this->active_pokemon)
        {
            continue;
        }
        else
        {
            if(this->member[i].get_status() != Status::Fainted)
            {
                this->move_options.push_back(&this->switches[i]);
            }
        }
    }
}

// returns true if move is affected by taunt
bool Team::taunt_move(const Move move)
{
    switch(move)
    {
        case Move::Acid_Armor:
        case Move::Agility:
        case Move::Amnesia:
        case Move::Barrier:
        case Move::Bide:
        case Move::Confuse_Ray:
        case Move::Conversion:
        case Move::Conversion_2:
        case Move::Counter:
        case Move::Defense_Curl:
        case Move::Double_Team:
        case Move::Flash:
        case Move::Focus_Energy:
        case Move::Glare:
        case Move::Growl:
        case Move::Growth:
        case Move::Harden:
        case Move::Haze:
        case Move::Hypnosis:
        case Move::Kinesis:
        case Move::Leech_Seed:
        case Move::Leer:
        case Move::Light_Screen:
        case Move::Lovely_Kiss:
        case Move::Meditate:
        case Move::Metronome:
        case Move::Mimic:
        case Move::Minimize:
        case Move::Mirror_Move:
        case Move::Mist:
        case Move::Poison_Gas:
        case Move::Poison_Powder:
        case Move::Recover:
        case Move::Reflect:
        case Move::Rest:
        case Move::Roar:
        case Move::Sand_Attack:
        case Move::Screech:
        case Move::Sharpen:
        case Move::Sing:
        case Move::Sleep_Powder:
        case Move::Smog:
        case Move::Smokescreen:
        case Move::Soft_Boiled:
        case Move::Splash:
        case Move::Spore:
        case Move::String_Shot:
        case Move::Stun_Spore:
        case Move::Substitute:
        case Move::Swords_Dance:
        case Move::Tail_Whip:
        case Move::Teleport:
        case Move::Thunder_Wave:
        case Move::Toxic:
        case Move::Transform:
        case Move::Whirlwind:
        case Move::Withdraw:
        case Move::Attract:
        case Move::Baton_Pass:
        case Move::Belly_Drum:
        case Move::Charm:
        case Move::Cotton_Spore:
        case Move::Curse:
        case Move::Destiny_Bond:
        case Move::Detect:
        case Move::Encore:
        case Move::Endure:
        case Move::Foresight:
        case Move::Heal_Bell:
        case Move::Lock_On:
        case Move::Mean_Look:
        case Move::Milk_Drink:
        case Move::Mind_Reader:
        case Move::Mirror_Coat:
        case Move::Moonlight:
        case Move::Morning_Sun:
        case Move::Pain_Split:
        case Move::Perish_Song:
        case Move::Present:
        case Move::Protect:
        case Move::Psych_Up:
        case Move::Rain_Dance:
        case Move::Safeguard:
        case Move::Sandstorm:
        case Move::Scary_Face:
        case Move::Sketch:
        case Move::Sleep_Talk:
        case Move::Spider_Web:
        case Move::Spikes:
        case Move::Sunny_Day:
        case Move::Swagger:
        case Move::Sweet_Kiss:
        case Move::Sweet_Scent:
        case Move::Synthesis:
        case Move::Aromatherapy:
        case Move::Assist:
        case Move::Block:
        case Move::Bulk_Up:
        case Move::Calm_Mind:
        case Move::Cosmic_Power:
        case Move::Covet:
        case Move::Dragon_Dance:
        case Move::Fake_Tears:
        case Move::Feather_Dance:
        case Move::Flatter:
        case Move::Follow_Me:
        case Move::Grass_Whistle:
        case Move::Hail:
        case Move::Helping_Hand:
        case Move::Howl:
        case Move::Imprison:
        case Move::Ingrain:
        case Move::Iron_Defense:
        case Move::Magic_Coat:
        case Move::Memento:
        case Move::Metal_Sound:
        case Move::Mud_Shot:
        case Move::Mud_Sport:
        case Move::Odor_Sleuth:
        case Move::Recycle:
        case Move::Refresh:
        case Move::Role_Play:
        case Move::Skill_Swap:
        case Move::Slack_Off:
        case Move::Snatch:
        case Move::Stockpile:
        case Move::Swallow:
        case Move::Tail_Glow:
        case Move::Taunt:
        case Move::Teeter_Dance:
        case Move::Tickle:
        case Move::Torment:
        case Move::Trick:
        case Move::Water_Sport:
        case Move::Will_O_Wisp:
        case Move::Wish:
        case Move::Yawn:
            return true;
        default:
            return false;
    }
}