#ifndef UIPROVIDER_H
#define UIPROVIDER_H
#include "state.h"

class UIProvider
{    
    //user actions
    enum
    {
        ACTION_HELP=0,
        ACTION_ADD,
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

   static void clearStream();

   static void handleHelp();
   static void handleAddAction( List<State>&list);
   static void handleFindAction( List<State>&list);
   static void handlePrintAction( List<State>&list);
   static void handleSortAction( List<State>&list);
   static void handleReadAction( List<State>&list);
   static void handleWriteAction( List<State>&list);

   static void printList(List<State>& list);


public:

   static void handleUserInput(List<State>&list);
};

#endif // UIPROVIDER_H
