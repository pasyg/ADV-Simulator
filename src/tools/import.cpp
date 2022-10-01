#include "import.hpp"

//NICKNAME=0|SPECIES=1|ITEM=2|ABILITY=3|MOVES=4|NATURE=5|EVS=6|GENDER=7|IVS=8|SHINY=9|LEVEL=10|HAPPINESS,POKEBALL,HIDDENPOWERTYPE=11

void set_moves(std::string &moves, Pokemon &pokemon)
{
    std::array<AttackMove, 4> moveset;
    std::string delimiter = ",";

    std::array<std::string, 4> arrmoves;
    size_t posmoves = 0;
    size_t moveindex = 0;
    moves += ",";
    while((posmoves = moves.find(delimiter)) != std::string::npos)
    {
        moveset[moveindex].set_move(from_string<Move>(moves.substr(0, posmoves)));
        moves.erase(0, posmoves + delimiter.length());
        ++moveindex;
    }
    pokemon.set_moveset(moveset);
    
}
void set_evs(std::string &evs, Pokemon &pokemon)
{
    Stats stats;
    std::string delimiter = ",";

    std::array<std::string, 6> arrevs;
    size_t posevs = 0;
    size_t evindex = 0;
    evs += ",";
    
    while((posevs = evs.find(delimiter)) != std::string::npos)
    {
        arrevs[evindex] = evs.substr(0, posevs);
        evs.erase(0, posevs + delimiter.length());
        ++evindex;
    }
    for(int i = 0; i < 6; ++i)
    {
        if(arrevs[i] == "")
        {
            arrevs[i] = "0";
        }
    }
    stats.hp    = std::stoi(arrevs[0]);
    stats.atk   = std::stoi(arrevs[1]);
    stats.def   = std::stoi(arrevs[2]);
    stats.satk  = std::stoi(arrevs[3]);
    stats.sdef  = std::stoi(arrevs[4]);
    stats.spe   = std::stoi(arrevs[5]);

    pokemon.set_evs(stats);
}
void set_ivs(std::string &ivs, Pokemon &pokemon)
{
    Stats stats;
    std::string delimiter = ",";

    std::array<std::string, 6> arrivs;
    size_t posivs = 0;
    size_t ivindex = 0;
    
    if(ivs == "")
    {
        stats.hp    = 31;
        stats.atk   = 31;
        stats.def   = 31;
        stats.satk  = 31;
        stats.sdef  = 31;
        stats.spe   = 31;

        pokemon.set_ivs(stats);
        return;
    }
    
    ivs += ",";


    while((posivs = ivs.find(delimiter)) != std::string::npos)
    {
        arrivs[ivindex] = ivs.substr(0, posivs);
        ivs.erase(0, posivs + delimiter.length());
        ++ivindex;
    }
    for(int i = 0; i < 6; ++i)
    {
        if(arrivs[i] == "")
        {
            arrivs[i] = "31";
        }
    }
    stats.hp    = std::stoi(arrivs[0]);
    stats.atk   = std::stoi(arrivs[1]);
    stats.def   = std::stoi(arrivs[2]);
    stats.satk  = std::stoi(arrivs[3]);
    stats.sdef  = std::stoi(arrivs[4]);
    stats.spe   = std::stoi(arrivs[5]);

    pokemon.set_ivs(stats);
}

std::vector<Team> import_team(std::string_view path)
{
    std::ifstream file("teams/packed/sample.txt");
    std::vector<Team> teams;

    if(file.is_open())
    {
        std::string line = "";
        std::string delimiter1 = "]";
        std::string delimiter2 = "|";
        size_t pos1 = 0;
        size_t pos2 = 0;

        std::array<std::string, 6> pokemon;
        std::array<std::array<std::string, 12>, 6> data;

        Team importteam;

        size_t j = 0;
        while(getline(file, line))
        {
            size_t i = 0;
            line += "]";

            // split packed in 6 pokemon
            while((pos1 = line.find(delimiter1)) != std::string::npos)
            {
                pokemon[i] = line.substr(0, pos1);
                line.erase(0, pos1 + delimiter1.length());
                ++i;
            }

            // split every pokemon into subcategories
            for(int i = 0; i < 6; ++i)
            {
                j = 0;
                while((pos2 = pokemon[i].find(delimiter2)) != std::string::npos)
                {
                    data[i][j] = pokemon[i].substr(0, pos2);
                    pokemon[i].erase(0, pos2 + delimiter2.length());
                    ++j;
                }
            }
            for(int i = 0; i < 6; ++i)
            {
                if(data[i][1] == "")
                {
                    importteam.member[i].set_species(from_string<Species>(data[i][0]));
                }
                else
                {
                    importteam.member[i].set_species(from_string<Species>(data[i][1]));
                }
                importteam.member[i].set_item(from_string<Item>(data[i][2]));
                importteam.member[i].set_ability(from_string<Ability>(data[i][3]));
                set_moves(data[i][4], importteam.member[i]);
                importteam.member[i].set_nature(from_string<Nature>(data[i][5]));
                set_evs(data[i][6], importteam.member[i]);
                importteam.member[i].set_gender(from_string<Gender>(data[i][7]));
                set_ivs(data[i][8], importteam.member[i]);
                if(data[i][10] == "")
                {
                    // defaults to level 100
                }
                else
                {
                    importteam.member[i].set_level(stoi(data[i][10]));
                }
            }
            teams.push_back(importteam);
        }

        return teams;
    }
    else
    {
        std::cout << "ERROR import team" << std::endl;
        return teams;
    }
}