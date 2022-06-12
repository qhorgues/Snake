cmake_minimum_required(VERSION 3.20.0)

project(Snake VERSION 0.1.0)

macro(snake_set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

snake_set_option(CMAKE_BUILD_TYPE Debug STRING "Choose the type of build (Debug or Release)")

if (NOT MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -Werror -pedantic -std=c++17")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -Wextra -Werror -pedantic -std=c++17 -DNDEBUG")
else()
    set(CMAKE_CXX_FLAGS_DEBUG "/g /Od /Wall /WX /pedantic /fsanitize=address")
    set(CMAKE_CXX_FLAGS_RELEASE "/O2 /Wall /WX /pedantic /fsanitize=address /DNDEBUG")
endif(NOT MSVC)

set (SOURCES
    src/main.cpp
    src/Snake.cpp
)

# set (HEADERS
#     include/Snake.hpp
# )

include_directories(include)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set (CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

add_executable(Snake ${SOURCES} ${HEADERS})