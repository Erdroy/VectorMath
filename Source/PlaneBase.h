// VectorMath (c) 2018-2020 Damian 'Erdroy' Korczowski

#pragma once

enum class PlaneIntersection
{
    None,
    Intersecting,
    Back,
    Front
};

template<typename T>
struct PlaneBase
{
public:
    /// <summary>
    ///     Initializes a new instance of the Plane struct.
    /// </summary>
    PlaneBase()
    {
    }

    /// <summary>
    ///     Initializes a new instance of the Plane struct.
    /// </summary>
    /// <param name="value">The value that will be assigned to all components.</param>
    explicit PlaneBase(const float value)
    {
        normal.x = normal.y = normal.z = distance = value;
    }

    /// <summary>
    ///     Initializes a new instance of the Plane struct.
    /// </summary>
    /// <param name="a">The X component of the normal.</param>
    /// <param name="b">The Y component of the normal.</param>
    /// <param name="c">The Z component of the normal.</param>
    /// <param name="d">The distance of the plane along its normal from the origin.</param>
    explicit PlaneBase(float a, float b, float c, float d)
    {
        normal.x = a;
        normal.y = b;
        normal.z = c;
        distance = d;
    }

    /// <summary>
    ///     Initializes a new instance of the Plane class.
    /// </summary>
    /// <param name="point">Any point that lies along the plane.</param>
    /// <param name="normal">The normal vector to the plane.</param>
    explicit PlaneBase(Vector3Base<T> point, Vector3Base<T> normal)
    {
        normal = normal;
        distance = -Vector3Base<T>::Dot(normal, point);
    }

    /// <summary>
    ///     Initializes a new instance of the Plane struct.
    /// </summary>
    /// <param name="a">First point of a triangle defining the plane.</param>
    /// <param name="b">Second point of a triangle defining the plane.</param>
    /// <param name="c">Third point of a triangle defining the plane.</param>
    explicit PlaneBase(Vector3Base<T> a, Vector3Base<T> b, Vector3Base<T> c)
    {
        auto xa = b - a;
        auto xb = a - c;
        auto dir = Vector3Base<T>::Cross(xa, xb);
        dir.Normalize();
        normal = dir;
        distance = dir.Length();
    }

public:
    float Dot(const Vector3Base<T> point) const
    {
        return normal.x* point.x
            + normal.y * point.y
            + normal.z * point.z
            + distance * 1;
    }

    /// <summary>
    ///     Changes the coefficients of the normal vector of the plane to make it of unit Length.
    /// </summary>
    void Normalize()
    {
        auto magnitude = 1.0f / static_cast<float>(Math::Sqrt(
            (normal.x * normal.x) + (normal.y * normal.y) + (normal.z * normal.z)));

        normal.x *= magnitude;
        normal.y *= magnitude;
        normal.z *= magnitude;
        distance = magnitude;
    }

public:
    /// <summary>
    ///     Determines whether there is an intersection between a <see cref="Plane"/> and a point.
    /// </summary>
    /// <param name="plane">The plane to test.</param>
    /// <param name="point">The point to test.</param>
    /// <returns>Whether the two objects intersected.</returns>
    static PlaneIntersection PlaneIntersectsPoint(PlaneBase<T>& plane, Vector3Base<T>& point)
    {
        auto distance = Vector3Base<T>::Dot(plane.normal, point);
        distance += plane.distance;

        if (distance > 0.0f)
            return PlaneIntersection::Front;

        if (distance < 0.0f)
            return PlaneIntersection::Back;

        return PlaneIntersection::Intersecting;
    }

public:
    /// <summary>
    ///     The normal vector of the plane.
    /// </summary>
    Vector3Base<T> normal = Vector3Base<T>::Zero;

    /// <summary>
    ///     The distance of the plane along its normal from the origin.
    /// </summary>
    float distance = 0.0f;
};
