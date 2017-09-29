#ifndef COMPOUNDING_EVENT_PROFILER
#define COMPOUNDING_EVENT_PROFILER

#include "Profiler.h"

class CompoundingEventProfiler: public Profiler {
	public:	
		CompoundingEventProfiler(std::string);
		~CompoundingEventProfiler();
		void stop();
};

#endif
