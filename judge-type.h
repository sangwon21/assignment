#pragma once
#include <string>

struct JudgeType
{
	std::string kor;
	std::string eng;
};

JudgeType judgeTypes[4] = { {"스트라이크", "strike" }, {"볼", "ball"}, {"안타", "hit"}, {"아웃", "out"}};

enum Judges
{
	JUDGES_STRIKE,
	JUDGES_BALL,
	JUDGES_HIT,
	JUDGES_OUT
};

void readJudge(const int ball)
{
	if (ball == JUDGES_BALL || ball == JUDGES_STRIKE)
	{
		std::cout << judgeTypes[ball].kor << "!" << std::endl;
		return;
	}
	std::cout << judgeTypes[ball].kor << "!"<<"다음 타자가 타석에 입장했습니다." << std::endl;
	return;
}