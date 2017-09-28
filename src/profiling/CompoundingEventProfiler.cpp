#include "CompoundingEventProfiler.h"

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


