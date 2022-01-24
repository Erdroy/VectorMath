// VectorMath (c) 2018-2022 Damian 'Erdroy' Korczowski

#pragma once

template<typename T>
struct BoundingSphereBase
{
public:
    /// <summary>
    /// Default constructor
    /// Sets 0 to all components of this structure
    /// </summary>
    BoundingSphereBase()
    {
        center = Vector3Base<T>::Zero;
        radius = T(0);
    }

    /// <summary>
    /// Constructs BoundingSphere with given center and size.
    /// </summary>
    /// <param name="center">The center of the BoundingSphere.</param>
    /// <param name="radius">The radius of the BoundingSphere.</param>
    explicit BoundingSphereBase(const Vector3Base<T>& center, const T radius)
    {
        this->center = center;
        this->radius = radius;
    }

public:
    /// <summary>
    /// Check if two BoundingSphereBase intersect each other
    /// </summary>
    static bool Intersects(const BoundingSphereBase<T>& a, const BoundingSphereBase<T>& b)
    {
        const auto distance = Vector3Base<T>::DistanceSquared(a.center, b.center);
        const auto r1Squared = a.radius * a.radius;
        const auto r2Squared = b.radius * b.radius;

        return distance <= r1Squared + r2Squared;
    }

    /// <summary>
    /// Check if point is within a BoundingBox
    /// </summary>
    static bool Contains(const BoundingSphereBase<T>& sphere, const Vector3Base<T>& point)
    {
        const auto distance = Vector3Base<T>::DistanceSquared(sphere.center, point);
        const auto rSquared = sphere.radius * sphere.radius;

        return rSquared <= distance;
    }

public:
    /// <summary>
    /// Center of this BoundingSphere
    /// </summary>
    Vector3Base<T> center;

    /// <summary>
    /// Size of this BoundingSphere
    /// </summary>
    T radius;
};