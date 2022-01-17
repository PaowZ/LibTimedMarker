
#ifndef TIME_MARKER_H
#define TIME_MARKER_H

#include <chrono>
#include <iostream>
#include <iomanip>
#include <type_traits>
#include <cstring>

namespace TM {

#if __cplusplus < 201703 || (defined(_MSVC_LANG) && _MSVC_LANG < 201703L)
    #error "Need C++17 compiler at least !"
#endif

constexpr const int padding{15};
constexpr const int precision{2};

using min   = std::ratio<3600>;
using sec   = std::ratio<60>;
using milli = std::milli;
using micro = std::micro;
using nano  = std::nano;

#define START_TIMER(unit)                                   \
  using t_unit = unit ;                                     \
  using namespace std::chrono;                              \
  auto start_total = std::chrono::high_resolution_clock::now(); \
  {                                                         \
    static_assert(std::is_same_v<t_unit, TM::min>             \
                    || std::is_same_v<t_unit, TM::sec>        \
                    || std::is_same_v<t_unit, TM::milli>      \
                    || std::is_same_v<t_unit, TM::micro>      \
                    || std::is_same_v<t_unit, TM::nano>       , "wrong unit");\
    auto start = start_total;

#define LAP(msg)                                                        \
    duration<double, t_unit> time_block                                 \
        = std::chrono::high_resolution_clock::now() - start;            \
    std::cout << std::setw(3) << "»"                                    \
        << std::setw(TM::padding) << msg << ": "                        \
        << std::setprecision(TM::precision)                             \
        << std::fixed << time_block.count()                             \
        << " " << TM::GetUnitExt<t_unit>() << std::endl;                \
    }                                                                   \
    {                                                                   \
    auto start = std::chrono::high_resolution_clock::now();


#define END_TIMER(msg)                                                  \
    auto end = std::chrono::high_resolution_clock::now();               \
    duration<double, t_unit> time_block = end - start;                  \
    duration<double, t_unit> time_total = end - start_total;            \
    std::cout << std::setw(3) << "»"                                    \
        << std::setw(TM::padding) << msg << ": "                        \
        << std::setprecision(TM::precision)                             \
        << std::fixed << time_block.count()                             \
        << " " << TM::GetUnitExt<t_unit>() << std::endl;                \
    std::cout << "----------------------------" << std::endl            \
        << std::setw(3) << "»" << std::setw(TM::padding) << "Total: "   \
        << std::setprecision(TM::precision)                             \
        << std::fixed << time_total.count()                             \
        << " " << TM::GetUnitExt<t_unit>() << std::endl;                \
    }

template<typename T>
inline constexpr const char* GetUnitExt(){
    if constexpr(std::is_same_v<T, TM::min>)     return "min";
    if constexpr(std::is_same_v<T, TM::sec>)     return "s";
    if constexpr(std::is_same_v<T, TM::milli>)   return "ms";
    if constexpr(std::is_same_v<T, TM::micro>)   return "µs";
    if constexpr(std::is_same_v<T, TM::nano>)    return "nano";
    return "";
}

}   // end of namespace
#endif


