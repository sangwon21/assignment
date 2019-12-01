#pragma once
#include <string>
#include "judge-type.h"

class Record
{
public:
	Record()
		: mStrike(0)
		, mBall(0)
		, mOut(0)
		, mHit(0)
		, mScore(0)
		, mTotalHit(0)
		, mTotalOut(0)
		, mTotalThrow(0)
	{
	}

	int getScore()
	{
		return mScore;
	}

	int getTotalHit()
	{
		return mTotalHit;
	}

	int getTotalThrow()
	{
		return mTotalThrow;
	}

	int getTotalOut()
	{
		return mTotalOut;
	}
	void flushStrikesAndBalls()
	{
		mStrike = 0;
		mBall = 0;
	}

	void flushOuts()
	{
		mOut = 0;
	}

	void writeToRecord(int ball)
	{
		mTotalThrow += 1;
		switch (ball)
		{
		case JUDGES_STRIKE:
			mStrike += 1;
			break;
		case JUDGES_BALL:
			mBall += 1;
			break;
		case JUDGES_HIT:
			flushStrikesAndBalls();
			mHit += 1;
			mTotalHit += 1;
			break;
		case JUDGES_OUT:
			flushStrikesAndBalls();
			mOut += 1;
			mTotalOut += 1;
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
		flushStrikesAndBalls();
		mHit += 1;
		mTotalHit += 1;
	}

	void handleThreeStrikes()
	{
		flushStrikesAndBalls();
		mOut += 1;
		mTotalOut += 1;
	}

	bool convertThreeStrikesOrFourBalls()
	{
		if (mStrike == 3)
		{
			flushStrikesAndBalls();
			mOut += 1;
			mTotalOut += 1;
			return true;
		}
		if (mBall == 4)
		{
			flushStrikesAndBalls();
			mHit += 1;
			mTotalHit += 1;
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

	void convertHitsIntoScore()
	{
		mScore += mHit / 4;
	}

private:
	int mStrike;
	int mBall;
	int mOut;
	int mHit;
	int mTotalThrow;
	int mTotalHit;
	int mTotalOut;
	int mScore;
};
