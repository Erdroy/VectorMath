// VectorMath (c) 2018 Damian 'Erdroy' Korczowski

#pragma once

#ifndef MATRIX4X4BASE_H
#define MATRIX4X4BASE_H

#include "MatrixBase.h"
#include "Vector3Base.h"

template<typename T>
struct Matrix4x4Base : MatrixBase<T, 4, 4>
{
protected:
    /* Protected usings */
    using MatrixComponents<T, 4, 4>::components;
#if USE_UPPERCASE_COMPONENTS
    using MatrixComponents<T, 4, 4>::m11;
    using MatrixComponents<T, 4, 4>::m12;
    using MatrixComponents<T, 4, 4>::m13;
    using MatrixComponents<T, 4, 4>::m14;

    using MatrixComponents<T, 4, 4>::m21;
    using MatrixComponents<T, 4, 4>::m22;
    using MatrixComponents<T, 4, 4>::m23;
    using MatrixComponents<T, 4, 4>::m24;

    using MatrixComponents<T, 4, 4>::m31;
    using MatrixComponents<T, 4, 4>::m32;
    using MatrixComponents<T, 4, 4>::m33;
    using MatrixComponents<T, 4, 4>::m34;

    using MatrixComponents<T, 4, 4>::m41;
    using MatrixComponents<T, 4, 4>::m42;
    using MatrixComponents<T, 4, 4>::m43;
    using MatrixComponents<T, 4, 4>::m44;
#else
    using MatrixComponents<T, 4, 4>::M11;
    using MatrixComponents<T, 4, 4>::M12;
    using MatrixComponents<T, 4, 4>::M13;
    using MatrixComponents<T, 4, 4>::M14;

    using MatrixComponents<T, 4, 4>::M21;
    using MatrixComponents<T, 4, 4>::M22;
    using MatrixComponents<T, 4, 4>::M23;
    using MatrixComponents<T, 4, 4>::M24;

    using MatrixComponents<T, 4, 4>::M31;
    using MatrixComponents<T, 4, 4>::M32;
    using MatrixComponents<T, 4, 4>::M33;
    using MatrixComponents<T, 4, 4>::M34;

    using MatrixComponents<T, 4, 4>::M41;
    using MatrixComponents<T, 4, 4>::M42;
    using MatrixComponents<T, 4, 4>::M43;
    using MatrixComponents<T, 4, 4>::M44;
#endif

public:
    /* Public usings */
#if USE_UPPERCASE_COMPONENTS
    using MatrixComponents<T, 4, 4>::M11;
    using MatrixComponents<T, 4, 4>::M12;
    using MatrixComponents<T, 4, 4>::M13;
    using MatrixComponents<T, 4, 4>::M14;

    using MatrixComponents<T, 4, 4>::M21;
    using MatrixComponents<T, 4, 4>::M22;
    using MatrixComponents<T, 4, 4>::M23;
    using MatrixComponents<T, 4, 4>::M24;

    using MatrixComponents<T, 4, 4>::M31;
    using MatrixComponents<T, 4, 4>::M32;
    using MatrixComponents<T, 4, 4>::M33;
    using MatrixComponents<T, 4, 4>::M34;

    using MatrixComponents<T, 4, 4>::M41;
    using MatrixComponents<T, 4, 4>::M42;
    using MatrixComponents<T, 4, 4>::M43;
    using MatrixComponents<T, 4, 4>::M44;
#else
    using MatrixComponents<T, 4, 4>::m11;
    using MatrixComponents<T, 4, 4>::m12;
    using MatrixComponents<T, 4, 4>::m13;
    using MatrixComponents<T, 4, 4>::m14;

    using MatrixComponents<T, 4, 4>::m21;
    using MatrixComponents<T, 4, 4>::m22;
    using MatrixComponents<T, 4, 4>::m23;
    using MatrixComponents<T, 4, 4>::m24;

    using MatrixComponents<T, 4, 4>::m31;
    using MatrixComponents<T, 4, 4>::m32;
    using MatrixComponents<T, 4, 4>::m33;
    using MatrixComponents<T, 4, 4>::m34;

    using MatrixComponents<T, 4, 4>::m41;
    using MatrixComponents<T, 4, 4>::m42;
    using MatrixComponents<T, 4, 4>::m43;
    using MatrixComponents<T, 4, 4>::m44;
#endif

public:
    /* Constructors */
    Matrix4x4Base()
    {
        for (auto i = 0u; i < 16u; i++)
            components[i] = T(0);
    }

    explicit Matrix4x4Base(T value)
    {
        for (auto i = 0u; i < 16u; i++)
            components[i] = value;
    }

    Matrix4x4Base(T m11, T m12, T m13, T m14, T m21, T m22, T m23, T m24, T m31, T m32, T m33, T m34, T m41, T m42, T m43, T m44)
    {
        components[0] = m11;
        components[1] = m12;
        components[2] = m13;
        components[3] = m14;

        components[4] = m21;
        components[5] = m22;
        components[6] = m23;
        components[7] = m24;

        components[8] = m31;
        components[9] = m32;
        components[10] = m33;
        components[11] = m34;

        components[12] = m41;
        components[13] = m42;
        components[14] = m43;
        components[15] = m44;
    }

public:
    /* Public members */
    void Invert();
    void Transpose();
    void Negate();
    float Determinant();

    bool IsIdentity();

    VectorBase<T, 3> Translation();
    VectorBase<T, 3> Scale();

    void DecomposeTransform(VectorBase<T, 3>& translation, Quaternion& rotation, VectorBase<T, 3>& scale);
    void ComposeTransform(const VectorBase<T, 3>& translation, const Quaternion& rotation, const VectorBase<T, 3>& scale);

    VectorBase<T, 3> Up();
    VectorBase<T, 3> Down();
    VectorBase<T, 3> Left();
    VectorBase<T, 3> Right();
    VectorBase<T, 3> Forward();
    VectorBase<T, 3> Backward();

public:
    /* Public static members */
    static Matrix4x4Base<T> Invert(const Matrix4x4Base<T>& matrix);
    static Matrix4x4Base<T> Transpose(const Matrix4x4Base<T>& matrix);
    static Matrix4x4Base<T> Negate(const Matrix4x4Base<T>& matrix);

    static VectorBase<T, 3> Translation(const Matrix4x4Base<T>& matrix);
    static VectorBase<T, 3> Scale(const Matrix4x4Base<T>& matrix);
    static VectorBase<T, 3> Up(const Matrix4x4Base<T>& matrix);
    static VectorBase<T, 3> Down(const Matrix4x4Base<T>& matrix);
    static VectorBase<T, 3> Left(const Matrix4x4Base<T>& matrix);
    static VectorBase<T, 3> Right(const Matrix4x4Base<T>& matrix);
    static VectorBase<T, 3> Forward(const Matrix4x4Base<T>& matrix);
    static VectorBase<T, 3> Backward(const Matrix4x4Base<T>& matrix);

    static bool IsIdentity(const Matrix4x4Base<T>& matrix);

    static Matrix4x4Base<T> CreateLookAt(const Vector3Base<T>& eye, const Vector3Base<T>& target, const Vector3Base<T>& up);
    static Matrix4x4Base<T> CreatePerspective(T fov, T aspect, T znear, T zfar);
    static Matrix4x4Base<T> CreateOrtho(T width, T height, T znear, T zfar);
    static Matrix4x4Base<T> CreateOrthoOffCenter(T left, T right, T bottom, T top, T znear, T zfar);

    static Matrix4x4Base<T> CreateTranslation(const VectorBase<T, 3>& translation);
    static Matrix4x4Base<T> CreateScaling(const VectorBase<T, 3>& scale);
    static Matrix4x4Base<T> CreateRotationX(T angle);
    static Matrix4x4Base<T> CreateRotationY(T angle);
    static Matrix4x4Base<T> CreateRotationZ(T angle);
    static Matrix4x4Base<T> CreateRotation(const VectorBase<T, 3>& axis, T angle);
    static Matrix4x4Base<T> CreateRotation(const Quaternion& rotation);
    static Matrix4x4Base<T> CreateRotation(T yaw, T pitch, T roll);

    static Matrix4x4Base<T> CreateTransform(const VectorBase<T, 3>& translation, const Quaternion& rotation, const VectorBase<T, 3>& scaling);

public:
    /* Operators */
    void operator*=(const Matrix4x4Base<T>& other);
    Matrix4x4Base<T> operator*(const Matrix4x4Base<T>& other) const;

    void operator*=(T other);
    Matrix4x4Base<T> operator*(T other) const;

    Matrix4x4Base<T>& operator=(T value);
    Matrix4x4Base<T>& operator=(const T* data);
    Matrix4x4Base<T>& operator=(const Matrix4x4Base<T>& other);

public:
    /* Constant static members */
    static const Matrix4x4Base<T> Zero;
    static const Matrix4x4Base<T> Identity;
};

template <typename T>
void Matrix4x4Base<T>::Invert()
{
    T b0 = (m31 * m42) - (m32 * m41);
    T b1 = (m31 * m43) - (m33 * m41);
    T b2 = (m34 * m41) - (m31 * m44);
    T b3 = (m32 * m43) - (m33 * m42);
    T b4 = (m34 * m42) - (m32 * m44);
    T b5 = (m33 * m44) - (m34 * m43);

    T d11 = m22 * b5 + m23 * b4 + m24 * b3;
    T d12 = m21 * b5 + m23 * b2 + m24 * b1;
    T d13 = m21 * -b4 + m22 * b2 + m24 * b0;
    T d14 = m21 * b3 + m22 * -b1 + m23 * b0;

    T det = m11 * d11 - m12 * d12 + m13 * d13 - m14 * d14;

    if (Math::Abs(det) == 0.0f)
    {
        *this = Zero;
        return;
    }

    det = T(1.0) / det;

    T a0 = (m11 * m22) - (m12 * m21);
    T a1 = (m11 * m23) - (m13 * m21);
    T a2 = (m14 * m21) - (m11 * m24);
    T a3 = (m12 * m23) - (m13 * m22);
    T a4 = (m14 * m22) - (m12 * m24);
    T a5 = (m13 * m24) - (m14 * m23);

    T d21 = m12 * b5 + m13 * b4 + m14 * b3;
    T d22 = m11 * b5 + m13 * b2 + m14 * b1;
    T d23 = m11 * -b4 + m12 * b2 + m14 * b0;
    T d24 = m11 * b3 + m12 * -b1 + m13 * b0;

    T d31 = m42 * a5 + m43 * a4 + m44 * a3;
    T d32 = m41 * a5 + m43 * a2 + m44 * a1;
    T d33 = m41 * -a4 + m42 * a2 + m44 * a0;
    T d34 = m41 * a3 + m42 * -a1 + m43 * a0;

    T d41 = m32 * a5 + m33 * a4 + m34 * a3;
    T d42 = m31 * a5 + m33 * a2 + m34 * a1;
    T d43 = m31 * -a4 + m32 * a2 + m34 * a0;
    T d44 = m31 * a3 + m32 * -a1 + m33 * a0;

    m11 = +d11 * det; m12 = -d21 * det; m13 = +d31 * det; m14 = -d41 * det;
    m21 = -d12 * det; m22 = +d22 * det; m23 = -d32 * det; m24 = +d42 * det;
    m31 = +d13 * det; m32 = -d23 * det; m33 = +d33 * det; m34 = -d43 * det;
    m41 = -d14 * det; m42 = +d24 * det; m43 = -d34 * det; m44 = +d44 * det;
}

template <typename T>
void Matrix4x4Base<T>::Negate()
{
    auto temp = *this;

    m11 = -temp.m11;
    m12 = -temp.m12;
    m13 = -temp.m13;
    m14 = -temp.m14;
    m21 = -temp.m21;
    m22 = -temp.m22;
    m23 = -temp.m23;
    m24 = -temp.m24;
    m31 = -temp.m31;
    m32 = -temp.m32;
    m33 = -temp.m33;
    m34 = -temp.m34;
    m41 = -temp.m41;
    m42 = -temp.m42;
    m43 = -temp.m43;
    m44 = -temp.m44;
}

template <typename T>
float Matrix4x4Base<T>::Determinant()
{
    const T temp1 = (m33 * m44) - (m34 * m43);
    const T temp2 = (m32 * m44) - (m34 * m42);
    const T temp3 = (m32 * m43) - (m33 * m42);
    const T temp4 = (m31 * m44) - (m34 * m41);
    const T temp5 = (m31 * m43) - (m33 * m41);
    const T temp6 = (m31 * m42) - (m32 * m41);

    return ((((m11 * (((m22 * temp1) - (m23 * temp2)) + (m24 * temp3))) - (m12 * (((m21 * temp1) -
        (m23 * temp4)) + (m24 * temp5)))) + (m13 * (((m21 * temp2) - (m22 * temp4)) + (m24 * temp6)))) -
        (m14 * (((m21 * temp3) - (m22 * temp5)) + (m23 * temp6))));
}

template <typename T>
bool Matrix4x4Base<T>::IsIdentity()
{
    for(auto i = 0u; i < 4*4; i ++)
    {
        if (components[i] != Identity[i])
            return false;
    }

    return true;
}

template <typename T>
VectorBase<T, 3> Matrix4x4Base<T>::Translation()
{
    return Vector3Base<T>{ m41, m42, m43 };
}

template <typename T>
VectorBase<T, 3> Matrix4x4Base<T>::Scale()
{
    VectorBase<T, 3> scale;
    scale.x = Math::Sqrt((m11 * m11) + (m12 * m12) + (m13 * m13));
    scale.y = Math::Sqrt((m21 * m21) + (m22 * m22) + (m23 * m23));
    scale.z = Math::Sqrt((m31 * m31) + (m32 * m32) + (m33 * m33));
    return scale;
}

template <typename T>
void Matrix4x4Base<T>::DecomposeTransform(VectorBase<T, 3>& translation, Quaternion& rotation, VectorBase<T, 3>& scale)
{
    translation = Translation();
    scale = Scale();
    rotation = Quaternion::Rotation(*this);
}

template <typename T>
void Matrix4x4Base<T>::ComposeTransform(const VectorBase<T, 3>& translation, const Quaternion& rotation,
    const VectorBase<T, 3>& scale)
{
    auto matrix = Matrix4x4Base<T>::Translation(translation);
    matrix *= Matrix4x4Base<T>::CreateRotation(rotation);
    matrix *= Matrix4x4Base<T>::Scale(scale);

    *this = matrix;
}

template <typename T>
VectorBase<T, 3> Matrix4x4Base<T>::Up()
{
    return Vector3Base<T>{ m21, m22, m23 };
}

template <typename T>
VectorBase<T, 3> Matrix4x4Base<T>::Down()
{
    return Vector3Base<T>{ -m21, -m22, -m23 };
}

template <typename T>
VectorBase<T, 3> Matrix4x4Base<T>::Left()
{
    return Vector3Base<T>{ -m11, -m12, -m13 };
}

template <typename T>
VectorBase<T, 3> Matrix4x4Base<T>::Right()
{
    return Vector3Base<T>{ m11, m12, m13 };
}

template <typename T>
VectorBase<T, 3> Matrix4x4Base<T>::Forward()
{
    return Vector3Base<T>{ -m31, -m32, -m33 };
}

template <typename T>
VectorBase<T, 3> Matrix4x4Base<T>::Backward()
{
    return Vector3Base<T>{ m31, m32, m33 };
}

template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::Invert(const Matrix4x4Base<T>& matrix)
{
    auto result = matrix;
    result.Invert();
    return result;
}

template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::Transpose(const Matrix4x4Base<T>& matrix)
{
    auto result = matrix;
    result.Transpose();
    return result;
}

template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::Negate(const Matrix4x4Base<T>& matrix)
{
    auto result = matrix;
    result.Negate();
    return result;
}

template <typename T>
VectorBase<T, 3> Matrix4x4Base<T>::Translation(const Matrix4x4Base<T>& matrix)
{
    return matrix.Translation();
}

template <typename T>
VectorBase<T, 3> Matrix4x4Base<T>::Scale(const Matrix4x4Base<T>& matrix)
{
    return matrix.Scale();
}

template <typename T>
VectorBase<T, 3> Matrix4x4Base<T>::Up(const Matrix4x4Base<T>& matrix)
{
    return matrix.Up();
}

template <typename T>
VectorBase<T, 3> Matrix4x4Base<T>::Down(const Matrix4x4Base<T>& matrix)
{
    return matrix.Down();
}

template <typename T>
VectorBase<T, 3> Matrix4x4Base<T>::Left(const Matrix4x4Base<T>& matrix)
{
    return matrix.Left();
}

template <typename T>
VectorBase<T, 3> Matrix4x4Base<T>::Right(const Matrix4x4Base<T>& matrix)
{
    return matrix.Right();
}

template <typename T>
VectorBase<T, 3> Matrix4x4Base<T>::Forward(const Matrix4x4Base<T>& matrix)
{
    return matrix.Forward();
}

template <typename T>
VectorBase<T, 3> Matrix4x4Base<T>::Backward(const Matrix4x4Base<T>& matrix)
{
    return matrix.Backward();
}

template <typename T>
bool Matrix4x4Base<T>::IsIdentity(const Matrix4x4Base<T>& matrix)
{
    return matrix.IsIdentity();
}

template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::CreateLookAt(const Vector3Base<T>& eye, const Vector3Base<T>& target,
    const Vector3Base<T>& up)
{
    auto result = Identity;

    auto zAxis = target - eye;
    zAxis.Normalize();

    auto xAxis = Vector3Base<T>::Cross(up, zAxis);
    xAxis.Normalize();

    auto yAxis = Vector3Base<T>::Cross(zAxis, xAxis);

    result.m11 = xAxis.x;
    result.m12 = yAxis.x;
    result.m13 = zAxis.x;

    result.m21 = xAxis.y;
    result.m22 = yAxis.y;
    result.m23 = zAxis.y;

    result.m31 = xAxis.z;
    result.m32 = yAxis.z;
    result.m33 = zAxis.z;

    result.m41 = -Vector3Base<T>::Dot(xAxis, eye);
    result.m42 = -Vector3Base<T>::Dot(yAxis, eye);
    result.m43 = -Vector3Base<T>::Dot(zAxis, eye);

    return result;
}

template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::CreatePerspective(T fov, T aspect, T znear, T zfar)
{
    auto result = Zero;
    auto yScale = T(1.0) / tanf(fov * T(0.5));
    auto q = zfar / (zfar - znear);

    result.m11 = yScale / aspect;
    result.m22 = yScale;
    result.m33 = q;
    result.m34 = T(1.0);
    result.m43 = -q * znear;

    return result;
}

template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::CreateOrtho(T width, T height, T znear, T zfar)
{
    T halfWidth = width * T(0.5);
    T halfHeight = height * T(0.5);

    return CreateOrthoOffCenter(-halfWidth, halfWidth, -halfHeight, halfHeight, znear, zfar);
}

template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::CreateOrthoOffCenter(T left, T right, T bottom, T top, T znear, T zfar)
{
    auto result = Identity;

    T zRange = T(1.0) / (zfar - znear);

    result.m11 = T(2.0) / (right - left);
    result.m22 = T(2.0) / (top - bottom);
    result.m33 = zRange;
    result.m41 = (left + right) / (left - right);
    result.m42 = (top + bottom) / (bottom - top);
    result.m43 = -znear * zRange;

    return result;
}


template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::CreateTranslation(const VectorBase<T, 3>& translation)
{
    auto result = Identity;
    result.m41 = translation.x;
    result.m42 = translation.y;
    result.m43 = translation.z;
    return result;
}

template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::CreateScaling(const VectorBase<T, 3>& scale)
{
    auto result = Identity;
    result.m11 = scale.x;
    result.m22 = scale.y;
    result.m33 = scale.z;
    return result;
}

template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::CreateRotationX(T angle)
{
    T cos = Math::Cos(angle);
    T sin = Math::Sin(angle);

    auto result = Identity;
    result.m22 = cos;
    result.m23 = sin;
    result.m32 = -sin;
    result.m33 = cos;
    return result;
}

template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::CreateRotationY(T angle)
{
    T cos = Math::Cos(angle);
    T sin = Math::Sin(angle);

    auto result = Identity;
    result.m11 = cos;
    result.m13 = -sin;
    result.m31 = sin;
    result.m33 = cos;
    return result;
}

template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::CreateRotationZ(T angle)
{
    T cos = Math::Cos(angle);
    T sin = Math::Sin(angle);

    auto result = Identity;
    result.m11 = cos;
    result.m12 = sin;
    result.m21 = -sin;
    result.m22 = cos;
    return result;
}

template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::CreateRotation(const VectorBase<T, 3>& axis, T angle)
{
    const T x = axis.X;
    const T y = axis.Y;
    const T z = axis.Z;
    const T cos = Math::Cos(angle);
    const T sin = Math::Sin(angle);
    const T xx = x * x;
    const T yy = y * y;
    const T zz = z * z;
    const T xy = x * y;
    const T xz = x * z;
    const T yz = y * z;

    auto result = Identity;
    result.m11 = xx + (cos * (T(1.0) - xx));
    result.m12 = (xy - (cos * xy)) + (sin * z);
    result.m13 = (xz - (cos * xz)) - (sin * y);
    result.m21 = (xy - (cos * xy)) - (sin * z);
    result.m22 = yy + (cos * (T(1.0) - yy));
    result.m23 = (yz - (cos * yz)) + (sin * x);
    result.m31 = (xz - (cos * xz)) + (sin * y);
    result.m32 = (yz - (cos * yz)) - (sin * x);
    result.m33 = zz + (cos * (T(1.0) - zz));
    return result;
}

template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::CreateRotation(const Quaternion& rotation)
{
    const auto xx = T(rotation.X * rotation.X);
    const auto yy = T(rotation.Y * rotation.Y);
    const auto zz = T(rotation.Z * rotation.Z);
    const auto xy = T(rotation.X * rotation.Y);
    const auto zw = T(rotation.Z * rotation.W);
    const auto zx = T(rotation.Z * rotation.X);
    const auto yw = T(rotation.Y * rotation.W);
    const auto yz = T(rotation.Y * rotation.Z);
    const auto xw = T(rotation.X * rotation.W);

    auto result = Identity;
    result.m11 = T(1.0) - (T(2.0) * (yy + zz));
    result.m12 = T(2.0) * (xy + zw);
    result.m13 = T(2.0) * (zx - yw);
    result.m21 = T(2.0) * (xy - zw);
    result.m22 = T(1.0) - (T(2.0) * (zz + xx));
    result.m23 = T(2.0) * (yz + xw);
    result.m31 = T(2.0) * (zx + yw);
    result.m32 = T(2.0) * (yz - xw);
    result.m33 = T(1.0) - (T(2.0) * (yy + xx));
    return result;
}

template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::CreateRotation(T yaw, T pitch, T roll)
{
    return Matrix4x4Base<T>::CreateRotation(Quaternion::Rotation(yaw, pitch, roll));
}

template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::CreateTransform(const VectorBase<T, 3>& translation, const Quaternion& rotation,
    const VectorBase<T, 3>& scaling)
{
    return Matrix4x4Base<T>::CreateTranslation(translation) * Matrix4x4Base<T>::CreateRotation(rotation) * Matrix4x4Base<T>::CreateScaling(scaling);
}

template <typename T>
void Matrix4x4Base<T>::operator*=(const Matrix4x4Base<T>& other)
{
    const auto temp = *this;
    m11 = (temp.m11 * other.m11) + (temp.m12 * other.m21) + (temp.m13 * other.m31) + (temp.m14 * other.m41);
    m12 = (temp.m11 * other.m12) + (temp.m12 * other.m22) + (temp.m13 * other.m32) + (temp.m14 * other.m42);
    m13 = (temp.m11 * other.m13) + (temp.m12 * other.m23) + (temp.m13 * other.m33) + (temp.m14 * other.m43);
    m14 = (temp.m11 * other.m14) + (temp.m12 * other.m24) + (temp.m13 * other.m34) + (temp.m14 * other.m44);
    m21 = (temp.m21 * other.m11) + (temp.m22 * other.m21) + (temp.m23 * other.m31) + (temp.m24 * other.m41);
    m22 = (temp.m21 * other.m12) + (temp.m22 * other.m22) + (temp.m23 * other.m32) + (temp.m24 * other.m42);
    m23 = (temp.m21 * other.m13) + (temp.m22 * other.m23) + (temp.m23 * other.m33) + (temp.m24 * other.m43);
    m24 = (temp.m21 * other.m14) + (temp.m22 * other.m24) + (temp.m23 * other.m34) + (temp.m24 * other.m44);
    m31 = (temp.m31 * other.m11) + (temp.m32 * other.m21) + (temp.m33 * other.m31) + (temp.m34 * other.m41);
    m32 = (temp.m31 * other.m12) + (temp.m32 * other.m22) + (temp.m33 * other.m32) + (temp.m34 * other.m42);
    m33 = (temp.m31 * other.m13) + (temp.m32 * other.m23) + (temp.m33 * other.m33) + (temp.m34 * other.m43);
    m34 = (temp.m31 * other.m14) + (temp.m32 * other.m24) + (temp.m33 * other.m34) + (temp.m34 * other.m44);
    m41 = (temp.m41 * other.m11) + (temp.m42 * other.m21) + (temp.m43 * other.m31) + (temp.m44 * other.m41);
    m42 = (temp.m41 * other.m12) + (temp.m42 * other.m22) + (temp.m43 * other.m32) + (temp.m44 * other.m42);
    m43 = (temp.m41 * other.m13) + (temp.m42 * other.m23) + (temp.m43 * other.m33) + (temp.m44 * other.m43);
    m44 = (temp.m41 * other.m14) + (temp.m42 * other.m24) + (temp.m43 * other.m34) + (temp.m44 * other.m44);
}

template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::operator*(const Matrix4x4Base<T>& other) const
{
    auto temp = Matrix4x4Base<T>(0);
    temp.m11 = (this->m11 * other.m11) + (this->m12 * other.m21) + (this->m13 * other.m31) + (this->m14 * other.m41);
    temp.m12 = (this->m11 * other.m12) + (this->m12 * other.m22) + (this->m13 * other.m32) + (this->m14 * other.m42);
    temp.m13 = (this->m11 * other.m13) + (this->m12 * other.m23) + (this->m13 * other.m33) + (this->m14 * other.m43);
    temp.m14 = (this->m11 * other.m14) + (this->m12 * other.m24) + (this->m13 * other.m34) + (this->m14 * other.m44);
    temp.m21 = (this->m21 * other.m11) + (this->m22 * other.m21) + (this->m23 * other.m31) + (this->m24 * other.m41);
    temp.m22 = (this->m21 * other.m12) + (this->m22 * other.m22) + (this->m23 * other.m32) + (this->m24 * other.m42);
    temp.m23 = (this->m21 * other.m13) + (this->m22 * other.m23) + (this->m23 * other.m33) + (this->m24 * other.m43);
    temp.m24 = (this->m21 * other.m14) + (this->m22 * other.m24) + (this->m23 * other.m34) + (this->m24 * other.m44);
    temp.m31 = (this->m31 * other.m11) + (this->m32 * other.m21) + (this->m33 * other.m31) + (this->m34 * other.m41);
    temp.m32 = (this->m31 * other.m12) + (this->m32 * other.m22) + (this->m33 * other.m32) + (this->m34 * other.m42);
    temp.m33 = (this->m31 * other.m13) + (this->m32 * other.m23) + (this->m33 * other.m33) + (this->m34 * other.m43);
    temp.m34 = (this->m31 * other.m14) + (this->m32 * other.m24) + (this->m33 * other.m34) + (this->m34 * other.m44);
    temp.m41 = (this->m41 * other.m11) + (this->m42 * other.m21) + (this->m43 * other.m31) + (this->m44 * other.m41);
    temp.m42 = (this->m41 * other.m12) + (this->m42 * other.m22) + (this->m43 * other.m32) + (this->m44 * other.m42);
    temp.m43 = (this->m41 * other.m13) + (this->m42 * other.m23) + (this->m43 * other.m33) + (this->m44 * other.m43);
    temp.m44 = (this->m41 * other.m14) + (this->m42 * other.m24) + (this->m43 * other.m34) + (this->m44 * other.m44);
    return temp;
}

template <typename T>
void Matrix4x4Base<T>::operator*=(T other)
{
    m11 *= other;
    m12 *= other;
    m13 *= other;
    m14 *= other;
    m21 *= other;
    m22 *= other;
    m23 *= other;
    m24 *= other;
    m31 *= other;
    m32 *= other;
    m33 *= other;
    m34 *= other;
    m41 *= other;
    m42 *= other;
    m43 *= other;
    m44 *= other;
}

template <typename T>
Matrix4x4Base<T> Matrix4x4Base<T>::operator*(T other) const
{
    auto result = Zero;
    result.m11 = this->m11 * other;
    result.m12 = this->m12 * other;
    result.m13 = this->m13 * other;
    result.m14 = this->m14 * other;
    result.m21 = this->m21 * other;
    result.m22 = this->m22 * other;
    result.m23 = this->m23 * other;
    result.m24 = this->m24 * other;
    result.m31 = this->m31 * other;
    result.m32 = this->m32 * other;
    result.m33 = this->m33 * other;
    result.m34 = this->m34 * other;
    result.m41 = this->m41 * other;
    result.m42 = this->m42 * other;
    result.m43 = this->m43 * other;
    result.m44 = this->m44 * other;

    return result;
}

template <typename T>
Matrix4x4Base<T>& Matrix4x4Base<T>::operator=(T value)
{
    auto result = Zero;
    result.m11 = value;
    result.m12 = value;
    result.m13 = value;
    result.m14 = value;
    result.m21 = value;
    result.m22 = value;
    result.m23 = value;
    result.m24 = value;
    result.m31 = value;
    result.m32 = value;
    result.m33 = value;
    result.m34 = value;
    result.m41 = value;
    result.m42 = value;
    result.m43 = value;
    result.m44 = value;

    return result;
}

template <typename T>
Matrix4x4Base<T>& Matrix4x4Base<T>::operator=(const T* data)
{
    auto result = Zero;
    memcpy(&result, data, sizeof(components));
    return result;
}

template <typename T>
Matrix4x4Base<T>& Matrix4x4Base<T>::operator=(const Matrix4x4Base<T>& other)
{
    auto result = Zero;
    memcpy(&result, &other, sizeof(components));
    return result;
}

template <typename T>
void Matrix4x4Base<T>::Transpose()
{
    auto temp = *this;

    m11 = temp.m11;
    m12 = temp.m21;
    m13 = temp.m31;
    m14 = temp.m41;

    m21 = temp.m12;
    m22 = temp.m22;
    m23 = temp.m32;
    m24 = temp.m42;

    m31 = temp.m13;
    m32 = temp.m23;
    m33 = temp.m33;
    m34 = temp.m43;

    m41 = temp.m14;
    m42 = temp.m24;
    m43 = temp.m34;
    m44 = temp.m44;
}

template <typename T>
const Matrix4x4Base<T> Matrix4x4Base<T>::Zero = Matrix4x4Base<T>(0);

template <typename T>
const Matrix4x4Base<T> Matrix4x4Base<T>::Identity = Matrix4x4Base<T>(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

#endif // MATRIX4X4BASE_H
