#ifndef PROFILING_COORDINATOR_H
#define PROFILING_COORDINATOR_H

#include <vector>
#include "Profiler.h"

class ProfilingCoordinator {
	private:
		static std::vector<Profiler*> profilers;
	public:
		~ProfilingCoordinator();
		unsigned addProfiler(Profiler*) const; //returns index of child profiler
		void startProfiler(unsigned) const;
		void updateProfiler(unsigned) const;
		void stopProfiler(unsigned) const;
		float getProfilerTime(unsigned) const;
};

#endif
