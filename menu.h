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
		std::cout << "�ų��� �߱�����" << std::endl;
		std::cout << "1.������ �Է�" << std::endl;
		std::cout << "2.������ ���" << std::endl;
		std::cout << "\n�޴�����(1 - 2) ";
	}
};