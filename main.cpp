#include <iostream>
#include <string>
#include <ctime>
#include "JudgeType.h";

void writeToScreen(const std::string& message)
{
	std::cout << message << std::endl;
}

const std::string& throwBall()
{
	int ball = rand() % 3;

	return judgeTypes[ball].kor;
}

void gamePlay()
{
	writeToScreen("신나는 야구 게임!");
	writeToScreen("첫 번째 타자가 타석에 입장했습니다.");
	std::cout << throwBall() << std::endl;
}

int main(void)
{
	srand((unsigned int)time(0));
	for (unsigned int i = 0; i < 10; i++)
	{
		gamePlay();
	}
	return 0;
}