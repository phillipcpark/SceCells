#include "SingleEventProfiler.h"

void SingleEventProfiler::stop() {
	time = timer.getElapsedTime(eventPacket);
}

void SingleEventProfiler::update() {}


