#include "..\include\abundant.h"
#include <algorithm>

using namespace std;

unsigned int abundantHelper::getAbundance(unsigned int p_number)
{
    unsigned int retVal {0};
    if (p_number==1)
        retVal = 1;
    else
    {
        for(unsigned int i=1;i<=sqrt(p_number);i++)
        {
            if (p_number % i == 0)
            {
                retVal+=i;
                if (p_number/i != i && i != 1)
                    retVal+=(p_number/i);
            }
        }
    }
    return retVal;
}