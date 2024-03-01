#pragma once

class Vector3d;
class RotationMatrix;

/// <summary>
/// 执行旋转，从惯性坐标系到物体坐标系
/// </summary>
/// <param name="m">旋转矩阵</param>
/// <param name="p">待变换的点</param>
/// <returns>变换后的点</returns>
Vector3d implementRotationFromInertialToObject(const RotationMatrix& m, const Vector3d& p);

/// <summary>
/// 执行旋转，从物体坐标系到惯性坐标系
/// </summary>
/// <param name="m">旋转矩阵</param>
/// <param name="p">待变换的点</param>
/// <returns>变换后的点</returns>
Vector3d implementRotationFromObjectToInertial(const RotationMatrix& m, const Vector3d& p);
