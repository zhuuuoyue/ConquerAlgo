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
    /// ��������
    /// </summary>
    /// <returns>����</returns>
    double length() const;

    /// <summary>
    /// ������׼��
    /// </summary>
    /// <returns>��׼���������</returns>
    Vector3d& normalize();

    /// <summary>
    /// ��Ϊ������
    /// </summary>
    /// <returns>����������</returns>
    Vector3d& zero();

    /// <summary>
    /// �������������
    /// </summary>
    /// <param name="other">��һ������</param>
    /// <returns>��˻�</returns>
    double operator*(const Vector3d& other) const;
};

/// <summary>
/// ʵ�����������
/// </summary>
/// <param name="a">ʵ��</param>
/// <param name="v">����</param>
/// <returns>��˽������</returns>
Vector3d operator*(double a, const Vector3d& v);

/// <summary>
/// �������
/// </summary>
/// <param name="p1">��һ����</param>
/// <param name="p2">�ڶ�����</param>
/// <returns>����</returns>
double distance(const Vector3d& p1, const Vector3d& p2);

/// <summary>
/// �����������Ĳ��
/// </summary>
/// <param name="a">����</param>
/// <param name="b">����</param>
/// <returns>��˻�</returns>
Vector3d crossProduct(const Vector3d& a, const Vector3d& b);
