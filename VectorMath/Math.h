// VectorMath (c) 2018 Damian 'Erdroy' Korczowski

#pragma once

#ifndef MATH_H
#define MATH_H

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

using Vector2f = Vector2Base<float>;
using Vector3f = Vector3Base<float>;
using Vector4f = Vector4Base<float>;

using Vector2d = Vector2Base<double>;
using Vector3d = Vector3Base<double>;
using Vector4d = Vector4Base<double>;

#ifndef MATH_DEFAULT_DOUBLE_PRECISION
using Vector2 = Vector2f;
using Vector3 = Vector3f;
using Vector4 = Vector4f;
#else
using Vector2 = Vector2d;
using Vector3 = Vector3d;
using Vector4 = Vector4d;
#endif

#endif // MATH_H
