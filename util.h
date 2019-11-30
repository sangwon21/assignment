#pragma once
#include <cmath>

class Util
{
public:
	static bool isThreePointFloat(const float number)
	{
		float multipleBy100 = number * 1000;
		int compareTarget = static_cast<int>(ceil(multipleBy100));
		return static_cast<int>(multipleBy100) >= compareTarget;
	}

	static bool isFloatInRange(const float number, const float minFloat, const float maxFloat)
	{
		float multipleBy100 = number * 1000;
		float minRange = minFloat * 1000;
		float maxRange = maxFloat * 1000;
		return static_cast<int>(multipleBy100) > static_cast<int>(minRange) && static_cast<int>(multipleBy100) < static_cast<int>(maxRange);
	}
};