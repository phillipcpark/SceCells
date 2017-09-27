#ifndef PROFILER_H
#define PROFILER_H

#include "CudaEventLifecycleHandler.h"

class Profiler {
	protected:
		CudaEventLifecycleHandler timer;
		CudaEventPacket* eventPacket;
		float time;

	public:
		void start();
		virtual void stop()=0;
		void update();
		float getTime();
};

void Profiler::start() {
	eventPacket = timer.start();
}

void Profiler::update() {}

float Profiler::getTime() {
	return time;
}

#endif

