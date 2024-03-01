#include "RotationMatrixUtils.hpp"
#include "RotationMatrix.hpp"
#include "Vector3d.hpp"

Vector3d implementRotationFromInertialToObject(const RotationMatrix& m, const Vector3d& p)
{
    return Vector3d{
        p.x * m.m11 + p.y * m.m21 + p.z * m.m31,
        p.x * m.m12 + p.y * m.m22 + p.z * m.m32,
        p.x * m.m13 + p.y * m.m23 + p.z * m.m33
    };
}

Vector3d implementRotationFromObjectToInertial(const RotationMatrix& m, const Vector3d& p)
{
    // m �����������������������ת��
    return Vector3d{
        p.x * m.m11 + p.y * m.m12 + p.z * m.m13,
        p.x * m.m21 + p.y * m.m22 + p.z * m.m23,
        p.x * m.m31 + p.y * m.m32 + p.z * m.m33
    };
}
