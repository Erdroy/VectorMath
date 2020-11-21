// VectorMath (c) 2018-2020 Damian 'Erdroy' Korczowski

#pragma once

#include "Config.h"
#include "Math.h"

template<typename T>
struct ColorBase
{
public:
    /* Types */
    typedef T value_type;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

public:
    /* Components */
    union
    {
#if USE_UPPERCASE_COMPONENTS
        struct
        {
            T R;
            T G;
            T B;
            T A;
        };
#else
        struct
        {
            T r;
            T g;
            T b;
            T a;
        };
#endif

        T components[4];
    };

public:
    /* Constructors */
    ColorBase() = default;

    explicit ColorBase(T value)
    {
        components[0] = value;
        components[1] = value;
        components[2] = value;
        components[3] = value;
    }

    ColorBase(T r, T g, T b)
    {
        components[0] = r;
        components[1] = g;
        components[2] = b;
        components[3] = 1.0f;
    }

    ColorBase(T r, T g, T b, T a)
    {
        components[0] = r;
        components[1] = g;
        components[2] = b;
        components[3] = a;
    }

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
        return components + 4;
    }

    const_iterator begin() const
    {
        return components;
    }

    const_iterator end() const
    {
        return components + 4;
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
        return components + 4 - 1;
    }

    const_reverse_iterator rend() const
    {
        return components - 1;
    }

public:
    static const ColorBase<T> Red;
    static const ColorBase<T> Green;
    static const ColorBase<T> Blue;
    static const ColorBase<T> White;
    static const ColorBase<T> Black;
};

template<typename T>
const ColorBase<T> ColorBase<T>::Red(1, 0, 0);

template<typename T>
const ColorBase<T> ColorBase<T>::Green(0, 1, 0);

template<typename T>
const ColorBase<T> ColorBase<T>::Blue(0, 0, 1);

template<typename T>
const ColorBase<T> ColorBase<T>::White(1, 1, 1);

template<typename T>
const ColorBase<T> ColorBase<T>::Black(0, 0, 0);