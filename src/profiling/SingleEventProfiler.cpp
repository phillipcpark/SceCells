#include "SingleEventProfiler.h"

SingleEventProfiler::SingleEventProfiler(std::string identifier): Profiler(identifier) {}


SingleEventProfiler::~SingleEventProfiler() {
	delete eventPacket;
	eventPacket = NULL;
}

void SingleEventProfiler::stop() {
	time = timer.getElapsedTime(eventPacket);
}


