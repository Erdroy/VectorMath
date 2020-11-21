// VectorMath (c) 2018-2020 Damian 'Erdroy' Korczowski

#pragma once

#include "VectorBase.h"

template<typename T>
struct Vector4Base : VectorBase<T, 4>
{
protected:
    /* Protected usings */
    using VectorComponents<T, 4>::components;
#if USE_UPPERCASE_COMPONENTS
    using VectorComponents<T, 4>::x;
    using VectorComponents<T, 4>::y;
    using VectorComponents<T, 4>::z;
    using VectorComponents<T, 4>::w;
#else
    using VectorComponents<T, 4>::X;
    using VectorComponents<T, 4>::Y;
    using VectorComponents<T, 4>::Z;
    using VectorComponents<T, 4>::W;
#endif

public:
    /* Public usings */
#if USE_UPPERCASE_COMPONENTS
    using VectorComponents<T, 4>::X;
    using VectorComponents<T, 4>::Y;
    using VectorComponents<T, 4>::Z;
    using VectorComponents<T, 4>::W;
#else
    using VectorComponents<T, 4>::x;
    using VectorComponents<T, 4>::y;
    using VectorComponents<T, 4>::z;
    using VectorComponents<T, 4>::w;
#endif

public:
    /* Constructors */
    Vector4Base() = default;

    explicit Vector4Base(T value)
    {
        components[0] = value;
        components[1] = value;
        components[2] = value;
        components[3] = value;
    }

    Vector4Base(T x, T y, T z, T w)
    {
        components[0] = x;
        components[1] = y;
        components[2] = z;
        components[3] = w;
    }

public:
    /* Public members */
    void Negate();
    void Normalize();

    Vector4Base<T> Normalized() const;
    bool IsNormalized() const;
    bool IsZero() const;
    bool IsNaN() const;
    bool IsInfinity() const;

    T Dot(const Vector4Base<T>& a) const;
    T Length() const;
    T LengthSquared() const;

public:
    /* Public static members */
    static Vector4Base<T> Normalize(const Vector4Base<T>& a);
    static Vector4Base<T> Negate(const Vector4Base<T>& a);
    static Vector4Base<T> Abs(const Vector4Base<T>& a);
    static Vector4Base<T> Lerp(const Vector4Base<T>& from, const Vector4Base<T>& to, T amount);
    static Vector4Base<T> Transform(const Vector4Base<T>& a, const Quaternion& rotation);
    static Vector4Base<T> Transform(const Vector4Base<T>& a, const MatrixBase<T, 4, 4>& matrix);

    static T Dot(const Vector4Base<T>& a, const Vector4Base<T>& b);
    static T Length(const Vector4Base<T>& a);
    static T LengthSquared(const Vector4Base<T>& a);
    static T Distance(const Vector4Base<T>& a, const Vector4Base<T>& b);
    static T DistanceSquared(const Vector4Base<T>& a, const Vector4Base<T>& b);

    static bool NearEqual(const Vector4Base<T>& a, const Vector4Base<T>& b);

    static bool IsNormalized(const Vector4Base<T>& a);
    static bool IsZero(const Vector4Base<T>& a);
    static bool IsNaN(const Vector4Base<T>& a);
    static bool IsInfinity(const Vector4Base<T>& a);

public:
    /* Operators */
    void operator+=(const Vector4Base<T>& other);
    void operator-=(const Vector4Base<T>& other);
    void operator*=(const Vector4Base<T>& other);
    void operator/=(const Vector4Base<T>& other);

    Vector4Base<T> operator+(const Vector4Base<T>& other) const;
    Vector4Base<T> operator-(const Vector4Base<T>& other) const;
    Vector4Base<T> operator*(const Vector4Base<T>& other) const;
    Vector4Base<T> operator/(const Vector4Base<T>& other) const;

    void operator+=(T other);
    void operator-=(T other);
    void operator*=(T other);
    void operator/=(T other);

    Vector4Base<T> operator+(T other) const;
    Vector4Base<T> operator-(T other) const;
    Vector4Base<T> operator*(T other) const;
    Vector4Base<T> operator/(T other) const;

    Vector4Base<T> operator-() const;

    bool operator==(const Vector4Base<T>& other) const;
    bool operator!=(const Vector4Base<T>& other) const;
    bool operator<(const Vector4Base<T>& other) const;
    bool operator>(const Vector4Base<T>& other) const;
    bool operator<=(const Vector4Base<T>& other) const;
    bool operator>=(const Vector4Base<T>& other) const;

    Vector4Base<T>& operator=(T value);
    Vector4Base<T>& operator=(const T* data);
    Vector4Base<T>& operator=(const Vector4Base<T>& other);

public:
    /* Constant static members */
    static const Vector4Base<T> Up;
    static const Vector4Base<T> Down;
    static const Vector4Base<T> Left;
    static const Vector4Base<T> Right;
    static const Vector4Base<T> Forward;
    static const Vector4Base<T> Back;

    static const Vector4Base<T> One;
    static const Vector4Base<T> Zero;

    static const Vector4Base<T> UnitX;
    static const Vector4Base<T> UnitY;
    static const Vector4Base<T> UnitZ;
    static const Vector4Base<T> UnitW;
};

template<typename T>
const Vector4Base<T> Vector4Base<T>::Up(0, 1.0, 0, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::Down(0, -1, 0, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::Left(-1, 0, 0, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::Right(1, 0, 0, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::Forward(0, 0, 1, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::Back(0, 0, -1, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::One(1);

template<typename T>
const Vector4Base<T> Vector4Base<T>::Zero(0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::UnitX(1, 0, 0, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::UnitY(0, 1, 0, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::UnitZ(0, 0, 1, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::UnitW(0, 0, 0, 1);

template <typename T>
void Vector4Base<T>::Negate()
{
    x = -x;
    y = -y;
    z = -z;
    w = -w;
}

template <typename T>
void Vector4Base<T>::Normalize()
{
    T lenSqr = LengthSquared();

    if (Math::IsZero(lenSqr))
        return;

    T invLength = T(1) / Math::Sqrt(lenSqr);

    x *= invLength;
    y *= invLength;
    z *= invLength;
    w *= invLength;
}

template <typename T>
Vector4Base<T> Vector4Base<T>::Normalized() const
{
    return Normalize(*this);
}

template <typename T>
bool Vector4Base<T>::IsNormalized() const
{
    return IsNormalized(*this);
}

template <typename T>
bool Vector4Base<T>::IsZero() const
{
    return IsZero(*this);
}

template <typename T>
bool Vector4Base<T>::IsNaN() const
{
    return isnan(x) || isnan(y) || isnan(z) || isnan(w);
}

template <typename T>
bool Vector4Base<T>::IsInfinity() const
{
    return isinf(x) || isinf(y) || isinf(z) || isinf(w);
}

template <typename T>
T Vector4Base<T>::Dot(const Vector4Base<T>& a) const
{
    return (x * a.x) + (y * a.y) + (z * a.z) + (w * a.w);
}

template <typename T>
T Vector4Base<T>::Length() const
{
    return Math::Sqrt(LengthSquared());
}

template <typename T>
T Vector4Base<T>::LengthSquared() const
{
    return (x * x) + (y * y) + (z * z) + (w * w);
}

template <typename T>
Vector4Base<T> Vector4Base<T>::Normalize(const Vector4Base<T>& a)
{
    Vector3Base<T> result = a;
    result.Normalize();
    return result;
}

template <typename T>
Vector4Base<T> Vector4Base<T>::Negate(const Vector4Base<T>& a)
{
    Vector3Base<T> result = a;
    result.Negate();
    return result;
}

template <typename T>
Vector4Base<T> Vector4Base<T>::Abs(const Vector4Base<T>& a)
{
    Vector3Base<T> result = a;
    result.x = Math::Abs(result.x);
    result.y = Math::Abs(result.y);
    result.z = Math::Abs(result.z);
    result.w = Math::Abs(result.w);
    return result;
}

template <typename T>
Vector4Base<T> Vector4Base<T>::Lerp(const Vector4Base<T>& from, const Vector4Base<T>& to, T amount)
{
    return Math::Lerp(from, to, amount);
}

template <typename T>
Vector4Base<T> Vector4Base<T>::Transform(const Vector4Base<T>& a, const Quaternion& rotation)
{
    const auto x = T(rotation.X + rotation.X);
    const auto y = T(rotation.Y + rotation.Y);
    const auto z = T(rotation.Z + rotation.Z);
    const auto wx = T(rotation.W * x);
    const auto wy = T(rotation.W * y);
    const auto wz = T(rotation.W * z);
    const auto xx = T(rotation.X * x);
    const auto xy = T(rotation.X * y);
    const auto xz = T(rotation.X * z);
    const auto yy = T(rotation.Y * y);
    const auto yz = T(rotation.Y * z);
    const auto zz = T(rotation.Z * z);

    return Vector4Base<T>(
        ((a.x * ((T(1) - yy) - zz)) + (a.y * (xy - wz))) + (a.z * (xz + wy)),
        ((a.x * (xy + wz)) + (a.y * ((T(1) - xx) - zz))) + (a.z * (yz - wx)),
        ((a.x * (xz - wy)) + (a.y * (yz + wx))) + (a.z * ((T(1) - xx) - yy)),
        a.w
    );
}

template <typename T>
Vector4Base<T> Vector4Base<T>::Transform(const Vector4Base<T>& a, const MatrixBase<T, 4, 4>& matrix)
{
    return Vector4Base<T>(
        (a.x * matrix.m11) + (a.y * matrix.m21) + (a.z * matrix.m31) + (a.w * matrix.m41),
        (a.x * matrix.m12) + (a.y * matrix.m22) + (a.z * matrix.m32) + (a.w * matrix.m42),
        (a.x * matrix.m13) + (a.y * matrix.m23) + (a.z * matrix.m33) + (a.w * matrix.m43),
        (a.x * matrix.m14) + (a.y * matrix.m24) + (a.z * matrix.m34) + (a.w * matrix.m44));
}

template <typename T>
T Vector4Base<T>::Dot(const Vector4Base<T>& a, const Vector4Base<T>& b)
{
    return a.Dot(b);
}

template <typename T>
T Vector4Base<T>::Length(const Vector4Base<T>& a)
{
    return a.Length();
}

template <typename T>
T Vector4Base<T>::LengthSquared(const Vector4Base<T>& a)
{
    return a.LengthSquared();
}

template <typename T>
T Vector4Base<T>::Distance(const Vector4Base<T>& a, const Vector4Base<T>& b)
{
    return Math::Sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z) + (b.w - a.w) * (b.w - a.w));
}

template <typename T>
T Vector4Base<T>::DistanceSquared(const Vector4Base<T>& a, const Vector4Base<T>& b)
{
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z) + (b.w - a.w) * (b.w - a.w);
}

template <typename T>
bool Vector4Base<T>::NearEqual(const Vector4Base<T>& a, const Vector4Base<T>& b)
{
    return Math::NearEqual(a.x, b.x) && Math::NearEqual(a.y, b.y) && Math::NearEqual(a.z, b.z) && Math::NearEqual(a.w, b.w);
}

template <typename T>
bool Vector4Base<T>::IsNormalized(const Vector4Base<T>& a)
{
    return Math::IsOne(a.LengthSquared());
}

template <typename T>
bool Vector4Base<T>::IsZero(const Vector4Base<T>& a)
{
    return a.x == 0 && a.y == 0 && a.z == 0 && a.w == 0;
}

template <typename T>
bool Vector4Base<T>::IsNaN(const Vector4Base<T>& a)
{
    return a.IsNaN();
}

template <typename T>
bool Vector4Base<T>::IsInfinity(const Vector4Base<T>& a)
{
    return a.IsInfinity();
}

template <typename T>
void Vector4Base<T>::operator+=(const Vector4Base<T>& other)
{
    components[0] += other[0];
    components[1] += other[1];
    components[2] += other[2];
    components[3] += other[3];
}

template <typename T>
void Vector4Base<T>::operator-=(const Vector4Base<T>& other)
{
    components[0] -= other[0];
    components[1] -= other[1];
    components[2] -= other[2];
    components[3] -= other[3];
}

template <typename T>
void Vector4Base<T>::operator*=(const Vector4Base<T>& other)
{
    components[0] *= other[0];
    components[1] *= other[1];
    components[2] *= other[2];
    components[3] *= other[3];
}

template <typename T>
void Vector4Base<T>::operator/=(const Vector4Base<T>& other)
{
    components[0] /= other[0];
    components[1] /= other[1];
    components[2] /= other[2];
    components[3] /= other[3];
}

template <typename T>
Vector4Base<T> Vector4Base<T>::operator+(const Vector4Base<T>& other) const
{
    return Vector4Base<T>(
        components[0] + other[0],
        components[1] + other[1],
        components[2] + other[2],
        components[3] + other[3]
    );
}

template <typename T>
Vector4Base<T> Vector4Base<T>::operator-(const Vector4Base<T>& other) const
{
    return Vector4Base<T>(
        components[0] - other[0],
        components[1] - other[1],
        components[2] - other[2],
        components[3] - other[3]
    );
}

template <typename T>
Vector4Base<T> Vector4Base<T>::operator*(const Vector4Base<T>& other) const
{
    return Vector4Base<T>(
        components[0] * other[0],
        components[1] * other[1],
        components[2] * other[2],
        components[3] * other[3]
    );
}

template <typename T>
Vector4Base<T> Vector4Base<T>::operator/(const Vector4Base<T>& other) const
{
    return Vector4Base<T>(
        components[0] / other[0],
        components[1] / other[1],
        components[2] / other[2],
        components[3] / other[3]
    );
}

template <typename T>
void Vector4Base<T>::operator+=(T other)
{
    components[0] += other;
    components[1] += other;
    components[2] += other;
    components[3] += other;
}

template <typename T>
void Vector4Base<T>::operator-=(T other)
{
    components[0] -= other;
    components[1] -= other;
    components[2] -= other;
    components[3] -= other;
}

template <typename T>
void Vector4Base<T>::operator*=(T other)
{
    components[0] *= other;
    components[1] *= other;
    components[2] *= other;
    components[3] *= other;
}

template <typename T>
void Vector4Base<T>::operator/=(T other)
{
    components[0] /= other;
    components[1] /= other;
    components[2] /= other;
    components[3] /= other;
}

template <typename T>
Vector4Base<T> Vector4Base<T>::operator+(T other) const
{
    return Vector4Base<T>(
        components[0] + other,
        components[1] + other,
        components[2] + other,
        components[3] + other
    );
}

template <typename T>
Vector4Base<T> Vector4Base<T>::operator-(T other) const
{
    return Vector4Base<T>(
        components[0] - other,
        components[1] - other,
        components[2] - other,
        components[3] - other
    );
}

template <typename T>
Vector4Base<T> Vector4Base<T>::operator*(T other) const
{
    return Vector4Base<T>(
        components[0] * other,
        components[1] * other,
        components[2] * other,
        components[3] * other
    );
}

template <typename T>
Vector4Base<T> Vector4Base<T>::operator/(T other) const
{
    return Vector4Base<T>(
        components[0] / other,
        components[1] / other,
        components[2] / other,
        components[3] / other
    );
}

template <typename T>
Vector4Base<T> Vector4Base<T>::operator-() const
{
    return Vector4Base<T>(
        -components[0],
        -components[1],
        -components[2],
        -components[3]
    );
}

template <typename T>
bool Vector4Base<T>::operator==(const Vector4Base<T>& other) const
{
    return
        components[0] == other[0] &&
        components[1] == other[1] &&
        components[2] == other[2] &&
        components[3] == other[3];
}

template <typename T>
bool Vector4Base<T>::operator!=(const Vector4Base<T>& other) const
{
    return
        components[0] != other[0] ||
        components[1] != other[1] ||
        components[2] != other[2] ||
        components[3] != other[3];
}

template <typename T>
bool Vector4Base<T>::operator<(const Vector4Base<T>& other) const
{
    return
        components[0] < other[0] &&
        components[1] < other[1] &&
        components[2] < other[2] &&
        components[3] < other[3];
}

template <typename T>
bool Vector4Base<T>::operator>(const Vector4Base<T>& other) const
{
    return
        components[0] > other[0] &&
        components[1] > other[1] &&
        components[2] > other[2] &&
        components[3] > other[3];
}

template <typename T>
bool Vector4Base<T>::operator<=(const Vector4Base<T>& other) const
{
    return
        components[0] <= other[0] &&
        components[1] <= other[1] &&
        components[2] <= other[2] &&
        components[3] <= other[3];
}

template <typename T>
bool Vector4Base<T>::operator>=(const Vector4Base<T>& other) const
{
    return
        components[0] >= other[0] &&
        components[1] >= other[1] &&
        components[2] >= other[2] &&
        components[3] >= other[3];
}

template <typename T>
Vector4Base<T>& Vector4Base<T>::operator=(T value)
{
    components[0] = value;
    components[1] = value;
    components[2] = value;
    components[3] = value;
    return *this;
}

template <typename T>
Vector4Base<T>& Vector4Base<T>::operator=(const T* data)
{
    return *static_cast<Vector4Base<T>*>(data);
}

template <typename T>
Vector4Base<T>& Vector4Base<T>::operator=(const Vector4Base<T>& other)
{
    components[0] = other[0];
    components[1] = other[1];
    components[2] = other[2];
    components[3] = other[3];
    return *this;
}
