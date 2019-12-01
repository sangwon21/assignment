#include <iostream>
#include <string>
#include <ctime>
#include "game.h"
#include "board.h"

int main(void)
{
	srand((unsigned int)time(0));

	//Game game;
	//while (true)
	//{
	//	game.startGame();
	//}

	Board board;
	while (true)
	{
		board.startBoard();
	}
	return 0;
}