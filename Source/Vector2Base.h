// VectorMath (c) 2018-2022 Damian 'Erdroy' Korczowski

#pragma once

#include "VectorBase.h"
#include "Quaternion.h"

template<typename T>
struct Vector2Base : VectorBase<T, 2>
{
protected:
    /* Protected usings */
    using VectorComponents<T, 2>::components;
#if USE_UPPERCASE_COMPONENTS
    using VectorComponents<T, 2>::x;
    using VectorComponents<T, 2>::y;
#else
    using VectorComponents<T, 2>::X;
    using VectorComponents<T, 2>::Y;
#endif

public:
    /* Public usings */
#if USE_UPPERCASE_COMPONENTS
    using VectorComponents<T, 2>::X;
    using VectorComponents<T, 2>::Y;
#else
    using VectorComponents<T, 2>::x;
    using VectorComponents<T, 2>::y;
#endif

public:
    /* Constructors */
    Vector2Base() = default;

    explicit Vector2Base(T value)
    {
        components[0] = value;
        components[1] = value;
    }

    Vector2Base(T x, T y)
    {
        components[0] = x;
        components[1] = y;
    }

public:
    /* Public members */
    void Negate();
    void Normalize();

    Vector2Base<T> Normalized() const;
    bool IsNormalized() const;
    bool IsZero() const;
    bool IsNaN() const;
    bool IsInfinity() const;

    T Dot(const Vector2Base<T>& a) const;
    T Length() const;
    T LengthSquared() const;
    T Distance(const Vector2Base<T>& a) const;

public:
    /* Public static members */
    static Vector2Base<T> Normalize(const Vector2Base<T>& a);
    static Vector2Base<T> Negate(const Vector2Base<T>& a);
    static Vector2Base<T> Abs(const Vector2Base<T>& a);
    static Vector2Base<T> Lerp(const Vector2Base<T>& from, const Vector2Base<T>& to, T amount);
    static Vector2Base<T> Transform(const Vector2Base<T>& a, const Quaternion& rotation);
    static Vector2Base<T> Transform(const Vector2Base<T>& a, const MatrixBase<T, 4, 4>& matrix);

    static T Dot(const Vector2Base<T>& a, const Vector2Base<T>& b);
    static T Length(const Vector2Base<T>& a);
    static T LengthSquared(const Vector2Base<T>& a);
    static T Distance(const Vector2Base<T>& a, const Vector2Base<T>& b);
    static T DistanceSquared(const Vector2Base<T>& a, const Vector2Base<T>& b);

    static bool NearEqual(const Vector2Base<T>& a, const Vector2Base<T>& b);

    static bool IsNormalized(const Vector2Base<T>& a);
    static bool IsZero(const Vector2Base<T>& a);
    static bool IsNaN(const Vector2Base<T>& a);
    static bool IsInfinity(const Vector2Base<T>& a);

public:
    /* Operators */
    void operator+=(const Vector2Base<T>& other);
    void operator-=(const Vector2Base<T>& other);
    void operator*=(const Vector2Base<T>& other);
    void operator/=(const Vector2Base<T>& other);

    Vector2Base<T> operator+(const Vector2Base<T>& other) const;
    Vector2Base<T> operator-(const Vector2Base<T>& other) const;
    Vector2Base<T> operator*(const Vector2Base<T>& other) const;
    Vector2Base<T> operator/(const Vector2Base<T>& other) const;

    void operator+=(T other);
    void operator-=(T other);
    void operator*=(T other);
    void operator/=(T other);
    
    Vector2Base<T> operator+(T other) const;
    Vector2Base<T> operator-(T other) const;
    Vector2Base<T> operator*(T other) const;
    Vector2Base<T> operator/(T other) const;

    Vector2Base<T> operator-() const;

    bool operator==(const Vector2Base<T>& other) const;
    bool operator!=(const Vector2Base<T>& other) const;
    bool operator<(const Vector2Base<T>& other) const;
    bool operator>(const Vector2Base<T>& other) const;
    bool operator<=(const Vector2Base<T>& other) const;
    bool operator>=(const Vector2Base<T>& other) const;

    Vector2Base<T>& operator=(T value);
    Vector2Base<T>& operator=(const T* data);
    Vector2Base<T>& operator=(const Vector2Base<T>& other);

public:
    /* Constant static members */
    static const Vector2Base<T> Up;
    static const Vector2Base<T> Down;
    static const Vector2Base<T> Left;
    static const Vector2Base<T> Right;

    static const Vector2Base<T> One;
    static const Vector2Base<T> Zero;

    static const Vector2Base<T> UnitX;
    static const Vector2Base<T> UnitY;
};

template<typename T>
const Vector2Base<T> Vector2Base<T>::Up(0, 1);

template<typename T>
const Vector2Base<T> Vector2Base<T>::Down(0, -1);

template<typename T>
const Vector2Base<T> Vector2Base<T>::Left(-1, 0);

template<typename T>
const Vector2Base<T> Vector2Base<T>::Right(1, 0);

template<typename T>
const Vector2Base<T> Vector2Base<T>::One(1);

template<typename T>
const Vector2Base<T> Vector2Base<T>::Zero(0);

template<typename T>
const Vector2Base<T> Vector2Base<T>::UnitX(1, 0);

template<typename T>
const Vector2Base<T> Vector2Base<T>::UnitY(0, 1);

template <typename T>
void Vector2Base<T>::Negate()
{
    x = -x;
    y = -y;
}

template <typename T>
void Vector2Base<T>::Normalize()
{
    T lenSqr = LengthSquared();

    if (Math::IsZero(lenSqr))
        return;

    T invLength = T(1) / Math::Sqrt(lenSqr);

    x *= invLength;
    y *= invLength;
}

template <typename T>
Vector2Base<T> Vector2Base<T>::Normalized() const
{
    return Normalize(*this);
}

template <typename T>
bool Vector2Base<T>::IsNormalized() const
{
    return IsNormalized(*this);
}

template <typename T>
bool Vector2Base<T>::IsZero() const
{
    return IsZero(*this);
}

template <typename T>
bool Vector2Base<T>::IsNaN() const
{
    return isnan(x) || isnan(y);
}

template <typename T>
bool Vector2Base<T>::IsInfinity() const
{
    return isinf(x) || isinf(y);
}

template <typename T>
T Vector2Base<T>::Dot(const Vector2Base<T>& a) const
{
    return (x * a.x) + (y * a.y);
}

template <typename T>
T Vector2Base<T>::Length() const
{
    return Math::Sqrt(LengthSquared());
}

template <typename T>
T Vector2Base<T>::LengthSquared() const
{
    return (x * x) + (y * y);
}

template <typename T>
T Vector2Base<T>::Distance(const Vector2Base<T>& a) const
{
    return Distance(*this, a);
}

template <typename T>
Vector2Base<T> Vector2Base<T>::Normalize(const Vector2Base<T>& a)
{
    Vector2Base<T> result = a;
    result.Normalize();
    return result;
}

template <typename T>
Vector2Base<T> Vector2Base<T>::Negate(const Vector2Base<T>& a)
{
    Vector2Base<T> result = a;
    result.Negate();
    return result;
}

template <typename T>
Vector2Base<T> Vector2Base<T>::Abs(const Vector2Base<T>& a)
{
    Vector2Base<T> result = a;
    result.x = Math::Abs(result.x);
    result.y = Math::Abs(result.y);
    return result;
}

template <typename T>
Vector2Base<T> Vector2Base<T>::Lerp(const Vector2Base<T>& from, const Vector2Base<T>& to, T amount)
{
    return Math::Lerp(from, to, amount);
}

template <typename T>
Vector2Base<T> Vector2Base<T>::Transform(const Vector2Base<T>& a, const Quaternion& rotation)
{
    const auto x = T(rotation.x + rotation.x);
    const auto y = T(rotation.y + rotation.y);
    const auto z = T(rotation.z + rotation.z);
    const auto wz = T(rotation.w * z);
    const auto xx = T(rotation.x * x);
    const auto xy = T(rotation.x * y);
    const auto yy = T(rotation.y * y);
    const auto zz = T(rotation.z * z);

    return Vector2Base<T>(
        (a.x * (T(1) - yy - zz)) + (a.y * (xy - wz)), 
        (a.x * (xy + wz)) + (a.y * (T(1) - xx - zz))
    );
}

template <typename T>
Vector2Base<T> Vector2Base<T>::Transform(const Vector2Base<T>& a, const MatrixBase<T, 4, 4>& matrix)
{
    return Vector2Base<T>(
        (a.x * matrix.m11) + (a.y * matrix.m21) + matrix.m41,
        (a.x * matrix.m12) + (a.y * matrix.m22) + matrix.m42);
}

template <typename T>
T Vector2Base<T>::Dot(const Vector2Base<T>& a, const Vector2Base<T>& b)
{
    return a.Dot(b);
}

template <typename T>
T Vector2Base<T>::Length(const Vector2Base<T>& a)
{
    return a.Length();
}

template <typename T>
T Vector2Base<T>::LengthSquared(const Vector2Base<T>& a)
{
    return a.LengthSquared();
}

template <typename T>
T Vector2Base<T>::Distance(const Vector2Base<T>& a, const Vector2Base<T>& b)
{
    return Math::Sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

template <typename T>
T Vector2Base<T>::DistanceSquared(const Vector2Base<T>& a, const Vector2Base<T>& b)
{
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

template <typename T>
bool Vector2Base<T>::NearEqual(const Vector2Base<T>& a, const Vector2Base<T>& b)
{
    return Math::NearEqual(a.x, b.x) && Math::NearEqual(a.y, b.y);
}

template <typename T>
bool Vector2Base<T>::IsNormalized(const Vector2Base<T>& a)
{
    return Math::IsOne(a.LengthSquared());
}

template <typename T>
bool Vector2Base<T>::IsZero(const Vector2Base<T>& a)
{
    return a.x == 0 && a.y == 0;
}

template <typename T>
bool Vector2Base<T>::IsNaN(const Vector2Base<T>& a)
{
    return a.IsNaN();
}

template <typename T>
bool Vector2Base<T>::IsInfinity(const Vector2Base<T>& a)
{
    return a.IsInfinity();
}

template <typename T>
void Vector2Base<T>::operator+=(const Vector2Base<T>& other)
{
    components[0] += other[0];
    components[1] += other[1];
}

template <typename T>
void Vector2Base<T>::operator-=(const Vector2Base<T>& other)
{
    components[0] -= other[0];
    components[1] -= other[1];
}

template <typename T>
void Vector2Base<T>::operator*=(const Vector2Base<T>& other)
{
    components[0] *= other[0];
    components[1] *= other[1];
}

template <typename T>
void Vector2Base<T>::operator/=(const Vector2Base<T>& other)
{
    components[0] /= other[0];
    components[1] /= other[1];
}

template <typename T>
Vector2Base<T> Vector2Base<T>::operator+(const Vector2Base<T>& other) const
{
    return Vector2Base<T>(
        components[0] + other[0],
        components[1] + other[1]
    );
}

template <typename T>
Vector2Base<T> Vector2Base<T>::operator-(const Vector2Base<T>& other) const
{
    return Vector2Base<T>(
        components[0] - other[0],
        components[1] - other[1]
    );
}

template <typename T>
Vector2Base<T> Vector2Base<T>::operator*(const Vector2Base<T>& other) const
{
    return Vector2Base<T>(
        components[0] * other[0], 
        components[1] * other[1]
    );
}

template <typename T>
Vector2Base<T> Vector2Base<T>::operator/(const Vector2Base<T>& other) const
{
    return Vector2Base<T>(
        components[0] / other[0],
        components[1] / other[1]
    );
}

template <typename T>
void Vector2Base<T>::operator+=(T other)
{
    components[0] += other;
    components[1] += other;
}

template <typename T>
void Vector2Base<T>::operator-=(T other)
{
    components[0] -= other;
    components[1] -= other;
}

template <typename T>
void Vector2Base<T>::operator*=(T other)
{
    components[0] *= other;
    components[1] *= other;
}

template <typename T>
void Vector2Base<T>::operator/=(T other)
{
    components[0] /= other;
    components[1] /= other;
}

template <typename T>
Vector2Base<T> Vector2Base<T>::operator+(T other) const
{
    return Vector2Base<T>(
        components[0] + other,
        components[1] + other
    );
}

template <typename T>
Vector2Base<T> Vector2Base<T>::operator-(T other) const
{
    return Vector2Base<T>(
        components[0] - other,
        components[1] - other
    );
}

template <typename T>
Vector2Base<T> Vector2Base<T>::operator*(T other) const
{
    return Vector2Base<T>(
        components[0] * other,
        components[1] * other
    );
}

template <typename T>
Vector2Base<T> Vector2Base<T>::operator/(T other) const
{
    return Vector2Base<T>(
        components[0] / other,
        components[1] / other
    );
}

template <typename T>
Vector2Base<T> Vector2Base<T>::operator-() const
{
    return Vector2Base<T>(
        -components[0],
        -components[1]
    );
}

template <typename T>
bool Vector2Base<T>::operator==(const Vector2Base<T>& other) const
{
    return
        components[0] == other[0] &&
        components[1] == other[1];
}

template <typename T>
bool Vector2Base<T>::operator!=(const Vector2Base<T>& other) const
{
    return
        components[0] != other[0] ||
        components[1] != other[1];
}

template <typename T>
bool Vector2Base<T>::operator<(const Vector2Base<T>& other) const
{
    return
        components[0] < other[0] &&
        components[1] < other[1];
}

template <typename T>
bool Vector2Base<T>::operator>(const Vector2Base<T>& other) const
{
    return
        components[0] > other[0] &&
        components[1] > other[1];
}

template <typename T>
bool Vector2Base<T>::operator<=(const Vector2Base<T>& other) const
{
    return
        components[0] <= other[0] &&
        components[1] <= other[1];
}

template <typename T>
bool Vector2Base<T>::operator>=(const Vector2Base<T>& other) const
{
    return
        components[0] >= other[0] &&
        components[1] >= other[1];
}

template <typename T>
Vector2Base<T>&  Vector2Base<T>::operator=(T value)
{
    components[0] = value;
    components[1] = value;
    return *this;
}

template <typename T>
Vector2Base<T>& Vector2Base<T>::operator=(const T* data)
{
    return *static_cast<Vector2Base<T>*>(data);
}

template <typename T>
Vector2Base<T>& Vector2Base<T>::operator=(const Vector2Base<T>& other)
{
    components[0] = other[0];
    components[1] = other[1];
    return *this;
}
