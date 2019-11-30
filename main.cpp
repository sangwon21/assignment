#include <iostream>
#include <string>
#include <ctime>
#include "judge-type.h"
#include "record-book.h"
#include "team.h"
#include "game.h"


const int throwBall()
{
	int ball = rand() % 3;

	return ball;
}

void gamePlay(Record& record)
{
	int ball = throwBall();
	record.writeToRecord(ball);
	readJudge(ball);
	record.convertThreeStrikesOrFourBalls();
	record.readRecord();
}

int main(void)
{
	srand((unsigned int)time(0));

	Game game;
	while (true)
		game.startGame();

	/*startMessage();
	while (!record.checkThreeOuts())
	{
		gamePlay(record);
	}
	record.readHits();*/

	return 0;
}