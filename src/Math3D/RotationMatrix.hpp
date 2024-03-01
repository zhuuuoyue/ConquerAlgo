#pragma once

class Quaternion;
class EulerAngles;

class RotationMatrix
{
public:

    double m11{ 1 }, m12{ 0 }, m13{ 0 };
    double m21{ 0 }, m22{ 1 }, m23{ 0 };
    double m31{ 0 }, m32{ 0 }, m33{ 1 };

    /// <summary>
    /// ����ת������Ϊ��λ����
    /// </summary>
    /// <returns>��λ����</returns>
    RotationMatrix& identity();

    /// <summary>
    /// ʹ��ŷ���ǹ�����ת����
    /// </summary>
    /// <param name="orientation">ŷ���Ǳ��ķ�λ</param>
    /// <returns>�������ת����</returns>
    RotationMatrix& fromEulerAngles(const EulerAngles& orientation);

    /// <summary>
    /// ʹ�ù���-��������ϵ����Ԫ��������ת����
    /// </summary>
    /// <param name="q">��Ԫ��</param>
    /// <returns>�������ת����</returns>
    RotationMatrix& fromInertialToObjectQuaternion(const Quaternion& q);

    /// <summary>
    /// ʹ������-��������ϵ����Ԫ��������ת����
    /// </summary>
    /// <param name="q">��Ԫ��</param>
    /// <returns>�������ת����</returns>
    RotationMatrix& fromObjectToInertialQuaternion(const Quaternion& q);
};
