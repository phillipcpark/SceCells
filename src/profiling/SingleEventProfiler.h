#ifndef SINGLE_EVENT_PROFILER
#define SINGLE_EVENT_PROFILER

#include "Profiler.h"

class SingleEventProfiler: public Profiler {
	private:
		CudaEventPacket* eventPacket;
	public:
		void start();
		void stop();
		void update(Profiler*);
		float getTime();
};

void SingleEventProfiler::start() {
	eventPacket = timer.start();
}

void SingleEventProfiler::stop() {
	time = timer.getElapsedTime(eventPacket);
}

void SingleEventProfiler::update(Profiler* null) {}

float SingleEventProfiler::getTime() {
	return time;
}

#endif
