// VectorMath (c) 2018-2022 Damian 'Erdroy' Korczowski

#include "Math.h"
#include "Vector2Base.h"
#include "Vector3Base.h"
#include "Vector4Base.h"
#include "Quaternion.h"
#include "Matrix4x4Base.h"


/* Math */
const float Math::ZeroTolerance = 1e-6f;
const float Math::Pi = 3.1415926535897932f;
const float Math::TwoPi = 2 * Pi;
const float Math::PiOverTwo = Pi / 2;
const float Math::PiOverFour = Pi / 4;

const float Math::DegreeToRadian = Pi / 180.0f;
const float Math::RadianToDegree = 180.0f / Pi;

/* Quaternion */
const Quaternion Quaternion::Identity(0.0f, 0.0f, 0.0f, 1.0f);
const Quaternion Quaternion::Zero(0.0f, 0.0f, 0.0f, 0.0f);
const Quaternion Quaternion::One(1.0f, 1.0f, 1.0f, 1.0f);
