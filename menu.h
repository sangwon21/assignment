#pragma once
#include <iostream>
#include <string>

class Menu
{
public:
	static bool isValidMenu(const int menu)
	{
		return menu >= MENU_START && menu <= MENU_END;
	}

	static void printMenu()
	{
		std::cout << std::endl;
		std::cout << "신나는 야구시합" << std::endl;
		std::cout << "1.데이터 입력" << std::endl;
		std::cout << "2.데이터 출력" << std::endl;
		std::cout << "3. 시합 시작" << std::endl;
		std::cout << "\n메뉴선택(1 - 3) ";
	}

private:
	static constexpr int MENU_START = 1;
	static constexpr int MENU_END = 3;
};