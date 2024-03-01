#pragma once

class Vector3d;
class RotationMatrix;

/// <summary>
/// ִ����ת���ӹ�������ϵ����������ϵ
/// </summary>
/// <param name="m">��ת����</param>
/// <param name="p">���任�ĵ�</param>
/// <returns>�任��ĵ�</returns>
Vector3d implementRotationFromInertialToObject(const RotationMatrix& m, const Vector3d& p);

/// <summary>
/// ִ����ת������������ϵ����������ϵ
/// </summary>
/// <param name="m">��ת����</param>
/// <param name="p">���任�ĵ�</param>
/// <returns>�任��ĵ�</returns>
Vector3d implementRotationFromObjectToInertial(const RotationMatrix& m, const Vector3d& p);
