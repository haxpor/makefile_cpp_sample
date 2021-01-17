#pragma once

#include <random>

namespace Util
{
	extern std::random_device g_randomDevice;
	extern std::mt19937 g_randomGenerator;

	static inline const char* GetMeSomeText() 
	{
		std::uniform_int_distribution<std::mt19937::result_type> udist(1, 4);

		auto randNum = udist(g_randomGenerator);
		if (randNum == 1)
			return "Hi";
		else if (randNum == 2)
			return "Sawasdee ka";
		else if (randNum == 3)
			return "Ni hao";
		else
			return "Guten Tag";
	}
};

