#include "gtest/gtest.h"
#include "MathUtils.hpp"
#include "Constants.hpp"

TEST(MathUtilsTest, Wrap_1)
{
    double wrapped = wrap(_2_PI);
    EXPECT_DOUBLE_EQ(wrapped, 0);
}

TEST(MathUtilsTest, Wrap_2)
{
    double wrapped = wrap(3 * _PI);
    EXPECT_DOUBLE_EQ(wrapped, -_PI);
}

TEST(MathUtilsTest, Wrap_3)
{
    double wrapped = wrap(-3 * _PI);
    EXPECT_DOUBLE_EQ(wrapped, -_PI);
}

TEST(MathUtilsTest, ACOSS_1)
{
    double angle = acos_s(1);
    EXPECT_DOUBLE_EQ(angle, 0);
}

TEST(MathUtilsTest, ACOSS_2)
{
    double angle = acos_s(0);
    EXPECT_DOUBLE_EQ(angle, _PI_2);
}

TEST(MathUtilsTest, ACOSS_3)
{
    double angle = acos_s(-1);
    EXPECT_DOUBLE_EQ(angle, _PI);
}

TEST(MathUtilsTest, ACOSS_4)
{
    double angle = acos_s(2);
    EXPECT_DOUBLE_EQ(angle, 0);
}

TEST(MathUtilsTest, ACOSS_5)
{
    double angle = acos_s(-2);
    EXPECT_DOUBLE_EQ(angle, _PI);
}
