#include "stdafx.h"
#include "CppUnitTest.h"

#include "../VectorMath/VectorMath.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorMathTests
{		
	TEST_CLASS(MathTests)
	{
	public:
        TEST_METHOD(VectorsSize)
        {
            Assert::IsTrue(sizeof(Vector2f) == 2 * sizeof(float));
            Assert::IsTrue(sizeof(Vector3f) == 3 * sizeof(float));
            Assert::IsTrue(sizeof(Vector4f) == 4 * sizeof(float));
        }

		TEST_METHOD(VectorConstructorTest)
		{
		    const auto vector2 = Vector2f(1.0f, 2.0f);
            const auto vector3 = Vector3f(1.0f, 2.0f, 3.0f);
            const auto vector4 = Vector4f(1.0f, 2.0f, 3.0f, 4.0f);

            Assert::AreEqual(vector2.x, 1.0f);
            Assert::AreEqual(vector2.y, 2.0f);

            Assert::AreEqual(vector3.x, 1.0f);
            Assert::AreEqual(vector3.y, 2.0f);
            Assert::AreEqual(vector3.z, 3.0f);

            Assert::AreEqual(vector4.x, 1.0f);
            Assert::AreEqual(vector4.y, 2.0f);
            Assert::AreEqual(vector4.z, 3.0f);
            Assert::AreEqual(vector4.w, 4.0f);
		}
	    
	    TEST_METHOD(VectorIterator)
        {
            auto vector4 = Vector4f(0.0f, 0.0f, 0.0f, 0.0f);

            auto i = 1;
            for(auto& comp : vector4)
            {
                comp = float(i);
                i++;
            }

            Assert::AreEqual(vector4.x, 1.0f);
            Assert::AreEqual(vector4.y, 2.0f);
            Assert::AreEqual(vector4.z, 3.0f);
            Assert::AreEqual(vector4.w, 4.0f);
        }

        TEST_METHOD(VectorSetComponentTest)
        {
            auto vector2 = Vector2f(1.0f, 2.0f);
            auto vector3 = Vector3f(1.0f, 2.0f, 3.0f);
            auto vector4 = Vector4f(1.0f, 2.0f, 3.0f, 4.0f);

            vector2.x = vector2.y;
            vector3.x = vector3.y;
            vector4.x = vector4.y;
            vector4.w = 8.0f;

            Assert::AreEqual(vector2.x, 2.0f);
            Assert::AreEqual(vector3.x, 2.0f);
            Assert::AreEqual(vector4.x, 2.0f);
            Assert::AreEqual(vector4.w, 8.0f);
        }

        TEST_METHOD(VectorStaticConstData)
        {
            // Dimension
            Assert::IsTrue(Vector2f::Dimension == 2);
            Assert::IsTrue(Vector3f::Dimension == 3);
            Assert::IsTrue(Vector4f::Dimension == 4);

            // One
            Assert::IsTrue(Vector2::Zero.y == 0.0f);
            Assert::IsTrue(Vector3::Zero.z == 0.0f);
            Assert::IsTrue(Vector4::Zero.w == 0.0f);

            Assert::IsTrue(Vector2::One.y == 1.0f);
            Assert::IsTrue(Vector3::One.z == 1.0f);
            Assert::IsTrue(Vector4::One.w == 1.0f);

        }

        TEST_METHOD(Vector2Operators)
        {
            Assert::IsTrue(Vector2(1.0f) + Vector2(2.0f) == Vector2(3.0f));
            Assert::IsTrue(Vector2(1.0f) - Vector2(2.0f) == -Vector2(1.0f));
            Assert::IsTrue(Vector2(1.0f) / Vector2(2.0f) == Vector2(0.5f));
            Assert::IsTrue(Vector2(1.0f) * Vector2(3.0f) == Vector2(3.0f));

            Assert::IsTrue(Vector2(1.0f) < Vector2(3.0f));
            Assert::IsTrue(Vector2(3.0f) > Vector2(1.0f));
            Assert::IsTrue(Vector2(2.0f) <= Vector2(3.0f));
            Assert::IsTrue(Vector2(3.0f) >= Vector2(2.0f));
        }

        TEST_METHOD(Vector2NormalizeLength)
        {
            Assert::IsTrue(Math::IsZero(Vector2(1.0f, 1.0f).Normalized().Length() - 1.0f));
        }

        TEST_METHOD(Vector2Distance)
        {
            Assert::IsTrue(Math::IsZero(Vector2::Distance(Vector2(0.0f, 1.0f), Vector2(0.0f, 0.0f)) - 1.0f));
        }

        TEST_METHOD(Vector2Lerp)
        {
            const auto interpolant = Vector2::Lerp(Vector2(0.0f, 0.0f), Vector2(1.0f, 0.0f), 0.5f);
            Assert::IsTrue(Math::IsZero(interpolant.x - 0.5f));
        }

        TEST_METHOD(Vector3NormalizeLength)
        {
            Assert::IsTrue(Math::IsZero(Vector3(1.0f, 1.0f, 1.0f).Normalized().Length() - 1.0f));
        }

        TEST_METHOD(Vector3Operators)
        {
            Assert::IsTrue(Vector3(1.0f) + Vector3(2.0f) == Vector3(3.0f));
            Assert::IsTrue(Vector3(1.0f) - Vector3(2.0f) == -Vector3(1.0f));
            Assert::IsTrue(Vector3(1.0f) / Vector3(2.0f) == Vector3(0.5f));
            Assert::IsTrue(Vector3(1.0f) * Vector3(3.0f) == Vector3(3.0f));

            Assert::IsTrue(Vector3(1.0f) < Vector3(3.0f));
            Assert::IsTrue(Vector3(3.0f) > Vector3(1.0f));
            Assert::IsTrue(Vector3(2.0f) <= Vector3(3.0f));
            Assert::IsTrue(Vector3(3.0f) >= Vector3(2.0f));
        }

        TEST_METHOD(Vector4Operators)
        {
            Assert::IsTrue(Vector4(1.0f) + Vector4(2.0f) == Vector4(3.0f));
            Assert::IsTrue(Vector4(1.0f) - Vector4(2.0f) == -Vector4(1.0f));
            Assert::IsTrue(Vector4(1.0f) / Vector4(2.0f) == Vector4(0.5f));
            Assert::IsTrue(Vector4(1.0f) * Vector4(3.0f) == Vector4(3.0f));

            Assert::IsTrue(Vector4(1.0f) < Vector4(3.0f));
            Assert::IsTrue(Vector4(3.0f) > Vector4(1.0f));
            Assert::IsTrue(Vector4(2.0f) <= Vector4(3.0f));
            Assert::IsTrue(Vector4(3.0f) >= Vector4(2.0f));
        }
	};
}