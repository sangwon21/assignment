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
		std::cout << "�ų��� �߱�����" << std::endl;
		std::cout << "1.������ �Է�" << std::endl;
		std::cout << "2.������ ���" << std::endl;
		std::cout << "3. ���� ����" << std::endl;
		std::cout << "\n�޴�����(1 - 3) ";
	}

private:
	static constexpr int MENU_START = 1;
	static constexpr int MENU_END = 3;
};