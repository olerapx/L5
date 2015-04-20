#include "state.h"


int State::compareCountryName(const State& s1, const State& s2)
{
    return strcmp(s1.countryName.c_str(), s2.countryName.c_str());
}

int State::compareCapitalName(const State& s1, const State& s2)
{
     return strcmp(s1.capitalName.c_str(), s2.capitalName.c_str());
}

int State::compareLanguage(const State& s1, const State& s2)
{
     return strcmp(s1.language.c_str(), s2.language.c_str());
}

int State::comparePopulation (const State& s1, const State& s2)
{
    if (s1.population<s2.population) return -1;
    if(s1.population==s2.population) return 0;
    if (s1.population>s2.population) return 1;
}

int State::compareTerrritoryArea(const State& s1, const State& s2)
{
    if (s1.territoryArea<s2.territoryArea) return -1;
    if(s1.territoryArea==s2.territoryArea) return 0;
    if (s1.territoryArea>s2.territoryArea) return 1;
}

int State::compareMonetaryUnit(const State& s1, const State& s2)
{
    return strcmp(s1.monetaryUnit.c_str(), s2.monetaryUnit.c_str());
}

int State::comparePoliticalSystem(const State& s1, const State& s2)
{
   return strcmp(s1.politicalSystem.c_str(), s2.politicalSystem.c_str());
}

void State::writeToFile (std::ofstream &ofs)
{

}

void State::readFromFile (std::ifstream &ifs, List<State>& list)
{

}
