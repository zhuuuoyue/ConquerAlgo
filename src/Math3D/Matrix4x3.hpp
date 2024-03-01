#pragma once

#include "Vector3d.hpp"

/// <summary>
/// ������
/// </summary>
enum class Axis
{
    X, Y, Z
};

/// <summary>
/// �任����
/// </summary>
class Matrix4x3
{
public:

    Matrix4x3();

    /// <summary>
    /// ��Ϊ��λ����
    /// </summary>
    /// <returns>��λ����</returns>
    Matrix4x3& identity();

    /// <summary>
    /// ��ȡƽ������
    /// </summary>
    /// <returns>ƽ������</returns>
    Vector3d translation() const;

    /// <summary>
    /// ƽ��������Ϊ��
    /// </summary>
    /// <returns>����</returns>
    Matrix4x3& zeroTranslation();

    /// <summary>
    /// ����ƽ������
    /// </summary>
    /// <param name="v">ƽ������</param>
    /// <returns>����</returns>
    Matrix4x3& setTranslation(const Vector3d& v);

    /// <summary>
    /// ����ǰ��������Ϊƽ�ƾ���
    /// </summary>
    /// <param name="v">ƽ������</param>
    /// <returns>ƽ�ƾ���</returns>
    Matrix4x3& setupTranslation(const Vector3d& v);

    /// <summary>
    /// ����ǰ��������Ϊ��ת����
    /// </summary>
    /// <param name="axis">��ת��</param>
    /// <param name="angle">��ת�Ƕ�</param>
    /// <returns>��ת����</returns>
    Matrix4x3& setupRotate(Axis axis, double angle);

    /// <summary>
    /// ����ǰ��������Ϊ��ת����
    /// </summary>
    /// <param name="axis">��ת��</param>
    /// <param name="angle">��ת�Ƕ�</param>
    /// <returns>��ת����</returns>
    Matrix4x3& setupRotate(const Vector3d& axis, double angle);

    /// <summary>
    /// ����ǰ��������Ϊ���ž���
    /// </summary>
    /// <param name="v">��������������</param>
    /// <returns>���ž���</returns>
    Matrix4x3& setupScale(const Vector3d& v);

    /// <summary>
    /// ����ǰ��������Ϊ���ž���
    /// </summary>
    /// <param name="axis">����������</param>
    /// <param name="k">��������</param>
    /// <returns>���ž���</returns>
    Matrix4x3& setupScale(const Vector3d& axis, double k);

    /// <summary>
    /// ����ǰ��������Ϊ�б����
    /// </summary>
    /// <param name="axis">�б���</param>
    /// <param name="s"></param>
    /// <param name="t"></param>
    /// <returns>�б����</returns>
    Matrix4x3& setupShear(Axis axis, double s, double t);

    /// <summary>
    /// ����ǰ��������ΪͶӰ����
    /// </summary>
    /// <param name="n">��ԭ��ͶӰ��ķ�����</param>
    /// <returns>ͶӰ����</returns>
    Matrix4x3& setupProject(const Vector3d& n);

    /// <summary>
    /// ����ǰ��������Ϊ�������
    /// </summary>
    /// <param name="axis">ƽ�洹ֱ����</param>
    /// <param name="k">ƽ��λ��</param>
    /// <returns>�������</returns>
    Matrix4x3& setupMirror(Axis axis, double k);

    /// <summary>
    /// ����ǰ��������Ϊ�������
    /// </summary>
    /// <param name="n">��ԭ��ƽ��ķ�����</param>
    /// <returns>�������</returns>
    Matrix4x3& setupMirror(const Vector3d& n);

public:

    double m11, m12, m13;
    double m21, m22, m23;
    double m31, m32, m33;
    double tx, ty, tz;
};

/// <summary>
/// �����������ˣ�ʹ�þ���Ե���б任
/// </summary>
/// <param name="p">���任�ĵ�</param>
/// <param name="m">�任����</param>
/// <returns>�任��ĵ�</returns>
Vector3d operator*(const Vector3d& p, const Matrix4x3& m);

/// <summary>
/// �����������ˣ�ʹ�þ���Ե���б任
/// </summary>
/// <param name="p">���任�ĵ�</param>
/// <param name="m">�任����</param>
/// <returns>�任��ĵ�</returns>
Vector3d& operator*=(Vector3d& p, const Matrix4x3& m);

/// <summary>
/// ����˷�
/// </summary>
/// <param name="a">����һ</param>
/// <param name="b">�����</param>
/// <returns>����</returns>
Matrix4x3 operator*(const Matrix4x3& a, const Matrix4x3& b);

/// <summary>
/// ����˷�
/// </summary>
/// <param name="a">����һ</param>
/// <param name="b">�����</param>
/// <returns>����</returns>
Matrix4x3& operator*=(Matrix4x3& a, const Matrix4x3& b);

/// <summary>
/// ���� 3x3 ��������ʽ
/// </summary>
/// <param name="m">����</param>
/// <returns>����ʽֵ</returns>
double determinant(const Matrix4x3& m);

/// <summary>
/// ��������
/// </summary>
/// <param name="m">������ľ���</param>
/// <returns>�����</returns>
Matrix4x3 inverse(const Matrix4x3& m);
