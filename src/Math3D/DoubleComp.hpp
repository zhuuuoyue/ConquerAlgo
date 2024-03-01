#pragma once

/// <summary>
/// ���� double ���
/// </summary>
struct DoubleEq
{
    double _tol;
    explicit DoubleEq(double tol = 0.000001);
    bool operator()(double a, double b) const;
};

/// <summary>
/// ���� double �����
/// </summary>
struct DoubleNE
{
    double _tol;
    explicit DoubleNE(double tol = 0.000001);
    bool operator()(double a, double b) const;
};

/// <summary>
/// double С��
/// </summary>
struct DoubleLT
{
    double _tol;
    explicit DoubleLT(double tol = 0.000001);
    bool operator()(double a, double b) const;
};

/// <summary>
/// double С�ڻ����
/// </summary>
struct DoubleLE
{
    double _tol;
    explicit DoubleLE(double tol = 0.000001);
    bool operator()(double a, double b) const;
};

/// <summary>
/// double ����
/// </summary>
struct DoubleGT
{
    double _tol;
    explicit DoubleGT(double tol = 0.000001);
    bool operator()(double a, double b) const;
};

/// <summary>
/// double ���ڻ����
/// </summary>
struct DoubleGE
{
    double _tol;
    explicit DoubleGE(double tol = 0.000001);
    bool operator()(double a, double b) const;
};
