cmake_minimum_required(VERSION 3.20.0)

project(Snake VERSION 0.1.0)

macro(snake_set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

snake_set_option(CMAKE_BUILD_TYPE Debug STRING "Choose the type of build (Debug or Release)")


set (SOURCES
    src/main.cpp
)

set (HEADERS
)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(Snake ${SOURCES} ${HEADERS})

set_target_warnings(Snake)