#pragma once

/// <summary>
/// ���Ƕȹ��õ� [-pi, pi) ���䡣
/// </summary>
/// <param name="angle">�����õĽǶ�</param>
/// <returns>���ú�ĽǶ�</returns>
double wrap(double angle);

/// <summary>
/// ��ȫ�� arccos ������������ 1 ��ֵ��Ϊ 1����С�� -1 ��ֵ��Ϊ -1��
/// </summary>
/// <param name="value">cos ֵ</param>
/// <returns>�Ƕ�</returns>
double acos_s(double value);

/// <summary>
/// ���� sin �� cos ֵ��
/// </summary>
/// <param name="s">[out] sin ֵ</param>
/// <param name="c">[out] cos ֵ</param>
/// <param name="angle">������ĽǶ�</param>
/// <returns></returns>
void sincos(double& s, double& c, double angle);
