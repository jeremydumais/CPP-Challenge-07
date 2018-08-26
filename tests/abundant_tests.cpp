#include <gtest/gtest.h>
#include "../include/abundant.h"

using namespace std;

int main(int argc, char**argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(getAbundance, Number1_Return1)
{
    ASSERT_EQ(abundantHelper::getAbundance(1), 1);
}

TEST(getAbundance, Number4_Return3)
{
    ASSERT_EQ(abundantHelper::getAbundance(4), 3);
}

TEST(getAbundance, Number10_Return8)
{
    ASSERT_EQ(abundantHelper::getAbundance(10), 8);
}

TEST(getAbundance, Number12_Return16)
{
    ASSERT_EQ(abundantHelper::getAbundance(12), 16);
}

TEST(getAbundance, Number220_Return284)
{
    ASSERT_EQ(abundantHelper::getAbundance(220), 284);
}

TEST(getAbundance, Number284_Return220)
{
    ASSERT_EQ(abundantHelper::getAbundance(284), 220);
}