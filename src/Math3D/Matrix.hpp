#pragma once

#include <utility>

/// <summary>
/// 矩阵
/// </summary>
/// <typeparam name="R">行数</typeparam>
/// <typeparam name="C">列数</typeparam>
template<std::size_t R, std::size_t C>
class Matrix {
public:

    /// <summary>
    /// 矩阵行数
    /// </summary>
    /// <returns>行数</returns>
    static constexpr std::size_t rows()
    {
        return R;
    }

    /// <summary>
    /// 矩阵列数
    /// </summary>
    /// <returns>列数</returns>
    static constexpr std::size_t cols()
    {
        return C;
    }

    Matrix()
        : _d{ 0 }
    {
    }

    /// <summary>
    /// 访问矩阵元素
    /// </summary>
    /// <param name="r">行索引</param>
    /// <param name="c">列索引</param>
    /// <returns>矩阵元素值引用</returns>
    double& operator()(std::size_t r, std::size_t c)
    {
        std::size_t i = index(r, c);
        return _d[i];
    }

    /// <summary>
    /// 访问矩阵元素
    /// </summary>
    /// <param name="r">行索引</param>
    /// <param name="c">列索引</param>
    /// <returns>矩阵元素值</returns>
    double operator()(std::size_t r, std::size_t c) const
    {
        std::size_t i = index(r, c);
        return _d[i];
    }

    /// <summary>
    /// 矩阵的转置
    /// </summary>
    /// <returns>转置后的矩阵</returns>
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
    /// 矩阵乘法
    /// </summary>
    /// <typeparam name="N">另一个矩阵的列数</typeparam>
    /// <param name="that">另一个矩阵</param>
    /// <returns>矩阵相乘结果</returns>
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
    /// 校验索引
    /// </summary>
    /// <param name="r">行索引</param>
    /// <param name="c">列索引</param>
    /// <returns>若索引有效，则返回 true，否则返回 false</returns>
    bool validate(std::size_t r, std::size_t c) const
    {
        return r < R && c < C;
    }

    /// <summary>
    /// 二维坐标转一维坐标
    /// </summary>
    /// <param name="r">行索引</param>
    /// <param name="c">列索引</param>
    /// <returns>一维索引</returns>
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
