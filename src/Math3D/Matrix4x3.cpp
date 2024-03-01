#include "Matrix4x3.hpp"
#include <cassert>
#include "MathUtils.hpp"
#include "DoubleComp.hpp"

Matrix4x3::Matrix4x3()
    : m11{ 1 }, m12{ 0 }, m13{ 0 }
    , m21{ 0 }, m22{ 1 }, m23{ 0 }
    , m31{ 0 }, m32{ 0 }, m33{ 1 }
    , tx{ 0 }, ty{ 0 }, tz{ 0 }
{
}

Matrix4x3& Matrix4x3::identity()
{
    m11 = 1; m12 = 0, m13 = 0;
    m21 = 0; m22 = 1; m23 = 0;
    m31 = 0; m32 = 0; m33 = 1;
    tx = 0; ty = 0; tz = 0;
    return *this;
}

Vector3d Matrix4x3::translation() const
{
    return Vector3d{ tx, ty, tz };
}

Matrix4x3& Matrix4x3::zeroTranslation()
{
    tx = 0; ty = 0; tz = 0;
    return *this;
}

Matrix4x3& Matrix4x3::setTranslation(const Vector3d& v)
{
    tx = v.x; ty = v.y; tz = v.z;
    return *this;
}

Matrix4x3& Matrix4x3::setupTranslation(const Vector3d& v)
{
    identity();
    setTranslation(v);
    return *this;
}

Matrix4x3& Matrix4x3::setupRotate(Axis axis, double angle)
{
    double s{ 0 };
    double c{ 0 };
    sincos(s, c, angle);

    if (Axis::X == axis)
    {
        m11 = 1; m12 = 0; m13 = 0;
        m21 = 0; m22 = c; m23 = s;
        m31 = 0; m32 = -s; m33 = c;
    }
    else if (Axis::Y == axis)
    {
        m11 = c; m12 = 0; m13 = -s;
        m21 = 0; m22 = 1; m23 = 0;
        m31 = s; m32 = 0; m33 = c;
    }
    else if (Axis::Z == axis)
    {
        m11 = c; m12 = s; m13 = 0;
        m21 = -s; m22 = c; m23 = 0;
        m31 = 0; m32 = 0; m33 = 1;
    }
    else
    {
        assert(false);
    }

    tx = 0; ty = 0; tz = 0;

    return *this;
}

Matrix4x3& Matrix4x3::setupRotate(const Vector3d& axis, double angle)
{
    assert(DoubleEq{}(axis.length(), 1));

    double c{ 0 };
    double s{ 0 };
    sincos(s, c, angle);

    double a = 1 - c;
    double ax = a * axis.x;
    double ay = a * axis.y;
    double az = a * axis.z;

    m11 = ax * axis.x + c;
    m12 = ax * axis.y + axis.z * s;
    m13 = ax * axis.z - axis.y * s;

    m21 = ay * axis.x - axis.z * s;
    m22 = ay * axis.y + c;
    m23 = ay * axis.z + axis.x * s;

    m31 = az * axis.x + axis.y * s;
    m32 = az * axis.y - axis.x * s;
    m33 = az * axis.z + c;

    tx = 0;
    ty = 0;
    tz = 0;

    return *this;
}

Matrix4x3& Matrix4x3::setupScale(const Vector3d& v)
{
    m11 = v.x; m12 = 0; m13 = 0;
    m21 = 0; m22 = v.y; m23 = 0;
    m31 = 0; m32 = 0; m33 = v.z;
    tx = 0; ty = 0; tz = 0;
    return *this;
}

Matrix4x3& Matrix4x3::setupScale(const Vector3d& axis, double k)
{
    assert(DoubleEq{}(axis.length(), 1));

    double a = k - 1;
    double ax = a * axis.x;
    double ay = a * axis.y;
    double az = a * axis.z;

    m11 = ax * axis.x + 1; m12 = ax * axis.y; m13 = ax * axis.z;
    m22 = ay * axis.y + 1;
    m33 = az * axis.z + 1;

    m12 = m21 = ax * axis.y;
    m13 = m31 = ax * axis.z;
    m23 = m32 = ay * axis.z;

    tx = 0; ty = 0; tz = 0;

    return *this;
}

Matrix4x3& Matrix4x3::setupShear(Axis axis, double s, double t)
{
    if (Axis::X == axis)
    {
        identity();
        m12 = s;
        m13 = t;
    }
    else if (Axis::Y == axis)
    {
        identity();
        m21 = s;
        m23 = t;
    }
    else if (Axis::Z == axis)
    {
        identity();
        m31 = s;
        m32 = t;
    }
    else
    {
        assert(false);
    }
    tx = ty = tz = 0;
    return *this;
}

Matrix4x3& Matrix4x3::setupProject(const Vector3d& n)
{
    assert(DoubleEq{}(n.length(), 1));

    m11 = 1 - n.x * n.x;
    m22 = 1 - n.y * n.y;
    m33 = 1 - n.z * n.z;

    m12 = m21 = -n.x * n.y;
    m13 = m31 = -n.x * n.z;
    m23 = m32 = -n.y * n.z;

    tx = ty = tz = 0;

    return *this;
}

Matrix4x3& Matrix4x3::setupMirror(Axis axis, double k)
{
    if (Axis::X == axis)
    {
        identity();
        m11 = -1;
        tx = 2 * k;
    }
    else if (Axis::Y == axis)
    {
        identity();
        m22 = -1;
        ty = 2 * k;
    }
    else if (Axis::Z == axis)
    {
        identity();
        m33 = -1;
        tz = 2 * k;
    }
    else
    {
        assert(false);
    }
    return *this;
}

Matrix4x3& Matrix4x3::setupMirror(const Vector3d& n)
{
    assert(DoubleEq{}(n * n, 1));

    double ax = -2 * n.x;
    double ay = -2 * n.y;
    double az = -2 * n.z;

    m11 = 1 + ax * n.x;
    m22 = 1 + ay * n.y;
    m33 = 1 + az * n.z;

    m12 = m21 = ax * n.y;
    m13 = m31 = ax * n.z;
    m23 = m32 = ay * n.z;

    tx = ty = tz = 0;

    return *this;
}

Vector3d operator*(const Vector3d& p, const Matrix4x3& m)
{
    return Vector3d{
        p.x * m.m11 + p.y * m.m21 + p.z * m.m31 + m.tx,
        p.x * m.m12 + p.y * m.m22 + p.z * m.m32 + m.ty,
        p.x * m.m13 + p.y * m.m23 + p.z * m.m33 + m.tz,
    };
}

Vector3d& operator*=(Vector3d& p, const Matrix4x3& m)
{
    double x = p.x;
    double y = p.y;
    double z = p.z;
    p.x = x * m.m11 + y * m.m21 + z * m.m31 + m.tx;
    p.y = x * m.m12 + y * m.m22 + z * m.m32 + m.ty;
    p.z = x * m.m13 + y * m.m23 + z * m.m33 + m.tz;
    return p;
}

Matrix4x3 operator*(const Matrix4x3& a, const Matrix4x3& b)
{
    Matrix4x3 m;

    m.m11 = a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31;
    m.m12 = a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32;
    m.m13 = a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33;

    m.m21 = a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31;
    m.m22 = a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32;
    m.m23 = a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33;

    m.m31 = a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31;
    m.m32 = a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32;
    m.m33 = a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33;

    m.tx = a.tx * b.m11 + a.ty * b.m21 + a.tz * b.m31 + b.tx;
    m.ty = a.tx * b.m12 + a.ty * b.m22 + a.tz * b.m32 + b.ty;
    m.tz = a.tx * b.m13 + a.ty * b.m23 + a.tz * b.m33 + b.tz;

    return m;
}

Matrix4x3& operator*=(Matrix4x3& a, const Matrix4x3& b)
{
    a = a * b;
    return a;
}

double determinant(const Matrix4x3& m)
{
    return
        m.m11 * (m.m22 * m.m33 - m.m23 * m.m32)
        + m.m12 * (m.m23 * m.m31 - m.m21 * m.m33)
        + m.m13 * (m.m21 * m.m32 - m.m22 * m.m31);
}

Matrix4x3 inverse(const Matrix4x3& m)
{
    double det = determinant(m);
    assert(!DoubleEq{}(det, 0));

    Matrix4x3 r;

    r.m11 = (m.m22 * m.m33 - m.m23 * m.m32) / det;
    r.m12 = (m.m13 * m.m32 - m.m12 * m.m33) / det;
    r.m13 = (m.m12 * m.m23 - m.m13 * m.m22) / det;

    r.m21 = (m.m23 * m.m31 - m.m21 * m.m33) / det;
    r.m22 = (m.m11 * m.m33 - m.m13 * m.m31) / det;
    r.m23 = (m.m13 * m.m21 - m.m23 * m.m11) / det;

    r.m31 = (m.m21 * m.m32 - m.m22 * m.m31) / det;
    r.m32 = (m.m12 * m.m31 - m.m11 * m.m32) / det;
    r.m33 = (m.m11 * m.m22 - m.m12 * m.m21) / det;

    r.tx = -(m.tx * r.m11 + m.ty * r.m21 + m.tz * r.m31);
    r.ty = -(m.tx * r.m12 + m.ty * r.m22 + m.tz * r.m32);
    r.tz = -(m.tx * r.m13 + m.ty * r.m23 + m.tz * r.m33);

    return r;
}


