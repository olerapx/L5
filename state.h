#ifndef STATE_H
#define STATE_H
#include <string>
#include <cstring>

class State
{
private:

public:

    std::string countryName, capitalName, language;
    int population;
    float territoryArea;
    std::string monetaryUnit, politicalSystem;

};

//for sorting and finding by value
int compareCountryName(const State& s1, const State& s2);
int compareCapitalName(const State& s1, const State& s2);
int compareLanguage(const State& s1, const State& s2);
int comparePopulation (const State& s1, const State& s2);
int compareTerrritoryArea(const State& s1, const State& s2);
int compareMonetaryUnit(const State& s1, const State& s2);
int comparePoliticalSystem(const State& s1, const State& s2);


#endif // STATE_H

