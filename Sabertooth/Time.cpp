#include "Time.h"

void Time::Initialize()
{
	timeStart = std::chrono::high_resolution_clock::now();
	timeNewFrame = std::chrono::high_resolution_clock::now();
	timeLastFrame = std::chrono::high_resolution_clock::now();
}

void Time::Update()
{
	timeNewFrame = std::chrono::high_resolution_clock::now();

	elapsedTime = std::chrono::duration_cast< std::chrono::duration<float> >( timeNewFrame - timeStart ).count();
	deltaTime = std::chrono::duration_cast< std::chrono::duration<float> >( timeNewFrame - timeLastFrame ).count();

	timeLastFrame = timeNewFrame;
}