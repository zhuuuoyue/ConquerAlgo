#include "Quaternion.hpp"
#include <cassert>
#include <cmath>
#include "DoubleComp.hpp"
#include "MathUtils.hpp"

Quaternion Quaternion::operator*(const Quaternion& a) const
{
    Quaternion r;
    r.w = w * a.w - x * a.x - y * a.y - z * a.z;
    r.x = w * a.x + x * a.w + z * a.y - y * a.z;
    r.y = w * a.y + y * a.w + x * a.z - z * a.x;
    r.z = w * a.z + z * a.w + y * a.x - x * a.y;
    return r;
}

Quaternion& Quaternion::operator*=(const Quaternion& a)
{
    *this = *this * a;
    return *this;
}

Quaternion& Quaternion::identity()
{
    w = 1;
    x = y = z = 0;
    return *this;
}

Quaternion& Quaternion::normalize()
{
    double mag = std::sqrt(w * w + x * x + y * y + z * z);
    assert(DoubleNE{}(mag, 0));
    w /= mag;
    x /= mag;
    y /= mag;
    z /= mag;
    return *this;
}

Quaternion Quaternion::conjugate() const
{
    return Quaternion{ w, -x, -y, -z };
}

double dotProduct(const Quaternion& a, const Quaternion& b)
{
    return a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
}

Quaternion pow(const Quaternion& q, double k)
{
    if (DoubleGE{}(std::abs(q.w), 1))
    {
        return q;
    }

    double alpha = acos_s(q.w);
    double alpha2 = alpha * k;

    double s{ 0 };
    double c{ 0 };
    sincos(s, c, alpha2);
    double mult = s / sin(alpha);

    return Quaternion{ c, q.x * mult, q.y * mult, q.z * mult };
}
