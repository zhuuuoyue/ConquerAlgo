#pragma once

/// <summary>
/// ≈∑¿≠Ω«
/// </summary>
class EulerAngles
{
public:

    double heading{ 0 };
    double pitch{ 0 };
    double bank{ 0 };

    EulerAngles()
        : heading{ 0 }
        , pitch{ 0 }
        , bank{ 0 }
    {
    }

    EulerAngles(double h, double p, double b)
        : heading{ h }
        , pitch{ p }
        , bank{ 0 }
    {
    }

    // ÷√¡„
    EulerAngles& identity();

    EulerAngles& canonize();
};
