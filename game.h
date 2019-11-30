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

private:
	Team mTeam1;
	Team mTeam2;
};