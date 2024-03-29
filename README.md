# VectorMath
SharpDX Inspired C++ vector math library (scalar only).

**Status:** Production Ready

VectorMath was designed to be flexible, allows to define vectors using any integer/floating-point type.
Just drag and drop source and header files into your project! That's it.

## Sample code
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
Already there are some ready-to-use types defined in the [VectorMath.h](https://github.com/Erdroy/VectorMath/blob/master/Source/VectorMath.h) file.

By default UPPERCASE component naming is enabled, look: [Config.h](https://github.com/Erdroy/VectorMath/blob/master/Source/Config.h).

## Roadmap
- Disable explicit floating-point functions for integers
- Get rid of STD
- SIMD Support
- Documentation
- More functions!

## Contributions
I do accept PR. Feel free to contribute.

## License
MIT
