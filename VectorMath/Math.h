// VectorMath (c) 2018 Damian 'Erdroy' Korczowski

#pragma once

#ifndef MATH_H
#define MATH_H

#include "Config.h"

#if USE_MATH_NAMESPACE
namespace Math
{
#else
class Math
{
public:
#endif
    template<typename TValue>
    static TValue Clamp(TValue value, TValue min, TValue max)
    {
        return value < min ? min : 
               value > max ? max : value;
    }

    template<typename TValue>
    static TValue Min(TValue a, TValue b)
    {
        return a < b ? a : b;
    }

    template<typename TValue>
    static TValue Max(TValue a, TValue b)
    {
        return a > b ? a : b;
    }

    template<typename TValue>
    static TValue Min(TValue a, TValue b, TValue c)
    {
        return Min(Min(a, b), Min(b, c));
    }

    template<typename TValue>
    static TValue Max(TValue a, TValue b, TValue c)
    {
        return Max(Max(a, b), Max(b, c));
    }

    template<typename TValue>
    static TValue Abs(TValue value)
    {
        return value >= 0 ? value : -value;
    }

    template<typename TValue>
    static TValue Sqrt(TValue value)
    {
        return std::sqrt(value);
    }

    template<typename TValue>
    static TValue SmoothStep(TValue value)
    {
        return (value <= 0) ? 0
             : (value >= 1) ? 1
             : value * value * (3 - (2 * value));
    }

    template<typename TValue>
    static TValue SmootherStep(TValue value)
    {
        return (value <= 0) ? 0
             : (value >= 1) ? 1
             : value * value * value * (value * ((value * 6) - 15) + 10);
    }

    template<typename TBase, typename TAmount>
    static TBase Lerp(TBase from, TBase to, TAmount amount)
    {
        return from + (to - from) * amount;
    }

    template<typename TValue>
    static bool IsOne(TValue value)
    {
        return IsZero(value - 1);
    }

    static bool IsZero(const float a)
    {
        return Abs(a) < FLT_EPSILON;
    }

    static bool IsZero(const double a)
    {
        return Abs(a) < DBL_EPSILON;
    }
};

#endif // MATH_H