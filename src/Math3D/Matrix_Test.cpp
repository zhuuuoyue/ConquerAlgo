#include "gtest/gtest.h"
#include "Matrix.hpp"

TEST(MatrixTest, Dimension) {
    Matrix<3, 4> mat;
    EXPECT_EQ(mat.rows(), 3);
    EXPECT_EQ(mat.cols(), 4);
}

TEST(MatrixTest, Transform) {
    Matrix<4, 3> m;
    m(0, 0) = 1;
    m(0, 1) = 2;
    m(0, 2) = 3;
    m(1, 0) = 4;
    m(1, 1) = 5;
    m(1, 2) = 6;
    m(2, 0) = 7;
    m(2, 1) = 8;
    m(2, 2) = 9;
    m(3, 0) = 10;
    m(3, 1) = 11;
    m(3, 2) = 12;
    Matrix<3, 4> t = m.transform();
    EXPECT_DOUBLE_EQ(t(0, 0), 1);
    EXPECT_DOUBLE_EQ(t(0, 1), 4);
    EXPECT_DOUBLE_EQ(t(0, 2), 7);
    EXPECT_DOUBLE_EQ(t(0, 3), 10);
    EXPECT_DOUBLE_EQ(t(1, 0), 2);
    EXPECT_DOUBLE_EQ(t(1, 1), 5);
    EXPECT_DOUBLE_EQ(t(1, 2), 8);
    EXPECT_DOUBLE_EQ(t(1, 3), 11);
    EXPECT_DOUBLE_EQ(t(2, 0), 3);
    EXPECT_DOUBLE_EQ(t(2, 1), 6);
    EXPECT_DOUBLE_EQ(t(2, 2), 9);
    EXPECT_DOUBLE_EQ(t(2, 3), 12);
}

TEST(MatrixTest, Times) {
    Matrix<2, 2> a;
    a(0, 0) = -3;
    a(0, 1) = 0;
    a(1, 0) = 5;
    a(1, 1) = 0.5;

    Matrix<2, 2> b;
    b(0, 0) = -7;
    b(0, 1) = 2;
    b(1, 0) = 4;
    b(1, 1) = 6;

    Matrix<2, 2> ab = a * b;
    EXPECT_DOUBLE_EQ(ab(0, 0), 21);
    EXPECT_DOUBLE_EQ(ab(0, 1), -6);
    EXPECT_DOUBLE_EQ(ab(1, 0), -33);
    EXPECT_DOUBLE_EQ(ab(1, 1), 13);
}
