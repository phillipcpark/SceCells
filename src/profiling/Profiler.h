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
		virtual ~Profiler()=0;
		void start();
		virtual void stop()=0;
		float getTime();
};

#endif

