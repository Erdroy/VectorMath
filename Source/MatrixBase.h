// VectorMath (c) 2018-2019 Damian 'Erdroy' Korczowski

#pragma once

#include "Config.h"
#include "Math.h"

template <typename Type, size_t Cols, size_t Rows> struct MatrixComponents
{
protected:
    Type components[Cols * Rows];
};

template <typename Type> struct MatrixComponents<Type, 4, 4>
{
    union
    {
        struct
        {
            Type m11;
            Type m12;
            Type m13;
            Type m14;

            Type m21;
            Type m22;
            Type m23;
            Type m24;

            Type m31;
            Type m32;
            Type m33;
            Type m34;

            Type m41;
            Type m42;
            Type m43;
            Type m44;
        };

        struct
        {
            Type M11;
            Type M12;
            Type M13;
            Type M14;

            Type M21;
            Type M22;
            Type M23;
            Type M24;

            Type M31;
            Type M32;
            Type M33;
            Type M34;

            Type M41;
            Type M42;
            Type M43;
            Type M44;
        };

        Type components[4 * 4];
    };
};

template <typename Type> struct MatrixComponents<Type, 3, 3>
{
    union
    {
        struct
        {
            Type m11;
            Type m12;
            Type m13;

            Type m21;
            Type m22;
            Type m23;

            Type m31;
            Type m32;
            Type m33;
        };

        struct
        {
            Type M11;
            Type M12;
            Type M13;

            Type M21;
            Type M22;
            Type M23;

            Type M31;
            Type M32;
            Type M33;
        };

        Type components[3 * 3];
    };
};

template<typename T, size_t C, size_t R>
struct MatrixBase : MatrixComponents<T, C, R>
{
protected:
    /* Protected members */
    using MatrixComponents<T, C, R>::components;

public:
    /* Types */
    typedef T value_type;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

public:
    /* Public members */

public:
    /* Operators */
    T& operator[](const size_t index)
    {
        return components[index];
    }

    const T& operator[](const size_t index) const
    {
        return components[index];
    }

    T& at(const size_t index)
    {
        return components[index];
    }

    const T& at(const size_t index) const
    {
        return components[index];
    }

public:
    /* Iterators */
    iterator begin()
    {
        return components;
    }

    iterator end()
    {
        return components + Size;
    }

    const_iterator begin() const
    {
        return components;
    }

    const_iterator end() const
    {
        return components + Size;
    }

    reverse_iterator rbegin()
    {
        return components + Size - 1;
    }

    reverse_iterator rend()
    {
        return components - 1;
    }

    const_reverse_iterator rbegin() const
    {
        return components + Size - 1;
    }

    const_reverse_iterator rend() const
    {
        return components - 1;
    }

public:
    /* Static constant members */
    static const size_t Columns = C;
    static const size_t Rows = R;
    static const size_t Size = C * R;
};
