#include "SingleEventProfiler.h"


SingleEventProfiler::~SingleEventProfiler() {
	delete eventPacket;
	eventPacket = NULL;
}

void SingleEventProfiler::stop() {
	time = timer.getElapsedTime(eventPacket);
}


