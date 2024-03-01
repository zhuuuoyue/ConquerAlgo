#include "gtest/gtest.h"
#include "Vector3d.hpp"
#include "Matrix4x3.hpp"
#include "Constants.hpp"
#include "DoubleComp.hpp"

TEST(Matrix4x3Test, Translation)
{
    Vector3d s{ 1, 2, 3 };
    Matrix4x3 m;
    m.identity().setTranslation(Vector3d{ 1, 2, 3 });
    Vector3d d = s * m;
    EXPECT_DOUBLE_EQ(d.x, 2);
    EXPECT_DOUBLE_EQ(d.y, 4);
    EXPECT_DOUBLE_EQ(d.z, 6);
}

TEST(Matrix4x3Test, Translation2)
{
    Vector3d s{ 1, 2, 3 };
    Matrix4x3 m;
    m.identity().setTranslation(Vector3d{ 1, 2, 3 });
    s *= m;
    EXPECT_DOUBLE_EQ(s.x, 2);
    EXPECT_DOUBLE_EQ(s.y, 4);
    EXPECT_DOUBLE_EQ(s.z, 6);
}

TEST(Matrix4x3Test, RotateX)
{
    Vector3d s{ 1, 1, 1 };
    Matrix4x3 m;
    m.identity().setupRotate(Axis::X, _PI_2);
    Vector3d d = s * m;
    EXPECT_DOUBLE_EQ(d.x, 1);
    EXPECT_DOUBLE_EQ(d.y, -1);
    EXPECT_DOUBLE_EQ(d.z, 1);
}

TEST(Matrix4x3Test, RotateY)
{
    Vector3d s{ 1, 1, 1 };
    Matrix4x3 m;
    m.identity().setupRotate(Axis::Y, _PI_2);
    Vector3d d = s * m;
    EXPECT_DOUBLE_EQ(d.x, 1);
    EXPECT_DOUBLE_EQ(d.y, 1);
    EXPECT_DOUBLE_EQ(d.z, -1);
}

TEST(Matrix4x3Test, RotateZ)
{
    Vector3d s{ 1, 1, 1 };
    Matrix4x3 m;
    m.identity().setupRotate(Axis::Z, _PI_2);
    Vector3d d = s * m;
    EXPECT_DOUBLE_EQ(d.x, -1);
    EXPECT_DOUBLE_EQ(d.y, 1);
    EXPECT_DOUBLE_EQ(d.z, 1);
}

TEST(Matrix4x3Test, Rotate)
{
    Vector3d ax{ 1, 1, 1 };
    ax.normalize();
    Vector3d s{ 1, 0, 0 };
    Matrix4x3 m;
    m.identity().setupRotate(ax, _2_PI / 3.0);
    Vector3d d = s * m;
    DoubleEq de;
    EXPECT_TRUE(de(d.x, 0));
    EXPECT_TRUE(de(d.y, 1));
    EXPECT_TRUE(de(d.z, 0));
}

TEST(Matrix4x3Test, Scale)
{
    Vector3d s{ 1, 2, 3 };
    Matrix4x3 m;
    m.setupScale(Vector3d{ 1, 2, 3 });
    Vector3d d = s * m;
    DoubleEq de;
    EXPECT_TRUE(de(d.x, 1));
    EXPECT_TRUE(de(d.y, 4));
    EXPECT_TRUE(de(d.z, 9));
}

TEST(Matrix4x3Test, Scale2)
{
    Vector3d axis{ 1, 1, 1 };
    axis.normalize();
    Vector3d s{ 1, 1, 1 };
    Matrix4x3 m;
    m.identity().setupScale(axis, 3);
    Vector3d d = s * m;
    DoubleEq de;
    EXPECT_TRUE(de(d.x, 3));
    EXPECT_TRUE(de(d.y, 3));
    EXPECT_TRUE(de(d.z, 3));
}

TEST(Matrix4x3Test, Shear)
{
    Vector3d s{ 1, 1, 1 };
    Matrix4x3 m;
    m.identity().setupShear(Axis::X, 3, 5);
    Vector3d d = s * m;
    DoubleEq de;
    EXPECT_TRUE(de(d.x, 1));
    EXPECT_TRUE(de(d.y, 4));
    EXPECT_TRUE(de(d.z, 6));
}

TEST(Matrix4x3Test, Project)
{
    Vector3d s{ 1, 1, 1 };
    Vector3d n{ 0, 0, 1 };
    Matrix4x3 m;
    m.identity().setupProject(n);
    Vector3d d = s * m;
    DoubleEq de;
    EXPECT_TRUE(de(d.x, 1));
    EXPECT_TRUE(de(d.y, 1));
    EXPECT_TRUE(de(d.z, 0));
}

TEST(Matrix4x3Test, Mirror)
{
    Vector3d s{ 1, 1, 1 };
    Matrix4x3 m;
    m.setupMirror(Axis::X, 10);
    Vector3d d = s * m;
    DoubleEq de;
    EXPECT_TRUE(de(d.x, 19));
    EXPECT_TRUE(de(d.y, 1));
    EXPECT_TRUE(de(d.z, 1));
}

TEST(Matrix4x3Test, Mirror2)
{
    Vector3d s{ 1, 0, 0 };
    Vector3d n{ -1, 1, 0 };
    n.normalize();
    Matrix4x3 m;
    m.setupMirror(n);
    Vector3d d = s * m;
    DoubleEq de;
    EXPECT_TRUE(de(d.x, 0));
    EXPECT_TRUE(de(d.y, 1));
    EXPECT_TRUE(de(d.z, 0));
}

TEST(Matrix4x3Test, Product)
{
    Matrix4x3 a;
    a.m11 = 1;   a.m12 = -5;   a.m13 = 3;
    a.m21 = 0;   a.m22 = -2;   a.m23 = 6;
    a.m31 = 7;   a.m32 = 2;    a.m33 = -4;
    a.tx = 1;    a.ty = 2;     a.tz = 3;

    Matrix4x3 b;
    b.m11 = -8;  b.m12 = 6;    b.m13 = 1;
    b.m21 = 7;   b.m22 = 0;    b.m23 = -3;
    b.m31 = 2;   b.m32 = 4;    b.m33 = 5;
    b.tx = 1;    b.ty = 2;     b.tz = 3;

    Matrix4x3 c = a * b;
    DoubleEq de;

    EXPECT_TRUE(de(c.m11, -37));
    EXPECT_TRUE(de(c.m12, 18));
    EXPECT_TRUE(de(c.m13, 31));

    EXPECT_TRUE(de(c.m21, -2));
    EXPECT_TRUE(de(c.m22, 24));
    EXPECT_TRUE(de(c.m23, 36));

    EXPECT_TRUE(de(c.m31, -50));
    EXPECT_TRUE(de(c.m32, 26));
    EXPECT_TRUE(de(c.m33, -19));

    EXPECT_TRUE(de(c.tx, 13));
    EXPECT_TRUE(de(c.ty, 20));
    EXPECT_TRUE(de(c.tz, 13));
}

TEST(Matrix4x3Test, Determinant)
{
    Matrix4x3 m;
    m.m11 = 3; m.m12 = -2; m.m13 = 0;
    m.m21 = 1; m.m22 = 4; m.m23 = -3;
    m.m31 = -1; m.m32 = 0; m.m33 = 2;
    double det = determinant(m);
    EXPECT_DOUBLE_EQ(det, 22);
}

TEST(Matrix4x3Test, Inverse)
{
    Matrix4x3 m;
    m.m11 = -4; m.m12 = -3; m.m13 = 3;
    m.m21 = 0; m.m22 = 2; m.m23 = -2;
    m.m31 = 1; m.m32 = 4; m.m33 =-1;

    Matrix4x3 i = inverse(m);
    DoubleEq de;

    EXPECT_TRUE(de(i.m11, -1.0 / 4.0));
    EXPECT_TRUE(de(i.m12, -3.0 / 8.0));
    EXPECT_TRUE(de(i.m13, 0));

    EXPECT_TRUE(de(i.m21, 1.0 / 12.0));
    EXPECT_TRUE(de(i.m22, -1.0 / 24.0));
    EXPECT_TRUE(de(i.m23, 1.0 / 3.0));

    EXPECT_TRUE(de(i.m31, 1.0 / 12.0));
    EXPECT_TRUE(de(i.m32, -13.0 / 24.0));
    EXPECT_TRUE(de(i.m33, 1.0 / 3.0));

    EXPECT_TRUE(de(i.tx, 0));
    EXPECT_TRUE(de(i.ty, 0));
    EXPECT_TRUE(de(i.tz, 0));
}
