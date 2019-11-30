#pragma once
#include "team.h"
#include "menu.h"

class Game
{
public:

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
		while (!(std::cin >> menu) || !Menu::isValidMenu(menu))
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
	static constexpr int INNING_LIMIT = 6;
};