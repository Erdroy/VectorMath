// VectorMath (c) 2018 Damian 'Erdroy' Korczowski

#pragma once

#ifndef VECTOR3_H
#define VECTOR3_H

#include "VectorBase.h"

template<typename T>
struct Vector3Base : VectorBase<T, 3>
{
protected:
    /* Protected usings */
    using Components<T, 3>::components;
#if USE_UPPERCASE_COMPONENTS
    using Components<T, 3>::x;
    using Components<T, 3>::y;
    using Components<T, 3>::z;
#else
    using Components<T, 3>::X;
    using Components<T, 3>::Y;
    using Components<T, 3>::Z;
#endif

public:
    /* Public usings */
#if USE_UPPERCASE_COMPONENTS
    using Components<T, 3>::X;
    using Components<T, 3>::Y;
    using Components<T, 3>::Z;
#else
    using Components<T, 3>::x;
    using Components<T, 3>::y;
    using Components<T, 3>::z;
#endif

public:
    /* Constructors */
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
    VectorBase<T, 3> xxx() { return Vector<T, 3>(components[0], components[0], components[0]); }
    VectorBase<T, 3> yyy() { return Vector<T, 3>(components[1], components[1], components[1]); }
    VectorBase<T, 3> zzz() { return Vector<T, 3>(components[2], components[2], components[2]); }

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
const Vector3Base<T> Vector3Base<T>::Up = Vector3Base<T>(0, 1.0, 0);

template<typename T>
const Vector3Base<T> Vector3Base<T>::Down = Vector3Base<T>(0, -1, 0);

template<typename T>
const Vector3Base<T> Vector3Base<T>::Left = Vector3Base<T>(-1, 0, 0);

template<typename T>
const Vector3Base<T> Vector3Base<T>::Right = Vector3Base<T>(1, 0, 0);

template<typename T>
const Vector3Base<T> Vector3Base<T>::Forward = Vector3Base<T>(-1, 0, 1);

template<typename T>
const Vector3Base<T> Vector3Base<T>::Back = Vector3Base<T>(1, 0, -1);

template<typename T>
const Vector3Base<T> Vector3Base<T>::One = Vector3Base<T>(1);

template<typename T>
const Vector3Base<T> Vector3Base<T>::Zero = Vector3Base<T>(0);

template<typename T>
const Vector3Base<T> Vector3Base<T>::UnitX = Vector3Base<T>(1, 0, 0);

template<typename T>
const Vector3Base<T> Vector3Base<T>::UnitY = Vector3Base<T>(0, 1, 0);

template<typename T>
const Vector3Base<T> Vector3Base<T>::UnitZ = Vector3Base<T>(0, 0, 1);

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
