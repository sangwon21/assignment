#pragma once

class Ball
{
public:
	static const int throwBall()
	{
		int ball = rand() % 1000;
		return ball;
	}
};