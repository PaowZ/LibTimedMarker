
#ifndef TIME_MARKER_H
#define TIME_MARKER_H

#include <chrono>
#include <iostream>
#include <type_traits>
#include <cstring>

namespace TM {

#if __cplusplus < 201103 || (defined(_MSVC_LANG) && _MSVC_LANG < 201103L)
    #error "Need std::string_view feature compiler"
#endif


    using min = std::ratio<3600>;
    using sec = std::ratio<60>;
    using milli = std::milli;
    using micro = std::micro;
    using nano = std::nano;

#define START_TIMER(t_unit)                                 \
  {                                                         \
    using namespace std::chrono;                            \
    using unit = t_unit ;                                   \
    static_assert(std::is_same_v<unit, TM::min>             \
                    || std::is_same_v<unit, TM::sec>        \
                    || std::is_same_v<unit, TM::milli>      \
                    || std::is_same_v<unit, TM::micro>      \
                    || std::is_same_v<unit, TM::nano>       , "wrong unit");\
    auto start = std::chrono::high_resolution_clock::now();

#define END_TIMER(msg)                                          \
    duration<double, unit> time                                 \
        = std::chrono::high_resolution_clock::now() - start;    \
    char cUnit[5]{0};                                           \
    if constexpr(std::is_same_v<unit, TM::min>)     std::strcpy(cUnit, "min");  \
    if constexpr(std::is_same_v<unit, TM::sec>)     std::strcpy(cUnit, "s");    \
    if constexpr(std::is_same_v<unit, TM::milli>)   std::strcpy(cUnit, "ms");   \
    if constexpr(std::is_same_v<unit, TM::micro>)   std::strcpy(cUnit, "us");   \
    if constexpr(std::is_same_v<unit, TM::nano>)    std::strcpy(cUnit, "nano"); \
    std::cout << msg << " " << time.count() << " " << cUnit << endl; \
  }

#define MAX_LEN 128

struct Message{
    const char arrMsg[MAX_LEN]{0};
};

}   // end of namespace
#endif


