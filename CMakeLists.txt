cmake_minimum_required(VERSION 3.20.0)

project(Snake VERSION 0.1.0)

include(${CMAKE_SOURCE_DIR}/cmake/option.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)

set_choice(CMAKE_BUILD_TYPE "Debug;Release;MinSizeRel;RelWithDebInfo" "Debug" "Choose the type of build.")

set (SOURCES
    src/main.cpp
)

set (HEADERS
    include/interface.hpp
    include/GameStatut.hpp
    include/GameMode.hpp
)

set (CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(Snake ${SOURCES} ${HEADERS})
add_subdirectory(${CMAKE_SOURCE_DIR}/src/interfaceSFML)

set_target_warnings(Snake)