#pragma once
#include <iostream>
#include <string>

class Menu
{
public:
	static bool isValidMenu(const int menu)
	{
		return menu >= 1 && menu <= 2;
	}

	static void printMenu()
	{
		std::cout << std::endl;
		std::cout << "신나는 야구시합" << std::endl;
		std::cout << "1.데이터 입력" << std::endl;
		std::cout << "2.데이터 출력" << std::endl;
		std::cout << "\n메뉴선택(1 - 2) ";
	}
};