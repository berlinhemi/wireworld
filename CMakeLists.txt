cmake_minimum_required(VERSION 3.21.0)
project(wireworld)

enable_testing()

add_subdirectory(src)

add_subdirectory(tests)

#include_directories(src/include)
#file(GLOB SOURCES "src/*.c")
#add_executable(wireworld ${SOURCES})
