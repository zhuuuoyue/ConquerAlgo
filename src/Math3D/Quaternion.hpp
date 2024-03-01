#pragma once

class Quaternion
{
public:

    double w{ 1 };
    double x{ 0 };
    double y{ 0 };
    double z{ 0 };

    Quaternion()
        : w{ 1 }
        , x{ 0 }
        , y{ 0 }
        , z{ 0 }
    {
    }

    Quaternion(double _w, double _x, double _y, double _z)
        : w{ _w }
        , x{ _x }
        , y{ _y }
        , z{ _z }
    {
    }

    Quaternion operator*(const Quaternion& a) const;
    Quaternion& operator*=(const Quaternion& a);

    Quaternion& identity();

    Quaternion& normalize();

    Quaternion conjugate() const;
};

double dotProduct(const Quaternion& a, const Quaternion& b);

Quaternion pow(const Quaternion& q, double k);
