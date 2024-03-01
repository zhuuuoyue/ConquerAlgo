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
    /// 将旋转矩阵置为单位矩阵
    /// </summary>
    /// <returns>单位矩阵</returns>
    RotationMatrix& identity();

    /// <summary>
    /// 使用欧拉角构造旋转矩阵
    /// </summary>
    /// <param name="orientation">欧拉角表达的方位</param>
    /// <returns>构造的旋转矩阵</returns>
    RotationMatrix& fromEulerAngles(const EulerAngles& orientation);

    /// <summary>
    /// 使用惯性-物体坐标系的四元数构造旋转矩阵
    /// </summary>
    /// <param name="q">四元数</param>
    /// <returns>构造的旋转矩阵</returns>
    RotationMatrix& fromInertialToObjectQuaternion(const Quaternion& q);

    /// <summary>
    /// 使用物体-惯性坐标系的四元数构造旋转矩阵
    /// </summary>
    /// <param name="q">四元数</param>
    /// <returns>构造的旋转矩阵</returns>
    RotationMatrix& fromObjectToInertialQuaternion(const Quaternion& q);
};
