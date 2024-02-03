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

target_link_libraries(utils_test
  PRIVATE
  GTest::GTest
  utils
  )
  
add_test(utils_gtests utils_test)

