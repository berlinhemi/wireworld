
include_directories(include)
file(GLOB SOURCES "*.c")
add_library(utils utils.c)
add_library(wireworld ${SOURCES})
#add_executable(wireworld ${SOURCES})
