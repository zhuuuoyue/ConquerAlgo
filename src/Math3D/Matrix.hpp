#pragma once

#include <utility>

/// <summary>
/// ����
/// </summary>
/// <typeparam name="R">����</typeparam>
/// <typeparam name="C">����</typeparam>
template<std::size_t R, std::size_t C>
class Matrix {
public:

    /// <summary>
    /// ��������
    /// </summary>
    /// <returns>����</returns>
    static constexpr std::size_t rows()
    {
        return R;
    }

    /// <summary>
    /// ��������
    /// </summary>
    /// <returns>����</returns>
    static constexpr std::size_t cols()
    {
        return C;
    }

    Matrix()
        : _d{ 0 }
    {
    }

    /// <summary>
    /// ���ʾ���Ԫ��
    /// </summary>
    /// <param name="r">������</param>
    /// <param name="c">������</param>
    /// <returns>����Ԫ��ֵ����</returns>
    double& operator()(std::size_t r, std::size_t c)
    {
        std::size_t i = index(r, c);
        return _d[i];
    }

    /// <summary>
    /// ���ʾ���Ԫ��
    /// </summary>
    /// <param name="r">������</param>
    /// <param name="c">������</param>
    /// <returns>����Ԫ��ֵ</returns>
    double operator()(std::size_t r, std::size_t c) const
    {
        std::size_t i = index(r, c);
        return _d[i];
    }

    /// <summary>
    /// �����ת��
    /// </summary>
    /// <returns>ת�ú�ľ���</returns>
    Matrix<C, R> transform() const
    {
        Matrix<C, R> t;
        for (std::size_t r = 0; r < R; ++r) {
            for (std::size_t c = 0; c < C; ++c) {
                t(c, r) = (*this)(r, c);
            }
        }
        return t;
    }

    /// <summary>
    /// ����˷�
    /// </summary>
    /// <typeparam name="N">��һ�����������</typeparam>
    /// <param name="that">��һ������</param>
    /// <returns>������˽��</returns>
    template<std::size_t N>
    Matrix<R, N> operator*(const Matrix<C, N>& that) const
    {
        Matrix<R, N> m;
        for (std::size_t r = 0; r < R; ++r) {
            for (std::size_t n = 0; n < N; ++n) {
                double value{ 0 };
                for (std::size_t c = 0; c < C; ++c) {
                    value += ((*this)(r, c) * that(c, n));
                }
                m(r, n) = value;
            }
        }
        return m;
    }

private:

    /// <summary>
    /// У������
    /// </summary>
    /// <param name="r">������</param>
    /// <param name="c">������</param>
    /// <returns>��������Ч���򷵻� true�����򷵻� false</returns>
    bool validate(std::size_t r, std::size_t c) const
    {
        return r < R && c < C;
    }

    /// <summary>
    /// ��ά����תһά����
    /// </summary>
    /// <param name="r">������</param>
    /// <param name="c">������</param>
    /// <returns>һά����</returns>
    std::size_t index(std::size_t r, std::size_t c) const
    {
        return C * r + c;
    }

private:

    double _d[R * C];
};

template<>
class Matrix<0, 0> {};

template<std::size_t R>
class Matrix<R, 0> {};

template<std::size_t C>
class Matrix<0, C> {};
