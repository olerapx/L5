#include "uiprovider.h"


 UserAction UIProvider::getAction(char s)
 {
    if (Commands.find(s)!= Commands.end()) return Commands[s];

     return ACTION_UNKNOWN;
 }

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
        switch(getAction(s))
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
            std::cout<< "Wrong command. To get the command list, input h\n";
            break;
        }
    }
    while (true);
}


void UIProvider::handleAddAction(List<State>&list)
{
    readFromKeyboard(list);
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
              state=list.getElementByElementField(temp, &compareCountryName);
              break;

       case FIELD_CAPITAL_NAME:
              temp.capitalName=field;
              state=list.getElementByElementField(temp, &compareCapitalName);
              break;

       case FIELD_LANGUAGE:
              temp.language=field;
              state=list.getElementByElementField(temp, &compareLanguage);
              break;

       case FIELD_POPULATION:
              temp.population=atoi(field.c_str());
              state=list.getElementByElementField(temp, &comparePopulation);
              break;

       case FIELD_AREA:
              temp.territoryArea=atof(field.c_str());
              state=list.getElementByElementField(temp, &compareTerrritoryArea);
              break;

       case FIELD_UNIT:
              temp.monetaryUnit=field;
              state=list.getElementByElementField(temp, &compareMonetaryUnit);
              break;

       case FIELD_SYSTEM:
              temp.politicalSystem=field;
              state=list.getElementByElementField(temp, &comparePoliticalSystem);
              break;

       default:
              std::cout <<"Wrong field\n";
              return;
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
            list.Sort(0, list.Len()-1, &compareCountryName);
            break;

       case FIELD_CAPITAL_NAME:
            list.Sort(0, list.Len()-1, &compareCapitalName);
            break;

       case FIELD_LANGUAGE:
            list.Sort(0, list.Len()-1, &compareLanguage);
            break;

       case FIELD_POPULATION:
            list.Sort(0, list.Len()-1, &comparePopulation);
            break;

       case FIELD_AREA:
            list.Sort(0, list.Len()-1, &compareTerrritoryArea);
            break;

       case FIELD_UNIT:
            list.Sort(0, list.Len()-1, &compareMonetaryUnit);
            break;

       case FIELD_SYSTEM:
            list.Sort(0, list.Len()-1, &comparePoliticalSystem);
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
    readFromFile(ifs, list);
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
    writeToFile(ofs, list);
    ofs.close();
    std::cout << "successfully wrote to file\n";
}

void UIProvider::handleHelp()
{
    std::cout <<"input:\n"
                "h to get the command list\n"
                "a to add States into list\n"
                "f to find element\n"
                "p to print list\n"
                "s to sort\n"
                "r to read\n"
                "w to write\n"
                "c to clear\n"
                "q to quit\n";
}

void UIProvider::printList(List<State>& list)
{
    for (unsigned int i=0;i<list.Len();i++)
       std::cout<<"Capital name: "<<list[i].capitalName<<"\nCountry name: " <<list[i].countryName<<"\nLanguage: " <<list[i].language<<
                   "\nMonetary unit: "<<list[i].monetaryUnit<<"\nPolitical system: " <<list[i].politicalSystem<<
                   "\nPopulation: "<<list[i].population<<"\nArea: "<<list[i].territoryArea<<"\n\n\n";
}


void UIProvider::writeToFile (std::ofstream &ofs, List<State> &list)
{
    for (unsigned int i=0;i<list.Len();i++)
       ofs<<"Capital: "<<list[i].capitalName<<"\nCountry: " <<list[i].countryName<<"\nLanguage: " <<list[i].language<<
                   "\nMonetary unit: "<<list[i].monetaryUnit<<"\nPolitical system: " <<list[i].politicalSystem<<
                   "\nPopulation: "<<list[i].population<<"\nArea: "<<list[i].territoryArea<<"\n\n\n";
}


void UIProvider::readFromFile (std::ifstream &fs, List<State>& list)
{
    std::string s;
    int i=0, currListIndex=list.Len()-1;
    while (!fs.eof())
    {
       std::getline(fs,s);
       if (s=="") continue;
       switch(i)
       {
           case 0:
           {
                   State state;
                   list.add(state);
                   currListIndex++;

                   int index = s.find(':')+2;
                   list[currListIndex].capitalName=s.substr(index, s.length()-index);
                   i++;
                   break;
           }
           case 1:
           {
                  int index = s.find(':')+2;
                  list[currListIndex].countryName=s.substr(index, s.length()-index);
                  i++;
                  break;
           }
           case 2:
           {
                  int index = s.find(':')+2;
                  list[currListIndex].language=s.substr(index, s.length()-index);
                  i++;
                  break;
           }
           case 3:
           {
                  int index = s.find(':')+2;
                  list[currListIndex].monetaryUnit=s.substr(index, s.length()-index);
                  i++;
                  break;
           }
           case 4:
           {
                  int index = s.find(':')+2;
                  list[currListIndex].politicalSystem=s.substr(index, s.length()-index);
                  i++;
                  break;
           }
           case 5:
           {
                  std::string curr;
                  int index = s.find(':')+2;
                  curr=s.substr(index, s.length()-index);
                  list[currListIndex].population=atoi(curr.c_str());
                  i++;
                  break;
           }
           case 6:
           {
                  std::string curr;
                  int index = s.find(':')+2;
                  curr=s.substr(index, s.length()-index);
                  list[currListIndex].territoryArea=std::atof(curr.c_str());
                  i=0;
                  break;
           }
       }
   }
}


void UIProvider::readFromKeyboard(List<State>&list)
{
     std::string s=" ";
     std::cout <<"Input capital name, country name, language, monetary unit, political system, population and area."
                 "Each field must delim by tabulation. Input empty string to finish.\n";

    //clear console istream to read correctly
     std::cin.clear();

     while (true)
    {
        std::getline(std::cin,s);
        if (s=="") break;
        List <std::string> parsed;
        std::string curr;
        std::stringstream stream(s);

        while (std::getline(stream, curr, '\t'))
            parsed.add(curr);

          State state;

        int len=parsed.Len();
        if (len>0) state.capitalName=parsed[0];
        if (len>1)state.countryName=parsed[1];
        if (len>2)state.language=parsed[2];
        if (len>3)state.monetaryUnit=parsed[3];
        if (len>4)state.politicalSystem =parsed[4];
        if (len>5)
        {
            std::stringstream intStream(parsed[5]);
            intStream>> state.population;
        }

        if (len>6)
        {
            std::stringstream floatStream(parsed[6]);
            floatStream>> state.territoryArea;
        }

        list.add(state);
   }

}

