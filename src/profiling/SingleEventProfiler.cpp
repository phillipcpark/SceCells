#include "SingleEventProfiler.h"

SingleEventProfiler::SingleEventProfiler(std::string identifier, bool rowEnd): Profiler(identifier, rowEnd) {}


SingleEventProfiler::~SingleEventProfiler() {
	delete eventPacket;
}

void SingleEventProfiler::stop() {
	if (eventPacket != NULL) {
		time = timer.getElapsedTime(eventPacket);	
		eventPacket = NULL;
	}
}


