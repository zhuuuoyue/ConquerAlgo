#include "MathUtils.hpp"
#include "DoubleComp.hpp"
#include "Constants.hpp"
#include <cmath>

double wrap(double angle)
{
    angle += _PI;
    angle -= floor(angle / _2_PI) * _2_PI;
    angle -= _PI;
    return angle;
}

double acos_s(double value)
{
    DoubleEq de;
    if (de(value, 1) || value > 1)
    {
        return 0;
    }
    if (de(value, -1) || value < -1)
    {
        return _PI;
    }
    return acos(value);
}

void sincos(double& s, double& c, double angle)
{
    s = sin(angle);
    c = cos(angle);
}
