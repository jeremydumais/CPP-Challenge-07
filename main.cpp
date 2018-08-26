#include <iostream>
#include <conio.h>
#include "include/abundant.h"

using namespace std;

int main(int argc, char const *argv[])
{
    const unsigned int limit {1000000};
    cout << "Amicable numbers smaller than 1 million" << endl;
  
    //Calculation
    unsigned int amicableNumberCount {0};
    for(unsigned int i=1; i<limit; i++)
    {
        auto firstDivisors = abundantHelper::getDivisors(i);
        auto firstAbundance = abundantHelper::getAbundance(firstDivisors);
        for(unsigned int j=i+1; j<limit; j++)
        {
            auto secondDivisors = abundantHelper::getDivisors(j);
            auto secondAbundance = abundantHelper::getAbundance(secondDivisors);

            if (firstAbundance == j && secondAbundance == i)
            {
                if (amicableNumberCount > 0)
                    cout << ", ";
                cout << "(" << i <<  ", " << j << ")";
                amicableNumberCount++;
            }   
        }
    }

    cout << endl;
    cout << "Press any key to continue... " << endl;
    getch();
    return 0;
}
