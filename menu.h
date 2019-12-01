#pragma once
#include <iostream>
#include <string>

class Menu
{
public:
	static bool isValidMenu(std::string menu)
	{
		int menuNumber = atoi(menu.c_str());

		return menu.length() == 0 || (menuNumber >= MENU_START && menuNumber <= MENU_END);
	}

	static void printMenu()
	{
		std::cout << std::endl;
		std::cout << "다음 투구 보기(enter) or 스킵하고 X회말 후 투구보기(숫자+enter) ? (1~6회)";
	}

private:
	static constexpr int MENU_START = 1;
	static constexpr int MENU_END = 6;
};