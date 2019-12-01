#include <iostream>
#include <string>
#include <ctime>
#include "game.h"
#include "board.h"

int main(void)
{
	srand((unsigned int)time(0));

	Board board;
	while (true)
	{
		int isEnded = board.startBoard();
		board.readBoard(isEnded);
	}
	return 0;
}