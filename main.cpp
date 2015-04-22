#include <QCoreApplication>
#include <iostream>
#include "state.h"

void printList(List<State::State>& list)
{
 for (unsigned int i=0;i<list.Len();i++)
    std::cout<<list[i].capitalName<<"\n" <<list[i].countryName<<"\nLanguage: " <<list[i].language<<
                "\nMonetary unit: "<<list[i].monetaryUnit<<"\nPolitical system: " <<list[i].politicalSystem<<
                "\nPopulation: "<<list[i].population<<"\nArea: "<<list[i].territoryArea<<"\n\n\n";
}


int main(int argc, char *argv[])
{

    List<State::State> list;

    std::ofstream ofs;
    std::ifstream ifs;
    std::string fileName;
    std::cout <<"input filename\n";
    std::cin>>fileName;

    readFromKeyboard(list);
    std::cout <<"From keyboard:\n";
    printList(list);

    ofs.open(fileName);
    writeToFile(ofs, list);
    ofs.close();

    std::cout <<"Wrote to file\n";

    ifs.open(fileName);
    list.clear();
    State::readFromFile(ifs, list);
    ifs.close();

    std::cout <<"From file:\n";
    printList(list);

    std::cout <<"Sorted by country name:\n";
    list.Sort(0, list.Len()-1, &State::compareCountryName);
    printList(list);
    State::State temp;
    temp.countryName=list[0].countryName;
    std::cout <<"Language of first country:\n";
    std::cout <<list.getElementByElementField(temp, &State::compareCountryName).language<<"\n";



    return 0;
}
