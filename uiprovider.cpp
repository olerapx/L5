#include "uiprovider.h"

void UIProvider::clearStream()
 {
     std::cin.clear();
     while (std::cin.get() != '\n');
 }


void UIProvider::handleUserInput(List<State>&list)
{
    char s='\0';
    handleHelp();
    do{
        s=std::cin.get();
        clearStream();
        switch(s-'0')
        {

           case ACTION_HELP:
             handleHelp();
             break;

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

           default:
            std::cout<< "Wrong command. To get the command list, input 0\n";
            break;
        }
    }
    while (true);
}


void UIProvider::handleAddAction(List<State>&list)
{
    State::readFromKeyboard(list);
    std::cout << "inputting finished\n";
}

void UIProvider::handleFindAction(List<State>&list)
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

   State state, temp;

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

void UIProvider::handlePrintAction(List<State>&list)
{
    printList(list);
}

void UIProvider::handleSortAction(List<State>&list)
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

       default:
            std::cout <<"Wrong field\n";
            return;
    }
    std::cout <<"list has been sorted\n";
}

void UIProvider::handleReadAction( List<State>&list)
{
    std::cout <<"Input filename\n";
    std::string filename;
    std::cin>>filename;
    clearStream();

    std::ifstream ifs;
    ifs.open(filename);
    if (!ifs.is_open())
    {
        ifs.close();
        std::cout <<"file is not exists\n";
        return;
    }
    State::readFromFile(ifs, list);
    ifs.close();
    std::cout << "file has been read successfully\n";
}

void UIProvider::handleWriteAction( List<State>&list)
{
    std::cout <<"Input filename\n";
    std::string filename;
    std::cin>>filename;
    clearStream();

    std::ofstream ofs;
    ofs.open(filename);
    State::writeToFile(ofs, list);
    ofs.close();
    std::cout << "successfully wrote to file\n";
}

void UIProvider::handleHelp()
{
    std::cout <<"input:\n"
                "0 to get the command list\n"
                "1 to add States into list\n"
                "2 to find element\n"
                "3 to print list\n"
                "4 to sort\n"
                "5 to read\n"
                "6 to write\n"
                "7 to clear\n"
                "8 to quit\n";
}

void UIProvider::printList(List<State>& list)
{
    for (unsigned int i=0;i<list.Len();i++)
       std::cout<<"Capital name: "<<list[i].capitalName<<"\nCountry name: " <<list[i].countryName<<"\nLanguage: " <<list[i].language<<
                   "\nMonetary unit: "<<list[i].monetaryUnit<<"\nPolitical system: " <<list[i].politicalSystem<<
                   "\nPopulation: "<<list[i].population<<"\nArea: "<<list[i].territoryArea<<"\n\n\n";
}
