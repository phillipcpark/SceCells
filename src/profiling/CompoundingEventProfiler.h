#ifndef COMPOUNDING_EVENT_PROFILER
#define COMPOUNDING_EVENT_PROFILER

#include "Profiler.h"

class CompoundingEventProfiler: public Profiler {
	private:
		float totalElapsedTime;
	public:	
		CompoundingEventProfiler();
		void stop();
		void update();
};

CompoundingEventProfiler::CompoundingEventProfiler() {
	totalElapsedTime = 0;
}

void CompoundingEventProfiler::stop() {
	time = timer.getElapsedTime(eventPacket);
	totalElapsedTime += time;	
}

void CompoundingEventProfiler::update() {
	time = timer.getElapsedTime(eventPacket);
	totalElapsedTime += time;
	eventPacket = timer.start();
}



#endif
