#include "CompoundingEventProfiler.h"
#include <iostream>


CompoundingEventProfiler::~CompoundingEventProfiler() { 
	delete eventPacket;
	eventPacket = NULL;
}

CompoundingEventProfiler::CompoundingEventProfiler() {
	time = 0;
}

void CompoundingEventProfiler::stop() {
	float lastTimeBlock = timer.getElapsedTime(eventPacket);
	time += lastTimeBlock;	
}

