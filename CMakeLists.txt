cmake_minimum_required (VERSION 3.1)
project (processorproject)

find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC -g")
if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive -D_GLIBCXX_USE_SCHED_YIELD -D_GLIBCXX_USE_NANOSLEEP")
endif()

file(GLOB SOURCES
${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

include_directories (
${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(imageprocessor
SHARED
${SOURCES}
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
