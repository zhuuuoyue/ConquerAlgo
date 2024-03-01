#include "Vector3d.hpp"
#include <cmath>
#include <cassert>
#include "DoubleComp.hpp"

Vector3d::Vector3d()
    : x{ 0 }
    , y{ 0 }
    , z{ 0 }
{
}

Vector3d::Vector3d(double _x, double _y, double _z)
    : x{ _x }
    , y{ _y }
    , z{ _z }
{
}

Vector3d::Vector3d(const Vector3d& other)
    : x{ other.x }
    , y{ other.y }
    , z{ other.z }
{
}

Vector3d::Vector3d(Vector3d&& other) noexcept
    : x{ other.x }
    , y{ other.y }
    , z{ other.z }
{
}

Vector3d& Vector3d::operator=(const Vector3d& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

Vector3d& Vector3d::operator=(Vector3d&& other) noexcept
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

bool Vector3d::operator==(const Vector3d& other) const
{
    DoubleEq de;
    return de(x, other.x)
        && de(y, other.y)
        && de(z, other.z);
}

bool Vector3d::operator!=(const Vector3d& other) const
{
    return !(*this == other);
}

Vector3d Vector3d::operator-() const
{
    return Vector3d{ -x, -y, -z };
}

Vector3d Vector3d::operator+() const
{
    return Vector3d{ *this };
}

Vector3d Vector3d::operator+(const Vector3d& other) const
{
    return Vector3d{
        x + other.x,
        y + other.y,
        z + other.z
    };
}

Vector3d Vector3d::operator-(const Vector3d& other) const
{
    return Vector3d{
        x - other.x,
        y - other.y,
        z - other.z
    };
}

Vector3d Vector3d::operator*(double a) const
{
    return Vector3d{ a * x, a * y, a * z };
}

Vector3d Vector3d::operator/(double a) const
{
    assert(DoubleNE{}(a, 0));
    return Vector3d{ x / a, y / a, z / a };
}

Vector3d& Vector3d::operator+=(const Vector3d& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3d& Vector3d::operator-=(const Vector3d& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3d& Vector3d::operator*=(double a)
{
    x *= a;
    y *= a;
    z *= a;
    return *this;
}

Vector3d& Vector3d::operator/=(double a)
{
    assert(DoubleNE{}(a, 0));
    x /= a;
    y /= a;
    z /= a;
    return *this;
}

double Vector3d::length() const
{
    return std::sqrt(x * x + y * y + z * z);
}

Vector3d& Vector3d::normalize()
{
    double len = length();
    assert(DoubleNE{}(len, 0));
    *this /= len;
    return *this;
}

Vector3d& Vector3d::zero()
{
    x = y = z = 0;
    return *this;
}

double Vector3d::operator*(const Vector3d& other) const
{
    return x * other.x + y * other.y + z * other.z;
}

Vector3d operator*(double a, const Vector3d& v)
{
    return v * a;
}

double distance(const Vector3d& p1, const Vector3d& p2)
{
    return (p1 - p2).length();
}

Vector3d crossProduct(const Vector3d& a, const Vector3d& b)
{
    return Vector3d{
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}
