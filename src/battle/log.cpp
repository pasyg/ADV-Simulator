#include "battle.hpp"

void Battle::cant_move_log(Team &team, std::string_view reason)
{
    if(this->logger.is_open())
    {
        this->logger << "|cant|" << team.team << ": " << to_string(team.active()->get_species()) << "|" << reason << "\n";
    }
}

void Battle::damage_log(Team &team, Pokemon &target, std::string_view from)
{
    if(this->logger.is_open())
    {
        this->logger <<  "|-damage|" << team.team << ": " << to_string(target.get_species()) 
                        << "|" << std::to_string(target.hp_percentage()) << "/100|[from] " << from << "\n";
    }
}

void Battle::atk_damage_log(Team &team)
{
    if(this->logger.is_open())
    {
        this->logger << "|-damage|" << team.team << ": " << to_string(team.active()->get_species())
                     << "|" << std::to_string(team.active()->hp_percentage()) << "/100\n";
    }
}

void Battle::faint_log(Team &team)
{
    if(this->logger.is_open())
    {
        this->logger << "|faint|" << team.team << ": " << to_string(team.active()->get_species()) << "\n";
    }
}

void Battle::heal_log(Team &team, Pokemon &target, std::string_view from)
{
    if(this->logger.is_open())
    {
        this->logger <<  "|-heal|" << team.team << ": " << to_string(target.get_species()) 
                        << "|" << std::to_string(target.hp_percentage()) << "/100|[from] " << from << "\n";
    }
}

void Battle::move_log(Team &atkteam, Team &defteam)
{
    if(this->logger.is_open())
    {
        this->logger << "|move|" << atkteam.team << ": " << to_string(atkteam.active()->get_species())
                     << "|" << to_string(atkteam.movechoice->get_move()) << "|" << defteam.team
                     << ": " << to_string(defteam.active()->get_species()) << "\n";
    }
}

void Battle::miss_log(bool team)
{
    if(this->logger.is_open())
    {
        this->logger << "|-miss|p" << std::to_string(team + 1) << "a: " << to_string(this->team[team].active()->get_species()) 
                     << "|p" << std::to_string(!team + 1) << "a: " << to_string(this->team[!team].active()->get_species()) << "\n";
    }
}

void Battle::crit_log(Team &team)
{
    if(this->logger.is_open())
    {
        this->logger << "|-crit|" << team.team << ": " << to_string(team.active()->get_species()) << "\n";
    }
}

void Battle::switch_log(Team &team)
{
    if(this->logger.is_open())
    {
        this->logger << "|switch|" << team.team << ": " << to_string(team.active()->get_species()) << "|" 
                     << to_string(team.active()->get_species()) << "| " << team.active()->hp_percentage() << "/100\n";
    }
}

void Battle::weather_start(Team &team, Weather weather, std::string_view from)
{
    if(this->logger.is_open())
    {
        this->logger << "|-weather|" << to_string(weather) << "|[from]" << from << "|[of] " << team.team 
                     << ": " << to_string(team.active()->get_species()) << "\n";
    }
}

void Battle::weather_upkeep()
{
    if(this->logger.is_open())
    {
        this->logger << "|-weather|" << to_string(this->weather) << "|[upkeep]\n";
    }
}

void Battle::weather_end()
{
    if(this->logger.is_open())
    {
        this->logger << "|-weather|none\n";
    }
}

void Battle::miss_log()
{
}

void Battle::substitute_log(Team &team)
{
    if(this->logger.is_open())
    {
        this->logger << "|-start|" << team.team << ": " << to_string(team.active()->get_species()) << "|Substitute\n";
    }
}

void Battle::confusion_log()
{
}

void Battle::infatuation_log()
{
}

void Battle::truant_log()
{    
}