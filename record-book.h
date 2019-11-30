#pragma once
#include <string>
#include "judge-type.h"

class Record
{
public:
	Record()
	{
		mStrike = 0;
		mBall = 0;
		mOut = 0;
		mHit = 0;
	}

	void flushRecord()
	{
		mStrike = 0;
		mBall = 0;
	}

	void writeToRecord(int ball)
	{
		switch (ball)
		{
		case JUDGES_STRIKE:
			mStrike += 1;
			break;
		case JUDGES_BALL:
			mBall += 1;
			break;
		case JUDGES_HIT:
			flushRecord();
			mHit += 1;
			break;
		case JUDGES_OUT:
			flushRecord();
			mOut += 1;
			break;
		default:
			break;
		}
	}

	void readRecord()
	{
		std::cout << mStrike << "S " << mBall << "B " << mOut << "O" << std::endl;
		std::cout << std::endl;
	}

	bool checkThreeStrikes()
	{
		return mStrike == 3;
	}

	bool checkFourBalls()
	{
		return mBall == 4;
	}

	bool checkThreeOuts()
	{
		return mOut == 3;
	}

	void handleFourBalls()
	{
		flushRecord();
		mHit += 1;
	}

	void handleThreeStrikes()
	{
		flushRecord();
		mOut += 1;
	}

	bool convertThreeStrikesOrFourBalls()
	{
		if (mStrike == 3)
		{
			flushRecord();
			mOut += 1;
			return true;
		}
		if (mBall == 4)
		{
			flushRecord();
			mHit += 1;
			return true;
		}
		return false;
	}

	void readHits()
	{
		std::cout << "최종 안타수: " << mHit << std::endl;
		std::cout << "GAME OVER" << std::endl;
		std::cout << std::endl;
	}

private:
	int mStrike;
	int mBall;
	int mOut;
	int mHit;
};
