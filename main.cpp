#include <iostream>
#include <string>
#include <ctime>
#include "judge-type.h";
#include "record-book.h"

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
	writeToScreen("���� Ÿ�ڰ� Ÿ���� �����߽��ϴ�.");
}

void startMessage()
{
	writeToScreen("�ų��� �߱� ����!");
	writeToScreen("ù ��° Ÿ�ڰ� Ÿ���� �����߽��ϴ�.");
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

	Record record(0, 0, 0, 0);

	startMessage();
	while (!record.checkThreeOuts())
	{
		gamePlay(record);
	}
	record.readHits();

	return 0;
}