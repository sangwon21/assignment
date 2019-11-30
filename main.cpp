#include <iostream>
#include <string>
#include <ctime>
#include "game.h"

int main(void)
{
	srand((unsigned int)time(0));

	Game game;
	while (true)
	{
		game.startGame();
	}

	return 0;
}