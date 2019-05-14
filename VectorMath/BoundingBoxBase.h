// VectorMath (c) 2018-2019 Damian 'Erdroy' Korczowski

#pragma once

template<typename T>
struct BoundingBoxBase
{
public:
    /// <summary>
    /// Default constructor
    /// Sets 0 to all components of this structure
    /// </summary>
    BoundingBoxBase()
    {
        center = Vector3Base<T>::Zero;
        size = Vector3Base<T>::Zero;
    }

    /// <summary>
    /// Constructs BoundingBox with given center and size.
    /// </summary>
    /// <param name="center">The center of the BoundingBox.</param>
    /// <param name="size">The size of the BoundingBox.</param>
    explicit BoundingBoxBase(const Vector3Base<T>& center, const Vector3Base<T>& size)
    {
        this->center = center;
        this->size = size;
    }

public:
    /// <summary>
    /// Minimum X coordinate of this BoundingBox
    /// </summary>
    float Left() const
    {
        return center.x - (size.x / 2);
    }

    /// <summary>
    /// Maximum X coordinate of this BoundingBox
    /// </summary>
    float Right() const
    {
        return center.x + (size.x / 2);
    }

    /// <summary>
    /// Minimum Y coordinate of this BoundingBox
    /// </summary>
    float Bottom() const
    {
        return center.y - (size.y / 2);
    }

    /// <summary>
    /// Maximum Y coordinate of this BoundingBox
    /// </summary>
    float Top() const
    {
        return center.y + (size.y / 2);
    }

    /// <summary>
    /// Minimum Z coordinate of this BoundingBox
    /// </summary>
    float Back() const
    {
        return center.z - (size.z / 2);
    }

    /// <summary>
    /// Maximum Z coordinate of this BoundingBox
    /// </summary>
    float Front() const
    {
        return center.z + (size.z / 2);
    }

    /// <summary>
    /// The maximum of the bounding box.
    /// </summary>
    Vector3Base<T> Maximum() const
    {
        return center + size * 0.5f;
    }

    /// <summary>
    /// The minimum of the bounding box.
    /// </summary>
    Vector3Base<T> Minimum() const
    {
        return center - size * 0.5f;
    }

    /// <summary>
    /// Check if two BoundingBoxes intersect each other
    /// </summary>
    static bool Intersects(const BoundingBoxBase<T>& a, const BoundingBoxBase<T>& b)
    {
        const auto amin = a.Minimum();
        const auto bmin = b.Minimum();
        const auto amax = a.Maximum();
        const auto bmax = b.Maximum();

        if (amin.x > bmax.x || bmin.x > amax.x)
            return false;

        if (amin.y > bmax.y || bmin.y > amax.y)
            return false;

        if (amin.z > bmax.z || bmin.z > amax.z)
            return false;

        return true;
    }

    /// <summary>
    /// Check if two BoundingBoxes intersect each other
    /// </summary>
    static void Intersects(const BoundingBoxBase<T>& a, const BoundingBoxBase<T>& b, bool* result)
    {
        *result = Intersects(a, b);
    }

    /// <summary>
    /// Check if point is within a BoundingBox
    /// </summary>
    static bool Contains(const BoundingBoxBase<T>& box, const Vector3Base<T>& point)
    {
        return point.x > box.Left() && point.x < box.Right() && point.y > box.Bottom() && point.y < box.Top() && point.z
        > box.Back() && point.z < box.Front();
    }

    /// <summary>
    /// Check if point is within a BoundingBox
    /// </summary>
    static void Contains(const BoundingBoxBase<T>& box, const Vector3Base<T>& point, bool* result)
    {
        *result = Contains(box, point);
    }

public:
    /// <summary>
    /// Center of this BoundingBox
    /// </summary>
    Vector3Base<T> center;

    /// <summary>
    /// Size of this BoundingBox
    /// </summary>
    Vector3Base<T> size;
};
