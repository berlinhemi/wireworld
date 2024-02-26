#include(FetchContent)

#FetchContent_Declare(
#  googletest
#  GIT_REPOSITORY https://github.com/google/googletest.git
#  GIT_TAG        release-1.11.0
#)
#FetchContent_MakeAvailable(googletest)
#add_library(GTest::GTest INTERFACE IMPORTED)
#target_link_libraries(GTest::GTest INTERFACE gtest_main)


#add_executable(test_defaults tests/test_defaults.cpp)
#target_include_directories(test_defaults PUBLIC ${CMAKE_SOURCE_DIR})
#target_link_libraries(test_defaults gtest gtest_main ${PROJECT_NAME})
#add_test(NAME test_defaults COMMAND test_defaults)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


#include_directories(../third-party/googletest/googletest/include)
# gtest_build_include_dirs - var from googletest CMakeLists
include_directories(${gtest_build_include_dirs})
include_directories(../src/include)
add_executable(utils_test utils_test.cpp)
add_executable(map_test map_test.cpp)

#target_link_libraries(utils_test PRIVATE GTest::GTest utils)
target_link_libraries(utils_test gtest gtest_main utils)

#target_link_libraries(map_test PRIVATE GTest::GTest map color)
target_link_libraries(map_test gtest gtest_main map color)

add_test(NAME utils_gtests 
        COMMAND utils_test
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )

add_test( NAME  map_gtests
         COMMAND  map_test
         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
       ) 

message(CMAKE_CURRENT_SOURCE_DIR="${CMAKE_SOURCE_DIR}")
