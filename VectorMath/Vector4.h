// VectorMath (c) 2018 Damian 'Erdroy' Korczowski

#pragma once

#ifndef VECTOR4_H
#define VECTOR4_H

#include "VectorBase.h"

template<typename T>
struct Vector4Base : VectorBase<T, 4>
{
protected:
    /* Protected usings */
    using Components<T, 4>::components;
#if USE_UPPERCASE_COMPONENTS
    using Components<T, 4>::x;
    using Components<T, 4>::y;
    using Components<T, 4>::z;
    using Components<T, 4>::w;
#else
    using Components<T, 4>::X;
    using Components<T, 4>::Y;
    using Components<T, 4>::Z;
    using Components<T, 4>::W;
#endif

public:
    /* Public usings */
#if USE_UPPERCASE_COMPONENTS
    using Components<T, 4>::X;
    using Components<T, 4>::Y;
    using Components<T, 4>::Z;
    using Components<T, 4>::W;
#else
    using Components<T, 4>::x;
    using Components<T, 4>::y;
    using Components<T, 4>::z;
    using Components<T, 4>::w;
#endif

public:
    /* Constructors */
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
    /* Combined Accessors */
    VectorBase<T, 3> xxx() { return VectorBase<T, 3>(components[0], components[0], components[0]); }
    VectorBase<T, 3> yyy() { return VectorBase<T, 3>(components[1], components[1], components[1]); }
    VectorBase<T, 3> zzz() { return VectorBase<T, 3>(components[2], components[2], components[2]); }

    VectorBase<T, 4> xxxx() { return VectorBase<T, 3>(components[0], components[0], components[0], components[0]); }
    VectorBase<T, 4> yyyy() { return VectorBase<T, 3>(components[1], components[1], components[1], components[1]); }
    VectorBase<T, 4> zzzy() { return VectorBase<T, 3>(components[2], components[2], components[2], components[2]); }
    VectorBase<T, 4> wwww() { return VectorBase<T, 3>(components[3], components[3], components[3], components[3]); }

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
const Vector4Base<T> Vector4Base<T>::Up = Vector4Base<T>(0, 1.0, 0, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::Down = Vector4Base<T>(0, -1, 0, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::Left = Vector4Base<T>(-1, 0, 0, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::Right = Vector4Base<T>(1, 0, 0, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::Forward = Vector4Base<T>(-1, 0, 1, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::Back = Vector4Base<T>(1, 0, -1, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::One = Vector4Base<T>(1);

template<typename T>
const Vector4Base<T> Vector4Base<T>::Zero = Vector4Base<T>(0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::UnitX = Vector4Base<T>(1, 0, 0, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::UnitY = Vector4Base<T>(0, 1, 0, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::UnitZ = Vector4Base<T>(0, 0, 1, 0);

template<typename T>
const Vector4Base<T> Vector4Base<T>::UnitW = Vector4Base<T>(0, 0, 0, 1);

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


#endif // VECTOR4_H
