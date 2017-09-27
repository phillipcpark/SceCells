#ifndef PROFILER_H
#define PROFILER_H

#include "CudaEventLifecycleHandler.h"

class Profiler {
	protected:
		CudaEventLifecycleHandler timer;
		float time;

	public:
		virtual void start()=0;
		virtual void stop()=0;
		virtual void update(Profiler*)=0;
		virtual float getTime()=0;
};

#endif

