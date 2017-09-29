#include "CompoundingEventProfiler.h"
#include <iostream>

CompoundingEventProfiler::CompoundingEventProfiler(std::string identifier): Profiler(identifier) {
	time = 0;
}


CompoundingEventProfiler::~CompoundingEventProfiler() { 
	delete eventPacket;
	eventPacket = NULL;
}

void CompoundingEventProfiler::stop() {
	float lastTimeBlock = timer.getElapsedTime(eventPacket);
	time += lastTimeBlock;	
}

