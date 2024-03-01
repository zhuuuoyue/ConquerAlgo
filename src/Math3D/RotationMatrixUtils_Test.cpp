#include "gtest/gtest.h"
#include "Vector3d.hpp"
#include "RotationMatrix.hpp"
#include "RotationMatrixUtils.hpp"

TEST(RotationMatrixTest, InertialToObject)
{
    RotationMatrix m;
    m.m11 = 0; m.m12 = 1; m.m13 = 0;
    m.m21 = -1; m.m22 = 0; m.m23 = 0;
    m.m31 = 0; m.m32 = 0; m.m33 = 1;

    Vector3d s{ 1, 1, 1 };
    Vector3d d = implementRotationFromInertialToObject(m, s);
    EXPECT_DOUBLE_EQ(d.x, -1);
    EXPECT_DOUBLE_EQ(d.y, 1);
    EXPECT_DOUBLE_EQ(d.z, 1);
}
