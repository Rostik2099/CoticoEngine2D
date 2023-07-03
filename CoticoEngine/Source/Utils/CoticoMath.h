#pragma once
#include <tgmath.h>
#include "Types/CVector.h"

namespace CoticoMath
{
	float ScalarVectorMultiply(CVector A, CVector B)
	{
		float result = A.X * B.X + A.Y * B.Y;
		return result;
	};

	float VectorModule(CVector vec)
	{
		float result = std::sqrt(vec.X * vec.X + vec.Y * vec.Y);
		return result;
	};

	float FindLookAt(CVector Vec)
	{
		float ScalarMult = CoticoMath::ScalarVectorMultiply(CVector(0, 10), Vec);
		float ModuleMult = CoticoMath::VectorModule(CVector(0, 10)) * CoticoMath::VectorModule(Vec);
		float result = std::acos(ScalarMult / ModuleMult) * 180.f / 3.14f;
		return result;
	};
};