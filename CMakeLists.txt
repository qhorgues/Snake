cmake_minimum_required(VERSION 3.20.0)

project(Snake VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

include(${CMAKE_SOURCE_DIR}/cmake/option.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)

set_choice(CMAKE_BUILD_TYPE "Debug;Release;MinSizeRel;RelWithDebInfo" "Debug" "Choose the type of build.")

## If you want to link SFML statically
set(SFML_STATIC_LIBRARIES TRUE)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set_option(SFML_DIR "/path/to/SFML/lib" PATH "Enter path to object SFML path")
    set (SFML_DIR "${SFML_DIR}/cmake/SFML")
endif()

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

set (SOURCES
    src/main.cpp
    src/SFML_Interface.cpp
    src/SFML_roundedRect.cpp
    src/SFML_TextButton.cpp
    src/SFML_Menu.cpp
    src/SFML_MainMenu.cpp
)

set (HEADERS
    include/interface.hpp
    include/GameStatut.hpp
    include/GameMode.hpp
    include/SFML_Interface.hpp
    include/SFML_theme.hpp
    include/SFML_roundedRect.hpp
    include/SFML_TextButton.hpp
    include/SFML_Menu.hpp
    include/SFML_MainMenu.hpp
)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

if (MINGW)
    set (CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
endif (MINGW)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows" AND ${CMAKE_BUILD_TYPE} MATCHES "Release")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
endif()

add_executable(Snake ${SOURCES} ${HEADERS})
target_link_libraries(Snake sfml-graphics)

set_target_warnings(Snake)

install(TARGETS Snake DESTINATION .)
install(DIRECTORY assets/ DESTINATION assets)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
