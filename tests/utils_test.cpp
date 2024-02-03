extern "C" {
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

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}