extern "C" 
{
    #include <map.h>
}
#include <gtest/gtest.h>
#include <string>



TEST(MapTests, read_map_not_exist)
{
    const std::string map_fname  = "test_maps/404.txt";
    char** map = NULL;
    int height = 0;
    int width = 0;

    const int expected = -1;
    const 
    int actual = read_map(&map, &height,  &width, map_fname.c_str());
    ASSERT_EQ(expected, actual);
}

TEST(MapTests, read_map_zero_size_map)
{
    const std::string map_fname  = "test_maps/map_zero_size.txt";
    char** map = NULL;
    int height = 0;
    int width = 0;

    const int expected = -1;
    const int actual = read_map(&map, &height,  &width, map_fname.c_str());
    ASSERT_EQ(expected, actual);
}

TEST(MapTests, read_map_3x3_empty)
{
    const std::string map_fname  = "test_maps/map_3x3_empty.txt";
    
    int height = 0;
    int width = 0;
    char** actual = NULL;
    const char expected[3][3] = {
        '0','0','0',
        '0','0','0',
        '0','0','0'
        };
    const int read_success = read_map(&actual, &height,  &width, map_fname.c_str());
    ASSERT_EQ(read_success, 0);
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < height; j++)
        {
            ASSERT_EQ(expected[i][j], actual[i][j]);
        }
    }
}

TEST(MapTests, read_map_5x5_square)
{
    const std::string map_fname  = "test_maps/map_5x5_square.txt";
    
    int height = 0;
    int width = 0;
    char** actual = NULL;
    const char expected[5][5] = {
        '3','2','1','4','4',
        '4','0','0','0','4',
        '4','0','0','0','4',
        '4','0','0','0','4',
        '4','4','4','4','4'
        };
    const int read_success = read_map(&actual, &height,  &width, map_fname.c_str());
    ASSERT_EQ(read_success, 0) << "read_map result";
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < height; j++)
        {
            ASSERT_EQ(expected[i][j], actual[i][j]) << "str:" << i << "col:" << j;
        }
    }
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}