// VectorMath (c) 2018-2022 Damian 'Erdroy' Korczowski

#pragma once

#include "Config.h"
#include "Vector3Base.h"
#include "PlaneBase.h"
#include "BoundingBoxBase.h"
#include "BoundingSphereBase.h"

template<typename T>
struct BoundingFrustumBase
{
private:
    static void GetBoxToPlanePVertexNVertex(const BoundingBoxBase<T>& box, const Vector3Base<T>& planeNormal, Vector3Base<T>* p, Vector3Base<T>* n)
    {
        const auto bmin = box.Minimum();
        const auto bmax = box.Maximum();

        *p = bmin;
        *n = bmax;

        if (planeNormal.x >= 0)
        {
            p->x = bmax.x;
            n->x = bmin.x;
        }
        if (planeNormal.y >= 0)
        {
            p->y = bmax.y;
            n->y = bmin.y;
        }
        if (planeNormal.z >= 0)
        {
            p->z = bmax.z;
            n->z = bmin.z;
        }
    }

    Vector3Base<T> Get3PlanesInterPoint(const PlaneBase<T>& p1, const PlaneBase<T>& p2, const PlaneBase<T>& p3) const
    {
            return Vector3Base<T>::Cross(p2.normal, p3.normal) / Vector3Base<T>::Dot(p1.normal, Vector3Base<T>::Cross(p2.normal, p3.normal)) * -p1.distance
            - Vector3Base<T>::Cross(p3.normal, p1.normal) / Vector3Base<T>::Dot(p2.normal, Vector3Base<T>::Cross(p3.normal, p1.normal)) * p2.distance
            - Vector3Base<T>::Cross(p1.normal, p2.normal) / Vector3Base<T>::Dot(p3.normal, Vector3Base<T>::Cross(p1.normal, p2.normal)) * p3.distance;
    }

public:
    /// <summary>
    ///     Returns one of the 6 planes related to this frustum.
    /// </summary>
    /// <param name="index">Plane index where 0 fro Left, 1 for Right, 2 for Top, 3 for Bottom, 4 for Near, 5 for Far</param>
    /// <returns>The plane.</returns>
    PlaneBase<T>& GetPlane(const int index)
    {
        switch (index)
        {
        case 0:
            return planeLeft;
        case 1:
            return planeRight;
        case 2:
            return planeTop;
        case 3:
            return planeBottom;
        case 4:
            return planeNear;
        case 5:
            return planeFar;
        default:
            return planeLeft;
        }
    }

    /// <summary>
    ///     Checks if the bounding frustum contains the bounding box.
    /// </summary>
    /// <param name="box">The bounding box.</param>
    /// <returns>The result, true when contains.</returns>
    bool Contains(const BoundingBoxBase<T>& box)
    {
        Vector3Base<T> p;
        Vector3Base<T> n;

        for (auto i = 0; i < 6; i++)
        {
            auto plane = GetPlane(i);

            GetBoxToPlanePVertexNVertex(box, plane.normal, &p, &n);

            if (PlaneBase<T>::PlaneIntersectsPoint(plane, p) == PlaneIntersection::Back)
                return false;

            if (PlaneBase<T>::PlaneIntersectsPoint(plane, n) == PlaneIntersection::Back)
                return true;
        }

        return true;
    }

    bool ContainsSphere(const BoundingSphereBase<T>& sphere)
    {
        for (auto i = 0; i < 6; i++)
        {
            auto plane = GetPlane(i);

            if (plane.Dot(sphere.center) + sphere.radius < 0.0f)
                return false;
        }

        return true;
    }

    bool IntersectsSphere(const BoundingSphereBase<T>& sphere)
    {
        for (auto i = 0; i < 6; i++)
        {
            auto plane = GetPlane(i);

            if (plane.Dot(sphere.center) + sphere.radius >= 0.0f)
                return true;
        }

        return false;
    }

    void SetPlanes(const MatrixBase<T, 4, 4>& matrix)
    {
        // Left plane
        planeLeft.normal.x = matrix.m14 + matrix.m11;
        planeLeft.normal.y = matrix.m24 + matrix.m21;
        planeLeft.normal.z = matrix.m34 + matrix.m31;
        planeLeft.distance = matrix.m44 + matrix.m41;

        // Right plane
        planeRight.normal.x = matrix.m14 - matrix.m11;
        planeRight.normal.y = matrix.m24 - matrix.m21;
        planeRight.normal.z = matrix.m34 - matrix.m31;
        planeRight.distance = matrix.m44 - matrix.m41;

        // Top plane
        planeTop.normal.x = matrix.m14 - matrix.m12;
        planeTop.normal.y = matrix.m24 - matrix.m22;
        planeTop.normal.z = matrix.m34 - matrix.m32;
        planeTop.distance = matrix.m44 - matrix.m42;

        // Bottom plane
        planeBottom.normal.x = matrix.m14 + matrix.m12;
        planeBottom.normal.y = matrix.m24 + matrix.m22;
        planeBottom.normal.z = matrix.m34 + matrix.m32;
        planeBottom.distance = matrix.m44 + matrix.m42;

        // Near plane
        planeNear.normal.x = matrix.m13;
        planeNear.normal.y = matrix.m23;
        planeNear.normal.z = matrix.m33;
        planeNear.distance = matrix.m43;

        // Far plane
        planeFar.normal.x = matrix.m14 - matrix.m13;
        planeFar.normal.y = matrix.m24 - matrix.m23;
        planeFar.normal.z = matrix.m34 - matrix.m33;
        planeFar.distance = matrix.m44 - matrix.m43;
    }

    std::array<Vector3Base<T>, 8> GetCorners() const
    {
        std::array<Vector3Base<T>, 8> corners = {};

        corners[0] = Get3PlanesInterPoint(planeNear, planeBottom, planeRight);    //Near1
        corners[1] = Get3PlanesInterPoint(planeNear, planeTop, planeRight);       //Near2
        corners[2] = Get3PlanesInterPoint(planeNear, planeTop, planeLeft);        //Near3
        corners[3] = Get3PlanesInterPoint(planeNear, planeBottom, planeLeft);     //Near3
        corners[4] = Get3PlanesInterPoint(planeFar, planeBottom, planeRight);    //Far1
        corners[5] = Get3PlanesInterPoint(planeFar, planeTop, planeRight);       //Far2
        corners[6] = Get3PlanesInterPoint(planeFar, planeTop, planeLeft);        //Far3
        corners[7] = Get3PlanesInterPoint(planeFar, planeBottom, planeLeft);     //Far3

        return corners;
    }

public:
    PlaneBase<T> planeNear = {};
    PlaneBase<T> planeFar = {};
    PlaneBase<T> planeLeft = {};
    PlaneBase<T> planeRight = {};
    PlaneBase<T> planeTop = {};
    PlaneBase<T> planeBottom = {};
};
