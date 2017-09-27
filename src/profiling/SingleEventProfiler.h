#ifndef SINGLE_EVENT_PROFILER
#define SINGLE_EVENT_PROFILER

#include "Profiler.h"

class SingleEventProfiler: public Profiler {
	public:
		void stop();
};

void SingleEventProfiler::stop() {
	time = timer.getElapsedTime(eventPacket);
}

#endif
