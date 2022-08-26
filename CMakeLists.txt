cmake_minimum_required(VERSION 3.20.0)

project(Snake VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

include(${CMAKE_SOURCE_DIR}/cmake/option.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)

set_choice(CMAKE_BUILD_TYPE "Debug;Release;MinSizeRel;RelWithDebInfo" "Debug" "Choose the type of build.")

## If you want to link SFML statically
set(SFML_STATIC_LIBRARIES TRUE)


find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

set (SOURCES
    src/main.cpp
)

set (HEADERS
    src/Interface.hpp
)

set (ASSETS
    assets/arial.ttf
    assets/forest.png
    assets/imprisha.ttf
    assets/sand.png
    assets/Snake.png
)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

if (MINGW)
    set (CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

    if (${CMAKE_BUILD_TYPE} MATCHES "Debug" OR ${CMAKE_BUILD_TYPE} MATCHES "RelWithDebInfo")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
    endif()
endif (MINGW)

add_subdirectory(src/Game)
add_subdirectory(src/SFML)

add_executable(Snake ${SOURCES} ${HEADERS})
target_link_libraries(Snake PRIVATE sfml-system sfml-window sfml-graphics Game SFML_Interface)

target_include_directories(Snake PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/src/Game"
                          "${PROJECT_SOURCE_DIR}/src/SFML_Interface"
                          )

set_target_warnings(Snake)

install(TARGETS Snake DESTINATION .)
install(DIRECTORY assets/ DESTINATION assets)

foreach(df ${ASSETS})
    file(COPY ${df} DESTINATION ${CMAKE_BINARY_DIR}/assets)
endforeach()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
