cmake_minimum_required (VERSION 2.8)
project (WebService)

#version number
set (WebService_VERSION_MAJOR 1)
set (WebService_VERSION_MINOR 0)
set(CMAKE_CXX_FLAGS "-fpermissive")

#include the subdirectory containing our libs
add_subdirectory (third-party/jsoncpp)
include_directories(third-party/jsoncpp)

#indicate the entry point for the executable

add_subdirectory (third-party/libwebsockets)
include_directories(third-party/libwebsockets)

add_subdirectory (src)
include_directories(src)

#add_executable (WebService third-party/jsoncpp third-party/libwebsockets src/ main.cc)
add_executable (WebService src/main.cc)

# Indicate which libraries to include during the link process.
target_link_libraries (WebService websocketManager)

install (TARGETS WebService DESTINATION bin)
