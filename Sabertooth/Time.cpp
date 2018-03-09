#include "Time.h"

Time* Time::instance = 0;

Time::Time()
{
	timeStart = std::chrono::high_resolution_clock::now();
	timeNewFrame = std::chrono::high_resolution_clock::now();
	timeLastFrame = std::chrono::high_resolution_clock::now();
}


Time::~Time()
{
}

void Time::Update()
{
	timeNewFrame = std::chrono::high_resolution_clock::now();

	elapsedTime = std::chrono::duration_cast< std::chrono::duration<float> >( timeNewFrame - timeStart ).count();
	deltaTime = std::chrono::duration_cast< std::chrono::duration<float> >( timeNewFrame - timeLastFrame ).count();

	timeLastFrame = timeNewFrame;
}

Time * Time::Instance()
{
	if ( instance == 0 ){
		instance = new Time();
	}
	return instance;
}
