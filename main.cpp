#include <iostream>
#include "state.h"

//user actions
enum
{
    ACTION_ADD=1,
    ACTION_FIND,
    ACTION_PRINT,
    ACTION_SORT,
    ACTION_READ,
    ACTION_WRITE,
    ACTION_CLEAR,
    ACTION_QUIT
};

//State class fields
enum
{
    FIELD_COUNTRY_NAME=1,
    FIELD_CAPITAL_NAME,
    FIELD_LANGUAGE,
    FIELD_POPULATION,
    FIELD_AREA,
    FIELD_UNIT,
    FIELD_SYSTEM
};


void handleUserInput(List<State::State>&list);
void handleAddAction( List<State::State>&list);
void handleFindAction( List<State::State>&list);
void handlePrintAction( List<State::State>&list);
void handleSortAction( List<State::State>&list);
void handleReadAction( List<State::State>&list);
void handleWriteAction( List<State::State>&list);

void clearStream()
{
    std::cin.clear();
    while (std::cin.get() != '\n');
}

void printList(List<State::State>& list)
{
 for (unsigned int i=0;i<list.Len();i++)
    std::cout<<list[i].capitalName<<"\n" <<list[i].countryName<<"\nLanguage: " <<list[i].language<<
                "\nMonetary unit: "<<list[i].monetaryUnit<<"\nPolitical system: " <<list[i].politicalSystem<<
                "\nPopulation: "<<list[i].population<<"\nArea: "<<list[i].territoryArea<<"\n\n\n";
}


int main(int argc, char *argv[])
{
   List<State::State>list;
   handleUserInput(list);

   return 0;
}

void handleUserInput(List<State::State>&list)
{

char s;
do{
    std::cout <<"input:\n1 to add States into list\n2 to find element\n3 to print list\n4 to sort\n"
                "5 to read\n6 to write\n7 to clear\n8 to quit\n";

    s=std::cin.get();
    clearStream();
    switch(s-'0')
    {
       case ACTION_ADD:
         handleAddAction(list);
         break;

       case ACTION_FIND:
        handleFindAction(list);
        break;

       case ACTION_PRINT:
        handlePrintAction(list);
        break;

       case ACTION_SORT:
        handleSortAction(list);
        break;

       case ACTION_READ:
        handleReadAction(list);
        break;

       case ACTION_WRITE:
        handleWriteAction(list);
        break;

       case ACTION_CLEAR:
        list.clear();
        break;

       case ACTION_QUIT:
        return;
    }
}
while (true);

}


void handleAddAction(List<State::State>&list)
{
    State::readFromKeyboard(list);

}

void handleFindAction(List<State::State>&list)
{

    std::cout <<"Input:\n"
                "1 to find by country name\n"
                "2 to find by capital name\n"
                "3 to find by language\n"
                "4 to find by population\n"
                "5 to find by area\n"
                "6 to find by monetary unit\n"
                "7 to find by system\n";
   char s=std::cin.get();
    clearStream();
    std::cout <<"Input field:\n";
    std::string field;
    std::getline(std::cin,field);
    State::State state, temp;

    try{
    switch(s-'0')
    {
       case FIELD_COUNTRY_NAME:
              temp.countryName=field;
              state=list.getElementByElementField(temp, &State::compareCountryName);
              break;

       case FIELD_CAPITAL_NAME:
              temp.capitalName=field;
              state=list.getElementByElementField(temp, &State::compareCapitalName);
              break;

       case FIELD_LANGUAGE:
              temp.language=field;
              state=list.getElementByElementField(temp, &State::compareLanguage);
              break;

       case FIELD_POPULATION:
              temp.population=atoi(field.c_str());
              state=list.getElementByElementField(temp, &State::comparePopulation);
              break;

       case FIELD_AREA:
              temp.territoryArea=atof(field.c_str());
              state=list.getElementByElementField(temp, &State::compareTerrritoryArea);
              break;

       case FIELD_UNIT:
              temp.monetaryUnit=field;
              state=list.getElementByElementField(temp, &State::compareMonetaryUnit);
              break;

       case FIELD_SYSTEM:
              temp.politicalSystem=field;
              state=list.getElementByElementField(temp, &State::comparePoliticalSystem);
              break;
      }

    std::cout<<state.capitalName<<"\n" <<state.countryName<<"\nLanguage: " <<state.language<<
                "\nMonetary unit: "<<state.monetaryUnit<<"\nPolitical system: " <<state.politicalSystem<<
                "\nPopulation: "<<state.population<<"\nArea: "<<state.territoryArea<<"\n\n\n";
    }
    catch (NullElementException)
    {
        std::cout <<"No element can be found\n";
    }

}

void handlePrintAction(List<State::State>&list)
{
    printList(list);

}

void handleSortAction(List<State::State>&list)
{
    std::cout <<"Input:\n"
                "1 to sort by name\n"
                "2 to sort by capital name\n"
                "3 to sort by language\n"
                "4 to sort by population\n"
                "5 to sort by area\n"
                "6 to sort by monetary unit\n"
                "7 to sort by system\n";
  char s=std::cin.get();
    clearStream();
    switch(s-'0')
    {
       case FIELD_COUNTRY_NAME:
        list.Sort(0, list.Len()-1, &State::compareCountryName);

        break;
       case FIELD_CAPITAL_NAME:
       list.Sort(0, list.Len()-1, &State::compareCapitalName);

        break;
       case FIELD_LANGUAGE:
    list.Sort(0, list.Len()-1, &State::compareLanguage);
        break;
       case FIELD_POPULATION:
       list.Sort(0, list.Len()-1, &State::comparePopulation);

        break;
       case FIELD_AREA:
     list.Sort(0, list.Len()-1, &State::compareTerrritoryArea);

        break;
       case FIELD_UNIT:
      list.Sort(0, list.Len()-1, &State::compareMonetaryUnit);

        break;
       case FIELD_SYSTEM:
 list.Sort(0, list.Len()-1, &State::comparePoliticalSystem);
        break;

    }


}

void handleReadAction( List<State::State>&list)
{
    std::cout <<"Input filename\n";
    std::string filename;
    std::cin>>filename;
    clearStream();
    std::ifstream ifs;
    ifs.open(filename);
    State::readFromFile(ifs, list);
    ifs.close();

}

void handleWriteAction( List<State::State>&list)
{
    std::cout <<"Input filename\n";
    std::string filename;
    std::cin>>filename;
    clearStream();
    std::ofstream ofs;
    ofs.open(filename);
    State::writeToFile(ofs, list);
    ofs.close();

}

