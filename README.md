# VectorMath
SharpDX Inspired C++ vector math library (scalar only).

**Status:** Production Ready

VectorMath was designed to be flexible, allows to define vectors using any integer/floating-point type.

Sample Code:

View Projection matrix calculation
```C++
m_lookAt = m_position + m_forward;
m_view = Matrix::CreateLookAt(m_position, m_lookAt, m_up);
m_projection = Matrix::CreatePerspective(Math::DegreeToRadian * m_fov, Display::GetAspectRatio(), m_nearPlane, m_farPlane);
m_viewProjection = m_view * m_projection;
// ...
auto transformed = Vector3::Transform(somePoint, m_viewProjection);
```

Vector2/3/4 functionality
```C++
const auto someVector = Vector3(0.0f, 2.0f, 1.0f);
auto normalized = Vector3::Normalize(someVector);
auto dot = Vector3::Dot(someVector, normalized);

if(normalized.IsNormalized()) {...}
if(normalized.IsNaN()) {...}
if(normalized.Length() > 2) {...}
// ...

```

Quaternion functionality
```C++
const auto someRotation = Quaternion(Vector3::Up, 50.0f);
auto axis = someRotation.Axis();

if(someRotation.IsNormalized()) {...}
if(someRotation.IsNaN()) {...}
if(someRotation.Length() > 2) {...}
// ...
```
*Note: Quaternions are built with float as their default type and there is no way to change it.*

Defining new vector type
```C++
using Vector2i = Vector2Base<int>;
using Vector3i = Vector3Base<int>;
using Vector4i = Vector4Base<int>;
```
There is already some ready-to-use types defined in the [VectorMath.h](https://github.com/Erdroy/VectorMath/blob/master/VectorMath/VectorMath.h) file.

By default UPPERCASE component naming is enabled, look: [Config.h](https://github.com/Erdroy/VectorMath/blob/master/VectorMath/Config.h).
You should use the source code, instead compiling it.

## Roadmap
Currently I don't have enough separete time to push into this library.
But still, it will get updates pulled from my projects, when I'm done with some new features.

What I would like to add/improve:
- Full 'accessors' implementation (v1 = v.xxy() etc.)
- Disable explicit floating-point functions for integers
- SIMD Support
- Documentation
- More functions!
- Premake project setup (or CMake)

## Contributions
I do accept PR. Feel free to contribute.

## License
MIT
