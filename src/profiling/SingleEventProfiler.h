#ifndef SINGLE_EVENT_PROFILER
#define SINGLE_EVENT_PROFILER

#include "Profiler.h"

class SingleEventProfiler: public Profiler {
	public:
		SingleEventProfiler(std::string);
		~SingleEventProfiler();
		void stop();
};

#endif
