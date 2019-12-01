#pragma once
#include "game.h"

class Board
{
public:
	void selectAction(const int menu)
	{
		switch (menu)
		{
		case INPUT_ENTER:
			game.takeTurn();
			break;
		default:
			game.playTillParticularInning(menu);
			break;
		}
	}

	void startBoard()
	{
		Menu::printMenu();
		std::string input;
		getline(std::cin, input);
		while (!Menu::isValidMenu(input))
		{
			std::cout << "에러: 1에서 6 사이 이닝 혹은 enter를 눌러주세요!";
			getline(std::cin, input);
		} 
		selectAction(atoi(input.c_str()));
	}

	void readBoard()
	{
		std::cout << "+-------------------------------- +" << std::endl;

		std::cout << "+-------------------------------- +" << std::endl;
	}


private:
	Game game;
	static constexpr int INPUT_ENTER = 0;
};