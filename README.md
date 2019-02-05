# VectorMath
[![Discord](https://discordapp.com/api/guilds/304571867203764233/widget.png)](https://discord.alwaystoolate.com) <br>
SharpDX Inspired C++ vector math library (scalar only).

**Status:** Production Ready

VectorMath was designed to be flexible, allows to define vectors using any integer/floating-point type.

Sample:
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
- SIMD Support
- Documentation
- More functions!
- Premake project setup (or CMake)

## Contributions
I do accept PR. Feel free to contribute.

## License
MIT
