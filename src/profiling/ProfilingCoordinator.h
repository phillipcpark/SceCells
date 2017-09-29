#ifndef PROFILING_COORDINATOR_H
#define PROFILING_COORDINATOR_H

#include <vector>
#include "Profiler.h"

class ProfilingCoordinator {
	private:
		static std::vector<Profiler*> profilers;
	public:
		//DO NOT define destructor, otherwise, static member will be deallocated
		unsigned addProfiler(Profiler*) const; //returns index of child profiler
		void startProfiler(unsigned) const;
		void stopProfiler(unsigned) const;
		float getProfilerTime(unsigned) const;
		std::string getProfilerID(unsigned) const;
};

#endif
