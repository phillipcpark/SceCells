#ifndef COMPOUNDING_EVENT_PROFILER
#define COMPOUNDING_EVENT_PROFILER

#include "Profiler.h"

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
	time += lastTimeBlock;
	eventPacket = timer.start();
}

#endif
