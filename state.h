#ifndef STATE_H
#define STATE_H
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "list.h"

namespace State
{

class State
{
public:

    std::string countryName, capitalName, language;
    int population;
    float territoryArea;
    std::string monetaryUnit, politicalSystem; 

    State();
};

//for sorting and getting an element by value of some field
int compareCountryName(const State& s1, const State& s2);
int compareCapitalName(const State& s1, const State& s2);
int compareLanguage(const State& s1, const State& s2);
int comparePopulation (const State& s1, const State& s2);
int compareTerrritoryArea(const State& s1, const State& s2);
int compareMonetaryUnit(const State& s1, const State& s2);
int comparePoliticalSystem(const State& s1, const State& s2);

void writeToFile (std::ofstream &ofs, List<State>& list);
void readFromFile (std::ifstream &ifs, List<State>& list);
void readFromKeyboard(List<State>&list);




}
#endif // STATE_H

