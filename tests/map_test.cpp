extern "C" {
    #include <map.h>
}
#include <gtest/gtest.h>
#include <string>



// TEST(UtilsTests, random_between_ZeroZero)
// {
//     const auto expected = 0;
//     const auto actual = random_between(0,0);
//     ASSERT_EQ(expected, actual);
// }

// TEST(UtilsTests, random_between_0_max){
//     const int max_runs = 1000;
//     for(int max = 0; max < max_runs; max++)
//     {
//         int rnd_value = random_between(0, max);
//         EXPECT_LE(0,  rnd_value);
//         EXPECT_LE(rnd_value, max);
//     }
// }


TEST(MapTests, read_map_NotExistsMap)
{
    const std::string map_fname  = "404.txt";
    char** map = NULL;
    int height = 0;
    int width = 0;

    const int expected = -1;
    const int actual = read_map(&map, &height,  &width, map_fname.c_str());
    ASSERT_EQ(expected, actual);
}

TEST(MapTests, read_map_EmptyMap)
{
    const std::string map_fname  = "empty_map.txt";
    char** map = NULL;
    int height = 0;
    int width = 0;

    const int expected = -1;
    const int actual = read_map(&map, &height,  &width, map_fname.c_str());
    ASSERT_EQ(expected, actual);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}