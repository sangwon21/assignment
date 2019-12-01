#pragma once
#include <string>
#include "player.h"
#include "record-book.h"
#include "judge-type.h"
#include "util.h"
#include "ball.h"

class Team
{
public:
	Team()
	{
		mRecord = Record();
		mPlayers = new Player[10]();
	}

	Team(const Team& otherTeam)
	{
		mRecord = otherTeam.mRecord;
		mPlayers = new Player[10]();
		for (int i = 0; i < TEAM_NUMBER_LIMITS; i++)
		{
			mPlayers[i] = otherTeam.mPlayers[i];
		}
	}

	void operator=(const Team& otherTeam)
	{
		mRecord = otherTeam.mRecord;
		delete mPlayers;
		mPlayers = new Player[10]();
		for (int i = 0; i < TEAM_NUMBER_LIMITS; i++)
		{
			mPlayers[i] = otherTeam.mPlayers[i];
		}
	}

	~Team()
	{
		delete[10] mPlayers;
	}

	void initializeTeam(Player *players, std::string name)
	{
		mName = name;
		for (int i = 0; i < TEAM_NUMBER_LIMITS; i++)
		{
			mPlayers[i] = players[i];
		}
	}

	std::string getName()
	{
		return mName;
	}

	bool isValidHitRate(const float hitRate)
	{
		return Util::isFloatInRange(hitRate, MIN_HIT_RATE, MAX_HIT_RATE) && Util::isThreePointFloat(hitRate);
	}

	void writePlayer(const int i)
	{
		std::cout << i + 1 << "번 타자 선수 정보입력 > ";
		float hitRate;
		std::string name;
		std::cin >> name;
		while (!(std::cin >> hitRate) || !isValidHitRate(hitRate))
		{
			std::cout << "에러: 타율은 0.1과 0.5사이 소수 3자리 값이어야 합니다. ";
			std::cin.clear();
			std::cin.ignore(123, '\n');
		}
		mPlayers[i].initializePlayer(name, hitRate);
	}


	void writeTeam(const int number)
	{
		std::cout << number << "팀의 이름을 입력하세요> ";
		std::cin >> mName;
		for (int i = 0; i < TEAM_NUMBER_LIMITS; i++)
		{
			writePlayer(i);
		}
	}

	void readTeam()
	{
		std::cout << mName << "팀 정보" << std::endl;
		for (int i = 0; i < TEAM_NUMBER_LIMITS; i++)
		{
			std::cout << i + 1 << "번 ";
			mPlayers[i].readPlayer();
		}
	}

	bool isTurnOver()
	{
		return mRecord.checkThreeOuts();
	}

	void updateOrder()
	{
		currentOrder = (currentOrder + 1) % TEAM_NUMBER_LIMITS;
	}

	void atBat()
	{
		std::cout << currentOrder + 1 << "번 " << mPlayers[currentOrder].getName() << std::endl;
	}

	void playInBase()
	{
		const int result = mPlayers[currentOrder].swingBet(Ball::throwBall());
		mRecord.writeToRecord(result);
		readJudge(result);
		mRecord.readRecord();
		if (mRecord.convertThreeStrikesOrFourBalls() || result == JUDGES_OUT || result == JUDGES_HIT)
		{
			updateOrder();
		}
	}

	void cleanUpRecord()
	{
		mRecord.flushStrikesAndBalls();
		mRecord.flushOuts();
		mRecord.convertHitsIntoScore();
	}

	int getTeamScore()
	{
		return mRecord.getScore();
	}

private:
	constexpr static int TEAM_NUMBER_LIMITS = 2;
	constexpr static float MIN_HIT_RATE = 0.1;
	constexpr static float MAX_HIT_RATE = 0.5;
	int currentOrder;
	std::string mName;
	Record mRecord;
	Player* mPlayers;
};