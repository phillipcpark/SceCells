#ifndef PROFILING_COORDINATOR_H
#define PROFILING_COORDINATOR_H

#include <vector>
#include "Profiler.h"
#include "OFStreamCSV.h"

class ProfilingCoordinator {
	private:
		static std::vector<Profiler*> profilers;
		static OFStreamCSV outputCSV;
	
	public:
		unsigned addProfiler(Profiler*) const; //returns index of child profiler
		void updateProfiler(unsigned, Profiler*) const;
};

#endif
