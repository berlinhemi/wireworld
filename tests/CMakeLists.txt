include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)



include_directories(../src/include)
add_executable(utils_test utils_test.cpp)
add_executable(map_test map_test.cpp)

target_link_libraries(utils_test PRIVATE GTest::GTest utils)

target_link_libraries(map_test PRIVATE GTest::GTest map color)

add_test(NAME utils_gtests 
        COMMAND utils_test
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )

add_test( NAME  map_gtests
         COMMAND  map_test
         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
       ) 

message(CMAKE_CURRENT_SOURCE_DIR="${CMAKE_SOURCE_DIR}")
