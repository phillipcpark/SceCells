#ifndef PROFILER_H
#define PROFILER_H

#include <iostream>
#include "CudaEventLifecycleHandler.h"

class Profiler {
	protected:
		CudaEventLifecycleHandler timer;
		CudaEventPacket* eventPacket;
		float time;

	public:
		~Profiler();
		void start();
		virtual void stop() = 0;
		virtual void update() = 0;
		float getTime();
};

Profiler::~Profiler() {}

void Profiler::start() {
	eventPacket = timer.start();
}

float Profiler::getTime() {
	return time;
}

#endif

