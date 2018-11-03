// VectorMath (c) 2018 Damian 'Erdroy' Korczowski

#pragma once

#ifndef MATH_H
#define MATH_H

#include "Config.h"

class Math
{
public:
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
    static TValue Acos(TValue value)
    {
        return std::acos(value);
    }

    template<typename TValue>
    static TValue Asin(TValue value)
    {
        return std::asin(value);
    }

    template<typename TValue>
    static TValue Cos(TValue value)
    {
        return std::cos(value);
    }

    template<typename TValue>
    static TValue Sin(TValue value)
    {
        return std::sin(value);
    }

    template<typename TValue>
    static TValue Tan(TValue value)
    {
        return std::tan(value);
    }

    template<typename TValue>
    static TValue Atan(TValue value)
    {
        return std::atan(value);
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
    static int Sign(TValue value)
    {
        return value < 0 ? -1 : 1;
    }

    template<typename TValue>
    static bool IsOne(TValue value)
    {
        return IsZero(value - 1);
    }

    static bool IsZero(const int a)
    {
        return a == 0;
    }

    static bool IsZero(const float a)
    {
        return Abs(a) < FLT_EPSILON;
    }

    static bool IsZero(const double a)
    {
        return Abs(a) < DBL_EPSILON;
    }

public:
    static const float ZeroTolerance;
    static const float Pi;
    static const float TwoPi;
    static const float PiOverTwo;
    static const float PiOverFour;
};

const float Math::ZeroTolerance = 1e-6f;
const float Math::Pi = 3.1415926535897932f;
const float Math::TwoPi = 2 * Pi;
const float Math::PiOverTwo = Pi / 2;
const float Math::PiOverFour = Pi / 4;

#endif // MATH_H