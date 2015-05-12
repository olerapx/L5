#ifndef UIPROVIDER_H
#define UIPROVIDER_H
#include "state.h"
#include "map"

//user actions
enum UserAction
{
    ACTION_UNKNOWN=-1,
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

static std::map <char, UserAction> Commands{{'h',ACTION_HELP}, {'a',ACTION_ADD}, {'f',ACTION_FIND},
                                           {'p',ACTION_PRINT}, {'s',ACTION_SORT}, {'r',ACTION_READ},
                                           {'w',ACTION_WRITE}, {'c',ACTION_CLEAR}, {'q',ACTION_QUIT}};
class UIProvider
{

   static UserAction getAction(char s);

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
