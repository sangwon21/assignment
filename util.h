#pragma once
#include <cmath>

class Util
{
public:
	static bool isThreePointFloat(const float number)
	{
		float multipleBy100 = number * 1000;
		int compareTarget = ceil(multipleBy100);

		return static_cast<int>(multipleBy100) >= compareTarget;
	}
};