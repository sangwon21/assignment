#pragma once
#include "team.h"
#include "menu.h"
#include "player.h"

class Game
{
public:
	Game()
		: mTurn(0)
		, mCurrentInning(1)
	{	
		Player players1[5] = { {"크롱", 0.123}, {"jk", 0.321}, {"에이스", 0.215}, {"상디", 0.126}, {"조로", 0.222} };
		Player players2[5] = { {"호눅스", 0.123}, {"김세정", 0.321}, {"루피",0.111},{"나루토", 0.312},{"나미", 0.111} };
		mTeam1.initializeTeam(players1, "코드");
		mTeam2.initializeTeam(players2, "스쿼드");
	}

	void selectAction(const int menu)
	{
		switch (menu)
		{
		case 1:
			writeTeamInfo();
			break;
		case 2:
			readTeamInfo();
			break;
		case 3:
			playFullInning();
			break;
		default:
			break;
		}
	}

	void startGame()
	{
		Menu::printMenu();
		int menu;
		while (!(std::cin >> menu))
		{
			std::cout << "에러: 1번 혹은 2번을 눌러주세요! ";
			std::cin.clear();
			std::cin.ignore(123, '\n');
		}
		selectAction(menu);
	}

	void writeTeamInfo()
	{
		mTeam1.writeTeam(1);
		std::cout << std::endl;
		mTeam2.writeTeam(2);
		std::cout << "\n팀데이터 입력이 완료되었습니다." << std::endl;
	}

	void readTeamInfo()
	{
		mTeam1.readTeam();
		std::cout << std::endl;
		mTeam2.readTeam();
		std::cout << "\n팀데이터 출력이 완료되었습니다." << std::endl;
	}

	void playGame(Team& team)
	{
		team.atBat();
		while (!team.isTurnOver())
		{
			team.playInBase();
		}
	}

	void changeTeam()
	{
		mTurn = (mTurn + 1) % 2;
	}

	void moveToNextInning()
	{
		mCurrentInning += 1;
	}

	void playOneThrow(Team& team)
	{
		team.atBat();
		team.playInBase();
		if (team.isTurnOver())
		{
			if (mTurn == TEAM2_TURN)
			{
				moveToNextInning();
			}
			team.cleanUpRecord();
			changeTeam();
		}
	}

	bool checkTeam2IsWinning()
	{
		if (mCurrentInning == INNING_LIMIT && mTurn == TEAM2_TURN && mTeam2.isWinningAgainstTeam(mTeam1))
		{
			return true;
		}
		return false;
	}

	void takeTurn()
	{
		if (checkTeam2IsWinning())
		{
			showResults();
			return;
		}
		std::cout << "누구의 턴이냐 : " << mTurn << "==============" << std::endl;
		std::cout << "몇 이닝 : " << mCurrentInning << "============" << std::endl;
		switch (mTurn)
		{
		case TEAM1_TURN:
			playOneThrow(mTeam1);
			break;
		case TEAM2_TURN:
			playOneThrow(mTeam2);
			break;
		}
	}

	void playTillParticularInning(const int targetInning)
	{
		while (targetInning >= mCurrentInning)
		{
			takeTurn();
		}
	}


	void playOneInning(const int i)
	{
		std::cout << i << "회 초 " + mTeam1.getName() + "의 공격" << std::endl;
		playGame(mTeam1);
		mTeam1.cleanUpRecord();
		std::cout << i << "회 말 " + mTeam2.getName() + "의 공격" << std::endl;
		playGame(mTeam2);
		mTeam2.cleanUpRecord();
	}

	void playFullInning()
	{
		std::cout << "\n" << mTeam1.getName() + " VS " + mTeam2.getName() << std::endl;
		for (int i = 1; i <= INNING_LIMIT; i++)
		{
			playOneInning(i);
		}
		showResults();
	}

	void showResults()
	{
		std::cout << "경기 종료" << std::endl;
		std::cout << "\n" << mTeam1.getName() + " VS " + mTeam2.getName() << std::endl;
		std::cout << mTeam1.getTeamScore() << " : " << mTeam2.getTeamScore() << std::endl;
		std::cout << "Thank you!" << std::endl;
	}

private:
	Team mTeam1;
	Team mTeam2;
	int mTurn;
	int mCurrentInning;
	static constexpr int TEAM1_TURN = 0;
	static constexpr int TEAM2_TURN = 1;
	static constexpr int INNING_LIMIT = 6;
};