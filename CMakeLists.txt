# CMake options
cmake_minimum_required (VERSION 2.8.5)

# Project simple.websocket
project(SW)

set(PROJECT_VERSION_MAJOR "0")
set(PROJECT_VERSION_MINOR "1")
set(PROJECT_VERSION_PATCH "0")
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
SET(PROJECT_SOVERSION "1")

option(DETECT_RPATH	"Auto detect rpath" OFF)
option(BUILD_EXAMPLES "Build with examples" OFF) # not implemented

# Global requirements
find_package(Boost 1.55.0 REQUIRED)
if(${Boost_FOUND})
    message(STATUS "Boost found. Include: ${Boost_INCLUDE_DIRS} Libraries: ${Boost_LIBRARY_DIRS}")
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
else()
    message(FATAL_ERROR "Boost not found")
endif()

find_package(OpenSSL)

include (CheckCXXCompilerFlag)

if(NOT CMAKE_COMPILER_IS_GNUCXX)
    message(WARNING "C++ compilers isn't GNU")
endif()

CHECK_CXX_COMPILER_FLAG("-std=c++11" HAS_CXX_FLAGS)
if(NOT HAS_CXX_FLAGS)
    message(FATAL_ERROR "C++ compiler doesn't support C++11 standard")
endif()

# Install
install(CODE "MESSAGE(\"Installing simple.websocket library.\")")
file(GLOB headers RELATIVE ${CMAKE_SOURCE_DIR} "*.hpp")
install(FILES ${headers} DESTINATION include/simple.websocket/)

# Uninstall
add_custom_target(uninstall
    ${CMAKE_COMMAND} -E remove_directory ${CMAKE_INSTALL_PREFIX}/include/simple.websocket
)
