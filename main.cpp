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

void gamePlay(Record& record)
{
	writeToScreen("�ų��� �߱� ����!");
	writeToScreen("ù ��° Ÿ�ڰ� Ÿ���� �����߽��ϴ�.");
	int ball = throwBall();
	writeToRecord(record, ball);
	writeToScreen(judgeTypes[ball].kor);
	readRecord(record);
}

int main(void)
{
	srand((unsigned int)time(0));
	
	Record record = { 0,0,0 };
	
	for (unsigned int i = 0; i < 10; i++)
	{
		gamePlay(record);
	}

	return 0;
}