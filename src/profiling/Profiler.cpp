#include "Profiler.h"

Profiler::~Profiler() {}

void Profiler::start() {
	eventPacket = timer.start();
}

float Profiler::getTime() {
	return time;
}


