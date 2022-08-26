cmake_minimum_required(VERSION 3.20.0)

project(SFML_Interface VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

include(${CMAKE_SOURCE_DIR}/cmake/option.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)

set_choice(CMAKE_BUILD_TYPE "Debug;Release;MinSizeRel;RelWithDebInfo" "Debug" "Choose the type of build.")

## If you want to link SFML statically
set(SFML_STATIC_LIBRARIES TRUE)


find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

set (SOURCES
    Interface/Interface.cpp
    RoundedRect/RoundedRect.cpp
    TextButton/TextButton.cpp
    Menu/Menu.cpp
    MainMenu/MainMenu.cpp
)

set (HEADERS
    Interface/Interface.hpp
    Theme/Theme.hpp
    RoundedRect/RoundedRect.hpp
    TextButton/TextButton.hpp
    Menu/Menu.hpp
    MainMenu/MainMenu.hpp
)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

if (MINGW)
    set (CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
    
    if (${CMAKE_BUILD_TYPE} MATCHES "Debug" OR ${CMAKE_BUILD_TYPE} MATCHES "RelWithDebInfo")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
    endif()
endif (MINGW)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics)

set_target_warnings(${PROJECT_NAME})
