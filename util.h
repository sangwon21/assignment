#pragma once
#include <cmath>

class Util
{
public:
	static bool isThreePointFloat(float number)
	{
		float multipleBy100 = number * 1000;

		int compareTarget = ceil(multipleBy100);
		std::cout << "multipleBy100 : " << multipleBy100 << std::endl
			<< "number : " << number << std::endl
			<< "compareTarget : " << compareTarget << std::endl
			<< "static_cast<int> version" << static_cast<int>(multipleBy100) << std::endl;
		return static_cast<int>(multipleBy100) >= compareTarget;
	}
	
};