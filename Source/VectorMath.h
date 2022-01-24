// VectorMath (c) 2018-2022 Damian 'Erdroy' Korczowski

#pragma once

#include "Config.h"
#include "Math.h"
#include "Vector2Base.h"
#include "Vector3Base.h"
#include "Vector4Base.h"
#include "Quaternion.h"
#include "Matrix4x4Base.h"
#include "PlaneBase.h"
#include "BoundingBoxBase.h"
#include "BoundingFrustumBase.h"
#include "ColorBase.h"

using Vector2f = Vector2Base<float>;
using Vector3f = Vector3Base<float>;
using Vector4f = Vector4Base<float>;

using Vector2d = Vector2Base<double>;
using Vector3d = Vector3Base<double>;
using Vector4d = Vector4Base<double>;

using Matrix4x4f = Matrix4x4Base<float>;
using Matrix4x4d = Matrix4x4Base<double>;

using Matrix = Matrix4x4f; // Maybe we want to also make the matrix double precision?

using PlaneF = PlaneBase<float>;
using BoundingBoxF = BoundingBoxBase<float>;
using BoundingFrustumF = BoundingFrustumBase<float>;
using BoundingSphereF = BoundingSphereBase<float>;

using PlaneD = PlaneBase<double>;
using BoundingBoxD = BoundingBoxBase<double>;
using BoundingFrustumD = BoundingFrustumBase<double>;
using BoundingSphereD = BoundingSphereBase<double>;

#ifndef MATH_DEFAULT_DOUBLE_PRECISION
using Vector2 = Vector2f;
using Vector3 = Vector3f;
using Vector4 = Vector4f;

using Plane = PlaneF;
using BoundingBox = BoundingBoxF;
using BoundingFrustum = BoundingFrustumF;
using BoundingSphere = BoundingSphereF;
#else
using Vector2 = Vector2d;
using Vector3 = Vector3d;
using Vector4 = Vector4d;

using Plane = PlaneD;
using BoundingBox = BoundingBoxD;
using BoundingFrustum = BoundingFrustumD;
using BoundingSphere = BoundingSphereD;
#endif

using Color = ColorBase<float>;
using Color4 = Color;
using Color32 = Color;
