#include <QCoreApplication>
#include <iostream>
#include "state.h"

int comparison(const int& i1, const int& i2)
{
    if (i1<i2) return -1;
    if(i1==i2) return 0;
    if (i1>i2) return 1;
}



int main(int argc, char *argv[])
{

 using namespace State;

    State::State s1,s2;
    s1.capitalName="Moscow";
    s2.capitalName="Amsterdam";

    List<State::State> list;

   list.add(s1);
   list.add(s2);
   std::cout <<list[0].capitalName<<" "<<list[1].capitalName<<"\n";





    list.Sort(0,list.Len()-1,&compareCapitalName);
    std::cout <<list[0].capitalName<<" "<<list[1].capitalName<<"\n";





    return 0;
}
