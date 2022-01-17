#include <iostream>

#include "TimedMarker.hpp"

using namespace std;

int main()
{

    START_TIMER(TM::milli)
    cout << "Hello World!" << endl;

    for(int i=0,j=0;i<100000000;++i)
        j++;

    END_TIMER("Time exec:")
    return 0;
}

