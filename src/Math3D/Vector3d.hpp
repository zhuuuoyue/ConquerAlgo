#pragma once

class Vector3d
{
public:
    double x;
    double y;
    double z;

    Vector3d();
    explicit Vector3d(double _x, double _y, double _z);
    Vector3d(const Vector3d& other);
    Vector3d(Vector3d&& other) noexcept;

    Vector3d& operator=(const Vector3d& other);
    Vector3d& operator=(Vector3d&& other) noexcept;

    bool operator==(const Vector3d& other) const;
    bool operator!=(const Vector3d& other) const;

    Vector3d operator-() const;
    Vector3d operator+() const;

    Vector3d operator+(const Vector3d& other) const;
    Vector3d operator-(const Vector3d& other) const;
    Vector3d operator*(double a) const;
    Vector3d operator/(double a) const;

    Vector3d& operator+=(const Vector3d& other);
    Vector3d& operator-=(const Vector3d& other);
    Vector3d& operator*=(double a);
    Vector3d& operator/=(double a);

    /// <summary>
    /// 向量长度
    /// </summary>
    /// <returns>长度</returns>
    double length() const;

    /// <summary>
    /// 向量标准化
    /// </summary>
    /// <returns>标准化后的向量</returns>
    Vector3d& normalize();

    /// <summary>
    /// 置为零向量
    /// </summary>
    /// <returns>置零后的向量</returns>
    Vector3d& zero();

    /// <summary>
    /// 向量与向量点乘
    /// </summary>
    /// <param name="other">另一个向量</param>
    /// <returns>点乘积</returns>
    double operator*(const Vector3d& other) const;
};

/// <summary>
/// 实数与向量相乘
/// </summary>
/// <param name="a">实数</param>
/// <param name="v">向量</param>
/// <returns>相乘结果向量</returns>
Vector3d operator*(double a, const Vector3d& v);

/// <summary>
/// 两点距离
/// </summary>
/// <param name="p1">第一个点</param>
/// <param name="p2">第二个点</param>
/// <returns>距离</returns>
double distance(const Vector3d& p1, const Vector3d& p2);

/// <summary>
/// 向量与向量的叉乘
/// </summary>
/// <param name="a">向量</param>
/// <param name="b">向量</param>
/// <returns>叉乘积</returns>
Vector3d crossProduct(const Vector3d& a, const Vector3d& b);
