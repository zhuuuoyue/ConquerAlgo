#pragma once

/// <summary>
/// 将角度归置到 [-pi, pi) 区间。
/// </summary>
/// <param name="angle">待归置的角度</param>
/// <returns>归置后的角度</returns>
double wrap(double angle);

/// <summary>
/// 安全的 arccos 函数。将大于 1 的值视为 1，将小于 -1 的值视为 -1。
/// </summary>
/// <param name="value">cos 值</param>
/// <returns>角度</returns>
double acos_s(double value);

/// <summary>
/// 计算 sin 和 cos 值。
/// </summary>
/// <param name="s">[out] sin 值</param>
/// <param name="c">[out] cos 值</param>
/// <param name="angle">待计算的角度</param>
/// <returns></returns>
void sincos(double& s, double& c, double angle);
