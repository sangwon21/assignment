#pragma once
#include <string>

class Player
{
public:
	void initializePlayer(std::string name, float hitRate)
	{
		mName = name;
		mHitRate = hitRate;
	}

	void readPlayer()
	{ 
		std::cout << mName << ", " << mHitRate << std::endl;
	}

private:
	std::string mName;
	float mHitRate;
};