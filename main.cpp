#include <QCoreApplication>
#include <iostream>
#include "state.h"

void printList(List<State::State>& list)
{
 for (int i=0;i<list.Len();i++)
    std::cout<<list[i].capitalName<<"\n" <<list[i].countryName<<"\nLanguage: " <<list[i].language<<
                "\nMonetary unit: "<<list[i].monetaryUnit<<"\nPolitical system: " <<list[i].politicalSystem<<
                "\nPopulation: "<<list[i].population<<"\nArea: "<<list[i].territoryArea<<"\n\n\n";
}


int main(int argc, char *argv[])
{

 using namespace State;

    List<State::State> list;

    std::ofstream ofs;
    std::ifstream ifs;
    /*
    ofs.open("State");

   readFromKeyboard(list);

   printList(list);
   writeToFile(ofs, list);
    ofs.close();
    */
    ifs.open("State");
    readFromFile(ifs, list);
    ifs.close();
    printList(list);


    list.Sort(0, list.Len()-1, &comparePopulation);
    printList(list);




    return 0;
}
