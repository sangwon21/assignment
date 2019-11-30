#pragma once
#include <string>
#include "judge-type.h"

class Player
{
public:
	std::string getName()
	{
		return mName;
	}

	void initializePlayer(std::string name, float hitRate)
	{
		mName = name;
		mHitRate = hitRate;
		maxHitRateRange = MAX_OUT_RANGE + static_cast<int>(mHitRate * 1000);
		maxStrikeRange = maxHitRateRange + static_cast<int>((1 - mHitRate) / 2 - 0.05);
	}

	void readPlayer()
	{
		std::cout << mName << ", " << mHitRate << std::endl;
	}

	const int swingBet(int target)
	{
		if (target < MAX_OUT_RANGE)
		{
			return JUDGES_OUT;
		}
		else if (target < maxHitRateRange)
		{
			return JUDGES_HIT;
		}
		else if (target < maxStrikeRange)
		{
			return JUDGES_STRIKE;
		}
		return JUDGES_BALL;
	}

private:
	std::string mName;
	float mHitRate;
	static constexpr int MAX_OUT_RANGE = 100;
	int maxHitRateRange;
	int maxStrikeRange;
};