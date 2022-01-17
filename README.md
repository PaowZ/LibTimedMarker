
# LibTimedMarker

Header-only file allowing timing runtime assessments for C++.

## Use:

START_TIMER(<unit>): Start a time-measured block. <unit> may be TM::nano, TM::micro, TM::milli, TM::sec, TM::min  
LAP(<msg>): Display intermediate timings. <msg> is the displayed message.  
END_TIMER(<msg>): Display last timer and total. <msg> is the displayed message.  

## Example:

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

Output:

Hello World!  
 »   intermediate: 174.81 ms  
 »      Time exec: 171.69 ms  
____________________________  
 »        Total: 346.59 ms  

## Requirements
 - C++17

## TBD
 - Change standard output for variable outputs.
