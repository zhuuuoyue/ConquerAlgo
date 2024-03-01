#include "gtest/gtest.h"
#include "RotationMatrix.hpp"
#include "EulerAngles.hpp"
#include "Constants.hpp"
#include "Vector3d.hpp"
#include "RotationMatrixUtils.hpp"

TEST(RotationMatrixTest, FromEulerAngles)
{
    EulerAngles ea{ -_PI, 0, 0 };
    RotationMatrix m;
    m.fromEulerAngles(ea);
    Vector3d s{ 1, 1, 1 };
    Vector3d d = implementRotationFromInertialToObject(m, s);
    //EXPECT_DOUBLE_EQ(d.x, -1);
    //EXPECT_DOUBLE_EQ(d.y, 1);
    //EXPECT_DOUBLE_EQ(d.z, 1);
}
