#pragma once
#include <string>

struct JudgeType
{
	std::string kor;
	std::string eng;
};

JudgeType judgeTypes[4] = { {"스트라이크", "strike" }, {"볼", "ball"}, {"안타", "hit"}, {"아웃", "out"} };

enum Judges
{
	JUDGES_STRIKE,
	JUDGES_BALL,
	JUDGES_HIT,
	JUDGES_OUT
};

void readJudge(const int ball)
{
	std::cout << judgeTypes[ball].kor << "!" << std::endl;
	return;
}