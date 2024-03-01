#pragma once

/// <summary>
/// 两个 double 相等
/// </summary>
struct DoubleEq
{
    double _tol;
    explicit DoubleEq(double tol = 0.000001);
    bool operator()(double a, double b) const;
};

/// <summary>
/// 两个 double 不相等
/// </summary>
struct DoubleNE
{
    double _tol;
    explicit DoubleNE(double tol = 0.000001);
    bool operator()(double a, double b) const;
};

/// <summary>
/// double 小于
/// </summary>
struct DoubleLT
{
    double _tol;
    explicit DoubleLT(double tol = 0.000001);
    bool operator()(double a, double b) const;
};

/// <summary>
/// double 小于或等于
/// </summary>
struct DoubleLE
{
    double _tol;
    explicit DoubleLE(double tol = 0.000001);
    bool operator()(double a, double b) const;
};

/// <summary>
/// double 大于
/// </summary>
struct DoubleGT
{
    double _tol;
    explicit DoubleGT(double tol = 0.000001);
    bool operator()(double a, double b) const;
};

/// <summary>
/// double 大于或等于
/// </summary>
struct DoubleGE
{
    double _tol;
    explicit DoubleGE(double tol = 0.000001);
    bool operator()(double a, double b) const;
};
