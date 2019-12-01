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
		Player players1[5] = { {"ũ��", 0.123}, {"jk", 0.321}, {"���̽�", 0.215}, {"���", 0.126}, {"����", 0.222} };
		Player players2[5] = { {"ȣ����", 0.123}, {"�輼��", 0.321}, {"����",0.111},{"������", 0.312},{"����", 0.111} };
		mTeam1.initializeTeam(players1, "�ڵ�");
		mTeam2.initializeTeam(players2, "������");
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
			std::cout << "����: 1�� Ȥ�� 2���� �����ּ���! ";
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
		std::cout << "\n�������� �Է��� �Ϸ�Ǿ����ϴ�." << std::endl;
	}

	void readTeamInfo()
	{
		mTeam1.readTeam();
		std::cout << std::endl;
		mTeam2.readTeam();
		std::cout << "\n�������� ����� �Ϸ�Ǿ����ϴ�." << std::endl;
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
		std::cout << "������ ���̳� : " << mTurn << "==============" << std::endl;
		std::cout << "�� �̴� : " << mCurrentInning << "============" << std::endl;
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
		std::cout << i << "ȸ �� " + mTeam1.getName() + "�� ����" << std::endl;
		playGame(mTeam1);
		mTeam1.cleanUpRecord();
		std::cout << i << "ȸ �� " + mTeam2.getName() + "�� ����" << std::endl;
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
		std::cout << "��� ����" << std::endl;
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