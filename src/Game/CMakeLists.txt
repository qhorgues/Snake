cmake_minimum_required(VERSION 3.20.0)

project(Game VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

include(${CMAKE_SOURCE_DIR}/cmake/option.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)

set_choice(CMAKE_BUILD_TYPE "Debug;Release;MinSizeRel;RelWithDebInfo" "Debug" "Choose the type of build.")

set (SOURCES
)

set (HEADERS
    Event/Event.hpp
    Mode/Mode.hpp
    Statut/Statut.hpp
)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

if (MINGW)
    set (CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
    
    if (${CMAKE_BUILD_TYPE} MATCHES "Debug" OR ${CMAKE_BUILD_TYPE} MATCHES "RelWithDebInfo")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
    endif()
endif (MINGW)

add_library(${PROJECT_NAME} INTERFACE ${SOURCES} ${HEADERS})

#set_target_warnings(${PROJECT_NAME})
