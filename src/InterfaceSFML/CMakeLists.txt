cmake_minimum_required(VERSION 3.20.0)

project(interfaceSFML VERSION 0.1)

include(${CMAKE_SOURCE_DIR}/cmake/option.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)

# include (${CMAKE_SOURCE_DIR}/cmake/SFMLConfig.cmake)
# find_package(SFML 2 REQUIRED system window graphics)
# if (SFML_FOUND)
#     include_directories(${SFML_INCLUDE_DIR})
#     target_link_libraries(${SFML_LIBRAIRIES})
# else ()
#     set_option(SFML_INCLUDE_DIR include PATH "enter path of SFML headers")
#     set_option(SFML_LIBRAIRIES lib PATH "enter path of SFML binary")
#     include_directories(${SFML_INCLUDE_DIR})
#     target_link_libraries(${SFML_LIBRAIRIES})
# endif ()



set(SRCS
src/interfaceSFML.cpp
)

set(HEADERS
include/InterfaceSFML.hpp
)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(interfaceSFML)
set_target_warnings(interfaceSFML)

INCLUDE(lib/cmake/SFML/SFMLConfig.cmake)
IF(NOT SFML_FOUND)
    FIND_LIBRARY(SFML_LIBRARIES REQUIRED system window graphics)
ENDIF(NOT SFML_FOUND)
INCLUDE_DIRECTORIES(${FREETYPE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(interfaceSFML ${FREETYPE_LIBRARIES})