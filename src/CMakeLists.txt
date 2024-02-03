
include_directories(include)
file(GLOB SOURCES "*.c")
add_library(utils utils.c)
add_library(map map.c)
add_library(color color.c)
add_library(wireworld ${SOURCES})
#target_include_directories(wireworld PUBLIC include)
#add_executable(wireworld ${SOURCES})
