#pragma once
#include <string>
#include "judge-type.h";

struct Record
{
	int strike;
	int ball;
	int out;
};

void flushRecord(Record& record)
{
	record.strike = 0;
	record.ball = 0;
}

void writeToRecord(Record& record, int ball)
{
	switch (ball)
	{
	case JUDGES_STRIKE:
		record.strike += 1;
		break;
	case JUDGES_BALL:
		record.ball += 1;
		break;
	case JUDGES_HIT:
		flushRecord(record);
		break;
	default:
		break;
	}
}

void readRecord(Record& record)
{
	std::cout << record.strike << "S " << record.ball << "B " << record.out << "O" << std::endl;
}