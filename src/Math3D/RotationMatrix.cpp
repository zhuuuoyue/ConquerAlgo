#include "RotationMatrix.hpp"
#include "MathUtils.hpp"
#include "EulerAngles.hpp"
#include "Quaternion.hpp"

RotationMatrix& RotationMatrix::identity()
{
    m11 = 1; m12 = 0; m13 = 0;
    m21 = 0; m22 = 1; m23 = 0;
    m31 = 0; m32 = 0; m33 = 1;
    return *this;
}

RotationMatrix& RotationMatrix::fromEulerAngles(const EulerAngles& orientation)
{
    double sh{ 0 }, sp{ 0 }, sb{ 0 };
    double ch{ 0 }, cp{ 0 }, cb{ 0 };
    sincos(sh, ch, orientation.heading);
    sincos(sp, cp, orientation.pitch);
    sincos(sb, cb, orientation.bank);

    m11 = ch * cb + sh * sp * sb;
    m12 = -ch * sb + sh * sp * cb;
    m13 = sh * cp;

    m21 = sb * cp;
    m22 = cb * cp;
    m23 = -sp;

    m31 = -sh * cb + ch * sp * sb;
    m32 = sb * sh + ch * sp * cb;
    m33 = ch * cp;

    return *this;
}

RotationMatrix& RotationMatrix::fromInertialToObjectQuaternion(const Quaternion& q)
{
    return *this;
}

RotationMatrix& RotationMatrix::fromObjectToInertialQuaternion(const Quaternion& q)
{
    return *this;
}
