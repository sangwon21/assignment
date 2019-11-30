#pragma once
#include <string>

struct JudgeType
{
	std::string kor;
	std::string eng;
};

JudgeType judgeTypes[4] = { {"��Ʈ����ũ", "strike" }, {"��", "ball"}, {"��Ÿ", "hit"}, {"�ƿ�", "out"} };

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