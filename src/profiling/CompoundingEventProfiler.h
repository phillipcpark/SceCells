#ifndef COMPOUNDING_EVENT_PROFILER
#define COMPOUNDING_EVENT_PROFILER

#include "Profiler.h"

#include <iostream>

class CompoundingEventProfiler: public Profiler {
	public:	
		CompoundingEventProfiler();
		void stop();
		void update();
};

CompoundingEventProfiler::CompoundingEventProfiler() {
	time = 0;
}

void CompoundingEventProfiler::stop() {
	float lastTimeBlock = timer.getElapsedTime(eventPacket);
	time += lastTimeBlock;	
}

void CompoundingEventProfiler::update() {
	float lastTimeBlock = timer.getElapsedTime(eventPacket);

std::cout << "\n\nLAST TIME BLOCK IS " << lastTimeBlock << std::endl;

	time += lastTimeBlock;

std::cout << "\n\nTOTAL TIME IS NOW " << time << std::endl;

	eventPacket = timer.start();
}

#endif
