// VectorMath (c) 2018 Damian 'Erdroy' Korczowski

#pragma once

#ifndef VECTORBASE_H
#define VECTORBASE_H

#include "Config.h"
#include "Math.h"

// source: http://seanmiddleditch.com/using-stdenable_if-on-constructors/

template <typename Type, size_t Size> struct Components
{
protected:
    Type components[Size];
};

template <typename Type> struct Components<Type, 2>
{
    union
    {
        struct
        {
            Type x;
            Type y;
        };

        struct
        {
            Type X;
            Type Y;
        };

        Type components[2];
    };
};

template <typename Type> struct Components<Type, 3>
{
    union
    {
        struct
        {
            Type x;
            Type y;
            Type z;
        };

        struct
        {
            Type X;
            Type Y;
            Type Z;
        };

        Type components[3];
    };
};

template <typename Type> struct Components<Type, 4>
{
    union
    {
        struct
        {
            Type x;
            Type y;
            Type z;
            Type w;
        };

        struct
        {
            Type X;
            Type Y;
            Type Z;
            Type W;
        };

        Type components[4];
    };
};


template<typename T, size_t S>
struct VectorBase : Components<T, S>
{
protected:
    /* Protected members */
    using Components<T, S>::components;

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
        return components + S;
    }

    const_iterator begin() const
    {
        return components;
    }

    const_iterator end() const
    {
        return components + S;
    }

    reverse_iterator rbegin()
    {
        return components + S - 1;
    }

    reverse_iterator rend()
    {
        return components - 1;
    }

    const_reverse_iterator rbegin() const
    {
        return components + S - 1;
    }

    const_reverse_iterator rend() const
    {
        return components - 1;
    }

public:
    /* Static constant members */
    static const size_t Dimension = S;
};

#endif // VECTORBASE_H
