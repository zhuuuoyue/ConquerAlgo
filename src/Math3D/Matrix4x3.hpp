#pragma once

#include "Vector3d.hpp"

/// <summary>
/// 坐标轴
/// </summary>
enum class Axis
{
    X, Y, Z
};

/// <summary>
/// 变换矩阵
/// </summary>
class Matrix4x3
{
public:

    Matrix4x3();

    /// <summary>
    /// 置为单位矩阵
    /// </summary>
    /// <returns>单位矩阵</returns>
    Matrix4x3& identity();

    /// <summary>
    /// 获取平移向量
    /// </summary>
    /// <returns>平移向量</returns>
    Vector3d translation() const;

    /// <summary>
    /// 平移向量置为零
    /// </summary>
    /// <returns>矩阵</returns>
    Matrix4x3& zeroTranslation();

    /// <summary>
    /// 设置平移向量
    /// </summary>
    /// <param name="v">平移向量</param>
    /// <returns>矩阵</returns>
    Matrix4x3& setTranslation(const Vector3d& v);

    /// <summary>
    /// 将当前矩阵设置为平移矩阵
    /// </summary>
    /// <param name="v">平移向量</param>
    /// <returns>平移矩阵</returns>
    Matrix4x3& setupTranslation(const Vector3d& v);

    /// <summary>
    /// 将当前矩阵设置为旋转矩阵
    /// </summary>
    /// <param name="axis">旋转轴</param>
    /// <param name="angle">旋转角度</param>
    /// <returns>旋转矩阵</returns>
    Matrix4x3& setupRotate(Axis axis, double angle);

    /// <summary>
    /// 将当前矩阵设置为旋转矩阵
    /// </summary>
    /// <param name="axis">旋转轴</param>
    /// <param name="angle">旋转角度</param>
    /// <returns>旋转矩阵</returns>
    Matrix4x3& setupRotate(const Vector3d& axis, double angle);

    /// <summary>
    /// 将当前矩阵设置为缩放矩阵
    /// </summary>
    /// <param name="v">各方向缩放因子</param>
    /// <returns>缩放矩阵</returns>
    Matrix4x3& setupScale(const Vector3d& v);

    /// <summary>
    /// 将当前矩阵设置为缩放矩阵
    /// </summary>
    /// <param name="axis">缩放轴向量</param>
    /// <param name="k">缩放因子</param>
    /// <returns>缩放矩阵</returns>
    Matrix4x3& setupScale(const Vector3d& axis, double k);

    /// <summary>
    /// 将当前矩阵设置为切变矩阵
    /// </summary>
    /// <param name="axis">切变轴</param>
    /// <param name="s"></param>
    /// <param name="t"></param>
    /// <returns>切变矩阵</returns>
    Matrix4x3& setupShear(Axis axis, double s, double t);

    /// <summary>
    /// 将当前矩阵设置为投影矩阵
    /// </summary>
    /// <param name="n">过原点投影面的法向量</param>
    /// <returns>投影矩阵</returns>
    Matrix4x3& setupProject(const Vector3d& n);

    /// <summary>
    /// 将当前矩阵设置为镜像矩阵
    /// </summary>
    /// <param name="axis">平面垂直的轴</param>
    /// <param name="k">平面位置</param>
    /// <returns>镜像矩阵</returns>
    Matrix4x3& setupMirror(Axis axis, double k);

    /// <summary>
    /// 将当前矩阵设置为镜像矩阵
    /// </summary>
    /// <param name="n">过原点平面的法向量</param>
    /// <returns>镜像矩阵</returns>
    Matrix4x3& setupMirror(const Vector3d& n);

public:

    double m11, m12, m13;
    double m21, m22, m23;
    double m31, m32, m33;
    double tx, ty, tz;
};

/// <summary>
/// 向量与矩阵相乘，使用矩阵对点进行变换
/// </summary>
/// <param name="p">待变换的点</param>
/// <param name="m">变换矩阵</param>
/// <returns>变换后的点</returns>
Vector3d operator*(const Vector3d& p, const Matrix4x3& m);

/// <summary>
/// 向量与矩阵相乘，使用矩阵对点进行变换
/// </summary>
/// <param name="p">待变换的点</param>
/// <param name="m">变换矩阵</param>
/// <returns>变换后的点</returns>
Vector3d& operator*=(Vector3d& p, const Matrix4x3& m);

/// <summary>
/// 矩阵乘法
/// </summary>
/// <param name="a">矩阵一</param>
/// <param name="b">矩阵二</param>
/// <returns>矩阵</returns>
Matrix4x3 operator*(const Matrix4x3& a, const Matrix4x3& b);

/// <summary>
/// 矩阵乘法
/// </summary>
/// <param name="a">矩阵一</param>
/// <param name="b">矩阵二</param>
/// <returns>矩阵</returns>
Matrix4x3& operator*=(Matrix4x3& a, const Matrix4x3& b);

/// <summary>
/// 左上 3x3 矩阵行列式
/// </summary>
/// <param name="m">矩阵</param>
/// <returns>行列式值</returns>
double determinant(const Matrix4x3& m);

/// <summary>
/// 求矩阵的逆
/// </summary>
/// <param name="m">待求逆的矩阵</param>
/// <returns>逆矩阵</returns>
Matrix4x3 inverse(const Matrix4x3& m);
