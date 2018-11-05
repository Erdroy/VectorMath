// VectorMath (c) 2018 Damian 'Erdroy' Korczowski

#pragma once

#ifndef VECTOR3_H
#define VECTOR3_H

#include "VectorBase.h"
#include "Quaternion.h"

template<typename T>
struct Vector3Base : VectorBase<T, 3>
{
protected:
    /* Protected usings */
    using VectorComponents<T, 3>::components;
#if USE_UPPERCASE_COMPONENTS
    using VectorComponents<T, 3>::x;
    using VectorComponents<T, 3>::y;
    using VectorComponents<T, 3>::z;
#else
    using VectorComponents<T, 3>::X;
    using VectorComponents<T, 3>::Y;
    using VectorComponents<T, 3>::Z;
#endif

public:
    /* Public usings */
#if USE_UPPERCASE_COMPONENTS
    using VectorComponents<T, 3>::X;
    using VectorComponents<T, 3>::Y;
    using VectorComponents<T, 3>::Z;
#else
    using VectorComponents<T, 3>::x;
    using VectorComponents<T, 3>::y;
    using VectorComponents<T, 3>::z;
#endif

public:
    /* Constructors */
    Vector3Base() = default;

    explicit Vector3Base(T value)
    {
        components[0] = value;
        components[1] = value;
        components[2] = value;
    }

    Vector3Base(T x, T y, T z)
    {
        components[0] = x;
        components[1] = y;
        components[2] = z;
    }

public:
    /* Public members */
    void Negate();
    void Normalize();

    Vector3Base<T> Normalized() const;
    bool IsNormalized() const;
    bool IsZero() const;

    T Dot(const Vector3Base<T>& a) const;
    T Length() const;
    T LengthSquared() const;

public:
    /* Public static members */
    static Vector3Base<T> Normalize(const Vector3Base<T>& a);
    static Vector3Base<T> Negate(const Vector3Base<T>& a);
    static Vector3Base<T> Abs(const Vector3Base<T>& a);
    static Vector3Base<T> Lerp(const Vector3Base<T>& from, const Vector3Base<T>& to, T amount);
    static Vector3Base<T> Cross(const Vector3Base<T>& a, const Vector3Base<T>& b);
    static Vector3Base<T> Transform(const Vector3Base<T>& a, const Quaternion& rotation);

    static T Dot(const Vector3Base<T>& a, const Vector3Base<T>& b);
    static T Length(const Vector3Base<T>& a);
    static T LengthSquared(const Vector3Base<T>& a);
    static T Distance(const Vector3Base<T>& a, const Vector3Base<T>& b);
    static T DistanceSquared(const Vector3Base<T>& a, const Vector3Base<T>& b);

    static bool IsNormalized(const Vector3Base<T>& a);
    static bool IsZero(const Vector3Base<T>& a);

public:
    /* Operators */
    void operator+=(const Vector3Base<T>& other);
    void operator-=(const Vector3Base<T>& other);
    void operator*=(const Vector3Base<T>& other);
    void operator/=(const Vector3Base<T>& other);

    Vector3Base<T> operator+(const Vector3Base<T>& other) const;
    Vector3Base<T> operator-(const Vector3Base<T>& other) const;
    Vector3Base<T> operator*(const Vector3Base<T>& other) const;
    Vector3Base<T> operator/(const Vector3Base<T>& other) const;

    void operator+=(T other);
    void operator-=(T other);
    void operator*=(T other);
    void operator/=(T other);

    Vector3Base<T> operator+(T other) const;
    Vector3Base<T> operator-(T other) const;
    Vector3Base<T> operator*(T other) const;
    Vector3Base<T> operator/(T other) const;

    Vector3Base<T> operator-() const;

    bool operator==(const Vector3Base<T>& other) const;
    bool operator!=(const Vector3Base<T>& other) const;
    bool operator<(const Vector3Base<T>& other) const;
    bool operator>(const Vector3Base<T>& other) const;
    bool operator<=(const Vector3Base<T>& other) const;
    bool operator>=(const Vector3Base<T>& other) const;

    Vector3Base<T>& operator=(T value);
    Vector3Base<T>& operator=(const T* data);
    Vector3Base<T>& operator=(const Vector3Base<T>& other);

public:
    /* Combined Accessors */
    VectorBase<T, 3> xxx() { return VectorBase<T, 3>(components[0], components[0], components[0]); }
    VectorBase<T, 3> yyy() { return VectorBase<T, 3>(components[1], components[1], components[1]); }
    VectorBase<T, 3> zzz() { return VectorBase<T, 3>(components[2], components[2], components[2]); }

public:
    /* Constant static members */
    static const Vector3Base<T> Up;
    static const Vector3Base<T> Down;
    static const Vector3Base<T> Left;
    static const Vector3Base<T> Right;
    static const Vector3Base<T> Forward;
    static const Vector3Base<T> Back;

    static const Vector3Base<T> One;
    static const Vector3Base<T> Zero;

    static const Vector3Base<T> UnitX;
    static const Vector3Base<T> UnitY;
    static const Vector3Base<T> UnitZ;
};

template<typename T>
const Vector3Base<T> Vector3Base<T>::Up(0, 1.0, 0);

template<typename T>
const Vector3Base<T> Vector3Base<T>::Down(0, -1, 0);

template<typename T>
const Vector3Base<T> Vector3Base<T>::Left(-1, 0, 0);

template<typename T>
const Vector3Base<T> Vector3Base<T>::Right(1, 0, 0);

template<typename T>
const Vector3Base<T> Vector3Base<T>::Forward(-1, 0, 1);

template<typename T>
const Vector3Base<T> Vector3Base<T>::Back(1, 0, -1);

template<typename T>
const Vector3Base<T> Vector3Base<T>::One(1);

template<typename T>
const Vector3Base<T> Vector3Base<T>::Zero(0);

template<typename T>
const Vector3Base<T> Vector3Base<T>::UnitX(1, 0, 0);

template<typename T>
const Vector3Base<T> Vector3Base<T>::UnitY(0, 1, 0);

template<typename T>
const Vector3Base<T> Vector3Base<T>::UnitZ(0, 0, 1);

template <typename T>
void Vector3Base<T>::Negate()
{
    x = -x;
    y = -y;
    z = -z;
}

template <typename T>
void Vector3Base<T>::Normalize()
{
    T invLength = T(1) / Length();

    x *= invLength;
    y *= invLength;
    z *= invLength;
}

template <typename T>
Vector3Base<T> Vector3Base<T>::Normalized() const
{
    return Normalize(*this);
}

template <typename T>
bool Vector3Base<T>::IsNormalized() const
{
    return IsNormalized(*this);
}

template <typename T>
bool Vector3Base<T>::IsZero() const
{
    return IsZero(*this);
}

template <typename T>
T Vector3Base<T>::Dot(const Vector3Base<T>& a) const
{
    return (x * a.x) + (y * a.y) + (z * a.z);
}

template <typename T>
T Vector3Base<T>::Length() const
{
    return Math::Sqrt(LengthSquared());
}

template <typename T>
T Vector3Base<T>::LengthSquared() const
{
    return (x * x) + (y * y) + (z * z);
}

template <typename T>
Vector3Base<T> Vector3Base<T>::Normalize(const Vector3Base<T>& a)
{
    Vector3Base<T> result = a;
    result.Normalize();
    return result;
}

template <typename T>
Vector3Base<T> Vector3Base<T>::Negate(const Vector3Base<T>& a)
{
    Vector3Base<T> result = a;
    result.Negate();
    return result;
}

template <typename T>
Vector3Base<T> Vector3Base<T>::Abs(const Vector3Base<T>& a)
{
    Vector3Base<T> result = a;
    result.x = Math::Abs(result.x);
    result.y = Math::Abs(result.y);
    result.z = Math::Abs(result.z);
    return result;
}

template <typename T>
Vector3Base<T> Vector3Base<T>::Lerp(const Vector3Base<T>& from, const Vector3Base<T>& to, T amount)
{
    return Math::Lerp(from, to, amount);
}

template <typename T>
Vector3Base<T> Vector3Base<T>::Cross(const Vector3Base<T>& a, const Vector3Base<T>& b)
{
    return Vector3Base<T>(
        (a.y * b.z) - (a.z * b.y),
        (a.z * b.x) - (a.x * b.z),
        (a.x * b.y) - (a.y * b.x)
    );
}

template <typename T>
Vector3Base<T> Vector3Base<T>::Transform(const Vector3Base<T>& a, const Quaternion& rotation)
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

    return Vector3Base<T>(
        ((a.x * ((T(1) - yy) - zz)) + (a.y * (xy - wz))) + (a.z * (xz + wy)),
        ((a.x * (xy + wz)) + (a.y * ((T(1) - xx) - zz))) + (a.z * (yz - wx)),
        ((a.x * (xz - wy)) + (a.y * (yz + wx))) + (a.z * ((T(1) - xx) - yy))
    );
}

template <typename T>
T Vector3Base<T>::Dot(const Vector3Base<T>& a, const Vector3Base<T>& b)
{
    return a.Dot(b);
}

template <typename T>
T Vector3Base<T>::Length(const Vector3Base<T>& a)
{
    return a.Length();
}

template <typename T>
T Vector3Base<T>::LengthSquared(const Vector3Base<T>& a)
{
    return a.LengthSquared();
}

template <typename T>
T Vector3Base<T>::Distance(const Vector3Base<T>& a, const Vector3Base<T>& b)
{
    return Math::Sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z));
}

template <typename T>
T Vector3Base<T>::DistanceSquared(const Vector3Base<T>& a, const Vector3Base<T>& b)
{
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z);
}

template <typename T>
bool Vector3Base<T>::IsNormalized(const Vector3Base<T>& a)
{
    return Math::IsOne(a.LengthSquared());
}

template <typename T>
bool Vector3Base<T>::IsZero(const Vector3Base<T>& a)
{
    return a.x == 0 && a.y == 0 && a.z == 0;
}

template <typename T>
void Vector3Base<T>::operator+=(const Vector3Base<T>& other)
{
    components[0] += other[0];
    components[1] += other[1];
    components[2] += other[2];
}

template <typename T>
void Vector3Base<T>::operator-=(const Vector3Base<T>& other)
{
    components[0] -= other[0];
    components[1] -= other[1];
    components[2] -= other[2];
}

template <typename T>
void Vector3Base<T>::operator*=(const Vector3Base<T>& other)
{
    components[0] *= other[0];
    components[1] *= other[1];
    components[2] *= other[2];
}

template <typename T>
void Vector3Base<T>::operator/=(const Vector3Base<T>& other)
{
    components[0] /= other[0];
    components[1] /= other[1];
    components[2] /= other[2];
}

template <typename T>
Vector3Base<T> Vector3Base<T>::operator+(const Vector3Base<T>& other) const
{
    return Vector3Base<T>(
        components[0] + other[0],
        components[1] + other[1],
        components[2] + other[2]
    );
}

template <typename T>
Vector3Base<T> Vector3Base<T>::operator-(const Vector3Base<T>& other) const
{
    return Vector3Base<T>(
        components[0] - other[0],
        components[1] - other[1],
        components[2] - other[2]
    );
}

template <typename T>
Vector3Base<T> Vector3Base<T>::operator*(const Vector3Base<T>& other) const
{
    return Vector3Base<T>(
        components[0] * other[0],
        components[1] * other[1],
        components[2] * other[2]
    );
}

template <typename T>
Vector3Base<T> Vector3Base<T>::operator/(const Vector3Base<T>& other) const
{
    return Vector3Base<T>(
        components[0] / other[0],
        components[1] / other[1],
        components[2] / other[2]
    );
}

template <typename T>
void Vector3Base<T>::operator+=(T other)
{
    components[0] += other;
    components[1] += other;
    components[2] += other;
}

template <typename T>
void Vector3Base<T>::operator-=(T other)
{
    components[0] -= other;
    components[1] -= other;
    components[2] -= other;
}

template <typename T>
void Vector3Base<T>::operator*=(T other)
{
    components[0] *= other;
    components[1] *= other;
    components[2] *= other;
}

template <typename T>
void Vector3Base<T>::operator/=(T other)
{
    components[0] /= other;
    components[1] /= other;
    components[2] /= other;
}

template <typename T>
Vector3Base<T> Vector3Base<T>::operator+(T other) const
{
    return Vector3Base<T>(
        components[0] + other,
        components[1] + other,
        components[2] + other
    );
}

template <typename T>
Vector3Base<T> Vector3Base<T>::operator-(T other) const
{
    return Vector3Base<T>(
        components[0] - other,
        components[1] - other,
        components[2] - other
    );
}

template <typename T>
Vector3Base<T> Vector3Base<T>::operator*(T other) const
{
    return Vector3Base<T>(
        components[0] * other,
        components[1] * other,
        components[2] * other
    );
}

template <typename T>
Vector3Base<T> Vector3Base<T>::operator/(T other) const
{
    return Vector3Base<T>(
        components[0] / other,
        components[1] / other,
        components[2] / other
    );
}

template <typename T>
Vector3Base<T> Vector3Base<T>::operator-() const
{
    return Vector3Base<T>(
        -components[0],
        -components[1],
        -components[2]
    );
}

template <typename T>
bool Vector3Base<T>::operator==(const Vector3Base<T>& other) const
{
    return
        components[0] == other[0] &&
        components[1] == other[1] &&
        components[2] == other[2];
}

template <typename T>
bool Vector3Base<T>::operator!=(const Vector3Base<T>& other) const
{
    return
        components[0] != other[0] ||
        components[1] != other[1] ||
        components[2] != other[2];
}

template <typename T>
bool Vector3Base<T>::operator<(const Vector3Base<T>& other) const
{
    return
        components[0] < other[0] &&
        components[1] < other[1] &&
        components[2] < other[2];
}

template <typename T>
bool Vector3Base<T>::operator>(const Vector3Base<T>& other) const
{
    return
        components[0] > other[0] &&
        components[1] > other[1] &&
        components[2] > other[2];
}

template <typename T>
bool Vector3Base<T>::operator<=(const Vector3Base<T>& other) const
{
    return
        components[0] <= other[0] &&
        components[1] <= other[1] &&
        components[2] <= other[2];
}

template <typename T>
bool Vector3Base<T>::operator>=(const Vector3Base<T>& other) const
{
    return
        components[0] >= other[0] &&
        components[1] >= other[1] &&
        components[2] >= other[2];
}

template <typename T>
Vector3Base<T>& Vector3Base<T>::operator=(T value)
{
    components[0] = value;
    components[1] = value;
    components[2] = value;
    return *this;
}

template <typename T>
Vector3Base<T>& Vector3Base<T>::operator=(const T* data)
{
    return *static_cast<Vector3Base<T>*>(data);
}

template <typename T>
Vector3Base<T>& Vector3Base<T>::operator=(const Vector3Base<T>& other)
{
    components[0] = other[0];
    components[1] = other[1];
    components[2] = other[2];
    return *this;
}


#endif // VECTOR3_H
