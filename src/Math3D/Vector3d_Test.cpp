#include "gtest/gtest.h"
#include "Vector3d.hpp"

TEST(Vector3dTest, CopyConstructor) {
    Vector3d v1{ 1, 2, 3 };
    Vector3d v2{ v1 };
    EXPECT_DOUBLE_EQ(v2.x, 1);
    EXPECT_DOUBLE_EQ(v2.y, 2);
    EXPECT_DOUBLE_EQ(v2.z, 3);
}

TEST(Vector3dTest, Length) {
    Vector3d v{ 3, 0 ,4 };
    double len = v.length();
    EXPECT_DOUBLE_EQ(len, 5);
}

TEST(Vector3dTest, DotProduct) {
    Vector3d v1{ 3, -2, 7 };
    Vector3d v2{ 0, 4, -1 };
    double dot = v1 * v2;
    EXPECT_DOUBLE_EQ(dot, -15);
}

TEST(Vector3dTest, CrossProduct) {
    Vector3d v1{ 1, 3, 4 };
    Vector3d v2{ 2, -5, 8 };
    Vector3d prod = crossProduct(v1, v2);
    EXPECT_DOUBLE_EQ(prod.x, 44);
    EXPECT_DOUBLE_EQ(prod.y, 0);
    EXPECT_DOUBLE_EQ(prod.z, -11);
}
