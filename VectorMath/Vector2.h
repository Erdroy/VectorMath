// VectorMath (c) 2018 Damian 'Erdroy' Korczowski

#pragma once

#ifndef VECTOR2_H
#define VECTOR2_H

#include "VectorBase.h"

template<typename T>
struct Vector2Base : VectorBase<T, 2>
{
protected:
    /* Protected usings */
    using Components<T, 2>::components;
#if USE_UPPERCASE_COMPONENTS
    using Components<T, 2>::x;
    using Components<T, 2>::y;
#else
    using Components<T, 2>::X;
    using Components<T, 2>::Y;
#endif

public:
    /* Public usings */
#if USE_UPPERCASE_COMPONENTS
    using Components<T, 2>::X;
    using Components<T, 2>::Y;
#else
    using Components<T, 2>::x;
    using Components<T, 2>::y;
#endif

public:
    /* Constructors */
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

    T Dot(const Vector2Base<T>& a) const;
    T Length() const;
    T LengthSquared() const;

public:
    /* Public static members */
    static Vector2Base<T> Normalize(const Vector2Base<T>& a);
    static Vector2Base<T> Negate(const Vector2Base<T>& a);
    static T Dot(const Vector2Base<T>& a, const Vector2Base<T>& b);
    static T Length(const Vector2Base<T>& a);
    static T LengthSquared(const Vector2Base<T>& a);

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
const Vector2Base<T> Vector2Base<T>::Up = Vector2Base<T>(0, 1);

template<typename T>
const Vector2Base<T> Vector2Base<T>::Down = Vector2Base<T>(0, -1);

template<typename T>
const Vector2Base<T> Vector2Base<T>::Left = Vector2Base<T>(-1, 0);

template<typename T>
const Vector2Base<T> Vector2Base<T>::Right = Vector2Base<T>(1, 0);

template<typename T>
const Vector2Base<T> Vector2Base<T>::One = Vector2Base<T>(1);

template<typename T>
const Vector2Base<T> Vector2Base<T>::Zero = Vector2Base<T>(0);

template<typename T>
const Vector2Base<T> Vector2Base<T>::UnitX = Vector2Base<T>(1, 0);

template<typename T>
const Vector2Base<T> Vector2Base<T>::UnitY = Vector2Base<T>(0, 1);

template <typename T>
void Vector2Base<T>::Negate()
{
    x = -x;
    y = -y;
}

template <typename T>
void Vector2Base<T>::Normalize()
{
    T invLength = T(1) / Length();

    x *= invLength;
    y *= invLength;
}

template <typename T>
T Vector2Base<T>::Dot(const Vector2Base<T>& a) const
{
    return (x * a.x) + (y * a.y);
}

template <typename T>
T Vector2Base<T>::Length() const
{
    return std::sqrt(LengthSquared());
}

template <typename T>
T Vector2Base<T>::LengthSquared() const
{
    return (x * x) + (y * y);
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

#endif // VECTOR2_H
