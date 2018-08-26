#include <iostream>
#include <conio.h>
#include "include/abundant.h"
#include <list>
#include <iomanip>

using namespace std;

void DisplayProgress(unsigned char p_progress);

int main(int argc, char const *argv[])
{
    const unsigned limit {1000000};
    cout << "Amicable numbers smaller than 1 million" << endl;
  
    //Calculation
    cout << "Calculating the amical numbers up to 999 999..." << endl;
    
    list<pair<unsigned, unsigned>> abundanceList;
    for(unsigned i=1; i<limit; i++)
    {
        auto abundance = abundantHelper::getAbundance(i);
        auto abundanceSecond = abundantHelper::getAbundance(abundance);
        //Example for Wikipedia
        //s(220)=1+2+4+5+10+11+20+22+44+55+110=284
        //s(284)=1+2+4+71+142=220.} s(284)=1+2+4+71+142=220.
        //220 and 284 are amicable numbers.
        if (abundanceSecond == i && i < abundance)
            abundanceList.push_back(pair<unsigned, unsigned>(i, abundance));

        if (i % (limit/20) == 0)
            DisplayProgress((i*100)/limit);
    }
    DisplayProgress(100);
    cout << endl;

    unsigned int amicableNumberCount {0};
    for(auto it : abundanceList)
    {
        if (amicableNumberCount > 0)
            cout << ", ";
        cout << "(" << it.first << "," << it.second << ")";
        amicableNumberCount++;
    }

    cout << endl;
    cout << "Press any key to continue... " << endl;
    getch();
    return 0;
}

void DisplayProgress(unsigned char p_progress)
{
    cout << "[";
    for(unsigned char i=0;i<=50;i++)
    {
        char progressSymbol = 219;
        if (i<=p_progress/2)
            cout << progressSymbol;
        else
            cout << " ";
    }
    cout << "]" << static_cast<unsigned>(p_progress) <<"% \r" << std::flush;
}
