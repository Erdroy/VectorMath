// VectorMath (c) 2018 Damian 'Erdroy' Korczowski

#pragma once

#ifndef QUATERNION_H
#define QUATERNION_H

#include "VectorBase.h"

struct Quaternion : VectorBase<float, 4>
{
protected:
    /* Protected members */
    using Components<float, 4>::components;

public:
    /* Public usings */
    using Components<float, 4>::x;
    using Components<float, 4>::y;
    using Components<float, 4>::z;
    using Components<float, 4>::w;

public:
    /* Constructors */
    Quaternion(const float x, const float y, const float z, const float w)
    {
        components[0] = x;
        components[1] = y;
        components[2] = z;
        components[3] = w;
    }

public:
    /* Constant static members */
    static const Quaternion Identity;
    static const Quaternion Zero;
};

const Quaternion Quaternion::Identity = Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
const Quaternion Quaternion::Zero = Quaternion(0.0f, 0.0f, 0.0f, 0.0f);

#endif // QUATERNION_H
