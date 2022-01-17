cmake_minimum_required(VERSION 3.5)

set(NAME_APP "LibTimedMarker")

project(${NAME_APP} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif(CCACHE_FOUND)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    message("        ########## Go for Debug build ##########")
    add_compile_definitions(TM_DEBUG)
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif ()

if(CMAKE_BUILD_TYPE MATCHES Release)
    message("        ########## Go for Release build ##########")
    add_compile_options(-Ofast)
endif ()

include_directories(
        src
        lib
        )

file(GLOB_RECURSE NAME_SRC
    src/*.cpp
    lib/*.hpp
    )


add_executable(${NAME_APP} ${NAME_SRC})
