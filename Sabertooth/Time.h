#ifndef TIME_H
#define TIME_H

#include <chrono>

class Time
{

private:
	static Time* instance;
	std::chrono::time_point<std::chrono::high_resolution_clock> timeStart;
	std::chrono::time_point<std::chrono::high_resolution_clock> timeNewFrame;
	std::chrono::time_point<std::chrono::high_resolution_clock> timeLastFrame;

public:
	float elapsedTime;
	float deltaTime;

private:
	Time();

public:
	~Time();

	void Update();

	static Time* Instance();

};

#endif