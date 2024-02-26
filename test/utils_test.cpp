extern "C" 
{
    #include <utils.h>
}
#include <gtest/gtest.h>

TEST(UtilsTests, random_between_OneOne)
{
    const auto expected = 1;
    const auto actual = random_between(1, 1);
    ASSERT_EQ(expected, actual);
}

TEST(UtilsTests, random_between_ZeroZero)
{
    const auto expected = 0;
    const auto actual = random_between(0,0);
    ASSERT_EQ(expected, actual);
}

TEST(UtilsTests, random_between_0_max){
    const int max_runs = 1000;
    for(int max = 0; max < max_runs; max++)
    {
        int rnd_value = random_between(0, max);
        EXPECT_LE(0,  rnd_value);
        EXPECT_LE(rnd_value, max);
    }
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}