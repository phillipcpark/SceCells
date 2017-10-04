#ifndef COMPOUNDING_EVENT_PROFILER
#define COMPOUNDING_EVENT_PROFILER

#include "Profiler.h"

class CompoundingEventProfiler: public Profiler {
	public:	
		CompoundingEventProfiler(std::string identifier, bool rowEnd = false);
		~CompoundingEventProfiler();
		void stop();
};

#endif
