#pragma once
#include <string>

struct JudgeType
{
	std::string kor;
	std::string eng;
};

JudgeType judgeTypes[4] = { {"��Ʈ����ũ", "strike" }, {"��", "ball"}, {"��Ÿ", "hit"}, {"�ƿ�", "out"}};