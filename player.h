#pragma once
#include <string>
#include "judge-type.h"

class Player
{
public:
	Player()
		: mHistoryPointer(0)
	{
		mJudgeHistory = new std::string[100];
	}

	Player(const Player& other)
		: mHistoryPointer(other.mHistoryPointer)
		, maxHitRateRange(other.maxHitRateRange)
		, maxStrikeRange(other.maxStrikeRange)
		, mHitRate(other.mHitRate)
		, mName(other.mName)
	{
		mJudgeHistory = new std::string[100];
		for (int i = 0; i < 100; i++)
		{
			mJudgeHistory[i] = other.mJudgeHistory[i];
		}
	}

	void operator=(const Player& other)
	{
		delete[100] mJudgeHistory;
		mJudgeHistory = new std::string[100];
		for (int i = 0; i < 100; i++)
		{
			mJudgeHistory[i] = other.mJudgeHistory[i];
		}
		mHistoryPointer = other.mHistoryPointer;
		maxHitRateRange = other.maxHitRateRange;
		maxStrikeRange = other.maxStrikeRange;
		mName = other.mName;
		mHitRate = other.mHitRate;
	}

	Player(std::string name, float hitRate)
		: mName(name)
		, mHitRate(hitRate)
		, mHistoryPointer(0)
	{
		maxHitRateRange = MAX_OUT_RANGE + static_cast<int>(mHitRate * 1000);
		maxStrikeRange = maxHitRateRange + static_cast<int>(((1 - mHitRate) / 2 - 0.05) * 1000);
		mJudgeHistory = new std::string[100];
	}

	~Player()
	{
		delete[100] mJudgeHistory;
	}

	std::string getName()
	{
		return mName;
	}

	void initializePlayer(std::string name, float hitRate)
	{
		mName = name;
		mHitRate = hitRate;
		maxHitRateRange = MAX_OUT_RANGE + static_cast<int>(mHitRate * 1000);
		maxStrikeRange = maxHitRateRange + static_cast<int>(((1 - mHitRate) / 2 - 0.05) * 1000);
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

	void recordHistory(const int ball)
	{
		switch (ball)
		{
		case JUDGES_BALL:
			mJudgeHistory[mHistoryPointer++] = "B";
			break;
		case JUDGES_HIT:
			mJudgeHistory[mHistoryPointer++] = "H";
			break;
		case JUDGES_OUT:
			mJudgeHistory[mHistoryPointer++] = "O";
			break;
		case JUDGES_STRIKE:
			mJudgeHistory[mHistoryPointer++] = "S";
			break;
		}
	}

	std::string readHistory()
	{
		std::string result = "";
		for (int i = 0; i < mHistoryPointer; i++)
		{
			result += mJudgeHistory[i];
		}
		return result;
	}

	void clearHistory()
	{
		for (int i = 0; i < mHistoryPointer; i++)
		{
			mJudgeHistory[i] = "";
		}
		mHistoryPointer = 0;
	}

private:
	std::string mName;
	float mHitRate;
	static constexpr int MAX_OUT_RANGE = 100;
	std::string* mJudgeHistory;
	int mHistoryPointer;
	int maxHitRateRange;
	int maxStrikeRange;
};