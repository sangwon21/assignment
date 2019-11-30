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
			playOneInning();
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

	void playOneInning()
	{
		std::cout << "\n" << mTeam1.getName() + " VS " + mTeam2.getName() << std::endl;
		while (!mTeam1.isTurnOver())
		{
			mTeam1.playInBase();
		}
		while (!mTeam2.isTurnOver())
		{
			mTeam2.playInBase();
		}
	}

private:
	Team mTeam1;
	Team mTeam2;
	static constexpr int INNING_LIMIT = 6;
};