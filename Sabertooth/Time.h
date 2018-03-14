#ifndef TIME_H
#define TIME_H

#include <chrono>

namespace Time
{
	std::chrono::time_point<std::chrono::high_resolution_clock> timeStart;
	std::chrono::time_point<std::chrono::high_resolution_clock> timeNewFrame;
	std::chrono::time_point<std::chrono::high_resolution_clock> timeLastFrame;

	float elapsedTime;
	float deltaTime;

	void Initialize();
	void Update();
};

#endif