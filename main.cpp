#include <iostream>
#include <string>
#include <ctime>
#include "judge-type.h"
#include "record-book.h"
#include "team.h"
#include "game.h"

void writeToScreen(const std::string& message)
{
	std::cout << message << std::endl;
}

const int throwBall()
{
	int ball = rand() % 3;

	return ball;
}

void showChangePlayerMessage()
{
	writeToScreen("다음 타자가 타석에 입장했습니다.");
}

void startMessage()
{
	writeToScreen("신나는 야구 게임!");
	writeToScreen("첫 번째 타자가 타석에 입장했습니다.");
	writeToScreen("");
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