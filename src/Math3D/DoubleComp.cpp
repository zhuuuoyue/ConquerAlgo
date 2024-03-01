#include "DoubleComp.hpp"
#include <cstdlib>

DoubleEq::DoubleEq(double tol/* = 0.000001*/)
    : _tol{ tol }
{
}

bool DoubleEq::operator()(double a, double b) const
{
    return std::abs(a - b) < _tol;
}

DoubleNE::DoubleNE(double tol/* = 0.000001*/)
    : _tol{ tol }
{
}

bool DoubleNE::operator()(double a, double b) const
{
    return !DoubleEq{ _tol }(a, b);
}

DoubleLT::DoubleLT(double tol/* = 0.000001*/)
    : _tol{ tol }
{
}

bool DoubleLT::operator()(double a, double b) const
{
    return !DoubleEq{ _tol }(a, b) && a < b;
}

DoubleLE::DoubleLE(double tol/* = 0.000001*/)
    : _tol{ tol }
{
}

bool DoubleLE::operator()(double a, double b) const
{
    return DoubleEq{ _tol }(a, b) || a < b;
}

DoubleGT::DoubleGT(double tol/* = 0.000001*/)
    : _tol{ tol }
{
}

bool DoubleGT::operator()(double a, double b) const
{
    return !DoubleEq{ _tol }(a, b) && a > b;
}

DoubleGE::DoubleGE(double tol/* = 0.000001*/)
    : _tol{ tol }
{
}

bool DoubleGE::operator()(double a, double b) const
{
    return DoubleEq{ _tol }(a, b) || a > b;
}
