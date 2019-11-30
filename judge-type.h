#pragma once
#include <string>

struct JudgeType
{
	std::string kor;
	std::string eng;
};

JudgeType judgeTypes[4] = { {"��Ʈ����ũ", "strike" }, {"��", "ball"}, {"��Ÿ", "hit"}, {"�ƿ�", "out"}};

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
	std::cout << judgeTypes[ball].kor << "!"<<"���� Ÿ�ڰ� Ÿ���� �����߽��ϴ�." << std::endl;
	return;
}