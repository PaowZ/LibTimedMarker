#include <iostream>

#include "TimedMarker.hpp"

int main()
{

    START_TIMER(TM::milli)
    std::cout << "Hello World!"
              << std::endl;

    for(int i=0,j=0;i<100000000;++i)
        j++;

    LAP("intermediate")

    for(int i=0,j=0;i<100000000;++i)
        j++;

    END_TIMER("Time exec")
    return 0;
}

