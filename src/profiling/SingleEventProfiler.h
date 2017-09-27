#ifndef SINGLE_EVENT_PROFILER
#define SINGLE_EVENT_PROFILER

#include "Profiler.h"

class SingleEventProfiler: public Profiler {
	public:
		void stop();
		void update();
};

void SingleEventProfiler::stop() {
	time = timer.getElapsedTime(eventPacket);
}

void SingleEventProfiler::update() {}

#endif
