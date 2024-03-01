#include "EulerAngles.hpp"
#include "MathUtils.hpp"
#include "Constants.hpp"
#include "DoubleComp.hpp"
#include <algorithm>

EulerAngles& EulerAngles::identity()
{
    heading = 0;
    pitch = 0;
    bank = 0;
    return *this;
}

EulerAngles& EulerAngles::canonize()
{
    DoubleGT gt;
    DoubleLT lt;

    pitch = wrap(pitch);
    if (lt(pitch, -_PI_2))
    {
        pitch = -_PI - pitch;
        heading += _PI;
        bank += _PI;
    }
    else if (gt(pitch, _PI_2))
    {
        pitch = _PI - pitch;
        heading += _PI;
        bank += _PI;
    }

    if (gt(std::abs(pitch), _PI_2))
    {
        heading += bank;
        bank = 0;
    }
    else
    {
        bank = wrap(bank);
    }

    heading = wrap(heading);

    return *this;
}
