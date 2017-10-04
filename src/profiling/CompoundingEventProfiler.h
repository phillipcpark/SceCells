#ifndef COMPOUNDING_EVENT_PROFILER
#define COMPOUNDING_EVENT_PROFILER

#include "Profiler.h"

#define SAMPLE_SIZE 250

class CompoundingEventProfiler: public Profiler {
	protected:
		unsigned sampleSize;
		unsigned currentCount;
	public:	
		CompoundingEventProfiler(std::string identifier, bool rowEnd = false);
		~CompoundingEventProfiler();
		void stop();
};

#endif
