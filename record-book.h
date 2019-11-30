#pragma once
#include <string>
#include "judge-type.h";

class Record
{
public:
	Record(int strike, int ball, int out, int hit)
	{
		mStrike = strike;
		mBall = ball;
		mOut = out;
		mHit = hit;
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

	void convertThreeStrikesOrFourBalls()
	{
		if (mStrike == 3)
		{
			flushRecord();
			mOut += 1;
			readJudge(JUDGES_OUT);
			return;
		}
		if (mBall == 4)
		{
			flushRecord();
			mHit += 1;
			readJudge(JUDGES_HIT);
			return;
		}
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
