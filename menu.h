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
		std::cout << "���� ���� ����(enter) or ��ŵ�ϰ� Xȸ�� �� ��������(����+enter) ? (1~6ȸ)";
	}

private:
	static constexpr int MENU_START = 1;
	static constexpr int MENU_END = 6;
};